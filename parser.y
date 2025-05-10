%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "quadruple.h"  
#include <ctype.h>

void yyerror(const char *s);
void var_error(const char *message, const char *var_name);
int yylex(void);
extern FILE *yyin;

void check_var_mod(const char *name); 
void check_op_types(Type left_type, Type right_type, const char* op, int allow_strings, int allow_float);
static Type type_arith(Type a, Type b); 
static int is_literal(const char *str);

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

  /* ExprValue for holding both place and type: */
  typedef struct {
      char *place;
      Type type;
      int is_literal;  /* Flag to indicate if this is a direct literal value */
  } ExprValue;

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
    double      fnum;  
    char       *id;
    Type        type;           /* for expressions and constants */
    TypeImmut   immutability;   /* for types and function returns */
    Param       param;          /* for single parameter */
    IdList     *idlist;         /* for decl_list */
    ExprValue   expr;           /* for expressions - holds both place and type */
}

%token <num> NUMBER CHAR_LITERAL
%token <fnum> FLOAT_LITERAL  // Use fnum instead of num
%token <id>     IDENTIFIER STRING_LITERAL

%token IF ELSE WHILE REPEAT UNTIL FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN
%token INT FLOAT CHAR STRING VOID CONST
%token EQ NEQ LE GE
%token PLUS MINUS MULT DIV MOD AND OR NOT
%token ';' ',' '(' ')' '{' '}' '=' '<' '>' ':'

/* Nonterminals carrying types and specs: */
%type <expr>               expression constant
%type <immutability>       type func_types
%type <param>              param      /* single parameter */
%type <param>              param_list /* used only internally */
%type <idlist>             decl_list

/* Fix dangling else problem with precedence */
%nonassoc NO_ELSE
%nonassoc ELSE

/* Operator precedence - arranged from lowest to highest */
%left OR
%left AND  
%left BITWISE_OR
%left BITWISE_AND
%left EQ NEQ
%left '<' '>' LE GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT BITWISE_NOT INC DEC

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
    : func_types IDENTIFIER '(' params ')' 
        {
          current_return_immutability = $1; 
          func_name_temp = strdup($2);
          
          // Generate function label
          emit(QUAD_LABEL, $2, NULL, NULL);
        }
      func_block
      {
        param_count = 0;
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
          if (param_count >= MAX_PARAMS) var_error("Too many parameters in function", func_name_temp);
          param_list[param_count].name = strdup($2);
          param_list[param_count].spec = $1;
          param_count++;
          
          // Register parameter in quadruple
          emit(QUAD_PARAM, $2, NULL, NULL);
        }
    ;

func_types
    : INT           { $$ = (TypeImmut){TYPE_INT,   0}; }
    | FLOAT         { $$ = (TypeImmut){TYPE_FLOAT, 0}; }
    | CHAR          { $$ = (TypeImmut){TYPE_CHAR,  0}; }
    | STRING        { $$ = (TypeImmut){TYPE_STRING, 0}; } 
    | CONST func_types { $$ = $2; $$.is_const = 1; }
    | VOID          { $$ = (TypeImmut){TYPE_VOID,  0}; }
    ;

type
    : INT           { $$ = (TypeImmut){TYPE_INT,   0}; }
    | FLOAT         { $$ = (TypeImmut){TYPE_FLOAT, 0}; }
    | CHAR          { $$ = (TypeImmut){TYPE_CHAR,  0}; }
    | STRING        { $$ = (TypeImmut){TYPE_STRING, 0}; } 
    | CONST type    { $$ = $2; $$.is_const = 1; }
    ;

decl_list
    : IDENTIFIER
        { $$ = new_idlist($1); }
    | decl_list ',' IDENTIFIER
        { $$ = idlist_append($1, $3); }
    ;

declaration
    : type decl_list ';'
        {
          TypeImmut ts = $1;
          for (IdList *it = $2; it; it = it->next) {
            if (!add_variable(it->name, ts))
              var_error("Variable redeclaration", it->name);
              
            // Initialize variable with default value (if tracking values)
            Symbol *v = lookup_symbol(it->name);
            if (v) {
              switch (ts.base) {
                case TYPE_INT: 
                  v->value.int_val = 0; 
                  break;
                case TYPE_FLOAT: 
                  v->value.float_val = 0.0; 
                  break;
                case TYPE_CHAR: 
                  v->value.char_val = '\0'; 
                  break;
                case TYPE_STRING: 
                  v->value.string_val = NULL; 
                  break;
                default: 
                  break;
              }
            }
          }
        }
    | type decl_list '=' expression ';'
        {
          TypeImmut ts = $1;
          if ($4.type != ts.base)
            var_error("Type mismatch in initializer for variable", ((IdList *)$2)->name);
            
          for (IdList *it = $2; it; it = it->next) {
            if (!add_variable(it->name, ts))
              var_error("Variable redeclaration", it->name);
              
            // Initialize with the expression value
            Symbol *v = lookup_symbol(it->name);
            if (v) {
              v->has_value = 1;
              
              // Direct assignment optimization
              char *place = $4.place;
              
              // Emit quadruple for assignment based on type
              if (ts.base == TYPE_STRING) {
                emit(QUAD_ASSIGN_STR, place, NULL, it->name);
              } else if (ts.base == TYPE_CHAR && $4.is_literal) {
                emit(QUAD_ASSIGN_CHAR, place, NULL, it->name);
              } else {
                emit(QUAD_ASSIGN, place, NULL, it->name);
              }
            }
          }
        }
    ;

block
    : '{' 
        { enter_scope(); }
      block_content '}'
        { exit_scope(); }
    ;

block_content
    : block_content declaration
    | block_content statement 
    | /* empty */
    ;

func_block
    : '{' 
        {
          if (!add_function(func_name_temp,
                            current_return_immutability,
                            param_count,
                            param_list))
            var_error("Function redefinition", func_name_temp);

          enter_scope();
                    
          for (int i = 0; i < param_count; i++)
            add_variable(param_list[i].name,
                         param_list[i].spec);
        }
      block_content return_statement '}'
        {
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
    | block
    ;

assignment
    : IDENTIFIER '=' expression ';'
        {
          Symbol *v = lookup_symbol($1);
          if (!v || v->kind!=SYM_VAR)       var_error("Undeclared variable", $1);
          if (v->spec.is_const)             var_error("Cannot assign to const variable", $1);
          if (v->spec.base != $3.type) {
              fprintf(stderr, "DEBUG: Type mismatch in assignment for '%s': expected %d, got %d\n", 
                      $1, v->spec.base, $3.type);
              var_error("Type mismatch in assignment", $1);
          }
          
          // Direct assignment optimization
          char *place = $3.place;
          
          // Choose appropriate quadruple type based on variable type and expression
          if (v->spec.base == TYPE_STRING) {
            emit(QUAD_ASSIGN_STR, place, NULL, $1);
          } else if (v->spec.base == TYPE_CHAR && $3.is_literal) {
            emit(QUAD_ASSIGN_CHAR, place, NULL, $1);
          } else {
            emit(QUAD_ASSIGN, place, NULL, $1);
          }
          
          // Update variable value in symbol table
          v->has_value = 1;
        }
    ;

break_statement
    : BREAK ';'
        {
          // Generate quadruple for break
          emit(QUAD_JUMP, NULL, NULL, "break_target");
        }
    ;

continue_statement
    : CONTINUE ';'
        {
          // Generate quadruple for continue
          emit(QUAD_JUMP, NULL, NULL, "continue_target");
        }
    ;

func_call
    : IDENTIFIER '(' ')' ';'
        {
          Symbol *f = lookup_symbol($1);
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", $1);
          
          // Generate quadruple for function call
          emit(QUAD_CALL, $1, "0", NULL); // 0 args
        }
    ;



/* Fix the dangling else problem with the %prec directive */
if_statement
    : if_start statement %prec NO_ELSE
        {
          // Place end label after the body
          char *end_label = $<id>1;  // Get saved label from if_start
          emit(QUAD_LABEL, end_label, NULL, NULL);
          free(end_label);
        }
    | if_start statement ELSE
        {
          // Generate end label after processing the if-body
          char *end_label = new_label();
          
          // Jump to end after then part
          emit(QUAD_JUMP, NULL, NULL, end_label);
          
          // Place else label before processing the else-body
          char *else_label = $<id>1;
          emit(QUAD_LABEL, else_label, NULL, NULL);
          
          // Free the else label as we're done with it
          free(else_label);
          
          // Pass the end label to the next rule
          $<id>$ = strdup(end_label);
        }
      statement
        {
          // Place end label after else part
          char *end_label = $<id>3;
          emit(QUAD_LABEL, end_label, NULL, NULL);
          free(end_label);
        }
    ;

if_start
    : IF '(' expression ')'
        {
          // Common code for both if types
          if ($3.type != TYPE_INT) 
            var_error("Condition must be int in if statement", "if");
            
          // Generate label
          char *label = new_label();
          
          // Jump to end/else if condition is false
          char *place = $3.place;
          emit(QUAD_JUMPZ, place, NULL, label);
          
          // Pass the label to the next rule
          $<id>$ = strdup(label);
        }
    ;

    
while_statement
    : WHILE '(' expression ')' statement
        {
          // Generate label for loop start
          char *start_label = new_label();
          
          // Generate label for loop end
          char *end_label = new_label();
          
          // Place start label
          emit(QUAD_LABEL, start_label, NULL, NULL);
          
          // Jump to end if condition is false
          char *place = $3.place;
          emit(QUAD_JUMPZ, place, NULL, end_label);
          
          // Jump back to start after body
          emit(QUAD_JUMP, NULL, NULL, start_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ($3.type != TYPE_INT) var_error("Condition must be int in while loop", "while");
        }
    ;

repeat_until_statement
    : REPEAT statements UNTIL '(' expression ')' ';'
        {
          // Generate label for loop start
          char *start_label = new_label();
          
          // Place start label
          emit(QUAD_LABEL, start_label, NULL, NULL);
          
          // Jump back to start if condition is false
          char *place = $5.place;
          emit(QUAD_JUMPZ, place, NULL, start_label);
          
          if ($5.type != TYPE_INT) var_error("Condition must be int in repeat-until loop", "until");
        }
    ;

for_statement
    : FOR '(' declaration expression ';' expression ')' statement
        {
          // Generate condition label
          char *cond_label = new_label();
          
          // Generate update label
          char *update_label = new_label();
          
          // Generate end label
          char *end_label = new_label();
          
          // Place condition label
          emit(QUAD_LABEL, cond_label, NULL, NULL);
          
          // Jump to end if condition is false
          char *cond_place = $4.place;
          emit(QUAD_JUMPZ, cond_place, NULL, end_label);
          
          // Jump to update after body
          emit(QUAD_JUMP, NULL, NULL, update_label);
          
          // Place update label
          emit(QUAD_LABEL, update_label, NULL, NULL);
          
          // Evaluate update expression
          char *update_place = $6.place;
          
          // Jump back to condition
          emit(QUAD_JUMP, NULL, NULL, cond_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ($4.type != TYPE_INT) var_error("Condition must be int in for loop", "for");
        }
    | FOR '(' assignment expression ';' expression ')' statement
        {
          // Generate condition label
          char *cond_label = new_label();
          
          // Generate update label
          char *update_label = new_label();
          
          // Generate end label
          char *end_label = new_label();
          
          // Place condition label
          emit(QUAD_LABEL, cond_label, NULL, NULL);
          
          // Jump to end if condition is false
          char *cond_place = $4.place;
          emit(QUAD_JUMPZ, cond_place, NULL, end_label);
          
          // Jump to update after body
          emit(QUAD_JUMP, NULL, NULL, update_label);
          
          // Place update label
          emit(QUAD_LABEL, update_label, NULL, NULL);
          
          // Evaluate update expression
          char *update_place = $6.place;
          
          // Jump back to condition
          emit(QUAD_JUMP, NULL, NULL, cond_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ($4.type != TYPE_INT) var_error("Condition must be int in for loop", "for");
        }
    ;

switch_statement
    : SWITCH '(' expression ')' '{' 
        {
          // Save the switch expression to a temp for case comparisons
          char *switch_expr = new_temp();
          char *place = $3.place;
          emit(QUAD_ASSIGN, place, NULL, switch_expr);
          
          // Store the switch expression for case comparisons
          $<id>$ = switch_expr;
          
          // Generate end label
          char *end_label = new_label();
          $<id>$ = strdup(end_label);
        }
      case_list '}'
        {
          // Place end label
          emit(QUAD_LABEL, $<id>6, NULL, NULL);
          
          if ($3.type != TYPE_INT) var_error("Switch expression must be int", "switch");
        }
    ;

case_list
    : case_list CASE constant ':' 
        {
          // Generate case label
          char *case_label = new_label();
          emit(QUAD_LABEL, case_label, NULL, NULL);
          
          // Get the switch expression from the parent rule
          char *switch_expr = $<id>0;
          
          // Generate comparison
          char *temp = new_temp();
          char *const_place = $3.place;
          emit(QUAD_EQ, switch_expr, const_place, temp);
          
          // Jump if not equal
          char *next_label = new_label();
          emit(QUAD_JUMPZ, temp, NULL, next_label);
          
          // Store next label for use after statements
          $<id>$ = strdup(next_label);
        }
      statements
        {
          // Jump to end after case body
          emit(QUAD_JUMP, NULL, NULL, $<id>0);
          
          // Place next label
          emit(QUAD_LABEL, $<id>5, NULL, NULL);
        }
    | case_list DEFAULT ':' statements
        {
          // Default code - just fall through
        }
    | /* empty */
    ;

constant
    : NUMBER
        { 
          char *num_str = int_to_string($1);
          $$.place = num_str;
          $$.type = TYPE_INT;
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER: value = %d, type = %d\n", $1, $$.type);
        }
    | CHAR_LITERAL
        {
          // Create a formatted character literal like 'a'
          char char_buf[8];
          sprintf(char_buf, "'%c'", (char)$1); 
          
          $$.place = strdup(char_buf);
          $$.type = TYPE_CHAR;
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: CHAR_LITERAL: value = %s (%d), type = %d\n", 
                  $$.place, $1, $$.type);
        }
    | IDENTIFIER
        {
          Symbol *s = lookup_symbol($1);
          if (!s)                var_error("Undeclared identifier", $1);
          if (s->kind != SYM_VAR) var_error("Case label must be a variable", $1);
          $$.type = s->spec.base;
          $$.place = strdup($1);
          $$.is_literal = 0;
        }
    ;

return_statement
    : RETURN expression ';'
        { 
          if ($2.type != current_return_immutability.base) 
            var_error("Return type mismatch in function", func_name_temp);
          
          // Generate return quadruple
          char *place = $2.place;
          emit(QUAD_RETURN, place, NULL, NULL);
        }
    | RETURN ';'
        { 
          if (current_return_immutability.base != TYPE_VOID)
            var_error("Return value expected in function", func_name_temp);
          
          // Generate void return quadruple
          emit(QUAD_RETURN, NULL, NULL, NULL);
        }
    ;

expression
    : expression PLUS expression 
        { 
          char *temp = new_temp();
          
          // Handle string concatenation as a special case
          if ($1.type == TYPE_STRING && $3.type == TYPE_STRING) {
            emit(QUAD_CONCAT, $1.place, $3.place, temp);
            $$.type = TYPE_STRING;
          } else {
            // Check that types match and are numeric
            if ($1.type != $3.type) {
              fprintf(stderr, "Error: Type mismatch in addition operation\n");
              exit(1);
            }
            
            // Only int and float are allowed for addition
            if ($1.type != TYPE_INT && $1.type != TYPE_FLOAT) {
              fprintf(stderr, "Error: Addition operation requires numeric types\n");
              exit(1);
            }
            
            emit(QUAD_ADD, $1.place, $3.place, temp);
            $$.type = $1.type;
          }
          
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression MINUS expression 
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types($1.type, $3.type, "subtraction", 0, 1);
          
          emit(QUAD_SUB, $1.place, $3.place, temp);
          $$.type = $1.type;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression MULT expression 
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types($1.type, $3.type, "multiplication", 0, 1);
          
          emit(QUAD_MUL, $1.place, $3.place, temp);
          $$.type = $1.type;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression DIV expression 
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types($1.type, $3.type, "division", 0, 1);
          
          emit(QUAD_DIV, $1.place, $3.place, temp);
          $$.type = $1.type;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression MOD expression 
        { 
          char *temp = new_temp();
          
          // Check types - modulo only works on integers
          if ($1.type != TYPE_INT || $3.type != TYPE_INT) {
            fprintf(stderr, "Error: Modulo operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_MOD, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression EQ expression 
        { 
          char *temp = new_temp();
          
          // Handle string comparison as a special case
          if ($1.type == TYPE_STRING && $3.type == TYPE_STRING) {
            emit(QUAD_STREQ, $1.place, $3.place, temp);
          } else {
            // Types must match for comparison
            if ($1.type != $3.type) {
              fprintf(stderr, "Error: Type mismatch in equality comparison\n");
              exit(1);
            }
            
            emit(QUAD_EQ, $1.place, $3.place, temp);
          }
          
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression NEQ expression 
        { 
          char *temp = new_temp();
          
          // Handle string comparison as a special case
          if ($1.type == TYPE_STRING && $3.type == TYPE_STRING) {
            emit(QUAD_STRNEQ, $1.place, $3.place, temp);
          } else {
            // Types must match for comparison
            if ($1.type != $3.type) {
              fprintf(stderr, "Error: Type mismatch in inequality comparison\n");
              exit(1);
            }
            
            emit(QUAD_NEQ, $1.place, $3.place, temp);
          }
          
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression AND expression 
        { 
          char *temp = new_temp();
          
          // Logical operations only work on integers (boolean values)
          if ($1.type != TYPE_INT || $3.type != TYPE_INT) {
            fprintf(stderr, "Error: Logical AND operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_AND, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression OR expression 
        { 
          char *temp = new_temp();
          
          // Logical operations only work on integers (boolean values)
          if ($1.type != TYPE_INT || $3.type != TYPE_INT) {
            fprintf(stderr, "Error: Logical OR operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_OR, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | NOT expression 
        { 
          char *temp = new_temp();
          
          // Logical NOT only works on integers (boolean values)
          if ($2.type != TYPE_INT) {
            fprintf(stderr, "Error: Logical NOT operation requires an integer operand\n");
            exit(1);
          }
          
          emit(QUAD_NOT, $2.place, NULL, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression '<' expression 
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ($1.type != $3.type) {
            fprintf(stderr, "Error: Type mismatch in less-than comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ($1.type == TYPE_STRING) {
            fprintf(stderr, "Error: Less-than comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_LT, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression '>' expression 
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ($1.type != $3.type) {
            fprintf(stderr, "Error: Type mismatch in greater-than comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ($1.type == TYPE_STRING) {
            fprintf(stderr, "Error: Greater-than comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_GT, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression LE expression 
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ($1.type != $3.type) {
            fprintf(stderr, "Error: Type mismatch in less-than-or-equal comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ($1.type == TYPE_STRING) {
            fprintf(stderr, "Error: Less-than-or-equal comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_LE, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | expression GE expression 
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ($1.type != $3.type) {
            fprintf(stderr, "Error: Type mismatch in greater-than-or-equal comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ($1.type == TYPE_STRING) {
            fprintf(stderr, "Error: Greater-than-or-equal comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_GE, $1.place, $3.place, temp);
          $$.type = TYPE_INT;
          $$.place = temp;
          $$.is_literal = 0;
        }
    | '(' expression ')'
        { 
          $$.type = $2.type;
          $$.place = $2.place;
          $$.is_literal = $2.is_literal;
        }
    | IDENTIFIER
        {
          Symbol *v = lookup_symbol($1);
          if (!v) var_error("Undeclared variable", $1);
          
          // Check if variable has been initialized
          if (v->kind == SYM_VAR && !v->has_value) {
            fprintf(stderr, "Error: Variable '%s' is being used without being initialized\n", $1);
            exit(1);
          }

          // Mark variable as used
          if (v->kind == SYM_VAR) {
            v->is_used = 1;
          }
          
          $$.type = v->spec.base;
          $$.place = strdup($1);
          $$.is_literal = 0;
          fprintf(stderr, "DEBUG: IDENTIFIER: %s, type = %d\n", $1, $$.type);
        }
    | NUMBER
        { 
          // Use the number directly without temporary for literals
          char *num_str = int_to_string($1);
          $$.type = TYPE_INT;
          $$.place = num_str;
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER LITERAL: value = %s\n", num_str);
        }
    | FLOAT_LITERAL
        { 
          char *num_str = float_to_string($1);
          $$.type = TYPE_FLOAT;
          $$.place = num_str;
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: FLOAT_LITERAL: value = %s\n", num_str);
        }
    | CHAR_LITERAL
        {
          // Format character literal for direct use
          char char_buf[8];
          sprintf(char_buf, "'%c'", (char)$1);
          
          $$.type = TYPE_CHAR;
          $$.place = strdup(char_buf);
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: CHAR_LITERAL: value = %s\n", char_buf);
        }
    | STRING_LITERAL
        {
          $$.type = TYPE_STRING;
          $$.place = strdup($1);
          $$.is_literal = 1;
          fprintf(stderr, "DEBUG: STRING_LITERAL: value = %s\n", $1);
        }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

void var_error(const char *message, const char *var_name) {
    fprintf(stderr, "Error: %s '%s'\n", message, var_name);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc>1) {
        yyin = fopen(argv[1],"r");
        if (!yyin) { perror("open"); return 1; }
    }
    
    // Initialize quadruples system
    init_quadruples();
    
    int result = yyparse();
    
    // Print generated quadruples
    if (result == 0) {
        // Print to console
        check_unused_variables();
        print_quadruples(stdout);
        
        // Save to files
        print_quadruples_to_file("quadruples.txt");
        print_symbol_table_to_file("symbols.txt");
        
        printf("Compilation successful. Output written to:\n");
        printf("- quadruples.txt\n");
        printf("- symbols.txt\n");
    }
    
    return result ? 1 : 0;
}

static Type type_arith(Type a, Type b) {
    if (a != b) yyerror("Type mismatch in expression");
    return a;
}

void check_var_mod(const char *name) {
   Symbol *v = lookup_symbol(name);
   if (!v || v->kind != SYM_VAR) var_error("Undeclared variable", name); 
   if (v->spec.is_const) var_error("Cannot modify const variable", name);
}

static int is_literal(const char *str) {
    return (str && (isdigit(str[0]) || str[0] == '\'' || str[0] == '"'));
}

void check_op_types(Type left_type, Type right_type, const char* op, int allow_strings, int allow_float) {
    // Check if types match
    if (left_type != right_type) {
        fprintf(stderr, "Error: Type mismatch in %s operation: cannot mix types\n", op);
        exit(1);
    }

    // Check for allowed types
    if (!allow_strings && (left_type == TYPE_STRING)) {
        fprintf(stderr, "Error: %s operation not supported on string types\n", op);
        exit(1);
    }
    
    if (!allow_float && (left_type == TYPE_FLOAT)) {
        fprintf(stderr, "Error: %s operation not supported on float types\n", op);
        exit(1);
    }
}