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

#line 97 "parser.tab.c"

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
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_STRING = 23,                    /* STRING  */
  YYSYMBOL_VOID = 24,                      /* VOID  */
  YYSYMBOL_CONST = 25,                     /* CONST  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_MULT = 32,                      /* MULT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_MOD = 34,                       /* MOD  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_NO_ELSE = 48,                   /* NO_ELSE  */
  YYSYMBOL_BITWISE_OR = 49,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_AND = 50,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_NOT = 51,               /* BITWISE_NOT  */
  YYSYMBOL_INC = 52,                       /* INC  */
  YYSYMBOL_DEC = 53,                       /* DEC  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_functions = 57,                 /* functions  */
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_59_2 = 59,                      /* $@2  */
  YYSYMBOL_params = 60,                    /* params  */
  YYSYMBOL_param_list = 61,                /* param_list  */
  YYSYMBOL_param = 62,                     /* param  */
  YYSYMBOL_func_types = 63,                /* func_types  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_decl_list = 65,                 /* decl_list  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_block_content = 69,             /* block_content  */
  YYSYMBOL_func_block = 70,                /* func_block  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_statements = 72,                /* statements  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_assignment = 74,                /* assignment  */
  YYSYMBOL_break_statement = 75,           /* break_statement  */
  YYSYMBOL_continue_statement = 76,        /* continue_statement  */
  YYSYMBOL_func_call = 77,                 /* func_call  */
  YYSYMBOL_if_statement = 78,              /* if_statement  */
  YYSYMBOL_79_5 = 79,                      /* @5  */
  YYSYMBOL_if_start = 80,                  /* if_start  */
  YYSYMBOL_while_statement = 81,           /* while_statement  */
  YYSYMBOL_repeat_until_statement = 82,    /* repeat_until_statement  */
  YYSYMBOL_for_statement = 83,             /* for_statement  */
  YYSYMBOL_switch_statement = 84,          /* switch_statement  */
  YYSYMBOL_85_6 = 85,                      /* @6  */
  YYSYMBOL_case_list = 86,                 /* case_list  */
  YYSYMBOL_87_7 = 87,                      /* @7  */
  YYSYMBOL_constant = 88,                  /* constant  */
  YYSYMBOL_return_statement = 89,          /* return_statement  */
  YYSYMBOL_expression = 90                 /* expression  */
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
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      40,    41,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    38,
      45,    44,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   105,   110,   111,   116,   115,   130,   131,
     135,   136,   140,   154,   155,   156,   157,   158,   159,   163,
     164,   165,   166,   167,   171,   173,   178,   207,   240,   239,
     246,   247,   248,   253,   252,   273,   274,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   292,   321,
     329,   337,   351,   359,   358,   386,   406,   432,   449,   484,
     523,   522,   547,   546,   575,   579,   583,   591,   603,   615,
     624,   635,   663,   675,   687,   699,   714,   735,   756,   771,
     786,   801,   822,   843,   864,   885,   891,   912,   921,   929,
     940
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER",
  "CHAR_LITERAL", "FLOAT_LITERAL", "IDENTIFIER", "STRING_LITERAL", "IF",
  "ELSE", "WHILE", "REPEAT", "UNTIL", "FOR", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "CONTINUE", "RETURN", "INT", "FLOAT", "CHAR", "STRING", "VOID",
  "CONST", "EQ", "NEQ", "LE", "GE", "PLUS", "MINUS", "MULT", "DIV", "MOD",
  "AND", "OR", "NOT", "';'", "','", "'('", "')'", "'{'", "'}'", "'='",
  "'<'", "'>'", "':'", "NO_ELSE", "BITWISE_OR", "BITWISE_AND",
  "BITWISE_NOT", "INC", "DEC", "$accept", "program", "$@1", "functions",
  "function", "$@2", "params", "param_list", "param", "func_types", "type",
  "decl_list", "declaration", "block", "$@3", "block_content",
  "func_block", "$@4", "statements", "statement", "assignment",
  "break_statement", "continue_statement", "func_call", "if_statement",
  "@5", "if_start", "while_statement", "repeat_until_statement",
  "for_statement", "switch_statement", "@6", "case_list", "@7", "constant",
  "return_statement", "expression", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,     2,   277,  -155,  -155,  -155,  -155,  -155,  -155,   277,
     277,  -155,     8,  -155,  -155,    -9,   151,  -155,  -155,  -155,
    -155,   151,    -5,    -4,  -155,    43,  -155,  -155,   151,  -155,
      16,  -155,  -155,  -155,  -155,   115,   -33,    22,    30,  -155,
      34,    42,    45,    49,    74,  -155,    89,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,   133,  -155,  -155,  -155,  -155,
      67,    72,    87,    87,    87,    11,   191,    87,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,    87,  -155,    87,   132,  -155,
    -155,   -12,   108,  -155,  -155,    80,   153,   174,   195,    82,
    -155,    86,    87,    87,   216,  -155,   237,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,  -155,    87,
      87,    46,  -155,   125,    87,  -155,  -155,  -155,  -155,   133,
      87,   258,   279,   100,  -155,   391,   391,   162,   162,    75,
      75,  -155,  -155,  -155,   384,    70,   162,   162,  -155,  -155,
     300,   133,  -155,   321,    87,    87,  -155,  -155,  -155,   107,
     342,   363,  -155,  -155,   133,   133,    -6,  -155,  -155,    69,
     101,  -155,  -155,  -155,  -155,   102,  -155,  -155,   133,  -155,
     133
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    13,    14,    15,    16,    18,     0,
       3,     5,     0,    17,     4,     0,     9,    19,    20,    21,
      22,     0,     0,     8,    11,     0,    23,     6,     0,    12,
       0,    10,    33,     7,    32,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,    28,     0,    30,    47,    31,
      37,    44,    45,    46,    38,     0,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      87,    89,    88,    86,    90,     0,    70,     0,     0,    32,
      24,     0,    52,    43,    34,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,    26,     0,     0,    53,    51,    48,    55,     0,
       0,     0,     0,     0,    85,    76,    77,    83,    84,    71,
      72,    73,    74,    75,    78,    79,    81,    82,    29,    25,
       0,     0,    56,     0,     0,     0,    60,    27,    54,     0,
       0,     0,    65,    57,     0,     0,     0,    58,    59,     0,
       0,    61,    66,    67,    68,     0,    36,    62,    64,    36,
      63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,   143,  -155,  -155,  -155,   126,   146,
     -15,  -155,    90,  -155,  -155,   111,  -155,  -155,  -154,   -35,
     103,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,   182,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    30,    22,    23,    24,    12,
      46,    81,    47,    48,    79,    35,    33,    34,    65,    90,
      50,    51,    52,    53,    54,   141,    55,    56,    57,    58,
      59,   152,   156,   169,   165,    83,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    25,     3,    86,    87,    88,    26,    61,    94,   159,
     160,    62,   168,    25,    15,   170,    95,    36,    96,    37,
      82,    38,    39,    89,    40,    41,   112,   113,    42,    43,
      44,    16,   114,   121,   122,    28,    27,   161,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    29,
     136,   137,    36,    45,    37,   140,    38,    39,    32,    40,
      41,   143,    63,    42,    43,    44,    17,    18,    19,    20,
      64,    21,   162,   163,    66,   164,    49,    70,    71,    72,
      73,    74,    67,    68,   142,   150,   151,    69,    45,   138,
      70,    71,    72,    73,    74,    80,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   148,   103,   104,   105,
      84,    75,    76,    85,    77,   109,   110,   115,   116,   157,
     158,    36,   120,    37,    75,    38,    39,    77,    40,    41,
      62,   139,    42,    43,    44,    17,    18,    19,    20,    36,
      21,    37,   146,    38,    39,   153,    40,    41,   166,   167,
      42,    43,    44,    14,    31,    13,    92,    45,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    93,
     108,    17,    18,    19,    20,    45,    21,   109,   110,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     111,   117,   101,   102,   103,   104,   105,    91,   109,   110,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    17,    18,    19,    20,   118,    21,    60,     0,   109,
     110,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   119,     0,     0,     0,
     109,   110,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   123,     0,     0,
       0,   109,   110,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   124,     0,
       0,     0,   109,   110,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   144,     4,     5,     6,
       7,     8,     9,   109,   110,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   145,     0,     0,
       0,     0,     0,     0,   109,   110,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   147,     0,
       0,     0,     0,     0,     0,   109,   110,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   149,     0,     0,     0,   109,   110,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   154,     0,     0,     0,   109,   110,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   155,     0,     0,     0,   109,   110,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   109,
     110,     0,     0,     0,     0,     0,   109,   110
};

static const yytype_int16 yycheck[] =
{
      35,    16,     0,    62,    63,    64,    21,    40,    67,    15,
      16,    44,   166,    28,     6,   169,    75,     6,    77,     8,
      55,    10,    11,    12,    13,    14,    38,    39,    17,    18,
      19,    40,    44,    92,    93,    39,    41,    43,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     6,
     109,   110,     6,    42,     8,   114,    10,    11,    42,    13,
      14,   120,    40,    17,    18,    19,    20,    21,    22,    23,
      40,    25,     3,     4,    40,     6,   111,     3,     4,     5,
       6,     7,    40,    38,   119,   144,   145,    38,    42,    43,
       3,     4,     5,     6,     7,     6,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   141,    32,    33,    34,
      43,    37,    38,    41,    40,    45,    46,     9,    38,   154,
     155,     6,    40,     8,    37,    10,    11,    40,    13,    14,
      44,     6,    17,    18,    19,    20,    21,    22,    23,     6,
      25,     8,    42,    10,    11,    38,    13,    14,    47,    47,
      17,    18,    19,    10,    28,     9,    66,    42,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    66,
      38,    20,    21,    22,    23,    42,    25,    45,    46,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      79,    38,    30,    31,    32,    33,    34,     6,    45,    46,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    20,    21,    22,    23,    41,    25,    35,    -1,    45,
      46,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    46,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    20,    21,    22,
      23,    24,    25,    45,    46,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,    20,    21,    22,    23,    24,    25,
      57,    58,    63,    63,    58,     6,    40,    20,    21,    22,
      23,    25,    60,    61,    62,    64,    64,    41,    39,     6,
      59,    62,    42,    70,    71,    69,     6,     8,    10,    11,
      13,    14,    17,    18,    19,    42,    64,    66,    67,    73,
      74,    75,    76,    77,    78,    80,    81,    82,    83,    84,
      89,    40,    44,    40,    40,    72,    40,    40,    38,    38,
       3,     4,     5,     6,     7,    37,    38,    40,    90,    68,
       6,    65,    73,    89,    43,    41,    90,    90,    90,    12,
      73,     6,    66,    74,    90,    90,    90,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    38,    45,
      46,    69,    38,    39,    44,     9,    38,    38,    41,    41,
      40,    90,    90,    41,    41,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    43,     6,
      90,    79,    73,    90,    38,    38,    42,    38,    73,    41,
      90,    90,    85,    38,    41,    41,    86,    73,    73,    15,
      16,    43,     3,     4,     6,    88,    47,    47,    72,    87,
      72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    56,    55,    57,    57,    59,    58,    60,    60,
      61,    61,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    68,    67,
      69,    69,    69,    71,    70,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      76,    77,    78,    79,    78,    80,    81,    82,    83,    83,
      85,    84,    87,    86,    86,    86,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,     7,     1,     0,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     5,     0,     4,
       2,     2,     0,     0,     5,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       2,     4,     2,     0,     5,     4,     5,     7,     8,     8,
       0,     8,     0,     6,     4,     0,     1,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1
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
#line 105 "parser.y"
        { init_symbol_table(); }
#line 1347 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 116 "parser.y"
        {
          current_return_immutability = (yyvsp[-4].immutability); 
          func_name_temp = strdup((yyvsp[-3].id));
          
          // Generate function label
          emit(QUAD_LABEL, (yyvsp[-3].id), NULL, NULL);
        }
#line 1359 "parser.tab.c"
    break;

  case 7: /* function: func_types IDENTIFIER '(' params ')' $@2 func_block  */
#line 124 "parser.y"
      {
        param_count = 0;
      }
#line 1367 "parser.tab.c"
    break;

  case 12: /* param: type IDENTIFIER  */
#line 142 "parser.y"
        {
          if (param_count >= MAX_PARAMS) var_error("Too many parameters in function", func_name_temp);
          param_list[param_count].name = strdup((yyvsp[0].id));
          param_list[param_count].spec = (yyvsp[-1].immutability);
          param_count++;
          
          // Register parameter in quadruple
          emit(QUAD_PARAM, (yyvsp[0].id), NULL, NULL);
        }
#line 1381 "parser.tab.c"
    break;

  case 13: /* func_types: INT  */
#line 154 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1387 "parser.tab.c"
    break;

  case 14: /* func_types: FLOAT  */
#line 155 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1393 "parser.tab.c"
    break;

  case 15: /* func_types: CHAR  */
#line 156 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1399 "parser.tab.c"
    break;

  case 16: /* func_types: STRING  */
#line 157 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_STRING, 0}; }
#line 1405 "parser.tab.c"
    break;

  case 17: /* func_types: CONST func_types  */
#line 158 "parser.y"
                       { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1411 "parser.tab.c"
    break;

  case 18: /* func_types: VOID  */
#line 159 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_VOID,  0}; }
#line 1417 "parser.tab.c"
    break;

  case 19: /* type: INT  */
#line 163 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_INT,   0}; }
#line 1423 "parser.tab.c"
    break;

  case 20: /* type: FLOAT  */
#line 164 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_FLOAT, 0}; }
#line 1429 "parser.tab.c"
    break;

  case 21: /* type: CHAR  */
#line 165 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_CHAR,  0}; }
#line 1435 "parser.tab.c"
    break;

  case 22: /* type: STRING  */
#line 166 "parser.y"
                    { (yyval.immutability) = (TypeImmut){TYPE_STRING, 0}; }
#line 1441 "parser.tab.c"
    break;

  case 23: /* type: CONST type  */
#line 167 "parser.y"
                    { (yyval.immutability) = (yyvsp[0].immutability); (yyval.immutability).is_const = 1; }
#line 1447 "parser.tab.c"
    break;

  case 24: /* decl_list: IDENTIFIER  */
#line 172 "parser.y"
        { (yyval.idlist) = new_idlist((yyvsp[0].id)); }
#line 1453 "parser.tab.c"
    break;

  case 25: /* decl_list: decl_list ',' IDENTIFIER  */
#line 174 "parser.y"
        { (yyval.idlist) = idlist_append((yyvsp[-2].idlist), (yyvsp[0].id)); }
#line 1459 "parser.tab.c"
    break;

  case 26: /* declaration: type decl_list ';'  */
#line 179 "parser.y"
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
#line 1492 "parser.tab.c"
    break;

  case 27: /* declaration: type decl_list '=' expression ';'  */
#line 208 "parser.y"
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
              } else if (ts.base == TYPE_CHAR && (yyvsp[-1].expr).is_literal) {
                emit(QUAD_ASSIGN_CHAR, place, NULL, it->name);
              } else {
                emit(QUAD_ASSIGN, place, NULL, it->name);
              }
            }
          }
        }
#line 1525 "parser.tab.c"
    break;

  case 28: /* $@3: %empty  */
#line 240 "parser.y"
        { enter_scope(); }
#line 1531 "parser.tab.c"
    break;

  case 29: /* block: '{' $@3 block_content '}'  */
#line 242 "parser.y"
        { exit_scope(); }
#line 1537 "parser.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 253 "parser.y"
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
#line 1555 "parser.tab.c"
    break;

  case 34: /* func_block: '{' $@4 block_content return_statement '}'  */
#line 267 "parser.y"
        {
          exit_scope();
        }
#line 1563 "parser.tab.c"
    break;

  case 48: /* assignment: IDENTIFIER '=' expression ';'  */
#line 293 "parser.y"
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
          } else if (v->spec.base == TYPE_CHAR && (yyvsp[-1].expr).is_literal) {
            emit(QUAD_ASSIGN_CHAR, place, NULL, (yyvsp[-3].id));
          } else {
            emit(QUAD_ASSIGN, place, NULL, (yyvsp[-3].id));
          }
          
          // Update variable value in symbol table
          v->has_value = 1;
        }
#line 1593 "parser.tab.c"
    break;

  case 49: /* break_statement: BREAK ';'  */
#line 322 "parser.y"
        {
          // Generate quadruple for break
          emit(QUAD_JUMP, NULL, NULL, "break_target");
        }
#line 1602 "parser.tab.c"
    break;

  case 50: /* continue_statement: CONTINUE ';'  */
#line 330 "parser.y"
        {
          // Generate quadruple for continue
          emit(QUAD_JUMP, NULL, NULL, "continue_target");
        }
#line 1611 "parser.tab.c"
    break;

  case 51: /* func_call: IDENTIFIER '(' ')' ';'  */
#line 338 "parser.y"
        {
          Symbol *f = lookup_symbol((yyvsp[-3].id));
          if (!f || f->kind!=SYM_FUNC) var_error("Undeclared function", (yyvsp[-3].id));
          
          // Generate quadruple for function call
          emit(QUAD_CALL, (yyvsp[-3].id), "0", NULL); // 0 args
        }
#line 1623 "parser.tab.c"
    break;

  case 52: /* if_statement: if_start statement  */
#line 352 "parser.y"
        {
          // Place end label after the body
          char *end_label = (yyvsp[-1].id);  // Get saved label from if_start
          emit(QUAD_LABEL, end_label, NULL, NULL);
          free(end_label);
        }
#line 1634 "parser.tab.c"
    break;

  case 53: /* @5: %empty  */
#line 359 "parser.y"
        {
          // Generate end label after processing the if-body
          char *end_label = new_label();
          
          // Jump to end after then part
          emit(QUAD_JUMP, NULL, NULL, end_label);
          
          // Place else label before processing the else-body
          char *else_label = (yyvsp[-2].id);
          emit(QUAD_LABEL, else_label, NULL, NULL);
          
          // Free the else label as we're done with it
          free(else_label);
          
          // Pass the end label to the next rule
          (yyval.id) = strdup(end_label);
        }
#line 1656 "parser.tab.c"
    break;

  case 54: /* if_statement: if_start statement ELSE @5 statement  */
#line 377 "parser.y"
        {
          // Place end label after else part
          char *end_label = (yyvsp[-2].id);
          emit(QUAD_LABEL, end_label, NULL, NULL);
          free(end_label);
        }
#line 1667 "parser.tab.c"
    break;

  case 55: /* if_start: IF '(' expression ')'  */
#line 387 "parser.y"
        {
          // Common code for both if types
          if ((yyvsp[-1].expr).type != TYPE_INT) 
            var_error("Condition must be int in if statement", "if");
            
          // Generate label
          char *label = new_label();
          
          // Jump to end/else if condition is false
          char *place = (yyvsp[-1].expr).place;
          emit(QUAD_JUMPZ, place, NULL, label);
          
          // Pass the label to the next rule
          (yyval.id) = strdup(label);
        }
#line 1687 "parser.tab.c"
    break;

  case 56: /* while_statement: WHILE '(' expression ')' statement  */
#line 407 "parser.y"
        {
          // Generate label for loop start
          char *start_label = new_label();
          
          // Generate label for loop end
          char *end_label = new_label();
          
          // Place start label
          emit(QUAD_LABEL, start_label, NULL, NULL);
          
          // Jump to end if condition is false
          char *place = (yyvsp[-2].expr).place;
          emit(QUAD_JUMPZ, place, NULL, end_label);
          
          // Jump back to start after body
          emit(QUAD_JUMP, NULL, NULL, start_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ((yyvsp[-2].expr).type != TYPE_INT) var_error("Condition must be int in while loop", "while");
        }
#line 1714 "parser.tab.c"
    break;

  case 57: /* repeat_until_statement: REPEAT statements UNTIL '(' expression ')' ';'  */
#line 433 "parser.y"
        {
          // Generate label for loop start
          char *start_label = new_label();
          
          // Place start label
          emit(QUAD_LABEL, start_label, NULL, NULL);
          
          // Jump back to start if condition is false
          char *place = (yyvsp[-2].expr).place;
          emit(QUAD_JUMPZ, place, NULL, start_label);
          
          if ((yyvsp[-2].expr).type != TYPE_INT) var_error("Condition must be int in repeat-until loop", "until");
        }
#line 1732 "parser.tab.c"
    break;

  case 58: /* for_statement: FOR '(' declaration expression ';' expression ')' statement  */
#line 450 "parser.y"
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
          char *cond_place = (yyvsp[-4].expr).place;
          emit(QUAD_JUMPZ, cond_place, NULL, end_label);
          
          // Jump to update after body
          emit(QUAD_JUMP, NULL, NULL, update_label);
          
          // Place update label
          emit(QUAD_LABEL, update_label, NULL, NULL);
          
          // Evaluate update expression
          char *update_place = (yyvsp[-2].expr).place;
          
          // Jump back to condition
          emit(QUAD_JUMP, NULL, NULL, cond_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ((yyvsp[-4].expr).type != TYPE_INT) var_error("Condition must be int in for loop", "for");
        }
#line 1771 "parser.tab.c"
    break;

  case 59: /* for_statement: FOR '(' assignment expression ';' expression ')' statement  */
#line 485 "parser.y"
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
          char *cond_place = (yyvsp[-4].expr).place;
          emit(QUAD_JUMPZ, cond_place, NULL, end_label);
          
          // Jump to update after body
          emit(QUAD_JUMP, NULL, NULL, update_label);
          
          // Place update label
          emit(QUAD_LABEL, update_label, NULL, NULL);
          
          // Evaluate update expression
          char *update_place = (yyvsp[-2].expr).place;
          
          // Jump back to condition
          emit(QUAD_JUMP, NULL, NULL, cond_label);
          
          // Place end label
          emit(QUAD_LABEL, end_label, NULL, NULL);
          
          if ((yyvsp[-4].expr).type != TYPE_INT) var_error("Condition must be int in for loop", "for");
        }
#line 1810 "parser.tab.c"
    break;

  case 60: /* @6: %empty  */
#line 523 "parser.y"
        {
          // Save the switch expression to a temp for case comparisons
          char *switch_expr = new_temp();
          char *place = (yyvsp[-2].expr).place;
          emit(QUAD_ASSIGN, place, NULL, switch_expr);
          
          // Store the switch expression for case comparisons
          (yyval.id) = switch_expr;
          
          // Generate end label
          char *end_label = new_label();
          (yyval.id) = strdup(end_label);
        }
#line 1828 "parser.tab.c"
    break;

  case 61: /* switch_statement: SWITCH '(' expression ')' '{' @6 case_list '}'  */
#line 537 "parser.y"
        {
          // Place end label
          emit(QUAD_LABEL, (yyvsp[-2].id), NULL, NULL);
          
          if ((yyvsp[-5].expr).type != TYPE_INT) var_error("Switch expression must be int", "switch");
        }
#line 1839 "parser.tab.c"
    break;

  case 62: /* @7: %empty  */
#line 547 "parser.y"
        {
          // Generate case label
          char *case_label = new_label();
          emit(QUAD_LABEL, case_label, NULL, NULL);
          
          // Get the switch expression from the parent rule
          char *switch_expr = (yyvsp[-4].id);
          
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
#line 1864 "parser.tab.c"
    break;

  case 63: /* case_list: case_list CASE constant ':' @7 statements  */
#line 568 "parser.y"
        {
          // Jump to end after case body
          emit(QUAD_JUMP, NULL, NULL, (yyvsp[-6].id));
          
          // Place next label
          emit(QUAD_LABEL, (yyvsp[-1].id), NULL, NULL);
        }
#line 1876 "parser.tab.c"
    break;

  case 64: /* case_list: case_list DEFAULT ':' statements  */
#line 576 "parser.y"
        {
          // Default code - just fall through
        }
#line 1884 "parser.tab.c"
    break;

  case 66: /* constant: NUMBER  */
#line 584 "parser.y"
        { 
          char *num_str = int_to_string((yyvsp[0].num));
          (yyval.expr).place = num_str;
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER: value = %d, type = %d\n", (yyvsp[0].num), (yyval.expr).type);
        }
#line 1896 "parser.tab.c"
    break;

  case 67: /* constant: CHAR_LITERAL  */
#line 592 "parser.y"
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
#line 1912 "parser.tab.c"
    break;

  case 68: /* constant: IDENTIFIER  */
#line 604 "parser.y"
        {
          Symbol *s = lookup_symbol((yyvsp[0].id));
          if (!s)                var_error("Undeclared identifier", (yyvsp[0].id));
          if (s->kind != SYM_VAR) var_error("Case label must be a variable", (yyvsp[0].id));
          (yyval.expr).type = s->spec.base;
          (yyval.expr).place = strdup((yyvsp[0].id));
          (yyval.expr).is_literal = 0;
        }
#line 1925 "parser.tab.c"
    break;

  case 69: /* return_statement: RETURN expression ';'  */
#line 616 "parser.y"
        { 
          if ((yyvsp[-1].expr).type != current_return_immutability.base) 
            var_error("Return type mismatch in function", func_name_temp);
          
          // Generate return quadruple
          char *place = (yyvsp[-1].expr).place;
          emit(QUAD_RETURN, place, NULL, NULL);
        }
#line 1938 "parser.tab.c"
    break;

  case 70: /* return_statement: RETURN ';'  */
#line 625 "parser.y"
        { 
          if (current_return_immutability.base != TYPE_VOID)
            var_error("Return value expected in function", func_name_temp);
          
          // Generate void return quadruple
          emit(QUAD_RETURN, NULL, NULL, NULL);
        }
#line 1950 "parser.tab.c"
    break;

  case 71: /* expression: expression PLUS expression  */
#line 636 "parser.y"
        { 
          char *temp = new_temp();
          
          // Handle string concatenation as a special case
          if ((yyvsp[-2].expr).type == TYPE_STRING && (yyvsp[0].expr).type == TYPE_STRING) {
            emit(QUAD_CONCAT, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
            (yyval.expr).type = TYPE_STRING;
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
          
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 1982 "parser.tab.c"
    break;

  case 72: /* expression: expression MINUS expression  */
#line 664 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "subtraction", 0, 1);
          
          emit(QUAD_SUB, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 1998 "parser.tab.c"
    break;

  case 73: /* expression: expression MULT expression  */
#line 676 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "multiplication", 0, 1);
          
          emit(QUAD_MUL, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2014 "parser.tab.c"
    break;

  case 74: /* expression: expression DIV expression  */
#line 688 "parser.y"
        { 
          char *temp = new_temp();
          
          // Check types - no strings allowed
          check_op_types((yyvsp[-2].expr).type, (yyvsp[0].expr).type, "division", 0, 1);
          
          emit(QUAD_DIV, (yyvsp[-2].expr).place, (yyvsp[0].expr).place, temp);
          (yyval.expr).type = (yyvsp[-2].expr).type;
          (yyval.expr).place = temp;
          (yyval.expr).is_literal = 0;
        }
#line 2030 "parser.tab.c"
    break;

  case 75: /* expression: expression MOD expression  */
#line 700 "parser.y"
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
#line 2049 "parser.tab.c"
    break;

  case 76: /* expression: expression EQ expression  */
#line 715 "parser.y"
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
#line 2074 "parser.tab.c"
    break;

  case 77: /* expression: expression NEQ expression  */
#line 736 "parser.y"
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
#line 2099 "parser.tab.c"
    break;

  case 78: /* expression: expression AND expression  */
#line 757 "parser.y"
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
#line 2118 "parser.tab.c"
    break;

  case 79: /* expression: expression OR expression  */
#line 772 "parser.y"
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
#line 2137 "parser.tab.c"
    break;

  case 80: /* expression: NOT expression  */
#line 787 "parser.y"
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
#line 2156 "parser.tab.c"
    break;

  case 81: /* expression: expression '<' expression  */
#line 802 "parser.y"
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
#line 2181 "parser.tab.c"
    break;

  case 82: /* expression: expression '>' expression  */
#line 823 "parser.y"
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
#line 2206 "parser.tab.c"
    break;

  case 83: /* expression: expression LE expression  */
#line 844 "parser.y"
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
#line 2231 "parser.tab.c"
    break;

  case 84: /* expression: expression GE expression  */
#line 865 "parser.y"
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
#line 2256 "parser.tab.c"
    break;

  case 85: /* expression: '(' expression ')'  */
#line 886 "parser.y"
        { 
          (yyval.expr).type = (yyvsp[-1].expr).type;
          (yyval.expr).place = (yyvsp[-1].expr).place;
          (yyval.expr).is_literal = (yyvsp[-1].expr).is_literal;
        }
#line 2266 "parser.tab.c"
    break;

  case 86: /* expression: IDENTIFIER  */
#line 892 "parser.y"
        {
          Symbol *v = lookup_symbol((yyvsp[0].id));
          if (!v) var_error("Undeclared variable", (yyvsp[0].id));
          
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
#line 2291 "parser.tab.c"
    break;

  case 87: /* expression: NUMBER  */
#line 913 "parser.y"
        { 
          // Use the number directly without temporary for literals
          char *num_str = int_to_string((yyvsp[0].num));
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).place = num_str;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: NUMBER LITERAL: value = %s\n", num_str);
        }
#line 2304 "parser.tab.c"
    break;

  case 88: /* expression: FLOAT_LITERAL  */
#line 922 "parser.y"
        { 
          char *num_str = float_to_string((yyvsp[0].fnum));
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).place = num_str;
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: FLOAT_LITERAL: value = %s\n", num_str);
        }
#line 2316 "parser.tab.c"
    break;

  case 89: /* expression: CHAR_LITERAL  */
#line 930 "parser.y"
        {
          // Format character literal for direct use
          char char_buf[8];
          sprintf(char_buf, "'%c'", (char)(yyvsp[0].num));
          
          (yyval.expr).type = TYPE_CHAR;
          (yyval.expr).place = strdup(char_buf);
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: CHAR_LITERAL: value = %s\n", char_buf);
        }
#line 2331 "parser.tab.c"
    break;

  case 90: /* expression: STRING_LITERAL  */
#line 941 "parser.y"
        {
          (yyval.expr).type = TYPE_STRING;
          (yyval.expr).place = strdup((yyvsp[0].id));
          (yyval.expr).is_literal = 1;
          fprintf(stderr, "DEBUG: STRING_LITERAL: value = %s\n", (yyvsp[0].id));
        }
#line 2342 "parser.tab.c"
    break;


#line 2346 "parser.tab.c"

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

#line 948 "parser.y"


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
