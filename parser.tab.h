/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "parser.y"

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

#line 80 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    CHAR_LITERAL = 259,            /* CHAR_LITERAL  */
    FLOAT_LITERAL = 260,           /* FLOAT_LITERAL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    REPEAT = 266,                  /* REPEAT  */
    UNTIL = 267,                   /* UNTIL  */
    FOR = 268,                     /* FOR  */
    SWITCH = 269,                  /* SWITCH  */
    CASE = 270,                    /* CASE  */
    DEFAULT = 271,                 /* DEFAULT  */
    BREAK = 272,                   /* BREAK  */
    CONTINUE = 273,                /* CONTINUE  */
    RETURN = 274,                  /* RETURN  */
    INT = 275,                     /* INT  */
    FLOAT = 276,                   /* FLOAT  */
    CHAR = 277,                    /* CHAR  */
    STRING = 278,                  /* STRING  */
    VOID = 279,                    /* VOID  */
    CONST = 280,                   /* CONST  */
    EQ = 281,                      /* EQ  */
    NEQ = 282,                     /* NEQ  */
    LE = 283,                      /* LE  */
    GE = 284,                      /* GE  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    MULT = 287,                    /* MULT  */
    DIV = 288,                     /* DIV  */
    MOD = 289,                     /* MOD  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    NOT = 292,                     /* NOT  */
    NO_ELSE = 293,                 /* NO_ELSE  */
    BITWISE_OR = 294,              /* BITWISE_OR  */
    BITWISE_AND = 295,             /* BITWISE_AND  */
    BITWISE_NOT = 296,             /* BITWISE_NOT  */
    INC = 297,                     /* INC  */
    DEC = 298                      /* DEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 59 "parser.y"

    int         num;
    double      fnum;  
    char       *id;
    Type        type;           /* for expressions and constants */
    TypeImmut   immutability;   /* for types and function returns */
    Param       param;          /* for single parameter */
    IdList     *idlist;         /* for decl_list */
    ExprValue   expr;           /* for expressions - holds both place and type */

#line 151 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
