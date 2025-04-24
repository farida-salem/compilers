%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}
int yylex(void);
%}

%union {
    int num;
    char *id;
}

%token <num> NUMBER
%token <id> IDENTIFIER

%token IF THEN ELSE WHILE REPEAT UNTIL FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN
%token INT FLOAT CHAR VOID CONST
%token EQ NEQ LE GE
%token PLUS MINUS MULT DIV MOD

// revisit
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
    : type IDENTIFIER '(' params ')' block
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

type
    : INT
    | FLOAT
    | CHAR
    | VOID
    | CONST type
    ;

block
    : '{' declarations statements '}'
    ;

declarations
    : declarations declaration
    | /* empty */
    ;

declaration
    : type decl_list ';'
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
    | block
    ;

assignment
    : IDENTIFIER '=' expression
    ;

if_statement
    : IF '(' expression ')' THEN statement ELSE statement
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
    : RETURN expression
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

int main(int argc, char **argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Error opening file: %s\n", argv[1]);
            return 1;
        }
    } 
    if(yyparse()==0){
        return 0;
    }

    return 1;
}
