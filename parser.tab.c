/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 93 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_THEN = 6,                       /* THEN  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_REPEAT = 9,                     /* REPEAT  */
  YYSYMBOL_UNTIL = 10,                     /* UNTIL  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_VOID = 21,                      /* VOID  */
  YYSYMBOL_CONST = 22,                     /* CONST  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MULT = 29,                      /* MULT  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_MOD = 31,                       /* MOD  */
  YYSYMBOL_INC = 32,                       /* INC  */
  YYSYMBOL_DEC = 33,                       /* DEC  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_BITWISE_AND = 37,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_NOT = 38,               /* BITWISE_NOT  */
  YYSYMBOL_BITWISE_OR = 39,                /* BITWISE_OR  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_functions = 53,                 /* functions  */
  YYSYMBOL_function = 54,                  /* function  */
  YYSYMBOL_params = 55,                    /* params  */
  YYSYMBOL_param_list = 56,                /* param_list  */
  YYSYMBOL_param = 57,                     /* param  */
  YYSYMBOL_func_types = 58,                /* func_types  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_decl_list = 60,                 /* decl_list  */
  YYSYMBOL_declaration = 61,               /* declaration  */
  YYSYMBOL_block = 62,                     /* block  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_block_content = 64,             /* block_content  */
  YYSYMBOL_func_block = 65,                /* func_block  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_statements = 67,                /* statements  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_break_statement = 70,           /* break_statement  */
  YYSYMBOL_continue_statement = 71,        /* continue_statement  */
  YYSYMBOL_func_call = 72,                 /* func_call  */
  YYSYMBOL_inc_dec = 73,                   /* inc_dec  */
  YYSYMBOL_if_statement = 74,              /* if_statement  */
  YYSYMBOL_while_statement = 75,           /* while_statement  */
  YYSYMBOL_repeat_until_statement = 76,    /* repeat_until_statement  */
  YYSYMBOL_for_statement = 77,             /* for_statement  */
  YYSYMBOL_78_4 = 78,                      /* $@4  */
  YYSYMBOL_switch_statement = 79,          /* switch_statement  */
  YYSYMBOL_case_list = 80,                 /* case_list  */
  YYSYMBOL_constant = 81,                  /* constant  */
  YYSYMBOL_return_statement = 82,          /* return_statement  */
  YYSYMBOL_expression = 83                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    40,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    83,    88,    89,    93,   103,   104,   108,
     109,   113,   124,   125,   126,   127,   128,   133,   134,   135,
     136,   141,   143,   149,   156,   170,   168,   178,   179,   180,
     186,   184,   210,   211,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   230,   240,   244,   248,
     256,   257,   258,   259,   263,   270,   275,   281,   280,   293,
     303,   308,   309,   310,   314,   316,   326,   329,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   354,   356,   358,   360,
     361,   367
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "IF", "THEN", "ELSE", "WHILE", "REPEAT", "UNTIL", "FOR", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "INT", "FLOAT", "CHAR",
  "VOID", "CONST", "EQ", "NEQ", "LE", "GE", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "INC", "DEC", "AND", "OR", "NOT", "BITWISE_AND", "BITWISE_NOT",
  "BITWISE_OR", "';'", "','", "'('", "')'", "'{'", "'}'", "'='", "'<'",
  "'>'", "':'", "$accept", "program", "$@1", "functions", "function",
  "params", "param_list", "param", "func_types", "type", "decl_list",
  "declaration", "block", "$@2", "block_content", "func_block", "$@3",
  "statements", "statement", "assignment", "break_statement",
  "continue_statement", "func_call", "inc_dec", "if_statement",
  "while_statement", "repeat_until_statement", "for_statement", "$@4",
  "switch_statement", "case_list", "constant", "return_statement",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,    22,   160,  -155,  -155,  -155,  -155,  -155,   160,   160,
    -155,    25,  -155,  -155,   -11,   167,  -155,  -155,  -155,   167,
      -9,    -6,  -155,    33,  -155,    -1,   167,  -155,  -155,  -155,
    -155,   140,    39,     4,     6,  -155,    20,    23,     7,    28,
       0,    65,    71,  -155,    76,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,    37,    44,
      49,    47,    41,    41,    41,    83,    92,    41,  -155,  -155,
    -155,   -20,    93,   100,    41,    41,  -155,    41,   170,    67,
      69,   121,  -155,   -26,  -155,  -155,  -155,    70,   196,   222,
     248,    63,  -155,  -155,    72,    41,   167,   274,  -155,  -155,
    -155,  -155,   482,   482,   300,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,  -155,    41,
      41,  -155,  -155,  -155,  -155,   113,    41,  -155,  -155,  -155,
     159,   159,    41,   326,    41,    75,  -155,   519,   519,   519,
     519,   502,   502,   536,   536,   536,   482,   482,   482,   482,
     519,   519,  -155,  -155,   352,   140,   116,  -155,   378,    41,
     404,  -155,   140,  -155,     5,   159,    80,   430,    41,    -4,
    -155,  -155,   159,   456,    13,    79,  -155,  -155,   159,  -155,
    -155,    82,  -155,  -155,  -155,   159,   159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    12,    13,    14,    16,     0,     3,
       5,     0,    15,     4,     0,     8,    17,    18,    19,     0,
       0,     7,    10,     0,    20,     0,     0,    11,    29,     6,
       9,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    27,    45,    28,    34,    41,
      42,    43,    44,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    47,    48,
      91,    90,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,    21,     0,    30,    50,    51,     0,     0,     0,
       0,     0,    32,    40,     0,     0,     0,     0,    85,    86,
      87,    88,    77,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,    52,    53,    25,    23,     0,     0,    29,    49,    46,
       0,     0,     0,     0,     0,     0,    89,    73,    74,    83,
      84,    68,    69,    70,    71,    72,    75,    76,    78,    79,
      81,    82,    29,    22,     0,     0,     0,    55,     0,     0,
       0,    63,    26,    24,    40,     0,     0,     0,     0,     0,
      54,    56,     0,     0,     0,     0,    60,    59,     0,    64,
      65,     0,    33,    58,    33,    62,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,   125,  -155,  -155,   109,   134,    87,
    -155,    50,  -155,  -155,   -41,  -155,  -155,  -154,   -64,    81,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   -31,   -56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    20,    21,    22,    11,    44,
      83,    45,    46,   152,    31,    29,   127,    65,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    96,    57,
     169,   181,    93,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    92,    81,    70,    71,   -31,    88,    89,    90,   174,
     175,    97,    98,    99,   124,   125,   179,   180,   102,   103,
     126,   104,     3,   -31,   -31,   -31,   -31,   -31,   185,    14,
     186,    15,    72,    73,    25,    26,    74,    27,    75,   133,
      76,   176,    77,    28,    70,    71,    63,    68,    64,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    66,   150,   151,    67,   156,   157,    69,    79,
     154,    59,    60,    72,    73,    80,   158,    74,   160,    75,
      82,    61,    84,    77,    85,    62,   155,    32,    33,    86,
      87,    34,    35,    91,    36,    37,    94,   100,    38,    39,
      40,   170,    23,   167,   101,   132,    24,   121,   177,   122,
     128,   162,   173,    23,   183,    41,    42,   153,    62,   161,
     171,    92,    92,   165,   164,    32,    33,    43,   182,    34,
      35,   184,    36,    37,    13,    30,    38,    39,    40,    16,
      17,    18,    12,    19,    32,    33,   134,    95,    34,    35,
       0,    36,    37,    41,    42,    38,    39,    40,    16,    17,
      18,     0,    19,    32,    33,    43,   123,    34,    35,     0,
      36,    37,    41,    42,    38,    39,    40,     0,     4,     5,
       6,     7,     8,     0,    43,    16,    17,    18,     0,    19,
       0,    41,    42,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,    43,   114,   115,     0,   116,     0,   117,
     118,     0,     0,     0,     0,     0,     0,   119,   120,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,   115,     0,   116,     0,   117,   129,     0,     0,     0,
       0,     0,     0,   119,   120,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,     0,   116,
       0,   117,     0,     0,     0,   130,     0,     0,     0,   119,
     120,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,   114,   115,     0,   116,     0,   117,     0,     0,
       0,   131,     0,     0,     0,   119,   120,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,   114,   115,
       0,   116,     0,   117,     0,     0,     0,   135,     0,     0,
       0,   119,   120,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,   114,   115,     0,   116,     0,   117,
       0,     0,     0,   136,     0,     0,     0,   119,   120,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,   115,     0,   116,     0,   117,   159,     0,     0,     0,
       0,     0,     0,   119,   120,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,     0,   116,
       0,   117,   163,     0,     0,     0,     0,     0,     0,   119,
     120,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,   114,   115,     0,   116,     0,   117,     0,     0,
       0,   166,     0,     0,     0,   119,   120,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,   114,   115,
       0,   116,     0,   117,   168,     0,     0,     0,     0,     0,
       0,   119,   120,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,   114,   115,     0,   116,     0,   117,
       0,     0,     0,   172,     0,     0,     0,   119,   120,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,   115,     0,   116,     0,   117,     0,     0,     0,   178,
       0,     0,     0,   119,   120,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   114,   115,     0,   116,
       0,   117,     0,     0,     0,   105,   106,   107,   108,   119,
     120,   111,   112,   113,     0,     0,   114,   115,     0,   116,
       0,   117,   -32,   -32,   -32,   -32,     0,     0,     0,   119,
     120,     0,     0,   114,   115,     0,   116,     0,   117,   105,
     106,   107,   108,     0,     0,     0,   -32,   -32,     0,     0,
     114,   115,     0,   116,     0,   117,     0,     0,     0,     0,
       0,     0,     0,   119,   120
};

static const yytype_int16 yycheck[] =
{
      31,    65,    43,     3,     4,     0,    62,    63,    64,    13,
      14,    67,    32,    33,    40,    41,     3,     4,    74,    75,
      46,    77,     0,    18,    19,    20,    21,    22,   182,     4,
     184,    42,    32,    33,    43,    41,    36,     4,    38,    95,
      40,    45,    42,    44,     3,     4,    42,    40,    42,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    42,   119,   120,    42,   130,   131,    40,     4,
     126,    32,    33,    32,    33,     4,   132,    36,   134,    38,
       4,    42,    45,    42,    40,    46,   127,     4,     5,    40,
      43,     8,     9,    10,    11,    12,     4,     4,    15,    16,
      17,   165,    15,   159,     4,    42,    19,    40,   172,    40,
      40,   152,   168,    26,   178,    32,    33,     4,    46,    44,
      40,   185,   186,     7,   155,     4,     5,    44,    49,     8,
       9,    49,    11,    12,     9,    26,    15,    16,    17,    18,
      19,    20,     8,    22,     4,     5,    96,    66,     8,     9,
      -1,    11,    12,    32,    33,    15,    16,    17,    18,    19,
      20,    -1,    22,     4,     5,    44,    45,     8,     9,    -1,
      11,    12,    32,    33,    15,    16,    17,    -1,    18,    19,
      20,    21,    22,    -1,    44,    18,    19,    20,    -1,    22,
      -1,    32,    33,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    44,    34,    35,    -1,    37,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    48,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    48,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    37,    -1,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    48,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    48,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    -1,    -1,    -1,    23,    24,    25,    26,    47,
      48,    29,    30,    31,    -1,    -1,    34,    35,    -1,    37,
      -1,    39,    23,    24,    25,    26,    -1,    -1,    -1,    47,
      48,    -1,    -1,    34,    35,    -1,    37,    -1,    39,    23,
      24,    25,    26,    -1,    -1,    -1,    47,    48,    -1,    -1,
      34,    35,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,    18,    19,    20,    21,    22,    53,
      54,    58,    58,    54,     4,    42,    18,    19,    20,    22,
      55,    56,    57,    59,    59,    43,    41,     4,    44,    65,
      57,    64,     4,     5,     8,     9,    11,    12,    15,    16,
      17,    32,    33,    44,    59,    61,    62,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    82,    32,
      33,    42,    46,    42,    42,    67,    42,    42,    40,    40,
       3,     4,    32,    33,    36,    38,    40,    42,    83,     4,
       4,    64,     4,    60,    45,    40,    40,    43,    83,    83,
      83,    10,    68,    82,     4,    69,    78,    83,    32,    33,
       4,     4,    83,    83,    83,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    34,    35,    37,    39,    40,    47,
      48,    40,    40,    45,    40,    41,    46,    66,    40,    40,
      43,    43,    42,    83,    61,    43,    43,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    63,     4,    83,    64,    68,    68,    83,    40,
      83,    44,    64,    40,    82,     7,    43,    83,    40,    80,
      68,    40,    43,    83,    13,    14,    45,    68,    43,     3,
       4,    81,    49,    68,    49,    67,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    54,    55,    55,    56,
      56,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    61,    61,    63,    62,    64,    64,    64,
      66,    65,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    71,    72,
      73,    73,    73,    73,    74,    75,    76,    78,    77,    77,
      79,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     6,     1,     0,     3,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       2,     1,     3,     3,     5,     0,     5,     2,     2,     0,
       0,     7,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     2,     4,
       3,     3,     3,     3,     7,     5,     7,     0,     9,     8,
       7,     5,     4,     0,     1,     1,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 83 "parser.y"
        { init_symbol_table(); }
#line 1368 "parser.tab.c"
    break;

  case 6: /* function: func_types IDENTIFIER '(' params ')' func_block  */
#line 95 "parser.y"
        { 
          current_return_immutability = (yyvsp[-5].immutability); 
          func_name_temp              = strdup((yyvsp[-4].id));
          param_count                 = 0;
        }
#line 1378 "parser.tab.c"
    break;

  case 11: /* param: type IDENTIFIER  */
#line 115 "parser.y"
        {
          if (param_count >= MAX_PARAMS) yyerror("Too many parameters");
          param_list[param_count].name = strdup((yyvsp[0].id));
          param_list[param_count].spec = (yyvsp[-1].immutability);
          param_count++;
        }
#line 1389 "parser.tab.c"
    break;

  case 12: /* func_types: INT  */
#line 124 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1395 "parser.tab.c"
    break;

  case 13: /* func_types: FLOAT  */
#line 125 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1401 "parser.tab.c"
    break;

  case 14: /* func_types: CHAR  */
#line 126 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1407 "parser.tab.c"
    break;

  case 15: /* func_types: CONST func_types  */
#line 127 "parser.y"
                       { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1413 "parser.tab.c"
    break;

  case 16: /* func_types: VOID  */
#line 128 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_VOID,  0}; }
#line 1419 "parser.tab.c"
    break;

  case 17: /* type: INT  */
#line 133 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1425 "parser.tab.c"
    break;

  case 18: /* type: FLOAT  */
#line 134 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1431 "parser.tab.c"
    break;

  case 19: /* type: CHAR  */
#line 135 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1437 "parser.tab.c"
    break;

  case 20: /* type: CONST type  */
#line 136 "parser.y"
                    { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1443 "parser.tab.c"
    break;

  case 21: /* decl_list: IDENTIFIER  */
#line 142 "parser.y"
        { (yyval.idlist) = new_idlist((yyvsp[0].id)); }
#line 1449 "parser.tab.c"
    break;

  case 22: /* decl_list: decl_list ',' IDENTIFIER  */
#line 144 "parser.y"
        { (yyval.idlist) = idlist_append((yyvsp[-2].idlist), (yyvsp[0].id)); }
#line 1455 "parser.tab.c"
    break;

  case 23: /* declaration: type decl_list ';'  */
#line 150 "parser.y"
        {
          TypeImmut ts = (yyvsp[-2].immutability);
          for (IdList *it = (yyvsp[-1].idlist); it; it = it->next)
            if (!add_variable(it->name, ts))
              yyerror("Variable redeclaration");
        }
#line 1466 "parser.tab.c"
    break;

  case 24: /* declaration: type decl_list '=' expression ';'  */
#line 157 "parser.y"
        {
          TypeImmut ts = (yyvsp[-4].immutability);
          if ((yyvsp[-1].type) != ts.base)
            yyerror("Type mismatch in initializer");
          for (IdList *it = (yyvsp[-3].idlist); it; it = it->next)
            if (!add_variable(it->name, ts))
              yyerror("Variable redeclaration");
        }
#line 1479 "parser.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 170 "parser.y"
        { enter_scope(); }
#line 1485 "parser.tab.c"
    break;

  case 26: /* block: '{' block_content '}' $@2 block_content  */
#line 172 "parser.y"
        {
          exit_scope();
        }
#line 1493 "parser.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 186 "parser.y"
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
#line 1512 "parser.tab.c"
    break;

  case 31: /* func_block: '{' block_content return_statement '}' $@3 block_content return_statement  */
#line 202 "parser.y"
        {
          /* close the function scope */
          exit_scope();
        }
#line 1521 "parser.tab.c"
    break;

  case 46: /* assignment: IDENTIFIER '=' expression ';'  */
#line 231 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[-3].id));
          if (!v || v->kind!=SYM_VAR)       yyerror("Undeclared variable");
          if (v->spec.is_const)             yyerror("Cannot assign to const");
          if (v->spec.base  != (yyvsp[-1].type))          yyerror("Type mismatch in assignment");
        }
#line 1532 "parser.tab.c"
    break;

  case 49: /* func_call: IDENTIFIER '(' ')' ';'  */
#line 249 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-3].id));
          if (!f || f->kind!=SYM_FUNC) yyerror("Undeclared function call");
        }
#line 1541 "parser.tab.c"
    break;

  case 50: /* inc_dec: IDENTIFIER INC ';'  */
#line 256 "parser.y"
                          { check_var_mod((yyvsp[-2].id)); }
#line 1547 "parser.tab.c"
    break;

  case 51: /* inc_dec: IDENTIFIER DEC ';'  */
#line 257 "parser.y"
                          { check_var_mod((yyvsp[-2].id)); }
#line 1553 "parser.tab.c"
    break;

  case 52: /* inc_dec: INC IDENTIFIER ';'  */
#line 258 "parser.y"
                          { check_var_mod((yyvsp[-1].id)); }
#line 1559 "parser.tab.c"
    break;

  case 53: /* inc_dec: DEC IDENTIFIER ';'  */
#line 259 "parser.y"
                          { check_var_mod((yyvsp[-1].id)); }
#line 1565 "parser.tab.c"
    break;

  case 54: /* if_statement: IF '(' expression ')' statement ELSE statement  */
#line 264 "parser.y"
        {
          if ((yyvsp[-4].type) != TYPE_INT) yyerror("Condition must be int");
        }
#line 1573 "parser.tab.c"
    break;

  case 55: /* while_statement: WHILE '(' expression ')' statement  */
#line 271 "parser.y"
        { if ((yyvsp[-2].type) != TYPE_INT) yyerror("Condition must be int"); }
#line 1579 "parser.tab.c"
    break;

  case 56: /* repeat_until_statement: REPEAT statements UNTIL '(' expression ')' ';'  */
#line 276 "parser.y"
        { if ((yyvsp[-2].type) != TYPE_INT) yyerror("Condition must be int"); }
#line 1585 "parser.tab.c"
    break;

  case 57: /* $@4: %empty  */
#line 281 "parser.y"
        { 
          /* 1) open a fresh scope for the “int x=…” */
          enter_scope(); 
        }
#line 1594 "parser.tab.c"
    break;

  case 58: /* for_statement: FOR '(' $@4 declaration expression ';' expression ')' statement  */
#line 287 "parser.y"
        {
          /* 2) now that we’ve seen “x<7”, validate it and tear down that scope */
          if ((yyvsp[-4].type) != TYPE_INT) 
            yyerror("Condition must be int");
          exit_scope();
        }
#line 1605 "parser.tab.c"
    break;

  case 59: /* for_statement: FOR '(' assignment expression ';' expression ')' statement  */
#line 294 "parser.y"
        {
          /* plain old for without an int-decl */
          if ((yyvsp[-4].type) != TYPE_INT) 
            yyerror("Condition must be int");
        }
#line 1615 "parser.tab.c"
    break;

  case 60: /* switch_statement: SWITCH '(' expression ')' '{' case_list '}'  */
#line 304 "parser.y"
        { if ((yyvsp[-4].type) != TYPE_INT) yyerror("Switch expr must be int"); }
#line 1621 "parser.tab.c"
    break;

  case 64: /* constant: NUMBER  */
#line 315 "parser.y"
        { (yyval.type) = TYPE_INT; }
#line 1627 "parser.tab.c"
    break;

  case 65: /* constant: IDENTIFIER  */
#line 317 "parser.y"
        {
          Symbol *s = lookup_symbol((yyvsp[0].id));
          if (!s)                yyerror("Undeclared identifier");
          if (s->kind != SYM_VAR)yyerror("Case label must be variable");
          (yyval.type) = s->spec.base;
        }
#line 1638 "parser.tab.c"
    break;

  case 66: /* return_statement: RETURN expression ';'  */
#line 327 "parser.y"
        { if ((yyvsp[-1].type) != current_return_immutability.base) 
            yyerror("Return type mismatch"); }
#line 1645 "parser.tab.c"
    break;

  case 67: /* return_statement: RETURN ';'  */
#line 330 "parser.y"
        { if (current_return_immutability.base != TYPE_VOID)
            yyerror("Return value expected"); }
#line 1652 "parser.tab.c"
    break;

  case 68: /* expression: expression PLUS expression  */
#line 335 "parser.y"
                                      { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1658 "parser.tab.c"
    break;

  case 69: /* expression: expression MINUS expression  */
#line 336 "parser.y"
                                      { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1664 "parser.tab.c"
    break;

  case 70: /* expression: expression MULT expression  */
#line 337 "parser.y"
                                      { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1670 "parser.tab.c"
    break;

  case 71: /* expression: expression DIV expression  */
#line 338 "parser.y"
                                      { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); if ((yyvsp[0].type) == 0) yyerror("Division by zero"); }
#line 1676 "parser.tab.c"
    break;

  case 72: /* expression: expression MOD expression  */
#line 339 "parser.y"
                                      { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1682 "parser.tab.c"
    break;

  case 73: /* expression: expression EQ expression  */
#line 340 "parser.y"
                                      { (yyval.type) = TYPE_INT; }
#line 1688 "parser.tab.c"
    break;

  case 74: /* expression: expression NEQ expression  */
#line 341 "parser.y"
                                      { (yyval.type) = TYPE_INT; }
#line 1694 "parser.tab.c"
    break;

  case 75: /* expression: expression AND expression  */
#line 342 "parser.y"
                                      { (yyval.type) = TYPE_INT; }
#line 1700 "parser.tab.c"
    break;

  case 76: /* expression: expression OR expression  */
#line 343 "parser.y"
                                      { (yyval.type) = TYPE_INT; }
#line 1706 "parser.tab.c"
    break;

  case 77: /* expression: NOT expression  */
#line 344 "parser.y"
                                        { (yyval.type) = (yyvsp[0].type);            }
#line 1712 "parser.tab.c"
    break;

  case 78: /* expression: expression BITWISE_AND expression  */
#line 345 "parser.y"
                                        { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1718 "parser.tab.c"
    break;

  case 79: /* expression: expression BITWISE_OR expression  */
#line 346 "parser.y"
                                        { (yyval.type) = type_arith((yyvsp[-2].type),(yyvsp[0].type)); }
#line 1724 "parser.tab.c"
    break;

  case 80: /* expression: BITWISE_NOT expression  */
#line 347 "parser.y"
                                       { (yyval.type) = (yyvsp[0].type);            }
#line 1730 "parser.tab.c"
    break;

  case 81: /* expression: expression '<' expression  */
#line 348 "parser.y"
                                       { (yyval.type) = TYPE_INT;      }
#line 1736 "parser.tab.c"
    break;

  case 82: /* expression: expression '>' expression  */
#line 349 "parser.y"
                                       { (yyval.type) = TYPE_INT;      }
#line 1742 "parser.tab.c"
    break;

  case 83: /* expression: expression LE expression  */
#line 350 "parser.y"
                                       { (yyval.type) = TYPE_INT;      }
#line 1748 "parser.tab.c"
    break;

  case 84: /* expression: expression GE expression  */
#line 351 "parser.y"
                                       { (yyval.type) = TYPE_INT;      }
#line 1754 "parser.tab.c"
    break;

  case 85: /* expression: IDENTIFIER INC  */
#line 353 "parser.y"
        { check_var_mod((yyvsp[-1].id));  (yyval.type) = TYPE_INT; }
#line 1760 "parser.tab.c"
    break;

  case 86: /* expression: IDENTIFIER DEC  */
#line 355 "parser.y"
        { check_var_mod((yyvsp[-1].id));  (yyval.type) = TYPE_INT; }
#line 1766 "parser.tab.c"
    break;

  case 87: /* expression: INC IDENTIFIER  */
#line 357 "parser.y"
        { check_var_mod((yyvsp[0].id));  (yyval.type) = TYPE_INT; }
#line 1772 "parser.tab.c"
    break;

  case 88: /* expression: DEC IDENTIFIER  */
#line 359 "parser.y"
        { check_var_mod((yyvsp[0].id));  (yyval.type) = TYPE_INT; }
#line 1778 "parser.tab.c"
    break;

  case 89: /* expression: '(' expression ')'  */
#line 360 "parser.y"
                                       { (yyval.type) = (yyvsp[-1].type);            }
#line 1784 "parser.tab.c"
    break;

  case 90: /* expression: IDENTIFIER  */
#line 362 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[0].id));
          if (!v) yyerror("Undeclared variable");
          (yyval.type) = v->spec.base;
        }
#line 1794 "parser.tab.c"
    break;

  case 91: /* expression: NUMBER  */
#line 367 "parser.y"
                                        { (yyval.type) = TYPE_INT;      }
#line 1800 "parser.tab.c"
    break;


#line 1804 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 369 "parser.y"


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



