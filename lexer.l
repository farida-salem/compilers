%{
#include <stdlib.h>
#include <string.h>    
#include "parser.tab.h"



%}

DIGIT       [0-9]
LETTER      [A-Za-z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUM         {DIGIT}+(\.{DIGIT}+)?

%%

[ \t\n]+;
"//".* ;
"/*"([^*]|\*+[^*/])*\*+"/"*;

"if"           return IF;
"then"         return THEN;
"else"         return ELSE;
"while"        return WHILE;
"repeat"       return REPEAT;
"until"        return UNTIL;
"for"          return FOR;
"switch"       return SWITCH;
"case"         return CASE;
"default"      return DEFAULT;
"break"        return BREAK;
"continue"     return CONTINUE;
"return"       return RETURN;

"int"          return INT;
"float"        return FLOAT;
"char"         return CHAR;
"void"         return VOID;
"const"        return CONST;

"=="           return EQ;
"!="           return NEQ;
"<="           return LE;
">="           return GE;

"<"            return '<';
">"            return '>';
"="            return '=';
"+"            return PLUS;
"-"            return MINUS;
"*"            return MULT;
"/"            return DIV;
"%"            return MOD;

";"            return ';';
","            return ',';
"("            return '(';
")"            return ')';
"{"            return '{';
"}"            return '}';
":"            return ':';

{NUM}                   { yylval.num = atof(yytext); return NUMBER; }
{ID}                    { yylval.id = strdup(yytext); return IDENTIFIER; }

.                       { return yytext[0]; }

%%

int yywrap() {
    return 1; // Indicates end of input
}
