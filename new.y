revisit all semicolons and define them were rules resolves to terminals %{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;
%}

%define parse.error verbose

%union {
    int num;
    char *id;
}

%token <num> NUMBER
%token <id> IDENTIFIER

%token IF THEN ELSE WHILE REPEAT UNTIL FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN
%token INT FLOAT CHAR VOID CONST
%token EQ NEQ LE GE
%token PLUS MINUS MULT DIV MOD INC DEC
%token ';' ',' '(' ')' '{' '}' '=' '<' '>' ':'

%left PLUS MINUS
%left MULT DIV MOD
%nonassoc EQ NEQ '<' '>' LE GE

%%

program
    : functions
    ;

functions
    : functions function
    | function
    ;

function
    : func_types IDENTIFIER '(' params ')' func_block
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
    ;

func_types
    : INT
    | FLOAT
    | CHAR
    | CONST func_types
    | VOID
    ;

type
    : INT
    | FLOAT
    | CHAR
    | CONST type
    ;

block
    : '{' block_content'}'
      
    ;
block_content
    : block_content declarations
    | block_content statements
    | /* empty */
    ;

func_block
    : '{' block_content return_statement '}'
    ;    

declarations
    : declarations declaration
    | /* empty */
    ;

declaration
    : type decl_list ';'| type decl_list '=' expression ';'
    ;

decl_list
    : decl_list ',' IDENTIFIER
    | IDENTIFIER
    ;

statements
    : statements statement
    | /* empty */
    ;

statement
    : assignment ';'
    | if_statement
    | while_statement
    | repeat_until_statement
    | for_statement
    | switch_statement
    | return_statement ';'
    | BREAK ';'
    | CONTINUE ';'
    | IDENTIFIER '('')' ';'
    | IDENTIFIER INC ';'
    | IDENTIFIER DEC ';'
    | INC IDENTIFIER ';'
    | DEC IDENTIFIER ';'
    | block
    ;

assignment
    : IDENTIFIER '=' expression
    ;

if_statement
    : IF '(' expression ')' statement ELSE statement
    ;

while_statement
    : WHILE '(' expression ')' statement
    ;

repeat_until_statement
    : REPEAT statements UNTIL '(' expression ')' ';'
    ;

for_statement
    : FOR '(' assignment ';' expression ';' assignment ')' statement
    ;

switch_statement
    : SWITCH '(' expression ')' '{' case_list '}'
    ;

case_list
    : case_list CASE constant ':' statements
    | case_list DEFAULT ':' statements
    | /* empty */
    ;

constant
    : NUMBER
    | IDENTIFIER
    ;

return_statement
    : RETURN expression | RETURN
    ;

expression
    : expression PLUS expression
    | expression MINUS expression
    | expression MULT expression
    | expression DIV expression
    | expression MOD expression
    | expression EQ expression
    | expression NEQ expression
    | expression '<' expression
    | expression '>' expression
    | expression LE expression
    | expression GE expression
    | '(' expression ')'
    | IDENTIFIER
    | NUMBER
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening input file");
            return 1;
        }
    }
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
        return 0;
    }
    return 1;
}
