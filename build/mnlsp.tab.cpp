/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "src/mnlsp.y" /* yacc.c:337  */

#include<stdio.h>
#include"mnlsp.hpp"

#define DEBUG true

// #define ERR_SYN "syntax error"

extern "C"
{
    void yyerror(const char* msg);
    extern int yylex();
};

mnlsp::RTE* brte;

#line 87 "build/mnlsp.tab.cpp" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mnlsp.tab.h".  */
#ifndef YY_YY_INC_MNLSP_TAB_H_INCLUDED
# define YY_YY_INC_MNLSP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 21 "src/mnlsp.y" /* yacc.c:352  */

#include"mnlsp.hpp"

#line 124 "build/mnlsp.tab.cpp" /* yacc.c:352  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    BOOL_VAL = 260,
    LP = 261,
    RP = 262,
    PRINT_NUM_ID = 263,
    PRINT_BOOL_ID = 264,
    PLUS_ID = 265,
    MINUS_ID = 266,
    MULTIPLY_ID = 267,
    DIVIDE_ID = 268,
    MODULUS_ID = 269,
    GREATER_ID = 270,
    SMALLER_ID = 271,
    EQUAL_ID = 272,
    AND_ID = 273,
    OR_ID = 274,
    NOT_ID = 275,
    DEFINE_ID = 276,
    FUN_ID = 277,
    IF_ID = 278
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_MNLSP_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

#define YYUNDEFTOK  2
#define YYMAXUTOK   278

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   106,   111,   117,   118,   119,   122,   127,
     133,   134,   135,   136,   137,   138,   139,   140,   144,   149,
     157,   164,   171,   172,   173,   174,   175,   176,   177,   178,
     181,   189,   196,   204,   211,   218,   225,   232,   241,   242,
     243,   246,   254,   262,   270,   278,   284,   285,   288,   292,
     299,   308,   316,   321,   324,   330,   334,   341,   344,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "BOOL_VAL", "LP", "RP",
  "PRINT_NUM_ID", "PRINT_BOOL_ID", "PLUS_ID", "MINUS_ID", "MULTIPLY_ID",
  "DIVIDE_ID", "MODULUS_ID", "GREATER_ID", "SMALLER_ID", "EQUAL_ID",
  "AND_ID", "OR_ID", "NOT_ID", "DEFINE_ID", "FUN_ID", "IF_ID", "$accept",
  "program", "stmts", "stmt", "exps", "exp", "print_stmt", "def_stmt",
  "variable", "num_op", "plus", "minus", "multiply", "divide", "modulus",
  "greater", "smaller", "equal", "logical_op", "and_op", "or_op", "not_op",
  "fun_exp", "fun_ids", "idsn", "fun_body", "fun_call", "paramsn", "param",
  "fun_name", "if_exp", "test_exp", "than_exp", "else_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,   -53,   -53,   -53,    90,     4,   -53,     8,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -17,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,     2,    17,    12,    12,    12,   -53,   -53,
     110,    19,    20,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    21,    12,    25,    16,   -53,    12,   -53,
      36,    12,    37,   -53,   -53,    42,    12,    43,    44,    45,
      46,    48,    53,    54,    55,    56,   -53,    58,    25,    65,
      63,   -53,    12,    80,   -53,    12,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,    82,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    21,    10,     0,     0,     2,     4,     5,     6,
       7,    12,    13,    22,    23,    24,    25,    26,    27,    28,
      29,    14,    38,    39,    40,    15,    16,    17,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    53,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,    57,     0,    54,
       0,    53,     0,    18,    19,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,    47,     0,
       0,    49,     0,     0,    58,     0,    50,    52,    51,    30,
       8,    31,    32,    33,    34,    35,    36,    37,    41,    42,
      20,    46,    45,    48,    44,    59,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,    83,   -53,   -52,     0,   -53,    27,    72,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,    -2,   -53,   -18,   -53,   -53,   -46,   -53,   -53,
     -53,   -53,   -53,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    75,    76,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    66,    89,    93,    26,    70,    71,    47,
      27,    68,    95,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    72,    46,    78,    48,    44,     2,     8,    83,    84,
      85,     1,     2,     3,     4,     1,     2,     3,    50,     1,
       2,     3,    90,    65,   100,    97,    73,    74,    86,    88,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    96,    98,    67,    69,    69,    46,    99,
     101,   102,   103,   104,    77,   105,    79,    80,    81,    82,
     106,   107,   108,   109,    87,   110,    91,    28,    94,    29,
     111,    69,   112,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   114,    46,   117,
      49,     0,   113,    92,    28,   115,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    28,    64,    29,     0,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    44,    45
};

static const yytype_int8 yycheck[] =
{
       0,    47,     4,    55,     0,    22,     4,     7,    60,    61,
      62,     3,     4,     5,     6,     3,     4,     5,     6,     3,
       4,     5,     6,     6,    76,    71,     7,     7,     7,     4,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     7,     7,    45,    46,    47,    50,     7,
       7,     7,     7,     7,    54,     7,    56,    57,    58,    59,
       7,     7,     7,     7,    64,     7,    66,     4,    68,     6,
      88,    71,     7,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     7,    90,     7,
       7,    -1,    92,    66,     4,    95,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     4,    43,     6,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    25,    26,    27,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    50,    54,     4,     6,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    46,    53,     0,    26,
       6,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    32,     6,    47,    29,    55,    29,
      51,    52,    51,     7,     7,    28,    29,    29,    28,    29,
      29,    29,    29,    28,    28,    28,     7,    29,     4,    48,
       6,    29,    31,    49,    29,    56,     7,    51,     7,     7,
      28,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,    48,     7,    29,     7,    29,    57,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    28,    28,
      29,    29,    29,    29,    29,    29,    29,    29,    30,    30,
      31,    32,    33,    33,    33,    33,    33,    33,    33,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    42,
      42,    43,    44,    45,    46,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    53,    54,    55,    56,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     5,     5,     5,     1,     1,
       1,     5,     5,     4,     5,     3,     2,     0,     2,     1,
       4,     4,     2,     0,     1,     1,     6,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 98 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).r = mnlsp::RTE::get_base_rte();
        (yyval.t).r->add_params(*(yyvsp[0].t).v);
        brte = (yyval.t).r;
        // printf(">>>\n");
    }
#line 1325 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 106 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[0].t).v);
    }
#line 1335 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 111 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[0].t).n);
    }
#line 1344 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 117 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1350 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 118 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1356 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 119 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1362 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 122 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[0].t).v);
    }
#line 1372 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 127 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[0].t).n);
    }
#line 1381 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 133 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(*(yyvsp[0].t).d);}
#line 1387 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 134 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(*(yyvsp[0].t).d);}
#line 1393 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 135 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1399 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 136 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1405 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 137 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1411 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 138 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1417 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 139 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1423 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 140 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = new mnlsp::ExpNode(mnlsp::Data((yyvsp[0].t).r));}
#line 1429 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 144 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_print-num", *(yyval.t).v);
    }
#line 1439 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 149 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_print-bool", *(yyval.t).v);
    }
#line 1449 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 157 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_define", *(yyval.t).v);
    }
#line 1459 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 164 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).n = (mnlsp::ExpNode*)(new mnlsp::VarNode());
        ((mnlsp::VarNode*)(yyval.t).n)->vid = *(yyvsp[0].t).s;
    }
#line 1468 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 171 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1474 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 172 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1480 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 173 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1486 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 174 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1492 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 175 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1498 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 176 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1504 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 177 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1510 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 178 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1516 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 181 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_plus", *(yyval.t).v);
    }
#line 1527 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 189 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_minus", *(yyval.t).v);
    }
#line 1537 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 196 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_multiply", *(yyval.t).v);
    }
#line 1548 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 204 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_divide", *(yyval.t).v);
    }
#line 1558 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 211 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_modulus", *(yyval.t).v);
    }
#line 1568 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 218 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_greater", *(yyval.t).v);
    }
#line 1578 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 225 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_smaller", *(yyval.t).v);
    }
#line 1588 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 232 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_equal", *(yyval.t).v);
    }
#line 1599 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 241 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1605 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 242 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1611 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 243 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).r = (yyvsp[0].t).r;}
#line 1617 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 246 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_and", *(yyval.t).v);
    }
#line 1628 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 254 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_or", *(yyval.t).v);
    }
#line 1639 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 262 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_not", *(yyval.t).v);
    }
#line 1649 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 270 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-2].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_fun", *(yyval.t).v);
    }
#line 1660 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 278 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).n = (mnlsp::ExpNode*)(new mnlsp::VarNode());
        ((mnlsp::VarNode*)(yyval.t).n)->vid = "_p" + *(yyvsp[-1].t).s;
    }
#line 1669 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 284 "src/mnlsp.y" /* yacc.c:1652  */
    {*(yyval.t).s = "_" + *(yyvsp[-1].t).s + *(yyvsp[0].t).s;}
#line 1675 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 285 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).s = new std::string();}
#line 1681 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 288 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n); (yyval.t).v->push_back((yyvsp[0].t).n);
    }
#line 1690 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 292 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[0].t).n);
    }
#line 1699 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 299 "src/mnlsp.y" /* yacc.c:1652  */
    {
        // $$.r = new mnlsp::RTE();
        // $$.r->set_fun(new mnlsp::ExpNode());
        // $$.r->add_params(*$3.v, true);
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back(new mnlsp::ExpNode(mnlsp::Data((yyvsp[-2].t).r)));
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_fun_call", *(yyval.t).v);
    }
#line 1713 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 308 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back(new mnlsp::ExpNode(*(yyvsp[-2].t).s, 0));
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[-1].t).v);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_fun_call", *(yyval.t).v);
    }
#line 1724 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 316 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-1].t).n);
        mnlsp::utl::v_concat((yyval.t).v, (yyvsp[0].t).v);
    }
#line 1734 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 321 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).v = mnlsp::utl::v_new();}
#line 1740 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 324 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1746 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 330 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).s = (yyvsp[0].t).s;}
#line 1752 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 334 "src/mnlsp.y" /* yacc.c:1652  */
    {
        (yyval.t).v = mnlsp::utl::v_new();
        (yyval.t).v->push_back((yyvsp[-3].t).n); (yyval.t).v->push_back((yyvsp[-2].t).n); (yyval.t).v->push_back((yyvsp[-1].t).n);
        (yyval.t).r = mnlsp::RTE::get_var_fun_rte("_if", *(yyval.t).v);
    }
#line 1762 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 341 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1768 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 344 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1774 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 347 "src/mnlsp.y" /* yacc.c:1652  */
    {(yyval.t).n = (yyvsp[0].t).n;}
#line 1780 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
    break;


#line 1784 "build/mnlsp.tab.cpp" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 350 "src/mnlsp.y" /* yacc.c:1918  */

void yyerror(const char* msg)
{
    #if DEBUG
        fprintf(stderr, "%s\n", msg);
    #else
        fprintf(stderr, "%s\n", msg);
    #endif
    exit(0);

    return;
}

int main()
{
    mnlsp::RTES* prtes = mnlsp::mnlsp_init();

    try
    {
        yyparse();
        prtes->eval(brte);
        /* printf(">>>\n"); */
    }
    catch(mnlsp::ErrPkt ep)
    {
        yyerror(ep.msg.c_str());
    }

    return 0;
}
