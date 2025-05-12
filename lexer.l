%{
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

void token_seen(const char* token_text);

#define YY_USER_ACTION { token_seen(yytext); }

// Track line numbers
extern int yylineno;
extern int column; 
%}


DIGIT       [0-9]
LETTER      [A-Za-z_]
ID          {LETTER}({LETTER}|{DIGIT})*

%%

\n          { column = 1; yylineno++; printf("line:%d\n",yylineno);}

[ \t\r]+        ;  // This rule ignores whitespace and does not need a print

"//".*            ;  // Single-line comment (no print here unless needed)

"/*"([^*]|\*+[^*/])*\*+"/"* ;  // Multi-line comment (no print here unless needed)

"if"              { printf("Keyword IF: %s\n", yytext); return IF; }
"else"            { printf("Keyword ELSE: %s\n", yytext); return ELSE; }
"while"           { printf("Keyword WHILE: %s\n", yytext); return WHILE; }
"repeat"          { printf("Keyword REPEAT: %s\n", yytext); return REPEAT; }
"until"           { printf("Keyword UNTIL: %s\n", yytext); return UNTIL; }
"for"             { printf("Keyword FOR: %s\n", yytext); return FOR; }
"switch"          { printf("Keyword SWITCH: %s\n", yytext); return SWITCH; }
"case"            { printf("Keyword CASE: %s\n", yytext); return CASE; }
"default"         { printf("Keyword DEFAULT: %s\n", yytext); return DEFAULT; }
"break"           { printf("Keyword BREAK: %s\n", yytext); return BREAK; }
"return"          { printf("Keyword RETURN: %s\n", yytext); return RETURN; }

"int"             { printf("Type INT: %s\n", yytext); return INT; }
"float"           { printf("Type FLOAT: %s\n", yytext); return FLOAT; }
"char"            { printf("Type CHAR: %s\n", yytext); return CHAR; }
"string"          { printf("Type STRING: %s\n", yytext); return STRING; }
"void"            { printf("Type VOID: %s\n", yytext); return VOID; }
"const"           { printf("Keyword CONST: %s\n", yytext); return CONST; }

"=="              { printf("Operator EQ: %s\n", yytext); return EQ; }
"!="              { printf("Operator NEQ: %s\n", yytext); return NEQ; }
"<="              { printf("Operator LE: %s\n", yytext); return LE; }
">="              { printf("Operator GE: %s\n", yytext); return GE; }
"++"              { printf("Operator INC: %s\n", yytext); return INC; }
"--"              { printf("Operator DEC: %s\n", yytext); return DEC; }

"<"               { printf("Operator < : %s\n", yytext); return '<'; }
">"               { printf("Operator > : %s\n", yytext); return '>'; }
"="               { printf("Operator = : %s\n", yytext); return '='; }
"+"               { printf("Operator PLUS: %s\n", yytext); return PLUS; }
"-"               { printf("Operator MINUS: %s\n", yytext); return MINUS; }
"*"               { printf("Operator MULT: %s\n", yytext); return MULT; }
"/"               { printf("Operator DIV: %s\n", yytext); return DIV; }
"%"               { printf("Operator MOD: %s\n", yytext); return MOD; }
"&&"              { printf("Operator AND: %s\n", yytext); return AND; }
"||"              { printf("Operator OR: %s\n", yytext); return OR; }
"!"               { printf("Operator NOT: %s\n", yytext); return NOT; }

";"               { printf("Semicolon ;\n"); return ';'; }
","               { printf("Comma ,\n"); return ','; }
"("               { printf("Left Parenthesis (\n"); return '('; }
")"               { printf("Right Parenthesis )\n"); return ')'; }
"{"               { printf("Left Brace {\n"); return '{'; }
"}"               { printf("Right Brace }\n"); return '}'; }
":"               { printf("Colon :\n"); return ':'; }

{ID}              { printf("IDENTIFIER: %s\n", yytext); yylval.id = strdup(yytext); return IDENTIFIER; }
{DIGIT}+"."{DIGIT}+   {printf("FLOAT_LITERAL: %s\n", yytext);  yylval.fnum = atof(yytext);  return FLOAT_LITERAL;}
{DIGIT}+             { printf("NUMBER: %s\n", yytext); yylval.num = atof(yytext); return NUMBER; }

  /* Character literals - single character in single quotes */
'.'              { 
                    printf("CHAR_LITERAL: %s\n", yytext);
                    yylval.num = yytext[1]; // Store the ASCII value 
                    return CHAR_LITERAL;
                  }


  /* String literals - text in double quotes */
\"[^\"]*\"       {
                    printf("STRING_LITERAL: %s\n", yytext);
                    // Remove the quotes and store just the string content
                    int len = strlen(yytext) - 2;
                    char* str = malloc(len + 1);
                    strncpy(str, yytext + 1, len);
                    str[len] = '\0';
                    yylval.id = str;
                    return STRING_LITERAL;
                  }

.                 { printf("Unknown token (hex): 0x%02x\n", yytext[0]); return yytext[0]; }

%%

int yywrap() {
    return 1;
}