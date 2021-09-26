
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"

#include "yyfuncs.h"


/* Line 189 of yacc.c  */
#line 78 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADD_ASSIGN = 258,
     SUB_ASSIGN = 259,
     MUL_ASSIGN = 260,
     DIV_ASSIGN = 261,
     MOD_ASSIGN = 262,
     BIT_XOR_ASSIGN = 263,
     BIT_AND_ASSIGN = 264,
     BIT_OR_ASSIGN = 265,
     LEFT_SHIFT_ASSIGN = 266,
     RIGHT_SHIFT_ASSIGN = 267,
     LEFT_SHIFT = 268,
     RIGHT_SHIFT = 269,
     EQUAL = 270,
     NOT_EQUAL = 271,
     LESS_EQUAL = 272,
     GREATER_EQUAL = 273,
     AND = 274,
     OR = 275,
     INC = 276,
     DEC = 277,
     BOOL = 278,
     CHAR = 279,
     WCHAR_T = 280,
     SHORT = 281,
     LONG = 282,
     INT = 283,
     FLOAT = 284,
     DOUBLE = 285,
     SIGNED = 286,
     UNSIGNED = 287,
     STRING_T = 288,
     NAMESPACE = 289,
     ENUM = 290,
     CLASS = 291,
     STRUCT = 292,
     STATIC = 293,
     VIRTUAL = 294,
     VOID = 295,
     CONST = 296,
     OPERATOR = 297,
     TYPEDEF = 298,
     TYPENAME = 299,
     ABSTRACT = 300,
     GET = 301,
     SET = 302,
     CANDIDATE = 303,
     NOMETA = 304,
     NOCODE = 305,
     EXPORT = 306,
     OVERRIDE = 307,
     SCOPE = 308,
     IDENTIFY = 309,
     STRING = 310,
     U8STRING = 311,
     TEMPLATE = 312,
     DELEGATE = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 178 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNRULES -- Number of states.  */
#define YYNSTATES  484

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,     2,     2,    21,    16,     2,
       7,     8,    15,    17,     3,    19,     4,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     6,
      13,    25,    14,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     9,     2,    10,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    11,    22,    12,    23,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    17,    19,
      22,    25,    29,    32,    36,    38,    41,    44,    48,    51,
      55,    58,    62,    66,    71,    75,    80,    82,    85,    87,
      90,    92,    94,    96,    99,   101,   103,   107,   111,   113,
     117,   121,   126,   129,   131,   135,   137,   140,   142,   146,
     152,   159,   164,   171,   179,   185,   188,   193,   195,   200,
     202,   206,   208,   211,   213,   215,   217,   220,   223,   225,
     229,   234,   238,   242,   246,   250,   256,   262,   268,   274,
     277,   282,   286,   288,   291,   293,   296,   299,   304,   306,
     308,   311,   313,   317,   319,   321,   324,   326,   329,   331,
     335,   337,   339,   343,   348,   353,   358,   364,   367,   371,
     375,   380,   386,   392,   399,   406,   413,   420,   428,   436,
     438,   441,   444,   448,   452,   456,   461,   466,   471,   476,
     483,   490,   492,   495,   497,   500,   502,   506,   510,   515,
     520,   525,   531,   537,   539,   542,   546,   550,   554,   560,
     562,   565,   567,   570,   573,   576,   578,   581,   584,   589,
     591,   593,   595,   597,   599,   601,   603,   605,   607,   609,
     611,   613,   615,   617,   620,   623,   625,   627,   629,   631,
     633,   635,   637,   639,   641,   643,   645,   647,   649,   651,
     653,   655,   657,   659,   661,   663,   669,   676,   683,   691,
     694,   698,   702,   706,   712,   714,   717,   719,   722,   725,
     727,   730,   735,   741,   747,   750,   754,   758,   762,   768,
     771,   775,   777,   779,   781,   783,   785,   787,   789,   791,
     794,   797,   799,   802,   804,   806,   809,   812,   814,   818,
     823,   826,   832,   835,   841,   843,   847,   851,   856,   859,
     864,   866,   869,   871,   874,   876,   879,   881,   883,   887,
     891,   897,   900,   905,   911,   918,   920,   922,   924,   926,
     928,   930,   933,   936,   938,   941,   943,   945,   948,   951,
     956,   962,   963
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     154,     0,    -1,    63,    -1,    46,    -1,    47,    -1,    54,
      47,    -1,    55,    47,    -1,    48,    -1,    49,    -1,    49,
      51,    -1,    54,    49,    -1,    54,    49,    51,    -1,    55,
      49,    -1,    55,    49,    51,    -1,    50,    -1,    50,    51,
      -1,    54,    50,    -1,    54,    50,    51,    -1,    55,    50,
      -1,    55,    50,    51,    -1,    50,    50,    -1,    50,    50,
      51,    -1,    54,    50,    50,    -1,    54,    50,    50,    51,
      -1,    55,    50,    50,    -1,    55,    50,    50,    51,    -1,
      51,    -1,    54,    51,    -1,    54,    -1,    55,    51,    -1,
      55,    -1,    52,    -1,    53,    -1,    50,    53,    -1,    56,
      -1,    77,    -1,    77,    25,    78,    -1,    77,    25,    79,
      -1,    85,    -1,    86,     3,    85,    -1,     9,    86,    10,
      -1,     9,    86,     3,    10,    -1,     9,    10,    -1,    77,
      -1,    88,     3,    77,    -1,    77,    -1,    87,    77,    -1,
      89,    -1,    90,     3,    89,    -1,    58,    77,    11,    90,
      12,    -1,    58,    77,    11,    90,     3,    12,    -1,    58,
      77,    11,    12,    -1,    58,    59,    77,    11,    90,    12,
      -1,    58,    59,    77,    11,    90,     3,    12,    -1,    58,
      59,    77,    11,    12,    -1,    91,     6,    -1,    91,    25,
      78,     6,    -1,    77,    -1,    77,    13,    98,    14,    -1,
      93,    -1,    94,    76,    93,    -1,    94,    -1,    76,    94,
      -1,    84,    -1,    95,    -1,    96,    -1,    73,    96,    -1,
      72,    96,    -1,    97,    -1,    98,     3,    97,    -1,    66,
      97,    77,     6,    -1,    67,    77,     6,    -1,    58,    77,
       6,    -1,    60,    77,     6,    -1,    59,    77,     6,    -1,
      67,    77,    25,    78,     6,    -1,    58,    77,    25,    78,
       6,    -1,    60,    77,    25,    78,     6,    -1,    59,    77,
      25,    78,     6,    -1,    97,    77,    -1,    97,    77,     9,
      10,    -1,    97,    15,    77,    -1,   100,    -1,    64,   100,
      -1,   101,    -1,    61,   101,    -1,   102,     6,    -1,   102,
      25,    78,     6,    -1,    69,    -1,   104,    -1,   104,    17,
      -1,   105,    -1,   105,    25,    78,    -1,    70,    -1,   107,
      -1,   107,    19,    -1,   108,    -1,   108,    82,    -1,   109,
      -1,   109,    25,    78,    -1,    71,    -1,    77,    -1,    77,
       9,    10,    -1,    77,     9,    82,    10,    -1,    77,     9,
      15,    10,    -1,    77,     9,    97,    10,    -1,    77,     9,
      97,    15,    10,    -1,    97,   112,    -1,    97,    15,   112,
      -1,    97,    16,   112,    -1,   113,    11,    12,     6,    -1,
     113,    11,   106,    12,     6,    -1,   113,    11,   110,    12,
       6,    -1,   113,    11,   106,   110,    12,     6,    -1,   113,
      11,   110,   106,    12,     6,    -1,   113,    11,   106,   111,
      12,     6,    -1,   113,    11,   110,   111,    12,     6,    -1,
     113,    11,   106,   110,   111,    12,     6,    -1,   113,    11,
     110,   106,   111,    12,     6,    -1,   114,    -1,    61,   114,
      -1,    97,    77,    -1,    97,    16,    77,    -1,    97,    15,
      77,    -1,    97,    19,    77,    -1,    97,    15,    16,    77,
      -1,    97,    15,    15,    77,    -1,    97,    17,    16,    77,
      -1,    97,    17,    15,    77,    -1,    97,    17,     9,    10,
      16,    77,    -1,    97,    17,     9,    10,    15,    77,    -1,
     116,    -1,    64,   116,    -1,   117,    -1,   117,    82,    -1,
     118,    -1,   119,     3,   118,    -1,    77,     7,     8,    -1,
      77,     7,    63,     8,    -1,    77,     7,   119,     8,    -1,
      77,     7,     8,    64,    -1,    77,     7,    63,     8,    64,
      -1,    77,     7,   119,     8,    64,    -1,   120,    -1,    97,
     120,    -1,    97,    16,   120,    -1,    97,    15,   120,    -1,
      97,    17,   120,    -1,    97,    17,     9,    10,   120,    -1,
     121,    -1,    64,   121,    -1,   122,    -1,    68,   122,    -1,
      62,   122,    -1,    61,   122,    -1,   123,    -1,    75,   123,
      -1,   124,     6,    -1,   124,    25,    78,     6,    -1,    17,
      -1,    19,    -1,    15,    -1,    20,    -1,    21,    -1,    18,
      -1,    16,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    13,    -1,    14,    -1,     3,    -1,     9,    10,    -1,
       7,     8,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    36,
      -1,    37,    -1,    34,    -1,    35,    -1,    38,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    65,   126,     7,     8,     6,    -1,    65,
     126,     7,   119,     8,     6,    -1,    65,   126,     7,     8,
      64,     6,    -1,    65,   126,     7,   119,     8,    64,     6,
      -1,    97,   127,    -1,    97,    16,   127,    -1,    97,    15,
     127,    -1,    97,    17,   127,    -1,    97,    17,     9,    10,
     127,    -1,   128,    -1,    64,   128,    -1,   129,    -1,    68,
     129,    -1,    62,   129,    -1,   130,    -1,    75,   130,    -1,
      77,     7,     8,     6,    -1,    77,     7,    63,     8,     6,
      -1,    77,     7,   119,     8,     6,    -1,    97,   132,    -1,
      97,    16,   132,    -1,    97,    15,   132,    -1,    97,    17,
     132,    -1,    97,    17,     9,    10,   132,    -1,    81,   133,
      -1,    81,    64,   133,    -1,   103,    -1,   115,    -1,   125,
      -1,   131,    -1,   146,    -1,   134,    -1,    92,    -1,    99,
      -1,    73,   135,    -1,    72,   135,    -1,   135,    -1,    87,
     135,    -1,   136,    -1,     6,    -1,   137,   136,    -1,   137,
       6,    -1,    77,    -1,   138,     3,    77,    -1,    80,    13,
     138,    14,    -1,    59,    77,    -1,    59,     7,    88,     8,
      77,    -1,    60,    77,    -1,    60,     7,    88,     8,    77,
      -1,   140,    -1,   140,     5,    98,    -1,   141,    11,    12,
      -1,   141,    11,   137,    12,    -1,   142,     6,    -1,   142,
      25,    78,     6,    -1,   143,    -1,    68,   143,    -1,   144,
      -1,    75,   144,    -1,   145,    -1,   139,   145,    -1,    77,
      -1,   126,    -1,   147,     3,    77,    -1,   147,     3,   126,
      -1,    74,    77,    13,    98,    14,    -1,   148,     6,    -1,
     148,    11,    12,     6,    -1,   148,    11,   147,    12,     6,
      -1,   148,    11,   147,     3,    12,     6,    -1,   146,    -1,
     134,    -1,    92,    -1,   149,    -1,    99,    -1,   153,    -1,
      73,   150,    -1,    72,   150,    -1,   150,    -1,    87,   150,
      -1,   151,    -1,     6,    -1,   152,   151,    -1,   152,     6,
      -1,    57,    77,    11,    12,    -1,    57,    77,    11,   152,
      12,    -1,    -1,   152,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    65,    66,    67,    70,    71,
      74,    75,    76,    79,    80,    83,    84,    87,    88,    92,
      93,    94,    95,    96,    97,   100,   101,   104,   105,   108,
     109,   112,   113,   116,   117,   120,   121,   122,   125,   126,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   140,
     141,   142,   145,   146,   149,   150,   153,   154,   158,   161,
     162,   165,   166,   169,   172,   173,   176,   177,   180,   181,
     184,   187,   188,   189,   190,   191,   192,   195,   196,   197,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   211,
     212,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   228,   229,   232,   233,   236,   237,   240,   241,   242,
     243,   244,   245,   248,   249,   250,   251,   252,   253,   256,
     257,   260,   261,   262,   263,   266,   267,   270,   271,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   313,   314,   315,   316,   320,
     321,   322,   323,   324,   327,   328,   331,   332,   333,   336,
     337,   340,   341,   342,   345,   346,   347,   348,   349,   352,
     353,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   368,   369,   372,   373,   374,   375,   378,   379,   382,
     385,   386,   387,   388,   391,   392,   395,   396,   399,   400,
     403,   404,   407,   408,   411,   412,   416,   417,   418,   419,
     422,   425,   426,   427,   428,   432,   433,   434,   435,   436,
     437,   438,   439,   442,   443,   446,   447,   448,   449,   452,
     453,   456,   457
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "','", "'.'", "':'", "';'", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'<'", "'>'", "'*'", "'&'", "'+'", "'^'",
  "'-'", "'/'", "'%'", "'|'", "'~'", "'!'", "'='", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "BIT_XOR_ASSIGN",
  "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "LEFT_SHIFT", "RIGHT_SHIFT", "EQUAL", "NOT_EQUAL",
  "LESS_EQUAL", "GREATER_EQUAL", "AND", "OR", "INC", "DEC", "BOOL", "CHAR",
  "WCHAR_T", "SHORT", "LONG", "INT", "FLOAT", "DOUBLE", "SIGNED",
  "UNSIGNED", "STRING_T", "NAMESPACE", "ENUM", "CLASS", "STRUCT", "STATIC",
  "VIRTUAL", "VOID", "CONST", "OPERATOR", "TYPEDEF", "TYPENAME",
  "ABSTRACT", "GET", "SET", "CANDIDATE", "NOMETA", "NOCODE", "EXPORT",
  "OVERRIDE", "SCOPE", "IDENTIFY", "STRING", "U8STRING", "TEMPLATE",
  "DELEGATE", "'?'", "$accept", "primitive", "attribute", "attributeList",
  "attributes", "identifyList", "enumerator", "enumeratorList", "enum_0",
  "enum", "scopeName", "scopeNameList_0", "scopeNameList", "typeName_0",
  "typeName", "typeNameList", "typeAlias", "field_0", "field_1", "field_2",
  "field", "getter_0", "getter_1", "getter", "setter_0", "setter_1",
  "setter_2", "setter", "candidate", "property_0", "property_1",
  "property_2", "property", "parameter_0", "parameter_1", "parameter",
  "parameterList", "method_0", "method_1", "method_2", "method_3",
  "method_4", "method", "operatorSign", "operator_0", "operator_1",
  "operator_2", "operator_3", "operator", "delegate_0", "delegate_1",
  "delegate", "classMember_0", "classMember", "classMemberList",
  "templateParameterList", "templateParameters", "class_0", "class_1",
  "class_2", "class_3", "class_4", "class_5", "class", "tokenList",
  "templateClassInstance_0", "templateClassInstance", "namespaceMember_0",
  "namespaceMember", "namespaceMemberList", "namespace", "program", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    44,    46,    58,    59,    40,    41,    91,
      93,   123,   125,    60,    62,    42,    38,    43,    94,    45,
      47,    37,   124,   126,    33,    61,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   110,
     111,   112,   112,   112,   112,   112,   112,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   133,   133,   133,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   136,   137,   137,   137,   137,   138,   138,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   147,   147,   147,
     148,   149,   149,   149,   149,   150,   150,   150,   150,   150,
     150,   150,   150,   151,   151,   152,   152,   152,   152,   153,
     153,   154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     2,     3,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     1,     3,     3,     1,     3,
       3,     4,     2,     1,     3,     1,     2,     1,     3,     5,
       6,     4,     6,     7,     5,     2,     4,     1,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     1,     3,
       4,     3,     3,     3,     3,     5,     5,     5,     5,     2,
       4,     3,     1,     2,     1,     2,     2,     4,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     2,     1,     3,
       1,     1,     3,     4,     4,     4,     5,     2,     3,     3,
       4,     5,     5,     6,     6,     6,     6,     7,     7,     1,
       2,     2,     3,     3,     3,     4,     4,     4,     4,     6,
       6,     1,     2,     1,     2,     1,     3,     3,     4,     4,
       4,     5,     5,     1,     2,     3,     3,     3,     5,     1,
       2,     1,     2,     2,     2,     1,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     6,     6,     7,     2,
       3,     3,     3,     5,     1,     2,     1,     2,     2,     1,
       2,     4,     5,     5,     2,     3,     3,     3,     5,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     1,     1,     2,     2,     1,     3,     4,
       2,     5,     2,     5,     1,     3,     3,     4,     2,     4,
       1,     2,     1,     2,     1,     2,     1,     1,     3,     3,
       5,     2,     4,     5,     6,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     1,     1,     2,     2,     4,
       5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     281,   276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   269,
     266,     0,   244,     0,     0,   250,   252,   254,   265,     0,
     268,   273,   275,   282,   270,     0,    42,    35,    38,     0,
       0,     0,     0,     0,   240,     0,   242,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
       0,     0,    57,    63,    59,    61,    64,    65,     0,     0,
       0,     0,   251,   272,   271,     0,   253,     0,     0,     0,
     219,   274,    55,     0,   255,     0,     0,   248,     0,   261,
       0,   278,   277,     1,     0,     0,    40,     0,     0,    72,
       0,     0,    43,     0,    74,     0,     0,    73,     0,     9,
      20,    15,    33,     5,    10,    16,    27,     6,    12,    18,
      29,    67,    66,    62,     0,     0,     0,    71,     0,   240,
     242,     0,   237,     0,   220,     0,     0,     0,     0,   214,
       0,    68,   245,   234,   246,     0,     0,     0,     0,     0,
       0,     0,    57,     0,   227,     0,   228,    82,    84,     0,
     221,     0,   119,   222,   143,   149,   151,   155,     0,   223,
     204,   206,   209,   224,   226,   231,   233,     0,   225,     0,
     172,     0,     0,     0,   170,   171,   161,   165,   159,   164,
     160,   162,   163,   166,   167,   168,   169,   175,   176,   177,
     178,   179,   180,   181,   182,   185,   186,   183,   184,   187,
     188,   189,   190,   191,   192,   193,   194,   256,   257,     0,
      36,    37,    41,    39,   279,     0,     0,    51,    45,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    21,    11,
      22,    17,    13,    24,    19,     0,    60,    70,     0,     0,
       0,   239,   216,   215,     0,   217,     0,    56,     0,     0,
       0,    85,   120,   154,     0,     0,   153,   208,     0,    83,
     150,   205,   152,   207,    65,   230,    65,   229,     0,   156,
     210,     0,   232,     0,     0,     0,     0,    79,   107,   144,
     199,    86,     0,     0,   157,     0,   236,   247,   235,   249,
     174,   173,   262,     0,     0,   280,    54,     0,    46,     0,
      49,    76,    44,   241,    78,   243,    77,    23,    25,    58,
      75,   260,   238,     0,     0,     2,     0,     0,   131,   133,
     135,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,   137,     2,     0,    81,   108,   146,
     201,   101,   109,   145,   200,     0,   147,   202,     0,     0,
       0,     0,    88,    93,    89,    91,     0,    94,    96,    98,
       0,     0,     0,   258,   259,   263,     0,    52,    50,    48,
     218,   211,     0,   132,     0,     0,     0,     0,   121,   134,
       0,     0,     0,     0,     0,    81,     0,     0,   140,   138,
     139,     0,     0,     0,    80,     0,     0,     0,    87,   110,
      90,     0,     0,   100,     0,     0,    95,    97,     0,     0,
       0,     0,   158,   264,    53,   212,     0,     0,   123,   122,
       0,     0,     0,   124,   136,   213,     0,    80,   141,   142,
     102,   148,   203,     0,     0,   104,   103,   105,     0,    92,
     111,     0,     0,     0,    99,   112,     0,     0,     0,   126,
     125,     0,   128,   127,   195,     0,     0,   106,   113,     0,
     115,   114,     0,   116,     0,     0,   197,   196,     0,   117,
     118,   130,   129,   198
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    63,    38,    39,    16,   103,   230,   231,    17,    18,
      64,    65,    66,    67,   155,   142,    19,   157,   158,   159,
     160,   364,   365,   366,   367,   368,   369,   370,   415,   288,
     161,   162,   163,   328,   329,   330,   331,   164,   165,   166,
     167,   168,   169,   218,   290,   170,   171,   172,   173,   139,
      80,    20,   175,   176,   177,   133,    21,    22,    23,    24,
      25,    26,    27,    28,   219,    29,    30,    31,    32,    33,
      34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -272
static const yytype_int16 yypact[] =
{
     363,  -272,    28,   -25,   -13,    21,    23,  1041,   -21,   348,
     447,   447,   -15,   277,    64,   881,   447,    44,  -272,  -272,
    -272,   194,   146,   167,    49,  -272,  -272,  -272,  -272,   188,
    -272,  -272,  -272,   382,  -272,   195,  -272,   198,  -272,   230,
     226,   183,    43,   199,    54,   199,   144,  -272,  -272,  -272,
     238,   317,  -272,  -272,  -272,   324,   329,  -272,  -272,   541,
     541,   285,   364,  -272,  -272,   305,  -272,  -272,   316,   148,
      24,    26,  -272,  -272,  -272,   384,  -272,   318,  1041,    50,
    -272,  -272,  -272,   321,  -272,  1041,   154,  -272,   369,  -272,
     457,  -272,  -272,  -272,   336,    33,  -272,   274,   402,  -272,
      25,   373,  -272,   282,  -272,   374,   315,  -272,   380,  -272,
     377,  -272,  -272,  -272,   408,   376,  -272,  -272,   410,   395,
    -272,  -272,  -272,   305,  1041,   285,   428,  -272,   387,  -272,
    -272,  1041,  -272,   174,  -272,   390,   390,    15,   446,  -272,
     462,  -272,   500,  -272,  -272,   913,   945,  1073,   849,   781,
     781,   817,    40,   781,  -272,   159,  -272,  -272,  -272,   186,
    -272,   497,  -272,  -272,  -272,  -272,  -272,  -272,   222,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,   249,  -272,   503,
    -272,   502,   501,   506,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   247,
    -272,  -272,  -272,  -272,  -272,   344,    30,  -272,  -272,   439,
    -272,   253,   511,   441,   448,   517,   452,   518,  -272,  -272,
     480,  -272,  -272,   482,  -272,   261,  -272,  -272,   564,   270,
     494,  -272,  -272,  -272,   562,  -272,   643,  -272,  1041,  1073,
     142,  -272,  -272,  -272,  1073,   229,  -272,  -272,   262,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   977,  -272,
    -272,   676,  -272,    87,    88,     5,   780,   375,  -272,  -272,
    -272,  -272,   495,    92,  -272,   498,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,   523,   569,  -272,  -272,   260,  -272,    32,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,   390,   571,   570,  1041,    42,  -272,   499,
    -272,   335,  -272,   155,   505,   507,    20,    90,    90,   572,
      91,   284,  1073,   251,   516,   575,   356,   378,  -272,  -272,
    -272,   383,  -272,  -272,  -272,   576,  -272,  -272,   578,   559,
     592,   593,  -272,  -272,   584,   577,    51,   600,   521,   595,
     116,   617,   618,  -272,  -272,  -272,    39,  -272,  -272,  -272,
    -272,  -272,   619,  -272,   120,   549,   272,   550,  -272,  -272,
    1009,   622,   552,   553,   623,   572,   624,   553,  -272,   573,
     574,   606,    90,   709,   628,   630,   632,   350,  -272,  -272,
    -272,   565,   638,  -272,    75,   633,  -272,  -272,   568,   641,
      76,   636,  -272,  -272,  -272,  -272,   586,   587,  -272,  -272,
     639,   588,   589,  -272,  -272,  -272,   553,  -272,  -272,  -272,
    -272,  -272,  -272,    19,   358,  -272,  -272,  -272,   640,  -272,
    -272,   661,   656,   664,  -272,  -272,   665,   660,   667,  -272,
    -272,   417,  -272,  -272,  -272,   668,    70,  -272,  -272,   669,
    -272,  -272,   670,  -272,   603,   604,  -272,  -272,   671,  -272,
    -272,  -272,  -272,  -272
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,   590,  -272,   -84,   642,  -264,   460,  -272,   -69,
     579,   644,  -272,   -24,    -7,   220,   -64,  -126,   555,  -272,
    -272,  -272,  -272,   331,  -272,  -272,  -272,   337,  -100,   -93,
    -272,   557,  -272,   385,  -272,   319,  -271,  -154,  -144,  -133,
     561,  -272,  -272,  -263,  -265,  -121,   252,   563,  -272,  -130,
     635,   -59,   256,   531,  -272,  -272,  -272,  -272,  -272,  -272,
       0,    -2,   689,   -54,  -272,  -272,  -272,   347,   -29,   621,
    -272,  -272
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      68,   289,   153,   270,    92,   252,   253,   255,    79,    72,
     346,    76,   263,   266,   355,   272,   229,   154,   350,   354,
     357,   269,   156,   358,   254,   464,   271,   174,    43,   394,
      45,    43,   178,    45,     2,   121,   122,   227,    36,     2,
     374,     2,   306,   222,   378,   379,    41,   281,     2,    99,
      82,   424,    40,   124,   100,    87,    69,   384,   385,   386,
     104,   387,    75,   412,    42,   135,   136,   137,   101,    83,
     286,    79,   350,   354,    88,   350,   477,    77,   141,   105,
     154,   154,   339,   465,   154,   156,   156,   451,   456,   156,
     174,   174,   138,   153,   174,   178,   178,   339,    44,   178,
      46,   129,   228,   130,   361,    37,   289,   228,   154,   228,
      37,   289,   379,   156,   289,   270,   228,   141,   174,   388,
     270,   363,   413,   178,   141,   274,   276,   138,   419,   349,
     353,   356,   444,   269,   478,   426,   427,   442,   260,   265,
     268,   265,   229,   271,   265,   263,   413,   413,    72,    76,
     107,    85,   286,   286,   127,   286,   286,   334,   335,   336,
     143,   362,   363,     2,   347,   351,   144,   339,   395,   108,
     392,   393,   336,   128,   283,   284,   285,   250,    86,   289,
     349,   353,   356,   349,   353,   362,   349,   413,   251,   289,
     348,   352,   291,   380,    89,    93,    92,   428,   270,    90,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   292,     4,     5,     6,   145,   146,    58,   147,   287,
       7,     8,   148,    94,   286,   229,   149,   150,   294,   151,
      61,   152,   341,    95,    14,    15,   287,    97,   349,   353,
      96,   348,   352,   349,   337,   338,   285,   295,   441,   327,
     303,   332,   333,    70,    71,   296,   309,   265,     2,   304,
      98,   297,     9,   376,   258,   310,   397,   393,   336,    13,
     421,   343,   377,   258,   327,   319,   102,   340,   338,   285,
       1,   430,   441,     2,   321,   233,   224,   431,   432,   109,
     234,   281,   229,   396,   286,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   339,     4,     5,     6,
     145,   146,    58,   147,   452,     7,     8,   148,   233,   327,
     457,   149,   150,   236,   151,    61,   152,   286,   339,    14,
      15,     3,     4,     5,     6,   343,    70,    71,   390,   341,
       7,     8,     9,   391,   245,     9,    10,    11,    12,    13,
      91,   249,   407,     2,    14,    15,   305,    73,    74,   390,
     447,   390,    62,    81,   400,   448,   466,   110,   111,     1,
     112,   113,     2,   114,   115,   116,   117,   124,   118,   119,
     120,   125,   281,   327,   359,   281,  -101,   401,    91,  -101,
     281,     2,   401,   126,   407,   132,   327,   131,   267,   140,
     273,     3,     4,     5,     6,   275,   277,    70,    71,   282,
       7,     8,     9,   226,   220,   221,    10,    11,    12,    13,
       3,     4,     5,     6,    14,    15,   240,   241,   238,     7,
       8,     9,   474,   475,   247,    10,    11,    12,    13,     3,
       4,     5,     6,    14,    15,   243,   244,   179,     7,     8,
       9,   232,   235,   256,    10,    11,    12,    13,   237,   239,
     180,   242,    14,    15,   181,   248,   182,   138,   257,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   258,     3,     4,     5,     6,   293,   299,
     300,   301,   302,     7,     8,     9,   308,   311,   312,    10,
      11,    12,    13,   314,   316,   313,   180,    14,    15,   315,
     181,   317,   182,   318,   217,   372,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   404,
     320,   322,   323,   360,   405,   375,   371,   381,   382,   281,
     398,   389,   347,   399,   351,   403,   402,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   408,   409,
     373,   410,   411,   417,    58,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   440,    61,    62,   416,
     418,   405,    58,   422,   423,   425,   429,   433,   435,   395,
     339,    59,    60,   436,   437,    61,    62,   438,   439,  -102,
     445,   406,   446,   449,   450,   453,   454,   455,   458,   461,
     467,   324,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   459,   460,   462,   463,   468,   469,    58,
     470,   471,   472,   473,   476,   479,   480,   483,    59,    60,
     481,   482,    61,    62,   344,   223,   307,   106,   406,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     261,   420,   262,   414,   246,   123,   325,   326,   298,   434,
      84,   383,   279,   134,   280,    59,    60,   443,   225,    61,
      62,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,   345,
     326,     0,     0,     0,     0,     0,     0,     0,    59,    60,
       0,     0,    61,    62,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,    58,   326,     0,     0,     0,     0,     0,     0,
       0,    59,    60,   180,     0,    61,    62,   181,     0,   182,
       0,     0,     0,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     4,
       5,     6,   145,   146,    58,   147,     0,     7,     8,   148,
       0,     0,     0,   149,   150,     0,   151,    61,   152,     0,
       0,    14,    15,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,    70,    71,   278,   146,
      58,   264,     0,     0,     0,   148,     0,     0,     0,    59,
      60,     0,     0,    61,   152,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,    70,    71,
       0,     0,    58,   264,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,    61,   152,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,    78,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,    61,    62,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    58,   259,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,    61,
     152,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,    58,   264,
       0,     0,     0,     0,     0,     0,     0,    59,    60,     0,
       0,    61,   152,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
      58,   342,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,    61,   152,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,    58,   326,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,    61,    62,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,    61,    62,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,    61,
     152
};

static const yytype_int16 yycheck[] =
{
       7,   155,    86,   147,    33,   135,   136,   137,    15,     9,
     281,    13,   145,   146,     9,   148,   100,    86,   283,   284,
     285,   147,    86,   286,     9,     6,   147,    86,     7,     9,
       7,     7,    86,     7,     9,    59,    60,    12,    10,     9,
     303,     9,    12,    10,    12,   309,    59,     7,     9,     6,
       6,    12,    77,    13,    11,     6,    77,    15,    16,    17,
       6,    19,    77,    12,    77,    15,    16,    17,    25,    25,
      65,    78,   337,   338,    25,   340,     6,    13,    85,    25,
     149,   150,    77,    64,   153,   149,   150,    12,    12,   153,
     149,   150,    77,   177,   153,   149,   150,    77,    77,   153,
      77,    77,    77,    77,    12,    77,   260,    77,   177,    77,
      77,   265,   376,   177,   268,   259,    77,   124,   177,    77,
     264,    70,    71,   177,   131,   149,   150,    77,    12,   283,
     284,   285,   403,   259,    64,    15,    16,   402,   145,   146,
     147,   148,   226,   264,   151,   278,    71,    71,   148,   151,
       6,     5,    65,    65,     6,    65,    65,    15,    16,    17,
       6,    69,    70,     9,    77,    77,    12,    77,    77,    25,
      15,    16,    17,    25,    15,    16,    17,     3,    11,   333,
     334,   335,   336,   337,   338,    69,   340,    71,    14,   343,
     283,   284,     6,   323,     6,     0,   225,    77,   342,    11,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    25,    58,    59,    60,    61,    62,    63,    64,    77,
      66,    67,    68,    25,    65,   309,    72,    73,     6,    75,
      76,    77,    77,     3,    80,    81,    77,    11,   392,   393,
      10,   334,   335,   397,    15,    16,    17,    25,   402,   256,
       3,   258,   259,    59,    60,     6,     3,   264,     9,    12,
      77,    12,    68,     3,     3,    12,    15,    16,    17,    75,
     370,   278,    12,     3,   281,    14,    77,    15,    16,    17,
       6,     9,   436,     9,    14,     3,    12,    15,    16,    51,
       8,     7,   376,     9,    65,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    77,    58,    59,    60,
      61,    62,    63,    64,   414,    66,    67,    68,     3,   326,
     420,    72,    73,     8,    75,    76,    77,    65,    77,    80,
      81,    57,    58,    59,    60,   342,    59,    60,     3,    77,
      66,    67,    68,     8,   124,    68,    72,    73,    74,    75,
       6,   131,   359,     9,    80,    81,    12,    10,    11,     3,
      10,     3,    77,    16,     8,    15,     8,    50,    51,     6,
      53,    47,     9,    49,    50,    51,    47,    13,    49,    50,
      51,    76,     7,   390,     9,     7,    11,     9,     6,    11,
       7,     9,     9,    77,   401,    77,   403,    13,   146,    78,
     148,    57,    58,    59,    60,   149,   150,    59,    60,   153,
      66,    67,    68,    11,    78,    79,    72,    73,    74,    75,
      57,    58,    59,    60,    80,    81,    50,    51,    51,    66,
      67,    68,    15,    16,     6,    72,    73,    74,    75,    57,
      58,    59,    60,    80,    81,    50,    51,    78,    66,    67,
      68,    78,    78,     7,    72,    73,    74,    75,    78,    51,
       3,    51,    80,    81,     7,    78,     9,    77,     6,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     3,    57,    58,    59,    60,    11,     6,
       8,    10,     6,    66,    67,    68,    77,     6,    77,    72,
      73,    74,    75,     6,     6,    77,     3,    80,    81,    77,
       7,    51,     9,    51,    77,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    10,
       6,    77,    10,    78,    15,     6,    78,     6,     8,     7,
      64,    82,    77,     8,    77,     7,    10,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     6,     6,
      77,    17,    25,    82,    63,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    10,    76,    77,    19,
      25,    15,    63,     6,     6,     6,    77,    77,     6,    77,
      77,    72,    73,    10,    10,    76,    77,    64,    64,    11,
      10,    82,    10,    78,     6,    12,    78,     6,    12,    10,
      10,     8,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    77,    77,    77,    77,     6,    12,    63,
       6,     6,    12,     6,     6,     6,     6,     6,    72,    73,
      77,    77,    76,    77,     8,    95,   226,    45,    82,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     145,   370,   145,   366,   125,    61,    63,    64,   177,   390,
      21,   326,   151,    78,   151,    72,    73,     8,    97,    76,
      77,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    77,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,     3,    -1,    76,    77,     7,    -1,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    72,    73,    -1,    75,    76,    77,    -1,
      -1,    80,    81,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    77,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    59,    60,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    77,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    57,    58,    59,    60,    66,    67,    68,
      72,    73,    74,    75,    80,    81,    87,    91,    92,    99,
     134,   139,   140,   141,   142,   143,   144,   145,   146,   148,
     149,   150,   151,   152,   153,   154,    10,    77,    85,    86,
      77,    59,    77,     7,    77,     7,    77,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    63,    72,
      73,    76,    77,    84,    93,    94,    95,    96,    97,    77,
      59,    60,   143,   150,   150,    77,   144,    13,    64,    97,
     133,   150,     6,    25,   145,     5,    11,     6,    25,     6,
      11,     6,   151,     0,    25,     3,    10,    11,    77,     6,
      11,    25,    77,    88,     6,    25,    88,     6,    25,    51,
      50,    51,    53,    47,    49,    50,    51,    47,    49,    50,
      51,    96,    96,    94,    13,    76,    77,     6,    25,    77,
      77,    13,    77,   138,   133,    15,    16,    17,    77,   132,
      78,    97,    98,     6,    12,    61,    62,    64,    68,    72,
      73,    75,    77,    87,    92,    97,    99,   100,   101,   102,
     103,   113,   114,   115,   120,   121,   122,   123,   124,   125,
     128,   129,   130,   131,   134,   135,   136,   137,   146,    78,
       3,     7,     9,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    77,   126,   147,
      78,    79,    10,    85,    12,   152,    11,    12,    77,    87,
      89,    90,    78,     3,     8,    78,     8,    78,    51,    51,
      50,    51,    51,    50,    51,    98,    93,     6,    78,    98,
       3,    14,   132,   132,     9,   132,     7,     6,     3,    64,
      97,   101,   114,   122,    64,    97,   122,   129,    97,   100,
     121,   128,   122,   129,    96,   135,    96,   135,    61,   123,
     130,     7,   135,    15,    16,    17,    65,    77,   112,   120,
     127,     6,    25,    11,     6,    25,     6,    12,   136,     6,
       8,    10,     6,     3,    12,    12,    12,    90,    77,     3,
      12,     6,    77,    77,     6,    77,     6,    51,    51,    14,
       6,    14,    77,    10,     8,    63,    64,    97,   116,   117,
     118,   119,    97,    97,    15,    16,    17,    15,    16,    77,
      15,    77,    64,    97,     8,    63,   119,    77,   112,   120,
     127,    77,   112,   120,   127,     9,   120,   127,   126,     9,
      78,    12,    69,    70,   104,   105,   106,   107,   108,   109,
     110,    78,    12,    77,   126,     6,     3,    12,    12,    89,
     132,     6,     8,   116,    15,    16,    17,    19,    77,    82,
       3,     8,    15,    16,     9,    77,     9,    15,    64,     8,
       8,     9,    10,     7,    10,    15,    82,    97,     6,     6,
      17,    25,    12,    71,   110,   111,    19,    82,    25,    12,
     106,   111,     6,     6,    12,     6,    15,    16,    77,    77,
       9,    15,    16,    77,   118,     6,    10,    10,    64,    64,
      10,   120,   127,     8,   119,    10,    10,    10,    15,    78,
       6,    12,   111,    12,    78,     6,    12,   111,    12,    77,
      77,    10,    77,    77,     6,    64,     8,    10,     6,    12,
       6,     6,    12,     6,    15,    16,     6,     6,    64,     6,
       6,    77,    77,     6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 30 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_void);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 31 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_bool);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 32 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_char);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 33 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_schar);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 34 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uchar);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 35 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_wchar_t);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 36 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_short);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 37 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 38 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 39 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_short);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 40 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ushort);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 41 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ushort);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 42 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_long);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 43 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 44 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 45 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_long);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 46 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ulong);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 47 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulong);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 48 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_longlong);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 49 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 50 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 51 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_longlong);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 52 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulonglong);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 53 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_ulonglong);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 54 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 55 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_int);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 56 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 57 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uint);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 58 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_uint);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 59 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_float);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 60 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_double);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 61 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long_double);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 62 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_string_t);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 65 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (1)].sn), NULL, 0);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 66 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn), 0);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 67 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn), 1);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 70 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 71 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 74 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (3)].sn);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 75 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (4)].sn);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 76 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 79 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 80 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 83 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 84 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 87 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 88 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 92 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 93 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), NULL, (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 94 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 95 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 96 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 97 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 100 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setEnumSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 101 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setEnumSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 104 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 105 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 108 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 109 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 112 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 113 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 116 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 117 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 120 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 121 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setTypeNameFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 122 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setTypeNameFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 125 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 126 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 129 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 130 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 131 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 132 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 133 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 134 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 135 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), enum_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 136 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), value_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 137 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), reference_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 140 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn), NULL, NULL);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 141 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 142 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn), NULL, NULL);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 145 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 146 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 149 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 150 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 153 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setFieldSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 154 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setFieldSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 158 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 161 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 162 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setGetterIncRef((yyval.sn));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 165 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 166 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 169 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 172 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 173 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterDecRef((yyval.sn));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 176 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 177 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 180 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 181 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 184 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 187 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 188 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 189 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), list_property);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 191 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 192 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 195 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 196 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 197 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 200 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 201 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 202 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 203 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(4) - (6)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 204 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 205 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 206 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 207 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (7)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (7)].sn)); setPropertySetter((yyvsp[(1) - (7)].sn), (yyvsp[(4) - (7)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 208 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (7)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (7)].sn)); setPropertySetter((yyvsp[(1) - (7)].sn), (yyvsp[(3) - (7)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 211 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 212 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 216 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 217 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 218 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 219 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 220 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 221 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 222 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 223 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 224 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 225 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 228 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 229 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 232 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 233 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 236 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 237 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 240 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 241 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 242 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 243 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 244 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 245 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 248 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 249 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 250 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 251 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 252 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 253 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 256 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 257 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 260 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 261 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 262 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 263 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 266 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 267 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 270 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 271 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 313 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 314 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 315 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 316 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 320 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 321 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 322 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 323 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 324 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 327 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 328 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 331 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 332 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 333 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 336 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 337 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 340 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 341 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 342 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 345 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 346 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 347 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 348 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 349 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 352 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 353 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 356 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 357 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 358 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 359 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 360 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 361 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 362 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 363 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 364 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMemberFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 365 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMemberFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 368 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 369 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 372 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 373 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 374 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 375 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 378 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 379 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 382 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 385 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 386 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 387 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 388 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 391 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 392 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 395 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 396 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 399 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 400 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 403 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 404 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 407 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 408 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 411 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 412 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 416 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 417 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 418 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 419 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 422 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 425 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 426 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 427 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 428 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 432 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 433 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 434 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 435 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 436 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 437 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 438 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMemberFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 439 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMemberFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 442 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 443 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 446 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 447 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 448 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 449 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 452 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 453 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 456 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 457 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3717 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



