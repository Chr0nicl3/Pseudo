/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pseudo.grm" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdarg.h>
	#include <stdlib.h>
	#include "lex.yy.c"
	#include "pseudo.h"
	#include "interpreter.h"

	nodeType *opr(int oper, int nops, ...);
	nodeType *integer(int value);
	nodeType *flt(float value);
	nodeType *string(char *value);
	nodeType *id(int i);
	void freeNode(nodeType *p);
	data ex(nodeType *p);
	int yylex(void);
	void yyerror(char *);
	void runtimeError(char *);
	char *file_name;

	int enclosed = 0;

	//#define YYDEBUG 1

#line 91 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    NUM = 259,
    REAL = 260,
    STRING_LITERAL = 261,
    INT = 262,
    FLOAT = 263,
    STRING = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    POW_OP = 271,
    UMINUS = 272,
    POST_INC_OP = 273,
    PRE_INC_OP = 274,
    POST_DEC_OP = 275,
    PRE_DEC_OP = 276,
    AND_OP = 277,
    OR_OP = 278,
    MUL_ASSIGN = 279,
    DIV_ASSIGN = 280,
    MOD_ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    AND_ASSIGN = 284,
    XOR_ASSIGN = 285,
    OR_ASSIGN = 286,
    NEW_LINE = 287,
    INPUT = 288,
    PRINT = 289,
    END = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    FOR = 294,
    REPEAT = 295,
    UNTIL = 296,
    CONTINUE = 297,
    BREAK = 298,
    RETURN = 299,
    TO = 300
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define NUM 259
#define REAL 260
#define STRING_LITERAL 261
#define INT 262
#define FLOAT 263
#define STRING 264
#define INC_OP 265
#define DEC_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define POW_OP 271
#define UMINUS 272
#define POST_INC_OP 273
#define PRE_INC_OP 274
#define POST_DEC_OP 275
#define PRE_DEC_OP 276
#define AND_OP 277
#define OR_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define AND_ASSIGN 284
#define XOR_ASSIGN 285
#define OR_ASSIGN 286
#define NEW_LINE 287
#define INPUT 288
#define PRINT 289
#define END 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define FOR 294
#define REPEAT 295
#define UNTIL 296
#define CONTINUE 297
#define BREAK 298
#define RETURN 299
#define TO 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "pseudo.grm" /* yacc.c:355  */

	int iValue;
	float fValue;
	char *sValue;
	char sIndex;
	struct nodeType *nptr;

#line 229 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,     2,     2,    58,    52,     2,
      60,    61,    57,    55,    46,    56,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
      53,    47,    54,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    50,     2,    63,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    59,    61,    66,    68,    70,    72,    74,
      76,    81,    83,    88,    90,    95,    97,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   125,   127,   132,
     134,   139,   141,   146,   148,   153,   155,   160,   162,   167,
     169,   171,   176,   178,   180,   182,   184,   189,   191,   193,
     198,   200,   202,   204,   209,   211,   213,   218,   220,   222,
     224,   226,   228,   230,   235,   237,   239,   244,   246,   248,
     250,   252,   258,   260,   266,   265,   273,   272,   282,   288,
     297,   299,   301,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "NUM", "REAL",
  "STRING_LITERAL", "INT", "FLOAT", "STRING", "INC_OP", "DEC_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "POW_OP", "UMINUS", "POST_INC_OP",
  "PRE_INC_OP", "POST_DEC_OP", "PRE_DEC_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "NEW_LINE", "INPUT", "PRINT",
  "END", "IF", "ELSE", "WHILE", "FOR", "REPEAT", "UNTIL", "CONTINUE",
  "BREAK", "RETURN", "TO", "','", "'='", "'?'", "':'", "'|'", "'^'", "'&'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'%'", "'/'", "'('", "')'", "'!'",
  "'~'", "$accept", "begin", "program", "statement", "statement_list",
  "expression_statement", "expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "or_expression", "xor_expression",
  "and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "selection_statement", "loop_statement", "$@1", "$@2", "jump_statement",
  "io_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    44,    61,    63,    58,
     124,    94,    38,    60,    62,    43,    45,    42,    37,    47,
      40,    41,    33,   126
};
# endif

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     360,    23,  -118,  -118,  -118,   401,   401,  -118,   -54,   421,
     421,   421,    20,  -118,  -118,   435,   435,   374,   435,   435,
      35,   360,    26,  -118,     9,  -118,  -118,    -4,     6,   -10,
      12,    24,    58,    21,    28,    37,  -118,  -118,    87,  -118,
    -118,  -118,    55,  -118,   435,   435,   435,   435,   435,   435,
     435,   435,   435,  -118,   421,  -118,  -118,    95,    10,    11,
      34,    14,  -118,  -118,    47,    52,   -22,  -118,  -118,  -118,
     111,    88,  -118,   421,   435,   421,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    64,    65,    66,  -118,   360,  -118,   421,
     435,   435,  -118,  -118,  -118,     6,   -24,   -10,    12,    24,
      58,    21,    21,    28,    28,    28,    28,    37,    37,  -118,
    -118,  -118,   125,   126,   127,   174,   236,   360,    60,  -118,
    -118,   435,    99,   100,   101,   102,   103,   189,   251,   421,
    -118,  -118,  -118,  -118,  -118,   360,   105,    39,   298,  -118,
    -118,   106,   360,  -118,   313,   107,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,    69,    68,    70,     0,     0,    14,     0,     0,
       0,     0,     0,    79,    78,     0,     0,     0,     0,     0,
       0,     2,     0,     5,     0,    15,    17,    27,    29,    31,
      33,    35,    37,    39,    42,    47,    50,    54,    57,    64,
       6,     7,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    58,    59,     0,     0,     0,
       0,     0,    61,    60,     0,     0,     0,    62,    63,     1,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     8,    23,    24,    26,    22,    25,    19,
      21,    20,    18,     0,     0,     0,    80,     0,    74,     0,
       0,     0,    71,    10,    16,    30,     0,    32,    34,    36,
      38,    40,    41,    46,    45,    43,    44,    48,    49,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    81,    82,    83,    72,     0,     0,     0,     0,    75,
      76,     0,     0,    73,     0,     0,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -118,  -118,  -118,     0,  -117,  -118,    -8,    67,   -34,  -118,
      68,    70,    74,    77,    73,    29,     8,    32,   -11,   118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,   135,   136,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   137,   162,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    58,    59,    60,    62,    63,    57,    67,    68,    66,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    74,
     148,    70,    73,    61,    73,   141,    -4,    71,    76,    -4,
      -4,    -4,    -4,    82,    83,    69,    -4,    -4,   158,   112,
      77,    72,   106,   107,    75,   164,    66,    44,    45,    46,
      47,    48,    49,    50,    51,    73,    73,    73,    -4,    -4,
      -4,   109,    -4,    78,    -4,    -4,   108,   116,    -4,    -4,
      52,   160,    80,    81,    84,    85,    79,   129,   130,   131,
      73,    -4,    -4,    86,    87,    73,    -4,    93,    -4,    -4,
     123,   124,   125,   126,    88,    89,    90,    91,    92,   139,
     140,   138,   103,   104,   105,   149,    73,   150,   110,   121,
     122,    -3,    71,   111,    -3,    -3,    -3,    -3,   127,   128,
     113,    -3,    -3,    55,    56,   132,   133,   134,   142,   143,
     144,   151,   152,   153,   154,   155,   147,   159,   163,   166,
     114,   157,   115,    -3,    -3,    -3,   117,    -3,   147,    -3,
      -3,   118,   120,    -3,    -3,   119,     0,     0,   147,     0,
       0,     0,     0,     0,   147,     0,    -3,    -3,     0,     0,
       0,    -3,     0,    -3,    -3,    71,     0,   -11,   -11,   -11,
     -11,     0,     0,     0,   -11,   -11,     0,     0,     0,     0,
      71,     0,   -12,   -12,   -12,   -12,     0,     0,     0,   -12,
     -12,     0,     0,     0,     0,     0,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,     0,     0,   -11,   -11,     0,     0,
       0,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -11,
     -11,   -12,   -12,     0,   -11,     0,   -11,   -11,     0,     1,
       2,     3,     4,     0,   -12,   -12,     5,     6,     0,   -12,
       0,   -12,   -12,     0,     1,     2,     3,     4,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     7,     8,
       9,   145,    10,   146,    11,    12,     0,     0,    13,    14,
       0,     0,     0,     7,     8,     9,   156,    10,     0,    11,
      12,    15,    16,    13,    14,     0,    17,     0,    18,    19,
       0,     1,     2,     3,     4,     0,    15,    16,     5,     6,
       0,    17,     0,    18,    19,     0,     1,     2,     3,     4,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       7,     8,     9,   161,    10,     0,    11,    12,     0,     0,
      13,    14,     0,     0,     0,     7,     8,     9,   165,    10,
       0,    11,    12,    15,    16,    13,    14,     0,    17,     0,
      18,    19,     0,     1,     2,     3,     4,     0,    15,    16,
       5,     6,     0,    17,     0,    18,    19,     1,     2,     3,
       4,    64,     0,    65,     5,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    10,     0,    11,    12,
       0,     0,    13,    14,    53,     2,     3,     4,     0,     0,
       0,     5,     6,     0,     0,    15,    16,     0,     0,     0,
      17,     0,    18,    19,     1,     2,     3,     4,     0,    15,
      16,     5,     6,     0,    17,     0,    18,    19,    53,     2,
       3,     4,     0,     0,     0,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
       0,    54,     0,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
       0,    17,     0,    18,    19,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,    17,     0,    18,    19
};

static const yytype_int16 yycheck[] =
{
       0,     9,    10,    11,    15,    16,    60,    18,    19,    17,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    23,
     137,    21,    46,     3,    46,    49,     0,     1,    22,     3,
       4,     5,     6,    12,    13,     0,    10,    11,   155,    61,
      50,    32,    32,    32,    48,   162,    54,    24,    25,    26,
      27,    28,    29,    30,    31,    46,    46,    46,    32,    33,
      34,    47,    36,    51,    38,    39,    32,    75,    42,    43,
      47,    32,    14,    15,    53,    54,    52,    88,    89,    90,
      46,    55,    56,    55,    56,    46,    60,    32,    62,    63,
      82,    83,    84,    85,    57,    58,    59,    10,    11,   110,
     111,   109,     7,     8,     9,    45,    46,   141,    61,    80,
      81,     0,     1,    61,     3,     4,     5,     6,    86,    87,
      32,    10,    11,     5,     6,    61,    61,    61,     3,     3,
       3,    32,    32,    32,    32,    32,   136,    32,    32,    32,
      73,   149,    74,    32,    33,    34,    76,    36,   148,    38,
      39,    77,    79,    42,    43,    78,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,   164,    -1,    55,    56,    -1,    -1,
      -1,    60,    -1,    62,    63,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    55,
      56,    42,    43,    -1,    60,    -1,    62,    63,    -1,     3,
       4,     5,     6,    -1,    55,    56,    10,    11,    -1,    60,
      -1,    62,    63,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    55,    56,    42,    43,    -1,    60,    -1,    62,    63,
      -1,     3,     4,     5,     6,    -1,    55,    56,    10,    11,
      -1,    60,    -1,    62,    63,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      42,    43,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    55,    56,    42,    43,    -1,    60,    -1,
      62,    63,    -1,     3,     4,     5,     6,    -1,    55,    56,
      10,    11,    -1,    60,    -1,    62,    63,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    36,    -1,    38,    39,
      -1,    -1,    42,    43,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    -1,    62,    63,     3,     4,     5,     6,    -1,    55,
      56,    10,    11,    -1,    60,    -1,    62,    63,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    -1,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    10,    11,    32,    33,    34,
      36,    38,    39,    42,    43,    55,    56,    60,    62,    63,
      65,    66,    67,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    90,    91,    24,    25,    26,    27,    28,    29,
      30,    31,    47,     3,    60,    83,    83,    60,    70,    70,
      70,     3,    82,    82,     7,     9,    70,    82,    82,     0,
      67,     1,    32,    46,    23,    48,    22,    50,    51,    52,
      14,    15,    12,    13,    53,    54,    55,    56,    57,    58,
      59,    10,    11,    32,    72,    72,    72,    72,    72,    72,
      72,    72,    72,     7,     8,     9,    32,    32,    32,    47,
      61,    61,    61,    32,    71,    74,    70,    75,    76,    77,
      78,    79,    79,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    61,    61,    61,    67,    68,    88,    70,    82,
      82,    49,     3,     3,     3,    35,    37,    67,    68,    45,
      72,    32,    32,    32,    32,    32,    35,    70,    68,    32,
      32,    35,    89,    32,    68,    35,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    88,    87,    89,    87,    90,    90,
      91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     2,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     4,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     3,     6,     9,     0,     7,     0,    11,     1,     1,
       3,     6,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 56 "pseudo.grm" /* yacc.c:1646  */
    {exit(0);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "pseudo.grm" /* yacc.c:1646  */
    { ex((yyvsp[0].nptr)); freeNode((yyvsp[0].nptr));}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "pseudo.grm" /* yacc.c:1646  */
    { ex((yyvsp[0].nptr)); freeNode((yyvsp[0].nptr));}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 67 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 71 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 75 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "pseudo.grm" /* yacc.c:1646  */
    { yyerrok;}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(NEW_LINE, 2, (yyvsp[-1].nptr), (yyvsp[0].nptr)); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(NEW_LINE, 2, NULL, NULL); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(',', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 103 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 105 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(AND_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(OR_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(XOR_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 113 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(ADD_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 115 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(MUL_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 117 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(DIV_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 119 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(SUB_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 121 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(MOD_ASSIGN, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nptr)); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 128 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('?', 3, (yyvsp[-4].nptr), (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(OR_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 142 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(AND_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 149 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('|', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 154 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('^', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 161 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('&', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 168 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(EQ_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 172 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(NE_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 177 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 179 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('<', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('>', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 183 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(GE_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 185 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(LE_OP, 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 190 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 192 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('+', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 194 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('-', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 199 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 201 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('*', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 203 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('%', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 205 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('/', 2, (yyvsp[-2].nptr), (yyvsp[0].nptr)); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 210 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 212 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(INT, 1, (yyvsp[0].nptr)); }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 214 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(STRING, 1, (yyvsp[0].nptr)); }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 219 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 221 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(PRE_INC_OP, 1, (yyvsp[0].nptr)); }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 223 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(PRE_DEC_OP, 1, (yyvsp[0].nptr)); }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 225 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('-', 1, (yyvsp[0].nptr)); }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 227 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('+', 1, (yyvsp[0].nptr)); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 229 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('!', 1, (yyvsp[0].nptr)); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr('~', 1, (yyvsp[0].nptr)); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[0].nptr); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 238 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(POST_INC_OP, 1, (yyvsp[-1].nptr)); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 240 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(POST_DEC_OP, 1, (yyvsp[-1].nptr)); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = id((yyvsp[0].sIndex)); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 247 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = flt((yyvsp[0].fValue)); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 249 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = integer((yyvsp[0].iValue)); }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 251 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = string((yyvsp[0].sValue)); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 253 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = (yyvsp[-1].nptr); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 259 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(IF, 2, (yyvsp[-4].nptr), (yyvsp[-2].nptr)); }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 261 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(IF, 3, (yyvsp[-7].nptr), (yyvsp[-5].nptr), (yyvsp[-2].nptr)); }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 266 "pseudo.grm" /* yacc.c:1646  */
    {enclosed++;}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 268 "pseudo.grm" /* yacc.c:1646  */
    {
											enclosed--;
											(yyval.nptr) = opr(WHILE, 2, (yyvsp[-5].nptr), (yyvsp[-2].nptr));
										}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 273 "pseudo.grm" /* yacc.c:1646  */
    {enclosed++;}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 275 "pseudo.grm" /* yacc.c:1646  */
    { 	
											enclosed--;
											(yyval.nptr) = opr(FOR, 4, id((yyvsp[-9].sIndex)), (yyvsp[-7].nptr), (yyvsp[-5].nptr), (yyvsp[-2].nptr));
										}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 283 "pseudo.grm" /* yacc.c:1646  */
    {
											if(enclosed<=0)
												yyerror("Break Outside Loop :"); 
											(yyval.nptr) = opr(BREAK, 1, enclosed);
										}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 289 "pseudo.grm" /* yacc.c:1646  */
    {
											if(enclosed<=0)
												yyerror("Continue Outside Loop :"); 
											(yyval.nptr) = opr(CONTINUE, 1, enclosed);
										}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 298 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(PRINT, 1, (yyvsp[-1].nptr)); }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 300 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(INPUT, 2, string((yyvsp[-3].sValue)), id((yyvsp[-1].sIndex))); }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 302 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(INPUT, 2, string((yyvsp[-3].sValue)), id((yyvsp[-1].sIndex))); }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 304 "pseudo.grm" /* yacc.c:1646  */
    { (yyval.nptr) = opr(INPUT, 2, string((yyvsp[-3].sValue)), id((yyvsp[-1].sIndex))); }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2016 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 306 "pseudo.grm" /* yacc.c:1906  */

#define SIZEOF_NODETYPE ((char *)&p->con-(char *)p) 

nodeType *integer(int value){
	nodeType *p;
	/*allocate node*/

    if ((p = malloc(sizeof(nodeType))) == NULL) 
        yyerror("out of memory"); 

    /* copy information */ 

    p->type = typeInt; 
    p->con.value = value; 
    return p; 
}

nodeType *flt(float value){
	nodeType *p;

	/*allocate node*/

	if((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	/*copy information*/

	p->type = typeFloat;
	p->flt.value = value;
	return p;
}

nodeType *string(char *value){
	nodeType *p;

	/*allocate node*/
	//puts("in string");
	if((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	/*copy information*/
	p->type = typeString;
	p->str.value = value;
	//printf("value : %s\n", value);
	//printf("function : %s\n", p->str.value);
	return p;
}

nodeType *id(int i){
	nodeType *p;
	/*allocate node*/

	if((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");

	/*copy information*/

	p->type = typeId;
	p->id.i = i;
	return p;
}

nodeType *opr(int oper, int nops, ...){
	nodeType *p;
	va_list ap;

	/*allocate node and expand op[] array*/

	if((p = malloc(sizeof(nodeType) + (nops-1)*sizeof(nodeType *))) == NULL)
		yyerror("out of memory");

	/*copy information*/

	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for(int i=0; i<nops; ++i){
		p->opr.op[i]=va_arg(ap, nodeType *);
	}
	va_end(ap);
	return p;
}

void freeNode(nodeType *p){
	if(!p) return;
	if(p->type == typeOpr){
		for(int i=0; i<p->opr.nops; ++i){
			freeNode(p->opr.op[i]);
		}
	}
	free(p);
}

void yyerror(char *s){
	fprintf(stderr, "%s : %s %i:%i : near %s\n", file_name, s, lineCount, colCount, buffer);	
}


int main(int argc, char* argv[]){
	#if YYDEBUG
	        yydebug = 1; 
    #endif 
	if (argc > 1){
		FILE *file;
		file = fopen(argv[1], "r");
		if (!file){
			fprintf(stderr, "Could not open %s\n", argv[1]);
			exit(1);
		}
		file_name = argv[1];
		yyin = file;
	}
	yyparse();
	return 0;
}

