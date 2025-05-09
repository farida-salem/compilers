%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;

void check_var_mod(const char *name); 
static int type_arith(Type a, Type b); 

#define MAX_PARAMS  16
static Param param_list[MAX_PARAMS];
static int   param_count = 0;
static TypeImmut current_return_immutability;


static char *func_name_temp;
%}

%code requires {
  #include "symbol_table.h"

  /* IdList for decl_list: */
  typedef struct IdList {
      char       *name;
      struct IdList *next;
  } IdList;

  /* Helpers to build a list of identifiers: */
  static IdList* new_idlist(char *n) {
      IdList *l = malloc(sizeof *l);
      l->name = strdup(n);
      l->next = NULL;
      return l;
  }
  static IdList* idlist_append(IdList *l, char *n) {
      IdList *it = l;
      while (it->next) it = it->next;
      it->next = new_idlist(n);
      return l;
  }
}

/* Tell Bison about our C types: */
%union {
    int         num;
    char       *id;
    Type        type;           /* for expressions and constants */
    TypeImmut   immutability;   /* for types and function returns */
    Param       param;          /* for single parameter */
    IdList     *idlist;         /* for decl_list */
}

%token <num>    NUMBER
%token <id>     IDENTIFIER

%token IF THEN ELSE WHILE REPEAT UNTIL FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN
%token INT FLOAT CHAR VOID CONST
%token EQ NEQ LE GE
%token PLUS MINUS MULT DIV MOD INC DEC AND OR NOT BITWISE_AND BITWISE_NOT BITWISE_OR
%token ';' ',' '(' ')' '{' '}' '=' '<' '>' ':'

/* Nonterminals carrying types and specs: */
%type <type>               expression constant
%type <immutability>       type func_types
%type <param>              param      /* single parameter */
%type <param>              param_list /* used only internally */
%type <idlist>             decl_list



/* Operator precedence */
%left PLUS MINUS
%left MULT DIV MOD
%nonassoc EQ NEQ '<' '>' LE GE

%%
program
    : /* initialize symbol table */       
        { init_symbol_table(); }
      functions
    ;

functions
    : functions function
    | function
    ;

function
    : func_types IDENTIFIER '(' params ')' func_block
        /* before func_block: record return type & name, reset params */
        { 
          current_return_immutability = $1; 
          func_name_temp              = strdup($2);
          param_count                 = 0;
        }
    ;

params
    : param_list
    | /* empty */
    ;

param_list
    : param_list ',' param
    | param
    ;

param
    : type IDENTIFIER
        /* collect parameters for later insertion */
        {
          if (param_count >= MAX_PARAMS) yyerror("Too many parameters");
          param_list[param_count].name = strdup($2);
          param_list[param_count].spec = $1;
          param_count++;
        }
    ;

func_types
    : INT           { $$ = (TypeImmut){TYPE_INT,   0}; }
    | FLOAT         { $$ = (TypeImmut){TYPE_FLOAT, 0}; }
    | CHAR          { $$ = (TypeImmut){TYPE_CHAR,  0}; }
    | CONST func_types { $$ = $2; $$.is_const = 1; }
    | VOID          { $$ = (TypeImmut){TYPE_VOID,  0}; }
    ;

/* Replace your old type with this: */
type
    : INT           { $$ = (TypeImmut){TYPE_INT,   0}; }
    | FLOAT         { $$ = (TypeImmut){TYPE_FLOAT, 0}; }
    | CHAR          { $$ = (TypeImmut){TYPE_CHAR,  0}; }
    | CONST type    { $$ = $2; $$.is_const = 1; }
    ;

/* Replace your old decl_list with this: */
decl_list
    : IDENTIFIER
        { $$ = new_idlist($1); }
    | decl_list ',' IDENTIFIER
        { $$ = idlist_append($1, $3); }
    ;

/* Replace your old declaration with this: */
declaration
    : type decl_list ';'
        {
          TypeImmut ts = $1;
          for (IdList *it = $2; it; it = it->next)
            if (!add_variable(it->name, ts))
              yyerror("Variable redeclaration");
        }
    | type decl_list '=' expression ';'
        {
          TypeImmut ts = $1;
          if ($4 != ts.base)
            yyerror("Type mismatch in initializer");
          for (IdList *it = $2; it; it = it->next)
            if (!add_variable(it->name, ts))
              yyerror("Variable redeclaration");
        }
    ;

block
    : '{' block_content '}'
        /* every `{}` opens and closes a scope */
        { enter_scope(); }
        block_content
        {
          exit_scope();
        }
    ;

block_content
    : block_content declaration
    | block_content statement 
    | /* empty */
    ;

func_block
    : '{' block_content return_statement '}'
        /* register function & open its scope */
        {
          if (!add_function(func_name_temp,
                            current_return_immutability,
                            param_count,
                            param_list))
            yyerror("Function redefinition");

          /* insert params as locals */
          for (int i = 0; i < param_count; i++)
            add_variable(param_list[i].name,
                         param_list[i].spec);

          enter_scope();
        }
        block_content
        return_statement
        {
          /* close the function scope */
          exit_scope();
        }
    ;


statements
    : statements statement
    | /* empty */
    ;

statement
    : assignment
    | if_statement
    | while_statement
    | repeat_until_statement
    | for_statement
    | switch_statement
    | return_statement
    | break_statement
    | continue_statement
    | func_call
    | inc_dec
    | block
    ;

assignment
    : IDENTIFIER '=' expression ';'
        {
          Symbol *v = lookup_symbol($1);
          if (!v || v->kind!=SYM_VAR)       yyerror("Undeclared variable");
          if (v->spec.is_const)             yyerror("Cannot assign to const");
          if (v->spec.base  != $3)          yyerror("Type mismatch in assignment");
        }
    ;

break_statement
    : BREAK ';'
    ;

continue_statement
    : CONTINUE ';'
    ;

func_call
    : IDENTIFIER '(' ')' ';'
        {
          Symbol *f = lookup_symbol($1);
          if (!f || f->kind!=SYM_FUNC) yyerror("Undeclared function call");
        }
    ;

inc_dec
    : IDENTIFIER INC ';'  { check_var_mod($1); }
    | IDENTIFIER DEC ';'  { check_var_mod($1); }
    | INC IDENTIFIER ';'  { check_var_mod($2); }
    | DEC IDENTIFIER ';'  { check_var_mod($2); }
    ;

if_statement
    : IF '(' expression ')' statement ELSE statement
        {
          if ($3 != TYPE_INT) yyerror("Condition must be int");
        }
    ;

while_statement
    : WHILE '(' expression ')' statement
        { if ($3 != TYPE_INT) yyerror("Condition must be int"); }
    ;

repeat_until_statement
    : REPEAT statements UNTIL '(' expression ')' ';'
        { if ($5 != TYPE_INT) yyerror("Condition must be int"); }
    ;

for_statement
    : FOR '(' 
        { 
          /* 1) open a fresh scope for the “int x=…” */
          enter_scope(); 
        }
      declaration        /* this will do add_variable(...) into the new scope */
      expression ';' expression ')' statement
        {
          /* 2) now that we’ve seen “x<7”, validate it and tear down that scope */
          if ($5 != TYPE_INT) 
            yyerror("Condition must be int");
          exit_scope();
        }
    | FOR '(' assignment expression ';' expression ')' statement
        {
          /* plain old for without an int-decl */
          if ($4 != TYPE_INT) 
            yyerror("Condition must be int");
        }
    ;


switch_statement
    : SWITCH '(' expression ')' '{' case_list '}'
        { if ($3 != TYPE_INT) yyerror("Switch expr must be int"); }
    ;

case_list
    : case_list CASE constant ':' statements
    | case_list DEFAULT ':' statements
    | /* empty */
    ;

constant
    : NUMBER
        { $$ = TYPE_INT; }
    | IDENTIFIER
        {
          Symbol *s = lookup_symbol($1);
          if (!s)                yyerror("Undeclared identifier");
          if (s->kind != SYM_VAR)yyerror("Case label must be variable");
          $$ = s->spec.base;
        }
    ;

return_statement
    : RETURN expression ';'
        { if ($2 != current_return_immutability.base) 
            yyerror("Return type mismatch"); }
    | RETURN ';'
        { if (current_return_immutability.base != TYPE_VOID)
            yyerror("Return value expected"); }
    ;

expression
    : expression PLUS      expression { $$ = type_arith($1,$3); }
    | expression MINUS     expression { $$ = type_arith($1,$3); }
    | expression MULT      expression { $$ = type_arith($1,$3); }
    | expression DIV       expression { $$ = type_arith($1,$3); if ($3 == 0) yyerror("Division by zero"); }
    | expression MOD       expression { $$ = type_arith($1,$3); }
    | expression EQ        expression { $$ = TYPE_INT; }
    | expression NEQ       expression { $$ = TYPE_INT; }
    | expression AND       expression { $$ = TYPE_INT; }
    | expression OR        expression { $$ = TYPE_INT; }
    | NOT expression                    { $$ = $2;            }
    | expression BITWISE_AND expression { $$ = type_arith($1,$3); }
    | expression BITWISE_OR  expression { $$ = type_arith($1,$3); }
    | BITWISE_NOT expression           { $$ = $2;            }
    | expression '<'      expression   { $$ = TYPE_INT;      }
    | expression '>'      expression   { $$ = TYPE_INT;      }
    | expression LE       expression   { $$ = TYPE_INT;      }
    | expression GE       expression   { $$ = TYPE_INT;      }
    | IDENTIFIER INC
        { check_var_mod($1);  $$ = TYPE_INT; }
    | IDENTIFIER DEC
        { check_var_mod($1);  $$ = TYPE_INT; }
    | INC IDENTIFIER
        { check_var_mod($2);  $$ = TYPE_INT; }
    | DEC IDENTIFIER
        { check_var_mod($2);  $$ = TYPE_INT; }
    | '(' expression ')'               { $$ = $2;            }
    | IDENTIFIER
        {
          Symbol *v = lookup_symbol($1);
          if (!v) yyerror("Undeclared variable");
          $$ = v->spec.base;
        }
    | NUMBER                            { $$ = TYPE_INT;      }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc>1) {
      yyin = fopen(argv[1],"r");
      if (!yyin) { perror("open"); return 1; }
    }
    return yyparse() ? 1 : 0;
}


static int type_arith(Type a, Type b) {
    if (a != b) yyerror("Type mismatch in expression");
    return a;
}

void check_var_mod(const char *name) {
   Symbol *v = lookup_symbol(name);
  if (!v || v->kind != SYM_VAR) yyerror("Undeclared variable"); 
  if (v->spec.is_const) yyerror("Cannot modify const variable"); }



