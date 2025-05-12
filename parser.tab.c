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
#include "quadruple.h"  
#include <ctype.h>

#ifndef HASH_SIZE
#define HASH_SIZE 97
#endif

void yyerror(const char *s);
void var_error(const char *message, const char *var_name);
int yylex(void);
void token_seen(const char* token_text); 
extern FILE *yyin;
extern int yylineno;
extern int yyleng;  
int column = 1; // Track column positions
char *last_token = NULL; // Keep track of the last token seen
int error_count = 0;

char *switch_expr_global;  
char *end_label_global; 

void check_var_mod(const char *name); 
void check_op_types(Type left_type, Type right_type, const char* op, int allow_strings, int allow_float);
static Type type_arith(Type a, Type b); 
static int is_literal(const char *str);

#define YYMAXDEPTH 20000
#define MAX_PARAMS  16
static Param param_list[MAX_PARAMS];
static int   param_count = 0;
static TypeImmut current_return_immutability;

// Add at the top of your file
char* start_loop_label[20];
char* update_loop_label[20];
char* end_loop_label[20];
char* loop_body_label[20];

int for_count=0;

static char *func_name_temp;

#line 119 "parser.tab.c"

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
  YYSYMBOL_CHAR_LITERAL = 4,               /* CHAR_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_REPEAT = 11,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 12,                     /* UNTIL  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_SWITCH = 14,                    /* SWITCH  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_DEFAULT = 16,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_CONST = 24,                     /* CONST  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_MULT = 31,                      /* MULT  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_INC = 37,                       /* INC  */
  YYSYMBOL_DEC = 38,                       /* DEC  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_NO_ELSE = 49,                   /* NO_ELSE  */
  YYSYMBOL_UMINUS = 50,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_functions = 54,                 /* functions  */
  YYSYMBOL_function = 55,                  /* function  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_params = 57,                    /* params  */
  YYSYMBOL_param_list = 58,                /* param_list  */
  YYSYMBOL_param = 59,                     /* param  */
  YYSYMBOL_func_types = 60,                /* func_types  */
  YYSYMBOL_type = 61,                      /* type  */
  YYSYMBOL_decl_list = 62,                 /* decl_list  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_block_content = 66,             /* block_content  */
  YYSYMBOL_func_block = 67,                /* func_block  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_statements = 70,                /* statements  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_assignment = 72,                /* assignment  */
  YYSYMBOL_break_statement = 73,           /* break_statement  */
  YYSYMBOL_inc_dec_statement = 74,         /* inc_dec_statement  */
  YYSYMBOL_func_call = 75,                 /* func_call  */
  YYSYMBOL_arg_list = 76,                  /* arg_list  */
  YYSYMBOL_if_statement = 77,              /* if_statement  */
  YYSYMBOL_78_6 = 78,                      /* $@6  */
  YYSYMBOL_if_start = 79,                  /* if_start  */
  YYSYMBOL_while_statement = 80,           /* while_statement  */
  YYSYMBOL_81_7 = 81,                      /* $@7  */
  YYSYMBOL_82_8 = 82,                      /* $@8  */
  YYSYMBOL_repeat_until_statement = 83,    /* repeat_until_statement  */
  YYSYMBOL_84_9 = 84,                      /* $@9  */
  YYSYMBOL_for_statement = 85,             /* for_statement  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_87_11 = 87,                     /* $@11  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_for_start = 89,                 /* for_start  */
  YYSYMBOL_for_update_expr = 90,           /* for_update_expr  */
  YYSYMBOL_switch_statement = 91,          /* switch_statement  */
  YYSYMBOL_92_13 = 92,                     /* @13  */
  YYSYMBOL_case_list = 93,                 /* case_list  */
  YYSYMBOL_94_14 = 94,                     /* @14  */
  YYSYMBOL_constant = 95,                  /* constant  */
  YYSYMBOL_return_statement = 96,          /* return_statement  */
  YYSYMBOL_expression = 97,                /* expression  */
  YYSYMBOL_primary_expression = 98         /* primary_expression  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      41,    42,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    39,
      46,    45,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37,    38,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   130,   135,   136,   141,   140,   155,   156,
     160,   161,   165,   179,   180,   181,   182,   183,   184,   188,
     189,   190,   191,   192,   196,   198,   203,   232,   272,   277,
     276,   283,   284,   285,   290,   312,   289,   320,   321,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   340,   377,   381,   390,   412,   437,   452,   474,   482,
     496,   504,   503,   531,   552,   562,   551,   581,   580,   601,
     616,   625,   600,   638,   638,   641,   642,   656,   662,   661,
     689,   688,   716,   720,   724,   732,   744,   756,   765,   776,
     829,   841,   853,   887,   902,   933,   954,   975,   990,  1005,
    1020,  1041,  1062,  1083,  1104,  1110,  1136,  1167,  1199,  1227,
    1258,  1267,  1275,  1286,  1293
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER",
  "CHAR_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "STRING_LITERAL", "IF",
  "ELSE", "WHILE", "REPEAT", "UNTIL", "FOR", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "RETURN", "INT", "FLOAT", "CHAR", "STRING", "VOID", "CONST",
  "EQ", "NEQ", "LE", "GE", "PLUS", "MINUS", "MULT", "DIV", "MOD", "AND",
  "OR", "NOT", "INC", "DEC", "';'", "','", "'('", "')'", "'{'", "'}'",
  "'='", "'<'", "'>'", "':'", "NO_ELSE", "UMINUS", "$accept", "program",
  "$@1", "functions", "function", "$@2", "params", "param_list", "param",
  "func_types", "type", "decl_list", "declaration", "block", "$@3",
  "block_content", "func_block", "$@4", "$@5", "statements", "statement",
  "assignment", "break_statement", "inc_dec_statement", "func_call",
  "arg_list", "if_statement", "$@6", "if_start", "while_statement", "$@7",
  "$@8", "repeat_until_statement", "$@9", "for_statement", "$@10", "$@11",
  "$@12", "for_start", "for_update_expr", "switch_statement", "@13",
  "case_list", "@14", "constant", "return_statement", "expression",
  "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,     5,   280,  -163,  -163,  -163,  -163,  -163,  -163,   280,
     280,  -163,     3,  -163,  -163,    -8,   299,  -163,  -163,  -163,
    -163,   299,    -3,     2,  -163,    46,  -163,  -163,   299,  -163,
      12,  -163,  -163,  -163,  -163,   133,    24,   -16,    26,    51,
    -163,    55,    73,    41,   196,  -163,    39,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,   155,  -163,  -163,  -163,  -163,
      84,  -163,    86,    90,   181,   174,   235,  -163,  -163,    88,
     235,  -163,  -163,  -163,  -163,    48,  -163,   235,   235,  -163,
     235,   227,  -163,  -163,    99,  -163,    81,   123,  -163,    96,
    -163,  -163,   103,     7,   443,   110,   259,   282,   235,   105,
     113,  -163,  -163,  -163,   305,  -163,  -163,   188,  -163,  -163,
     328,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,  -163,   235,   235,    40,  -163,  -163,   153,   235,
    -163,  -163,  -163,   235,   125,  -163,  -163,  -163,   351,   121,
    -163,   235,   124,  -163,    93,  -163,   475,   475,   176,   176,
     236,   236,  -163,  -163,  -163,   466,   454,   176,   176,  -163,
    -163,   374,   155,   443,  -163,  -163,   235,   397,  -163,  -163,
    -163,  -163,   155,   420,  -163,  -163,  -163,   131,   242,   -12,
    -163,   -11,   129,   443,    62,   126,  -163,   235,  -163,  -163,
    -163,  -163,   134,  -163,   443,   155,  -163,     0,  -163,  -163,
      87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    13,    14,    15,    16,    18,     0,
       3,     5,     0,    17,     4,     0,     9,    19,    20,    21,
      22,     0,     0,     8,    11,     0,    23,     6,     0,    12,
       0,    10,    34,     7,    33,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,    29,     0,    31,    49,    32,
      39,    46,    47,    48,    40,     0,    41,    42,    43,    44,
      45,    50,     0,     0,     0,     0,     0,    64,    38,     0,
       0,    53,   110,   112,   111,   105,   113,     0,     0,    88,
       0,     0,   104,    33,     0,    24,     0,    60,    45,     0,
      54,    55,     0,     0,    58,     0,     0,     0,     0,     0,
       0,    73,    74,    69,     0,   106,   107,     0,    94,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,    28,    26,     0,     0,
      61,    36,    56,     0,     0,    52,    51,    63,     0,     0,
      37,     0,     0,   108,     0,   114,    95,    96,   102,   103,
      89,    90,    91,    92,    93,    97,    98,   100,   101,    30,
      25,     0,     0,    59,    57,    65,     0,     0,    78,   109,
      27,    62,     0,     0,    70,    83,    66,     0,    77,     0,
      68,   105,     0,    75,     0,     0,    79,     0,    71,    84,
      85,    86,     0,    38,    76,     0,    80,     0,    72,    38,
       0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,  -163,   173,  -163,  -163,  -163,   161,   187,
      -9,  -163,   128,  -163,  -163,   107,  -163,  -163,  -163,  -162,
     -35,   143,  -163,  -163,  -163,   106,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,   179,   -42,  -163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    30,    22,    23,    24,    12,
      46,    86,    47,    48,    83,    35,    33,    34,    89,    99,
     140,    50,    51,    52,    53,    93,    54,   162,    55,    56,
      98,   172,    57,    68,    58,   141,   178,   195,   103,   182,
      59,   175,   179,   199,   192,    88,    94,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    36,    81,   184,   185,     3,    37,    25,    38,    15,
      39,    40,    26,    41,    42,   -82,   -82,    43,    44,    25,
      87,    62,    63,    96,    97,    64,   105,   106,   104,    65,
     107,   197,   186,    16,   187,   108,   109,   200,   110,    27,
      84,    36,    28,    45,   -82,    85,    37,   133,    38,   134,
      39,    40,    29,    41,    42,    32,   138,    43,    44,    17,
      18,    19,    20,    61,    21,   189,   190,    66,   191,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      71,   157,   158,    45,   159,   105,   106,   161,    36,   107,
      49,   163,    67,    37,   100,    38,    69,    39,    40,   167,
      41,    42,   -81,   -81,    43,    44,    36,    17,    18,    19,
      20,    37,    21,    38,    70,    39,    40,   139,    41,    42,
     127,   128,    43,    44,   173,    90,   129,   171,   -35,    91,
      45,   -81,   130,   133,    36,   169,   183,   176,   126,    37,
     131,    38,   132,    39,    40,   194,    41,    42,    45,   135,
      43,    44,    17,    18,    19,    20,    36,    21,    65,   160,
     198,    37,   166,    38,   164,    39,    40,   168,    41,    42,
     180,   188,    43,    44,   193,    95,    45,    72,    73,    74,
      75,    76,   196,    14,    72,    73,    74,    75,    76,    31,
     125,    72,    73,    74,    75,    76,    13,   101,    45,    72,
      73,    74,    75,    76,    77,   115,   116,   117,   118,   119,
      78,    77,   102,   144,    60,    80,     0,    78,    77,     0,
       0,     0,    80,    92,    78,     0,    77,     0,     0,    80,
     143,     0,    78,     0,     0,    79,     0,    80,    72,    73,
      74,    75,    76,     0,     0,    72,    73,    74,   181,    76,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,    77,   122,   117,   118,   119,
       0,    78,    77,   123,   124,     0,    80,     0,    78,     0,
       0,     0,     0,    80,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   136,     4,
       5,     6,     7,     8,     9,   123,   124,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    17,    18,
      19,    20,     0,    21,   137,     0,     0,     0,   123,   124,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   123,   124,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   123,   124,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,   123,   124,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
     123,   124,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,   123,   124,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,   177,     0,     0,     0,   123,   124,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   123,
     124,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     123,   124,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,   123,   124,     0,     0,     0,     0,     0,     0,
       0,   123,   124
};

static const yytype_int16 yycheck[] =
{
      35,     1,    44,    15,    16,     0,     6,    16,     8,     6,
      10,    11,    21,    13,    14,    15,    16,    17,    18,    28,
      55,    37,    38,    65,    66,    41,    37,    38,    70,    45,
      41,   193,    44,    41,    45,    77,    78,   199,    80,    42,
       1,     1,    40,    43,    44,     6,     6,    40,     8,    42,
      10,    11,     6,    13,    14,    43,    98,    17,    18,    19,
      20,    21,    22,    39,    24,     3,     4,    41,     6,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      39,   123,   124,    43,    44,    37,    38,   129,     1,    41,
     125,   133,    41,     6,     6,     8,    41,    10,    11,   141,
      13,    14,    15,    16,    17,    18,     1,    19,    20,    21,
      22,     6,    24,     8,    41,    10,    11,    12,    13,    14,
      39,    40,    17,    18,   166,    39,    45,   162,    44,    39,
      43,    44,     9,    40,     1,    42,   178,   172,    39,     6,
      44,     8,    39,    10,    11,   187,    13,    14,    43,    39,
      17,    18,    19,    20,    21,    22,     1,    24,    45,     6,
     195,     6,    41,     8,    39,    10,    11,    43,    13,    14,
      39,    42,    17,    18,    48,     1,    43,     3,     4,     5,
       6,     7,    48,    10,     3,     4,     5,     6,     7,    28,
      83,     3,     4,     5,     6,     7,     9,    69,    43,     3,
       4,     5,     6,     7,    30,    29,    30,    31,    32,    33,
      36,    30,    69,   107,    35,    41,    -1,    36,    30,    -1,
      -1,    -1,    41,    42,    36,    -1,    30,    -1,    -1,    41,
      42,    -1,    36,    -1,    -1,    39,    -1,    41,     3,     4,
       5,     6,     7,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    30,    39,    31,    32,    33,
      -1,    36,    30,    46,    47,    -1,    41,    -1,    36,    -1,
      -1,    -1,    -1,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    19,
      20,    21,    22,    23,    24,    46,    47,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    20,
      21,    22,    -1,    24,    42,    -1,    -1,    -1,    46,    47,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    46,
      47,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      46,    47,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    53,     0,    19,    20,    21,    22,    23,    24,
      54,    55,    60,    60,    55,     6,    41,    19,    20,    21,
      22,    24,    57,    58,    59,    61,    61,    42,    40,     6,
      56,    59,    43,    67,    68,    66,     1,     6,     8,    10,
      11,    13,    14,    17,    18,    43,    61,    63,    64,    71,
      72,    73,    74,    75,    77,    79,    80,    83,    85,    91,
      96,    39,    37,    38,    41,    45,    41,    41,    84,    41,
      41,    39,     3,     4,     5,     6,     7,    30,    36,    39,
      41,    97,    98,    65,     1,     6,    62,    71,    96,    69,
      39,    39,    42,    76,    97,     1,    97,    97,    81,    70,
       6,    63,    72,    89,    97,    37,    38,    41,    97,    97,
      97,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    39,    46,    47,    66,    39,    39,    40,    45,
       9,    44,    39,    40,    42,    39,    39,    42,    97,    12,
      71,    86,    42,    42,    76,    42,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    44,
       6,    97,    78,    97,    39,    42,    41,    97,    43,    42,
      39,    71,    82,    97,    39,    92,    71,    42,    87,    93,
      39,     6,    90,    97,    15,    16,    44,    45,    42,     3,
       4,     6,    95,    48,    97,    88,    48,    70,    71,    94,
      70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    53,    52,    54,    54,    56,    55,    57,    57,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    63,    65,
      64,    66,    66,    66,    68,    69,    67,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    77,    79,    81,    82,    80,    84,    83,    86,
      87,    88,    85,    89,    89,    90,    90,    90,    92,    91,
      94,    93,    93,    93,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,     7,     1,     0,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     5,     3,     0,
       4,     2,     2,     0,     0,     0,     6,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     2,     3,     3,     4,     5,     1,     3,
       2,     0,     5,     4,     0,     0,     7,     0,     8,     0,
       0,     0,    11,     1,     1,     1,     3,     0,     0,     8,
       0,     6,     4,     0,     1,     1,     1,     3,     2,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     1,     1,     2,     2,     3,     4,
       1,     1,     1,     1,     3
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 130 "parser.y"
        { init_symbol_table(); }
#line 1800 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 141 "parser.y"
        {
          current_return_immutability = (yyvsp[-4].immutability); 
          func_name_temp = strdup((yyvsp[-3].id));
          
          // Generate function label
          emit(QUAD_LABEL, (yyvsp[-3].id), NULL, NULL);
        }
#line 1812 "parser.tab.c"
    break;

  case 7: /* function: func_types IDENTIFIER '(' params ')' $@2 func_block  */
#line 149 "parser.y"
      {
        param_count = 0;
      }
#line 1820 "parser.tab.c"
    break;

  case 12: /* param: type IDENTIFIER  */
#line 167 "parser.y"
        {
          if (param_count >= MAX_PARAMS) var_error("Too many parameters in function", func_name_temp);
          param_list[param_count].name = strdup((yyvsp[0].id));
          param_list[param_count].spec = (yyvsp[-1].immutability);
          param_count++;
          
          // Register parameter in quadruple
          emit(QUAD_PARAM, (yyvsp[0].id), NULL, NULL);
        }
#line 1834 "parser.tab.c"
    break;

  case 13: /* func_types: INT  */
#line 179 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1840 "parser.tab.c"
    break;

  case 14: /* func_types: FLOAT  */
#line 180 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1846 "parser.tab.c"
    break;

  case 15: /* func_types: CHAR  */
#line 181 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1852 "parser.tab.c"
    break;

  case 16: /* func_types: STRING  */
#line 182 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_STRING, 0}; }
#line 1858 "parser.tab.c"
    break;

  case 17: /* func_types: CONST func_types  */
#line 183 "parser.y"
                       { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1864 "parser.tab.c"
    break;

  case 18: /* func_types: VOID  */
#line 184 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_VOID,  0}; }
#line 1870 "parser.tab.c"
    break;

  case 19: /* type: INT  */
#line 188 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1876 "parser.tab.c"
    break;

  case 20: /* type: FLOAT  */
#line 189 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1882 "parser.tab.c"
    break;

  case 21: /* type: CHAR  */
#line 190 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1888 "parser.tab.c"
    break;

  case 22: /* type: STRING  */
#line 191 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_STRING, 0}; }
#line 1894 "parser.tab.c"
    break;

  case 23: /* type: CONST type  */
#line 192 "parser.y"
                    { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1900 "parser.tab.c"
    break;

  case 24: /* decl_list: IDENTIFIER  */
#line 197 "parser.y"
        { (yyval.idlist) = new_idlist((yyvsp[0].id)); }
#line 1906 "parser.tab.c"
    break;

  case 25: /* decl_list: decl_list ',' IDENTIFIER  */
#line 199 "parser.y"
        { (yyval.idlist) = idlist_append((yyvsp[-2].idlist), (yyvsp[0].id)); }
#line 1912 "parser.tab.c"
    break;

  case 26: /* declaration: type decl_list ';'  */
#line 204 "parser.y"
        {
          TypeImmut ts = (yyvsp[-2].immutability);
          for (IdList *it = (yyvsp[-1].idlist); it; it = it->next) {
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
#line 1945 "parser.tab.c"
    break;

  case 27: /* declaration: type decl_list '=' expression ';'  */
#line 233 "parser.y"
        {
          TypeImmut ts = (yyvsp[-4].immutability);
          if ((yyvsp[-1].expr).type != ts.base)
            var_error("Type mismatch in initializer for variable", ((IdList *)(yyvsp[-3].idlist))->name);
            
          for (IdList *it = (yyvsp[-3].idlist); it; it = it->next) {
            if (!add_variable(it->name, ts))
              var_error("Variable redeclaration", it->name);
              
            // Initialize with the expression value
            Symbol *v = lookup_symbol(it->name);
            if (v) {
              v->has_value = 1;
              
              // Direct assignment optimization
              char *place = (yyvsp[-1].expr).place;
              
              // Emit quadruple for assignment based on type
              if (ts.base == TYPE_STRING) {
                emit(QUAD_ASSIGN_STR, place, NULL, it->name);
                set_string_value(it->name, place);
              } else if (ts.base == TYPE_CHAR && (yyvsp[-1].expr).is_literal) {
                emit(QUAD_ASSIGN_CHAR, place, NULL, it->name);
                if (strlen(place) >= 3) {
                set_char_value(it->name, place[1]);
                }
              } else {
                emit(QUAD_ASSIGN, place, NULL, it->name);
                if ((yyvsp[-1].expr).is_literal) {
                if (ts.base == TYPE_INT) {
                  set_int_value(it->name, atoi(place));
                } else if (ts.base == TYPE_FLOAT) {
                  set_float_value(it->name, atof(place));
                }
              }
              }
            }
          }
        }
#line 1989 "parser.tab.c"
    break;

  case 28: /* declaration: type error ';'  */
#line 272 "parser.y"
                     { yyerrok; }
#line 1995 "parser.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 277 "parser.y"
        { enter_scope(); }
#line 2001 "parser.tab.c"
    break;

  case 30: /* block: '{' $@3 block_content '}'  */
#line 279 "parser.y"
        { exit_scope(); }
#line 2007 "parser.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 290 "parser.y"
        {
          if (!add_function(func_name_temp,
                            current_return_immutability,
                            param_count,
                            param_list))
            var_error("Function redefinition", func_name_temp);

          enter_scope();
                    
          for (int i = 0; i < param_count; i++){
            add_variable(param_list[i].name,
                         param_list[i].spec);

            // Mark parameters as initialized and used
            Symbol *param = lookup_symbol(param_list[i].name);
            if (param) {
              param->has_value = 1;  // Parameters are initialized when function is called
              param->is_used = 1;    // Don't warn about unused parameters
            }
          }
        }
#line 2033 "parser.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 312 "parser.y"
      {
          exit_scope();
      }
#line 2041 "parser.tab.c"
    break;

  case 50: /* statement: error ';'  */
#line 336 "parser.y"
                 { yyerrok; }
#line 2047 "parser.tab.c"
    break;

  case 51: /* assignment: IDENTIFIER '=' expression ';'  */
#line 341 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[-3].id));
          if (!v || v->kind!=SYM_VAR)       var_error("Undeclared variable", (yyvsp[-3].id));
          if (v->spec.is_const)             var_error("Cannot assign to const variable", (yyvsp[-3].id));
          if (v->spec.base != (yyvsp[-1].expr).type) {
              fprintf(stderr, "DEBUG: Type mismatch in assignment for '%s': expected %d, got %d\n", 
                      (yyvsp[-3].id), v->spec.base, (yyvsp[-1].expr).type);
              var_error("Type mismatch in assignment", (yyvsp[-3].id));
          }
          
          // Direct assignment optimization
          char *place = (yyvsp[-1].expr).place;
          
          // Choose appropriate quadruple type based on variable type and expression
          if (v->spec.base == TYPE_STRING) {
            emit(QUAD_ASSIGN_STR, place, NULL, (yyvsp[-3].id));
            set_string_value((yyvsp[-3].id), place);
          } else if (v->spec.base == TYPE_CHAR && (yyvsp[-1].expr).is_literal) {
            emit(QUAD_ASSIGN_CHAR, place, NULL, (yyvsp[-3].id));
            if (strlen(place) >= 3) {
              set_char_value((yyvsp[-3].id), place[1]);
            }
          } else {
            emit(QUAD_ASSIGN, place, NULL, (yyvsp[-3].id));
            if ((yyvsp[-1].expr).is_literal) {
              if (v->spec.base == TYPE_INT) {
                set_int_value((yyvsp[-3].id), atoi(place));
              } else if (v->spec.base == TYPE_FLOAT) {
                set_float_value((yyvsp[-3].id), atof(place));
              }
            }
          }
          
          // Update variable value in symbol table
          v->has_value = 1;
        }
#line 2088 "parser.tab.c"
    break;

  case 52: /* assignment: IDENTIFIER '=' error ';'  */
#line 377 "parser.y"
                               { yyerrok; }
#line 2094 "parser.tab.c"
    break;

  case 53: /* break_statement: BREAK ';'  */
#line 382 "parser.y"
        {
          // Generate quadruple for break
          emit(QUAD_JUMP, NULL, NULL, end_label_global);
        }
#line 2103 "parser.tab.c"
    break;

  case 54: /* inc_dec_statement: IDENTIFIER INC ';'  */
#line 391 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[-2].id));
          if (!v || v->kind != SYM_VAR) var_error("Undeclared variable", (yyvsp[-2].id));
          if (v->spec.is_const) var_error("Cannot modify const variable", (yyvsp[-2].id));
          
          // Check if the variable type is numeric
          if (v->spec.base != TYPE_INT && v->spec.base != TYPE_FLOAT) {
            fprintf(stderr, "Error: Increment operation requires numeric types (int or float)\n");
            exit(1);
          }
          
          // Generate quadruples for x = x + 1
          char *temp = new_temp();
          char *one = int_to_string(1);
          
          emit(QUAD_ADD, (yyvsp[-2].id), one, temp);
          emit(QUAD_ASSIGN, temp, NULL, (yyvsp[-2].id));
          
          // Mark as initialized
          v->has_value = 1;
        }
#line 2129 "parser.tab.c"
    break;

  case 55: /* inc_dec_statement: IDENTIFIER DEC ';'  */
#line 413 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[-2].id));
          if (!v || v->kind != SYM_VAR) var_error("Undeclared variable", (yyvsp[-2].id));
          if (v->spec.is_const) var_error("Cannot modify const variable", (yyvsp[-2].id));
          
          // Check if the variable type is numeric
          if (v->spec.base != TYPE_INT && v->spec.base != TYPE_FLOAT) {
            fprintf(stderr, "Error: Decrement operation requires numeric types (int or float)\n");
            exit(1);
          }
          
          // Generate quadruples for x = x - 1
          char *temp = new_temp();
          char *one = int_to_string(1);
          
          emit(QUAD_SUB, (yyvsp[-2].id), one, temp);
          emit(QUAD_ASSIGN, temp, NULL, (yyvsp[-2].id));
          
          // Mark as initialized
          v->has_value = 1;
        }
#line 2155 "parser.tab.c"
    break;

  case 56: /* func_call: IDENTIFIER '(' ')' ';'  */
#line 438 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-3].id));
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", (yyvsp[-3].id));
          
          // Check if function expects parameters
          if (f->param_count > 0) {
            fprintf(stderr, "Error: Function '%s' expects %d arguments, but none were provided\n", 
                    (yyvsp[-3].id), f->param_count);
            exit(1);
          }
          
          // Generate quadruple for function call
          emit(QUAD_CALL, (yyvsp[-3].id), "0", NULL); // 0 args
        }
#line 2174 "parser.tab.c"
    break;

  case 57: /* func_call: IDENTIFIER '(' arg_list ')' ';'  */
#line 453 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-4].id));
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", (yyvsp[-4].id));
          
          // Check if argument count matches parameter count
          int arg_count = (yyvsp[-2].num);  // Get the argument count from arg_list
          if (arg_count != f->param_count) {
            fprintf(stderr, "Error: Function '%s' expects %d arguments, but %d were provided\n", 
                    (yyvsp[-4].id), f->param_count, arg_count);
            exit(1);
          }
          
          // Generate quadruple for function call with arguments
          char arg_count_str[16];
          snprintf(arg_count_str, sizeof(arg_count_str), "%d", arg_count);
          emit(QUAD_CALL, (yyvsp[-4].id), arg_count_str, NULL);
        }
#line 2196 "parser.tab.c"
    break;

  case 58: /* arg_list: expression  */
#line 475 "parser.y"
        {
          // First argument - emit ARG quadruple
          emit(QUAD_ARG, (yyvsp[0].expr).place, NULL, NULL);
          
          // Return the count of arguments seen so far
          (yyval.num) = 1;
        }
#line 2208 "parser.tab.c"
    break;

  case 59: /* arg_list: arg_list ',' expression  */
#line 483 "parser.y"
        {
          // Additional argument - emit ARG quadruple
          emit(QUAD_ARG, (yyvsp[0].expr).place, NULL, NULL);
          
          // Return the incremented count of arguments
          (yyval.num) = (yyvsp[-2].num) + 1;
        }
#line 2220 "parser.tab.c"
    break;

  case 60: /* if_statement: if_start statement  */
#line 497 "parser.y"
        {
          // Place end label after the body
          char *end_label = (yyvsp[-1].id);  // Get saved label from if_start
          emit(QUAD_LABEL, end_label, NULL, NULL);
          free(end_label);
        }
#line 2231 "parser.tab.c"
    break;

  case 61: /* $@6: %empty  */
#line 504 "parser.y"
        {
          // Generate end label after processing the if-body
          char *end_label = new_label();
          end_loop_label[for_count]=end_label;
          
          // Jump to end after then part
          emit(QUAD_JUMP, NULL, NULL, end_label);
          
          // Place else label before processing the else-body

          emit(QUAD_LABEL, update_loop_label[for_count], NULL, NULL);
          
          // Free the else label as we're done with it

          
          // Pass the end label to the next rule

        }
#line 2254 "parser.tab.c"
    break;

  case 62: /* if_statement: if_start statement ELSE $@6 statement  */
#line 523 "parser.y"
        {
          // Place end label after else part
          emit(QUAD_LABEL, end_loop_label[for_count], NULL, NULL);
          for_count++;
        }
#line 2264 "parser.tab.c"
    break;

  case 63: /* if_start: IF '(' expression ')'  */
#line 532 "parser.y"
        {
          // Common code for both if types
          if ((yyvsp[-1].expr).type != TYPE_INT) 
            var_error("Condition must be int in if statement", "if");
            
          // Generate label
          char *label = new_label();
          update_loop_label[for_count]=label;
          
          // Jump to end/else if condition is false
          char *place = (yyvsp[-1].expr).place;
          emit(QUAD_JUMPZ, place, NULL, label);
          

        }
#line 2284 "parser.tab.c"
    break;

  case 64: /* $@7: %empty  */
#line 552 "parser.y"
    {
      char *start_label = new_label();
      char *end_label = new_label(); 
      start_loop_label[for_count]=start_label;
      end_loop_label[for_count]=end_label;

      // Place the start label
      emit(QUAD_LABEL, start_label, NULL, NULL);
    }
#line 2298 "parser.tab.c"
    break;

  case 65: /* $@8: %empty  */
#line 562 "parser.y"
    {
      char *place = (yyvsp[-1].expr).place;
      emit(QUAD_JUMPZ, place, NULL, end_loop_label[for_count]);

    }
#line 2308 "parser.tab.c"
    break;

  case 66: /* while_statement: WHILE '(' $@7 expression ')' $@8 statement  */
#line 568 "parser.y"
    {

      emit(QUAD_JUMP, NULL, NULL, start_loop_label[for_count]);
      
      // Place end label
      emit(QUAD_LABEL, end_loop_label[for_count], NULL, NULL);
      for_count++;
      
    }
#line 2322 "parser.tab.c"
    break;

  case 67: /* $@9: %empty  */
#line 581 "parser.y"
    {
      char *start_label = new_label();
      start_loop_label[for_count]=start_label;

      // Place the start label
      emit(QUAD_LABEL, start_label, NULL, NULL);

    }
#line 2335 "parser.tab.c"
    break;

  case 68: /* repeat_until_statement: REPEAT $@9 statements UNTIL '(' expression ')' ';'  */
#line 589 "parser.y"
        {

          
          // Jump back to start if condition is false
          char *place = (yyvsp[-2].expr).place;
          emit(QUAD_JUMPZ, place, NULL, start_loop_label[for_count]);
          
        }
#line 2348 "parser.tab.c"
    break;

  case 69: /* $@10: %empty  */
#line 601 "parser.y"
    { 
      char *start_label = new_label();
      char *body_label = new_label();
      char *update_label = new_label();
      char *end_label = new_label(); 
      start_loop_label[for_count]=start_label;
      loop_body_label[for_count]=body_label;
      update_loop_label[for_count]=update_label;
      end_loop_label[for_count]=end_label;

      // Place the start label
      emit(QUAD_LABEL, start_label, NULL, NULL);

    }
#line 2367 "parser.tab.c"
    break;

  case 70: /* $@11: %empty  */
#line 616 "parser.y"
    {
      
      char *condition_place = (yyvsp[-1].expr).place;
      emit(QUAD_JUMPZ, condition_place, NULL, end_loop_label[for_count]);
      emit(QUAD_JUMP, NULL, NULL, loop_body_label[for_count]);
      emit(QUAD_LABEL, update_loop_label[for_count], NULL, NULL);

    }
#line 2380 "parser.tab.c"
    break;

  case 71: /* $@12: %empty  */
#line 625 "parser.y"
    {
    emit(QUAD_JUMP, NULL, NULL, start_loop_label[for_count]);
    emit(QUAD_LABEL, loop_body_label[for_count], NULL, NULL);
    }
#line 2389 "parser.tab.c"
    break;

  case 72: /* for_statement: FOR '(' for_start $@10 expression ';' $@11 for_update_expr ')' $@12 statement  */
#line 630 "parser.y"
    {
      emit(QUAD_JUMP, NULL, NULL, update_loop_label[for_count]);
      emit(QUAD_LABEL,end_loop_label[for_count], NULL, NULL);

      for_count++;
    }
#line 2400 "parser.tab.c"
    break;

  case 76: /* for_update_expr: IDENTIFIER '=' expression  */
#line 643 "parser.y"
      {
        Symbol *v = lookup_symbol((yyvsp[-2].id));
        if (!v || v->kind!=SYM_VAR) var_error("Undeclared variable", (yyvsp[-2].id));
        if (v->spec.is_const) var_error("Cannot assign to const variable", (yyvsp[-2].id));
        if (v->spec.base != (yyvsp[0].expr).type) {
          fprintf(stderr, "Type mismatch in for loop update assignment\n");
          exit(1);
        }
        
        // Generate the assignment quadruple
        emit(QUAD_ASSIGN, (yyvsp[0].expr).place, NULL, (yyvsp[-2].id));
        v->has_value = 1;
      }
#line 2418 "parser.tab.c"
    break;

  case 78: /* @13: %empty  */
#line 662 "parser.y"
        {
          // Save the switch expression to a temp for case comparisons
          char *switch_expr = new_temp();
          char *place = (yyvsp[-2].expr).place;
          emit(QUAD_ASSIGN, place, NULL, switch_expr);
          

          
          // Generate end label
          char *end_label = new_label();
          end_label_global=end_label;
          switch_expr_global=switch_expr;
          (yyval.id) = strdup(end_label);
          (yyvsp[-4].id) = strdup(switch_expr);

        }
#line 2439 "parser.tab.c"
    break;

  case 79: /* switch_statement: SWITCH '(' expression ')' '{' @13 case_list '}'  */
#line 679 "parser.y"
        {
          // Place end label
          emit(QUAD_LABEL,end_label_global, NULL, NULL);
          
          if ((yyvsp[-5].expr).type != TYPE_INT) var_error("Switch expression must be int", "switch");
        }
#line 2450 "parser.tab.c"
    break;

  case 80: /* @14: %empty  */
#line 689 "parser.y"
        {
          // // Generate case label
          // char *case_label = new_label();
          // emit(QUAD_LABEL, case_label, NULL, NULL);
          
          // Get the switch expression from the parent rule
          char *switch_expr = (yyvsp[(-5) - (4)].id);
          
          // Generate comparison
          char *temp = new_temp();
          char *const_place = (yyvsp[-1].expr).place;
          emit(QUAD_EQ, switch_expr, const_place, temp);
          
          // Jump if not equal
          char *next_label = new_label();
          emit(QUAD_JUMPZ, temp, NULL, next_label);
          
          // Store next label for use after statements
          (yyval.id) = strdup(next_label);
        }
#line 2475 "parser.tab.c"
    break;

  case 81: /* case_list: case_list CASE constant ':' @14 statements  */
#line 710 "parser.y"
        {

          
          // // Place next label
          emit(QUAD_LABEL, (yyvsp[-1].id), NULL, NULL);
        }
#line 2486 "parser.tab.c"
    break;

  case 82: /* case_list: case_list DEFAULT ':' statements  */
#line 717 "parser.y"
        {
          // Default code - just fall through
        }
#line 2494 "parser.tab.c"
    break;

  case 84: /* constant: NUMBER  */
#line 725 "parser.y"
        { 
          char *num_str = int_to_string((yyvsp[0].num));
          (yyval.expr).place = num_str;
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER: value = %d, type = %d\n", (yyvsp[0].num), (yyval.expr).type);
        }
#line 2506 "parser.tab.c"
    break;

  case 85: /* constant: CHAR_LITERAL  */
#line 733 "parser.y"
        {
          // Create a formatted character literal like 'a'
          char char_buf[8];
          sprintf(char_buf, "'%c'", (char)(yyvsp[0].num)); 
          
          (yyval.expr).place = strdup(char_buf);
          (yyval.expr).type = TYPE_CHAR;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: CHAR_LITERAL: value = %s (%d), type = %d\n", 
                  (yyval.expr).place, (yyvsp[0].num), (yyval.expr).type);
        }
#line 2522 "parser.tab.c"
    break;

  case 86: /* constant: IDENTIFIER  */
#line 745 "parser.y"
        {
          Symbol *s = lookup_symbol((yyvsp[0].id));
          if (!s)                var_error("Undeclared identifier", (yyvsp[0].id));
          if (s->kind != SYM_VAR) var_error("Case label must be a variable", (yyvsp[0].id));
          (yyval.expr).type = s->spec.base;
          (yyval.expr).place = strdup((yyvsp[0].id));
          (yyval.expr).is_literal = 0;
        }
#line 2535 "parser.tab.c"
    break;

  case 87: /* return_statement: RETURN expression ';'  */
#line 757 "parser.y"
        { 
          if ((yyvsp[-1].expr).type != current_return_immutability.base) 
            var_error("Return type mismatch in function", func_name_temp);
          
          // Generate return quadruple
          char *place = (yyvsp[-1].expr).place;
          emit(QUAD_RETURN, place, NULL, NULL);
        }
#line 2548 "parser.tab.c"
    break;

  case 88: /* return_statement: RETURN ';'  */
#line 766 "parser.y"
        { 
          if (current_return_immutability.base != TYPE_VOID)
            var_error("Return value expected in function", func_name_temp);
          
          // Generate void return quadruple
          emit(QUAD_RETURN, NULL, NULL, NULL);
        }
#line 2560 "parser.tab.c"
    break;

  case 89: /* expression: expression PLUS expression  */
#line 777 "parser.y"
        { 
          char *temp = new_temp();

          // Handle string concatenation as a special case
          if ((yyvsp[-2].expr).type == TYPE_STRING && (yyvsp[0].expr).type == TYPE_STRING) {
            emit(QUAD_CONCAT, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
            (yyval.expr).type = TYPE_STRING;
          } else if ((yyvsp[-2].expr).type == TYPE_CHAR && (yyvsp[0].expr).type == TYPE_STRING) {
            // Convert char to string for concatenation
            char *converted = new_temp();
            emit(QUAD_CHAR_TO_STRING, (yyvsp[-2].expr).place, NULL, converted);
            emit(QUAD_CONCAT, converted, (yyvsp[0].expr).place, temp);
            (yyval.expr).type = TYPE_STRING;
          } else if ((yyvsp[-2].expr).type == TYPE_STRING && (yyvsp[0].expr).type == TYPE_CHAR) {
            // Convert char to string for concatenation
            char *converted = new_temp();
            emit(QUAD_CHAR_TO_STRING, (yyvsp[0].expr).place, NULL, converted);
            emit(QUAD_CONCAT, (yyvsp[-2].expr).place, converted, temp);
            (yyval.expr).type = TYPE_STRING;
          } else {
            // Handle numeric addition with type conversion
            if ((yyvsp[-2].expr).type == TYPE_INT && (yyvsp[0].expr).type == TYPE_FLOAT) {
              char *converted = new_temp();
              emit(QUAD_INT_TO_FLOAT, (yyvsp[-2].expr).place, NULL, converted);
              emit(QUAD_ADD, converted, (yyvsp[0].expr).place, temp);
              (yyval.expr).type = TYPE_FLOAT;
            } else if ((yyvsp[-2].expr).type == TYPE_FLOAT && (yyvsp[0].expr).type == TYPE_INT) {
              char *converted = new_temp();
              emit(QUAD_INT_TO_FLOAT, (yyvsp[0].expr).place, NULL, converted);
              emit(QUAD_ADD, (yyvsp[-2].expr).place, converted, temp);
              (yyval.expr).type = TYPE_FLOAT;
            } else {
              // Check that types match and are numeric
              if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
                fprintf(stderr, "Error: Type mismatch in addition operation\n");
                exit(1);
              }

              // Only int and float are allowed for addition
              if ((yyvsp[-2].expr).type != TYPE_INT && (yyvsp[-2].expr).type != TYPE_FLOAT) {
                fprintf(stderr, "Error: Addition operation requires numeric types\n");
                exit(1);
              }

              emit(QUAD_ADD, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
              (yyval.expr).type = (yyvsp[-2].expr).type;
            }
          }

          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2617 "parser.tab.c"
    break;

  case 90: /* expression: expression MINUS expression  */
#line 830 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "subtraction", 0, 1);
          
          emit(QUAD_SUB, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2633 "parser.tab.c"
    break;

  case 91: /* expression: expression MULT expression  */
#line 842 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "multiplication", 0, 1);
          
          emit(QUAD_MUL, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2649 "parser.tab.c"
    break;

  case 92: /* expression: expression DIV expression  */
#line 854 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "division", 0, 1);
          
          // Check for division by zero for literals and known variables
          if ((yyvsp[0].expr).is_literal) {
            // Direct check for literal zero values
            if (((yyvsp[0].expr).type == TYPE_INT && strcmp((yyvsp[0].expr).place, "0") == 0) ||
                ((yyvsp[0].expr).type == TYPE_FLOAT && (strcmp((yyvsp[0].expr).place, "0.0") == 0 || 
                                          strcmp((yyvsp[0].expr).place, "0.00") == 0 ||
                                          strcmp((yyvsp[0].expr).place, "0") == 0))) {
              fprintf(stderr, "Error: Division by zero\n");
              exit(1);
            }
          } else {
            // For variables, check their value if known
            Symbol *s = lookup_symbol((yyvsp[0].expr).place);
            if (s && s->has_value) {
              if ((s->spec.base == TYPE_INT && s->value.int_val == 0) ||
                  (s->spec.base == TYPE_FLOAT && s->value.float_val == 0.0)) {
                fprintf(stderr, "Error: Division by zero (variable '%s' is 0)\n", (yyvsp[0].expr).place);
                exit(1);
              }
            }
          }
          
          emit(QUAD_DIV, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2687 "parser.tab.c"
    break;

  case 93: /* expression: expression MOD expression  */
#line 888 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - modulo only works on integers
          if ((yyvsp[-2].expr).type != TYPE_INT || (yyvsp[0].expr).type != TYPE_INT) {
            fprintf(stderr, "Error: Modulo operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_MOD, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2706 "parser.tab.c"
    break;

  case 94: /* expression: MINUS expression  */
#line 903 "parser.y"
        { 
          char *temp = new_temp();
          
          // Only numeric types can be negated
          if ((yyvsp[0].expr).type != TYPE_INT && (yyvsp[0].expr).type != TYPE_FLOAT) {
            fprintf(stderr, "Error: Unary minus requires numeric type\n");
            exit(1);
          }
          
          // For literals, we can optimize by directly negating the value
          if ((yyvsp[0].expr).is_literal) {
            if ((yyvsp[0].expr).place[0] == '-') {
              // Already negative, remove the minus sign
              (yyval.expr).place = strdup((yyvsp[0].expr).place + 1);
            } else {
              // Add a minus sign
              char *negated = malloc(strlen((yyvsp[0].expr).place) + 2);
              sprintf(negated, "-%s", (yyvsp[0].expr).place);
              (yyval.expr).place = negated;
            }
            (yyval.expr).type = (yyvsp[0].expr).type;
            (yyval.expr).is_literal = 1;
          } else {
            // Use the dedicated NEG operation
            emit(QUAD_NEG, (yyvsp[0].expr).place, NULL, temp);
            (yyval.expr).place = temp;
            (yyval.expr).type = (yyvsp[0].expr).type;
            (yyval.expr).is_literal = 0;
          }
        }
#line 2741 "parser.tab.c"
    break;

  case 95: /* expression: expression EQ expression  */
#line 934 "parser.y"
        { 
          char *temp = new_temp();
          
          // Handle string comparison as a special case
          if ((yyvsp[-2].expr).type == TYPE_STRING && (yyvsp[0].expr).type == TYPE_STRING) {
            emit(QUAD_STREQ, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          } else {
            // Types must match for comparison
            if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
              fprintf(stderr, "Error: Type mismatch in equality comparison\n");
              exit(1);
            }
            
            emit(QUAD_EQ, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          }
          
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2766 "parser.tab.c"
    break;

  case 96: /* expression: expression NEQ expression  */
#line 955 "parser.y"
        { 
          char *temp = new_temp();
          
          // Handle string comparison as a special case
          if ((yyvsp[-2].expr).type == TYPE_STRING && (yyvsp[0].expr).type == TYPE_STRING) {
            emit(QUAD_STRNEQ, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          } else {
            // Types must match for comparison
            if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
              fprintf(stderr, "Error: Type mismatch in inequality comparison\n");
              exit(1);
            }
            
            emit(QUAD_NEQ, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          }
          
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2791 "parser.tab.c"
    break;

  case 97: /* expression: expression AND expression  */
#line 976 "parser.y"
        { 
          char *temp = new_temp();
          
          // Logical operations only work on integers (boolean values)
          if ((yyvsp[-2].expr).type != TYPE_INT || (yyvsp[0].expr).type != TYPE_INT) {
            fprintf(stderr, "Error: Logical AND operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_AND, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2810 "parser.tab.c"
    break;

  case 98: /* expression: expression OR expression  */
#line 991 "parser.y"
        { 
          char *temp = new_temp();
          
          // Logical operations only work on integers (boolean values)
          if ((yyvsp[-2].expr).type != TYPE_INT || (yyvsp[0].expr).type != TYPE_INT) {
            fprintf(stderr, "Error: Logical OR operation requires integer operands\n");
            exit(1);
          }
          
          emit(QUAD_OR, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2829 "parser.tab.c"
    break;

  case 99: /* expression: NOT expression  */
#line 1006 "parser.y"
        { 
          char *temp = new_temp();
          
          // Logical NOT only works on integers (boolean values)
          if ((yyvsp[0].expr).type != TYPE_INT) {
            fprintf(stderr, "Error: Logical NOT operation requires an integer operand\n");
            exit(1);
          }
          
          emit(QUAD_NOT, (yyvsp[0].expr).place, NULL, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2848 "parser.tab.c"
    break;

  case 100: /* expression: expression '<' expression  */
#line 1021 "parser.y"
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
            fprintf(stderr, "Error: Type mismatch in less-than comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ((yyvsp[-2].expr).type == TYPE_STRING) {
            fprintf(stderr, "Error: Less-than comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_LT, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2873 "parser.tab.c"
    break;

  case 101: /* expression: expression '>' expression  */
#line 1042 "parser.y"
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
            fprintf(stderr, "Error: Type mismatch in greater-than comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ((yyvsp[-2].expr).type == TYPE_STRING) {
            fprintf(stderr, "Error: Greater-than comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_GT, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2898 "parser.tab.c"
    break;

  case 102: /* expression: expression LE expression  */
#line 1063 "parser.y"
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
            fprintf(stderr, "Error: Type mismatch in less-than-or-equal comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ((yyvsp[-2].expr).type == TYPE_STRING) {
            fprintf(stderr, "Error: Less-than-or-equal comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_LE, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2923 "parser.tab.c"
    break;

  case 103: /* expression: expression GE expression  */
#line 1084 "parser.y"
        { 
          char *temp = new_temp();
          
          // Comparison operators need matching types
          if ((yyvsp[-2].expr).type != (yyvsp[0].expr).type) {
            fprintf(stderr, "Error: Type mismatch in greater-than-or-equal comparison\n");
            exit(1);
          }
          
          // String comparisons aren't supported for < > <= >=
          if ((yyvsp[-2].expr).type == TYPE_STRING) {
            fprintf(stderr, "Error: Greater-than-or-equal comparison not supported for strings\n");
            exit(1);
          }
          
          emit(QUAD_GE, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2948 "parser.tab.c"
    break;

  case 105: /* primary_expression: IDENTIFIER  */
#line 1111 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[0].id));
          if (!v) var_error("Undeclared identifier", (yyvsp[0].id));
          
          if (v->kind == SYM_FUNC) {
            fprintf(stderr, "Error: Function '%s' used without calling it\n", (yyvsp[0].id));
            exit(1);
          }
          
          // Check if variable has been initialized
          if (v->kind == SYM_VAR && !v->has_value) {
            fprintf(stderr, "Error: Variable '%s' is being used without being initialized\n", (yyvsp[0].id));
            exit(1);
          }

          // Mark variable as used
          if (v->kind == SYM_VAR) {
            v->is_used = 1;
          }
          
          (yyval.expr).type = v->spec.base;
          (yyval.expr).place = strdup((yyvsp[0].id));
          (yyval.expr).is_literal = 0;
          fprintf(stderr, "DEBUG: IDENTIFIER: %s, type = %d\n", (yyvsp[0].id), (yyval.expr).type);
        }
#line 2978 "parser.tab.c"
    break;

  case 106: /* primary_expression: IDENTIFIER INC  */
#line 1137 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[-1].id));
          if (!v || v->kind != SYM_VAR) var_error("Undeclared variable", (yyvsp[-1].id));
          if (v->spec.is_const) var_error("Cannot modify const variable", (yyvsp[-1].id));
          
          // Check if the variable type is numeric
          if (v->spec.base != TYPE_INT && v->spec.base != TYPE_FLOAT) {
            fprintf(stderr, "Error: Increment operation requires numeric types (int or float)\n");
            exit(1);
          }
          
          // Generate temporary for the original value
          // char *temp = new_temp();
          // emit(QUAD_ASSIGN, $1, NULL, temp);
          
          // Generate increment operation after returning the original value
          char *inc_temp = new_temp();
          char *one = int_to_string(1);
          
          emit(QUAD_ADD, (yyvsp[-1].id), one, inc_temp);
          emit(QUAD_ASSIGN, inc_temp, NULL, (yyvsp[-1].id));
          
          // Return the original value
          (yyval.expr).type = v->spec.base;
          (yyval.expr).place = inc_temp;
          (yyval.expr).is_literal = 0;
          
          // Mark as initialized
          v->has_value = 1;
        }
#line 3013 "parser.tab.c"
    break;

  case 107: /* primary_expression: IDENTIFIER DEC  */
#line 1168 "parser.y"
        {
          // Similar to INC but with SUB operation
          Symbol *v = lookup_symbol((yyvsp[-1].id));
          if (!v || v->kind != SYM_VAR) var_error("Undeclared variable", (yyvsp[-1].id));
          if (v->spec.is_const) var_error("Cannot modify const variable", (yyvsp[-1].id));
          
          // Check if the variable type is numeric
          if (v->spec.base != TYPE_INT && v->spec.base != TYPE_FLOAT) {
            fprintf(stderr, "Error: Decrement operation requires numeric types (int or float)\n");
            exit(1);
          }
          
          // Generate temporary for the original value
          char *temp = new_temp();
          emit(QUAD_ASSIGN, (yyvsp[-1].id), NULL, temp);
          
          // Generate decrement operation after returning the original value
          char *dec_temp = new_temp();
          char *one = int_to_string(1);
          
          emit(QUAD_SUB, (yyvsp[-1].id), one, dec_temp);
          emit(QUAD_ASSIGN, dec_temp, NULL, (yyvsp[-1].id));
          
          // Return the original value
          (yyval.expr).type = v->spec.base;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
          
          // Mark as initialized
          v->has_value = 1;
        }
#line 3049 "parser.tab.c"
    break;

  case 108: /* primary_expression: IDENTIFIER '(' ')'  */
#line 1200 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-2].id));
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", (yyvsp[-2].id));
          
          // Check if function expects parameters
          if (f->param_count > 0) {
            fprintf(stderr, "Error: Function '%s' expects %d arguments, but none were provided\n", 
                    (yyvsp[-2].id), f->param_count);
            exit(1);
          }
          
          // Check for void function
          if (f->spec.base == TYPE_VOID) {
            fprintf(stderr, "Error: Cannot use void function '%s' in an expression\n", (yyvsp[-2].id));
            exit(1);
          }
          
          // Generate temporary to hold the return value
          char *temp = new_temp();
          
          // Generate call
          emit(QUAD_CALL, (yyvsp[-2].id), "0", temp);
          
          (yyval.expr).type = f->spec.base;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 3081 "parser.tab.c"
    break;

  case 109: /* primary_expression: IDENTIFIER '(' arg_list ')'  */
#line 1228 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-3].id));
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", (yyvsp[-3].id));
          
          // Check if argument count matches parameter count
          int arg_count = (yyvsp[-1].num);  // Use the returned value directly
          if (arg_count != f->param_count) {
            fprintf(stderr, "Error: Function '%s' expects %d arguments, but %d were provided\n", 
                    (yyvsp[-3].id), f->param_count, arg_count);
            exit(1);
          }
          
          // Check for void function
          if (f->spec.base == TYPE_VOID) {
            fprintf(stderr, "Error: Cannot use void function '%s' in an expression\n", (yyvsp[-3].id));
            exit(1);
          }
          
          // Generate temporary to hold the return value
          char *temp = new_temp();
          
          // Generate call with arguments
          char arg_count_str[16];
          snprintf(arg_count_str, sizeof(arg_count_str), "%d", arg_count);
          emit(QUAD_CALL, (yyvsp[-3].id), arg_count_str, temp);
          
          (yyval.expr).type = f->spec.base;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 3116 "parser.tab.c"
    break;

  case 110: /* primary_expression: NUMBER  */
#line 1259 "parser.y"
        { 
          // Use the number directly without temporary for literals
          char *num_str = int_to_string((yyvsp[0].num));
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = num_str;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER LITERAL: value = %s\n", num_str);
        }
#line 3129 "parser.tab.c"
    break;

  case 111: /* primary_expression: FLOAT_LITERAL  */
#line 1268 "parser.y"
        { 
          char *num_str = float_to_string((yyvsp[0].fnum));
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).place = num_str;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: FLOAT_LITERAL: value = %s\n", num_str);
        }
#line 3141 "parser.tab.c"
    break;

  case 112: /* primary_expression: CHAR_LITERAL  */
#line 1276 "parser.y"
        {
          // Format character literal for direct use
          char char_buf[8];
          sprintf(char_buf, "'%c'", (char)(yyvsp[0].num));
          
          (yyval.expr).type = TYPE_CHAR;
          (yyval.expr).place = strdup(char_buf);
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: CHAR_LITERAL: value = %s\n", char_buf);
        }
#line 3156 "parser.tab.c"
    break;

  case 113: /* primary_expression: STRING_LITERAL  */
#line 1287 "parser.y"
        {
          (yyval.expr).type = TYPE_STRING;
          (yyval.expr).place = strdup((yyvsp[0].id));
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: STRING_LITERAL: value = %s\n", (yyvsp[0].id));
        }
#line 3167 "parser.tab.c"
    break;

  case 114: /* primary_expression: '(' expression ')'  */
#line 1294 "parser.y"
        { 
          (yyval.expr).type = (yyvsp[-1].expr).type;
          (yyval.expr).place = (yyvsp[-1].expr).place;
          (yyval.expr).is_literal = (yyvsp[-1].expr).is_literal;
        }
#line 3177 "parser.tab.c"
    break;


#line 3181 "parser.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1300 "parser.y"


void yyerror(const char *s) {
    extern char *yytext;
    char *error_msg = (char *)s;
    char *suggestion = "";
    error_count++;
    
    // Check if it might be a missing semicolon
    if (strstr(s, "syntax error") && 
        (strstr(s, "unexpected identifier") || 
         strstr(s, "unexpected IF") || 
         strstr(s, "unexpected WHILE") || 
         strstr(s, "unexpected RETURN") ||
         strstr(s, "unexpected '}'") ||
         strstr(s, "unexpected FOR"))) {
        suggestion = " - Missing semicolon?";
    }
    
    // The line number is off by 2 in this example, so adjust it
    fprintf(stderr, "Error at line %d, column %d: %s%s\n", 
            yylineno, column - yyleng, error_msg, suggestion);
    
    if (last_token) {
        fprintf(stderr, "Near token: '%s'\n", last_token);
    }
}

void token_seen(const char* token_text) {
    if (last_token) {
        free(last_token);
    }
    last_token = strdup(token_text);
    column += yyleng;
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
    
    // Initialize error tracking
    yylineno = 1;
    column = 1;
    error_count = 0;

    for_count=0;

    int result = yyparse();
    
    // Free our tracking resources
    if (last_token) {
        free(last_token);
    }
    
    // Print generated quadruples
    if (result == 0 && error_count == 0) {
        // Print to console
        check_unused_variables();
        print_quadruples(stdout);
        
        // Save to files
        print_quadruples_to_file("quadruples.txt");
        // print_symbol_table_to_file("symbols.txt");
        export_global_scope();

        
        printf("Compilation successful. Output written to:\n");
        printf("- quadruples.txt\n");
        printf("- symbols.txt\n");
    } else {
        fprintf(stderr, "Compilation failed with errors.\n");
    }
    cleanup_symbol_table();

    
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
    if (left_type == right_type) return;


    
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
