
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
     PRIMITIVE = 299,
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
     TEMPLATE = 311,
     DELEGATE = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 177 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#define YYFINAL  90
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   920

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  277
/* YYNRULES -- Number of states.  */
#define YYNSTATES  472

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      13,    25,    14,    81,     2,     2,     2,     2,     2,     2,
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
      78,    79,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    17,    19,
      22,    25,    29,    32,    36,    38,    41,    44,    48,    51,
      55,    58,    62,    66,    71,    75,    80,    82,    85,    87,
      90,    92,    94,    96,    99,   101,   105,   107,   109,   113,
     117,   122,   125,   127,   131,   133,   136,   138,   142,   148,
     155,   160,   167,   175,   181,   184,   189,   191,   196,   198,
     202,   204,   207,   209,   211,   213,   217,   222,   226,   230,
     234,   238,   244,   250,   256,   262,   265,   270,   274,   276,
     279,   281,   284,   287,   292,   294,   296,   299,   301,   305,
     307,   309,   312,   314,   317,   319,   323,   325,   327,   331,
     336,   341,   346,   352,   355,   359,   364,   370,   376,   383,
     390,   397,   404,   412,   420,   422,   425,   428,   432,   436,
     440,   445,   450,   455,   460,   467,   474,   476,   479,   481,
     484,   486,   490,   494,   499,   504,   509,   515,   521,   523,
     526,   530,   534,   538,   544,   546,   549,   551,   554,   557,
     560,   562,   565,   568,   573,   575,   577,   579,   581,   583,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   604,
     607,   609,   611,   613,   615,   617,   619,   621,   623,   625,
     627,   629,   631,   633,   635,   637,   639,   641,   643,   645,
     647,   653,   660,   667,   675,   678,   682,   686,   690,   696,
     698,   701,   703,   706,   709,   711,   714,   719,   725,   731,
     734,   738,   742,   746,   752,   755,   759,   761,   763,   765,
     767,   769,   771,   773,   775,   778,   781,   783,   786,   788,
     790,   793,   796,   798,   802,   807,   810,   816,   819,   825,
     827,   831,   835,   840,   843,   848,   850,   853,   855,   858,
     860,   863,   865,   867,   871,   875,   881,   884,   889,   895,
     902,   904,   906,   908,   910,   912,   914,   917,   920,   922,
     925,   927,   929,   932,   935,   940,   946,   947
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     152,     0,    -1,    63,    -1,    46,    -1,    47,    -1,    54,
      47,    -1,    55,    47,    -1,    48,    -1,    49,    -1,    49,
      51,    -1,    54,    49,    -1,    54,    49,    51,    -1,    55,
      49,    -1,    55,    49,    51,    -1,    50,    -1,    50,    51,
      -1,    54,    50,    -1,    54,    50,    51,    -1,    55,    50,
      -1,    55,    50,    51,    -1,    50,    50,    -1,    50,    50,
      51,    -1,    54,    50,    50,    -1,    54,    50,    50,    51,
      -1,    55,    50,    50,    -1,    55,    50,    50,    51,    -1,
      51,    -1,    54,    51,    -1,    54,    -1,    55,    51,    -1,
      55,    -1,    52,    -1,    53,    -1,    50,    53,    -1,    56,
      -1,    77,    25,    78,    -1,    77,    -1,    84,    -1,    85,
       3,    84,    -1,     9,    85,    10,    -1,     9,    85,     3,
      10,    -1,     9,    10,    -1,    77,    -1,    87,     3,    77,
      -1,    77,    -1,    86,    77,    -1,    88,    -1,    89,     3,
      88,    -1,    58,    77,    11,    89,    12,    -1,    58,    77,
      11,    89,     3,    12,    -1,    58,    77,    11,    12,    -1,
      58,    59,    77,    11,    89,    12,    -1,    58,    59,    77,
      11,    89,     3,    12,    -1,    58,    59,    77,    11,    12,
      -1,    90,     6,    -1,    90,    25,    78,     6,    -1,    77,
      -1,    77,    13,    96,    14,    -1,    92,    -1,    93,    76,
      92,    -1,    93,    -1,    76,    93,    -1,    83,    -1,    94,
      -1,    95,    -1,    96,     3,    95,    -1,    66,    95,    77,
       6,    -1,    67,    77,     6,    -1,    58,    77,     6,    -1,
      60,    77,     6,    -1,    59,    77,     6,    -1,    67,    77,
      25,    78,     6,    -1,    58,    77,    25,    78,     6,    -1,
      60,    77,    25,    78,     6,    -1,    59,    77,    25,    78,
       6,    -1,    95,    77,    -1,    95,    77,     9,    10,    -1,
      95,    15,    77,    -1,    98,    -1,    64,    98,    -1,    99,
      -1,    61,    99,    -1,   100,     6,    -1,   100,    25,    78,
       6,    -1,    69,    -1,   102,    -1,   102,    17,    -1,   103,
      -1,   103,    25,    78,    -1,    70,    -1,   105,    -1,   105,
      19,    -1,   106,    -1,   106,    81,    -1,   107,    -1,   107,
      25,    78,    -1,    71,    -1,    77,    -1,    77,     9,    10,
      -1,    77,     9,    81,    10,    -1,    77,     9,    15,    10,
      -1,    77,     9,    95,    10,    -1,    77,     9,    95,    15,
      10,    -1,    95,   110,    -1,    95,    15,   110,    -1,   111,
      11,    12,     6,    -1,   111,    11,   104,    12,     6,    -1,
     111,    11,   108,    12,     6,    -1,   111,    11,   104,   108,
      12,     6,    -1,   111,    11,   108,   104,    12,     6,    -1,
     111,    11,   104,   109,    12,     6,    -1,   111,    11,   108,
     109,    12,     6,    -1,   111,    11,   104,   108,   109,    12,
       6,    -1,   111,    11,   108,   104,   109,    12,     6,    -1,
     112,    -1,    61,   112,    -1,    95,    77,    -1,    95,    16,
      77,    -1,    95,    15,    77,    -1,    95,    19,    77,    -1,
      95,    15,    16,    77,    -1,    95,    15,    15,    77,    -1,
      95,    17,    16,    77,    -1,    95,    17,    15,    77,    -1,
      95,    17,     9,    10,    16,    77,    -1,    95,    17,     9,
      10,    15,    77,    -1,   114,    -1,    64,   114,    -1,   115,
      -1,   115,    81,    -1,   116,    -1,   117,     3,   116,    -1,
      77,     7,     8,    -1,    77,     7,    63,     8,    -1,    77,
       7,   117,     8,    -1,    77,     7,     8,    64,    -1,    77,
       7,    63,     8,    64,    -1,    77,     7,   117,     8,    64,
      -1,   118,    -1,    95,   118,    -1,    95,    16,   118,    -1,
      95,    15,   118,    -1,    95,    17,   118,    -1,    95,    17,
       9,    10,   118,    -1,   119,    -1,    64,   119,    -1,   120,
      -1,    68,   120,    -1,    62,   120,    -1,    61,   120,    -1,
     121,    -1,    75,   121,    -1,   122,     6,    -1,   122,    25,
      78,     6,    -1,    17,    -1,    19,    -1,    15,    -1,    20,
      -1,    21,    -1,    18,    -1,    16,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    13,    -1,    14,    -1,     3,
      -1,     9,    10,    -1,     7,     8,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    36,    -1,    37,    -1,    34,    -1,    35,
      -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,
      -1,    43,    -1,    44,    -1,    45,    -1,    65,   124,     7,
       8,     6,    -1,    65,   124,     7,   117,     8,     6,    -1,
      65,   124,     7,     8,    64,     6,    -1,    65,   124,     7,
     117,     8,    64,     6,    -1,    95,   125,    -1,    95,    16,
     125,    -1,    95,    15,   125,    -1,    95,    17,   125,    -1,
      95,    17,     9,    10,   125,    -1,   126,    -1,    64,   126,
      -1,   127,    -1,    68,   127,    -1,    62,   127,    -1,   128,
      -1,    75,   128,    -1,    77,     7,     8,     6,    -1,    77,
       7,    63,     8,     6,    -1,    77,     7,   117,     8,     6,
      -1,    95,   130,    -1,    95,    16,   130,    -1,    95,    15,
     130,    -1,    95,    17,   130,    -1,    95,    17,     9,    10,
     130,    -1,    80,   131,    -1,    80,    64,   131,    -1,   101,
      -1,   113,    -1,   123,    -1,   129,    -1,   144,    -1,   132,
      -1,    91,    -1,    97,    -1,    73,   133,    -1,    72,   133,
      -1,   133,    -1,    86,   133,    -1,   134,    -1,     6,    -1,
     135,   134,    -1,   135,     6,    -1,    77,    -1,   136,     3,
      77,    -1,    79,    13,   136,    14,    -1,    59,    77,    -1,
      59,     7,    87,     8,    77,    -1,    60,    77,    -1,    60,
       7,    87,     8,    77,    -1,   138,    -1,   138,     5,    96,
      -1,   139,    11,    12,    -1,   139,    11,   135,    12,    -1,
     140,     6,    -1,   140,    25,    78,     6,    -1,   141,    -1,
      68,   141,    -1,   142,    -1,    75,   142,    -1,   143,    -1,
     137,   143,    -1,    77,    -1,   124,    -1,   145,     3,    77,
      -1,   145,     3,   124,    -1,    74,    77,    13,    96,    14,
      -1,   146,     6,    -1,   146,    11,    12,     6,    -1,   146,
      11,   145,    12,     6,    -1,   146,    11,   145,     3,    12,
       6,    -1,   144,    -1,   132,    -1,    91,    -1,   147,    -1,
      97,    -1,   151,    -1,    73,   148,    -1,    72,   148,    -1,
     148,    -1,    86,   148,    -1,   149,    -1,     6,    -1,   150,
     149,    -1,   150,     6,    -1,    57,    77,    11,    12,    -1,
      57,    77,    11,   150,    12,    -1,    -1,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    65,    66,    69,    70,    73,
      74,    75,    78,    79,    82,    83,    86,    87,    91,    92,
      93,    94,    95,    96,    99,   100,   103,   104,   107,   108,
     111,   112,   115,   116,   119,   120,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   134,   135,   136,   139,   140,
     143,   144,   147,   148,   152,   155,   156,   159,   160,   163,
     166,   167,   170,   171,   174,   175,   178,   181,   182,   183,
     184,   185,   186,   189,   190,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   204,   205,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   221,   222,   225,   226,
     229,   230,   233,   234,   235,   236,   237,   238,   241,   242,
     243,   244,   245,   246,   249,   250,   253,   254,   255,   256,
     259,   260,   263,   264,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     306,   307,   308,   309,   313,   314,   315,   316,   317,   320,
     321,   324,   325,   326,   329,   330,   333,   334,   335,   338,
     339,   340,   341,   342,   345,   346,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   361,   362,   365,   366,
     367,   368,   371,   372,   375,   378,   379,   380,   381,   384,
     385,   388,   389,   392,   393,   396,   397,   400,   401,   404,
     405,   409,   410,   411,   412,   415,   418,   419,   420,   421,
     425,   426,   427,   428,   429,   430,   431,   432,   435,   436,
     439,   440,   441,   442,   445,   446,   449,   450
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
  "VIRTUAL", "VOID", "CONST", "OPERATOR", "TYPEDEF", "PRIMITIVE",
  "ABSTRACT", "GET", "SET", "CANDIDATE", "NOMETA", "NOCODE", "EXPORT",
  "OVERRIDE", "SCOPE", "IDENTIFY", "STRING", "TEMPLATE", "DELEGATE", "'?'",
  "$accept", "primitive", "attribute", "attributeList", "attributes",
  "identifyList", "enumerator", "enumeratorList", "enum_0", "enum",
  "scopeName", "scopeNameList_0", "scopeNameList", "typeName",
  "typeNameList", "typeAlias", "field_0", "field_1", "field_2", "field",
  "getter_0", "getter_1", "getter", "setter_0", "setter_1", "setter_2",
  "setter", "candidate", "property_0", "property_1", "property_2",
  "property", "parameter_0", "parameter_1", "parameter", "parameterList",
  "method_0", "method_1", "method_2", "method_3", "method_4", "method",
  "operatorSign", "operator_0", "operator_1", "operator_2", "operator_3",
  "operator", "delegate_0", "delegate_1", "delegate", "classMember_0",
  "classMember", "classMemberList", "templateParameterList",
  "templateParameters", "class_0", "class_1", "class_2", "class_3",
  "class_4", "class_5", "class", "tokenList", "templateClassInstance_0",
  "templateClassInstance", "namespaceMember_0", "namespaceMember",
  "namespaceMemberList", "namespace", "program", 0
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
     312,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     106,   106,   107,   107,   108,   108,   109,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   128,   129,   129,   130,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   135,   135,
     135,   135,   136,   136,   137,   138,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   145,   145,   146,   147,   147,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   150,   150,   151,   151,   152,   152
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     2,     3,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     3,     3,
       4,     2,     1,     3,     1,     2,     1,     3,     5,     6,
       4,     6,     7,     5,     2,     4,     1,     4,     1,     3,
       1,     2,     1,     1,     1,     3,     4,     3,     3,     3,
       3,     5,     5,     5,     5,     2,     4,     3,     1,     2,
       1,     2,     2,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     2,     1,     3,     1,     1,     3,     4,
       4,     4,     5,     2,     3,     4,     5,     5,     6,     6,
       6,     6,     7,     7,     1,     2,     2,     3,     3,     3,
       4,     4,     4,     4,     6,     6,     1,     2,     1,     2,
       1,     3,     3,     4,     4,     4,     5,     5,     1,     2,
       3,     3,     3,     5,     1,     2,     1,     2,     2,     2,
       1,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     6,     6,     7,     2,     3,     3,     3,     5,     1,
       2,     1,     2,     2,     1,     2,     4,     5,     5,     2,
       3,     3,     3,     5,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     1,     1,
       2,     2,     1,     3,     4,     2,     5,     2,     5,     1,
       3,     3,     4,     2,     4,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     3,     5,     2,     4,     5,     6,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     2,     2,     4,     5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     276,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,   264,
     261,     0,   239,     0,     0,   245,   247,   249,   260,     0,
     263,   268,   270,   277,   265,     0,    41,    36,    37,     0,
       0,     0,     0,     0,   235,     0,   237,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
      56,    62,    58,    60,    63,     0,     0,     0,     0,   246,
     267,   266,     0,   248,     0,     0,     0,   214,   269,    54,
       0,   250,     0,     0,   243,     0,   256,     0,   273,   272,
       1,     0,     0,    39,     0,     0,    68,     0,     0,    42,
       0,    70,     0,     0,    69,     0,     9,    20,    15,    33,
       5,    10,    16,    27,     6,    12,    18,    29,    61,     0,
       0,     0,    67,     0,   235,   237,     0,   232,     0,   215,
       0,     0,     0,     0,   209,     0,    64,   240,   229,   241,
       0,     0,     0,     0,     0,     0,     0,    56,     0,   222,
       0,   223,    78,    80,     0,   216,     0,   114,   217,   138,
     144,   146,   150,     0,   218,   199,   201,   204,   219,   221,
     226,   228,     0,   220,     0,   167,     0,     0,     0,   165,
     166,   156,   160,   154,   159,   155,   157,   158,   161,   162,
     163,   164,   170,   171,   172,   173,   174,   175,   176,   177,
     180,   181,   178,   179,   182,   183,   184,   185,   186,   187,
     188,   189,   251,   252,     0,    35,    40,    38,   274,     0,
       0,    50,    44,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    21,    11,    22,    17,    13,    24,    19,     0,
      59,    66,     0,     0,     0,   234,   211,   210,     0,   212,
       0,    55,     0,     0,     0,    81,   115,   149,     0,     0,
     148,   203,     0,    79,   145,   200,   147,   202,   225,   224,
       0,   151,   205,     0,   227,     0,     0,     0,     0,    75,
     103,   139,   194,    82,     0,     0,   152,     0,   231,   242,
     230,   244,   169,   168,   257,     0,     0,   275,    53,     0,
      45,     0,    48,    72,    43,   236,    74,   238,    73,    23,
      25,    57,    71,   255,   233,     0,     0,     2,     0,     0,
     126,   128,   130,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,   132,     2,     0,    77,   104,
     141,   196,   140,   195,     0,   142,   197,     0,     0,     0,
       0,    84,    89,    85,    87,     0,    90,    92,    94,     0,
       0,     0,   253,   254,   258,     0,    51,    49,    47,   213,
     206,     0,   127,     0,     0,     0,     0,   116,   129,     0,
       0,     0,     0,    77,     0,     0,   135,   133,   134,     0,
       0,     0,    76,     0,     0,     0,    83,   105,    86,     0,
       0,    96,     0,     0,    91,    93,     0,     0,     0,     0,
     153,   259,    52,   207,     0,     0,   118,   117,     0,     0,
       0,   119,   131,   208,     0,    76,   136,   137,    98,   143,
     198,     0,     0,   100,    99,   101,     0,    88,   106,     0,
       0,     0,    95,   107,     0,     0,     0,   121,   120,     0,
     123,   122,   190,     0,     0,   102,   108,     0,   110,   109,
       0,   111,     0,     0,   192,   191,     0,   112,   113,   125,
     124,   193
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    38,    39,    16,   100,   224,   225,    17,    18,
      62,    63,    64,   150,   137,    19,   152,   153,   154,   155,
     353,   354,   355,   356,   357,   358,   359,   403,   280,   156,
     157,   158,   320,   321,   322,   323,   159,   160,   161,   162,
     163,   164,   213,   282,   165,   166,   167,   168,   134,    77,
      20,   170,   171,   172,   128,    21,    22,    23,    24,    25,
      26,    27,    28,   214,    29,    30,    31,    32,    33,    34,
      35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -262
static const yytype_int16 yypact[] =
{
     419,  -262,    76,   -47,    88,     7,    14,   793,   -44,    98,
     492,   492,    41,   382,   175,   698,   492,   146,  -262,  -262,
    -262,   405,   144,   223,   250,  -262,  -262,  -262,  -262,   353,
    -262,  -262,  -262,   443,  -262,   244,  -262,   255,  -262,   245,
     249,   205,   139,   221,   256,   221,   322,  -262,  -262,  -262,
     261,   454,  -262,  -262,  -262,   538,   564,  -262,  -262,   308,
     461,  -262,  -262,   344,  -262,   411,   336,    19,    21,  -262,
    -262,  -262,   484,  -262,   436,   793,    54,  -262,  -262,  -262,
     446,  -262,   793,   150,  -262,   463,  -262,    22,  -262,  -262,
    -262,   475,    77,  -262,   265,   544,  -262,    65,   490,  -262,
     327,  -262,   506,   372,  -262,   513,  -262,   470,  -262,  -262,
    -262,   518,   495,  -262,  -262,   519,   497,  -262,   344,   793,
     308,   599,  -262,   528,  -262,  -262,   793,  -262,   235,  -262,
     530,   530,    63,   605,  -262,   631,  -262,   635,  -262,  -262,
     717,   736,   811,   679,   644,   644,   407,   499,   644,  -262,
     159,  -262,  -262,  -262,   337,  -262,   629,  -262,  -262,  -262,
    -262,  -262,  -262,   420,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   241,  -262,   637,  -262,   636,   638,   639,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   303,  -262,  -262,  -262,  -262,   364,
      91,  -262,  -262,   570,  -262,   324,   645,   572,   576,   683,
     624,   703,  -262,  -262,   662,  -262,  -262,   663,  -262,   357,
    -262,  -262,   709,   360,   641,  -262,  -262,  -262,   712,  -262,
     302,  -262,   793,   811,   177,  -262,  -262,  -262,   811,   269,
    -262,  -262,   431,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     755,  -262,  -262,   546,  -262,    48,    90,    86,   643,   609,
    -262,  -262,  -262,  -262,   658,   203,  -262,   659,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   374,   734,  -262,  -262,   469,
    -262,    92,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   530,   735,   749,   793,   242,
    -262,   677,  -262,   432,  -262,   252,   682,   699,    64,    90,
     753,   163,   178,   811,   352,   713,   770,   511,   610,  -262,
    -262,  -262,  -262,  -262,   769,  -262,  -262,   788,   480,   790,
     791,  -262,  -262,   781,   789,   161,   796,   752,   792,   170,
     810,   828,  -262,  -262,  -262,    93,  -262,  -262,  -262,  -262,
    -262,   829,  -262,   107,   759,   418,   775,  -262,  -262,   774,
     847,   777,   845,   753,   858,   699,  -262,   807,   808,   527,
      90,   578,   862,   865,   866,   510,  -262,  -262,  -262,   799,
     872,  -262,   120,   867,  -262,  -262,   802,   875,   136,   870,
    -262,  -262,  -262,  -262,   806,   809,  -262,  -262,   874,   812,
     813,  -262,  -262,  -262,   699,  -262,  -262,  -262,  -262,  -262,
    -262,   214,   536,  -262,  -262,  -262,   881,  -262,  -262,   879,
     880,   887,  -262,  -262,   888,   883,   890,  -262,  -262,   547,
    -262,  -262,  -262,   891,   215,  -262,  -262,   892,  -262,  -262,
     893,  -262,   823,   824,  -262,  -262,   896,  -262,  -262,  -262,
    -262,  -262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,   814,  -262,   -82,   859,  -193,   685,  -262,   -65,
     783,   848,  -262,    -7,   363,   -63,  -129,   768,  -262,  -262,
    -262,  -262,   550,  -262,  -262,  -262,   555,  -242,  -165,  -262,
     771,  -262,   594,  -262,   534,  -261,  -148,  -138,  -124,   772,
    -262,  -262,   -43,  -253,  -132,   397,   773,  -262,  -125,   839,
     -56,   491,   743,  -262,  -262,  -262,  -262,  -262,  -262,     0,
      -2,   895,   -51,  -262,  -262,  -262,   254,   -30,   826,  -262,
    -262
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      65,   148,   281,    89,   264,   246,   247,   249,    76,    69,
     265,    73,   337,   263,    43,   223,   257,   260,   149,   266,
     151,    45,   341,   343,   346,   175,    43,   169,    45,   176,
      40,   177,   173,    66,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    76,   130,
     131,   132,   248,   382,     2,   136,   341,   221,   341,   149,
     149,   151,   151,   149,    44,   151,    36,   216,   169,   169,
     148,    46,   169,   173,   173,   344,   124,   173,   125,   212,
       2,     2,     2,   298,   367,   412,   281,   149,   368,   151,
     339,   281,   136,   278,   281,   264,   169,   409,    72,   136,
     264,   173,   414,   415,   263,   338,   265,   340,   342,   345,
     432,   133,   439,   254,   259,   262,   259,   430,   223,   259,
     133,   330,   222,    69,    73,    96,   257,    41,   444,    82,
      97,   278,    79,    37,    37,   278,   138,    67,    68,     2,
     440,   339,   139,   330,    98,    42,   445,   330,   222,   222,
     222,    80,   368,   400,   275,   276,   277,   281,   340,   342,
     345,   340,   407,   340,   416,   273,   281,   384,    74,    89,
     369,   401,   326,   327,   328,   264,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   401,     4,     5,
       6,   140,   141,    58,   142,   350,     7,     8,   143,   223,
     452,   465,   144,   145,   278,   146,    59,   147,   278,    14,
      15,   352,   401,   340,    83,   347,   279,   340,   244,   351,
     383,   401,   429,   319,    90,   324,   325,   288,    92,   245,
       2,   259,   363,   289,   279,    93,    84,   373,   374,   375,
      94,   376,   101,   334,    70,    71,   319,   381,   327,   328,
      78,     1,   351,   352,     2,    85,   429,   218,   453,   466,
      91,   102,    95,   223,   329,   276,   277,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    99,     4,
       5,     6,   140,   141,    58,   142,   295,     7,     8,   143,
     316,   319,   106,   144,   145,   296,   146,    59,   147,   377,
      14,    15,     3,     4,     5,     6,   334,   301,   104,   332,
     227,     7,     8,     9,   278,   228,   302,    10,    11,    12,
      13,   395,   122,   283,    14,    15,   330,   105,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    86,
     252,   123,   284,   252,    87,   317,   318,   385,   327,   328,
      88,   311,   319,     2,   313,   227,   297,   175,    59,    60,
     230,   176,   395,   177,   319,    60,   361,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     120,     3,     4,     5,     6,     1,   286,   418,     2,   330,
       7,     8,     9,   419,   420,   379,    10,    11,    12,    13,
     380,    67,    68,    14,    15,   287,   331,   276,   277,    88,
       9,   362,     2,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    67,    68,    67,    68,   270,   141,
      58,   258,   365,     9,   119,   143,     3,     4,     5,     6,
      13,   366,   239,    59,   147,     7,     8,     9,   121,   243,
     392,    10,    11,    12,    13,   393,   278,   126,    14,    15,
       3,     4,     5,     6,   107,   108,   273,   109,   332,     7,
       8,     9,   119,   127,   379,    10,    11,    12,    13,   388,
     435,   232,    14,    15,   135,   436,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   428,   261,   379,
     267,   174,   393,    58,   454,   234,   235,   237,   238,     3,
       4,     5,     6,   215,   335,   220,    59,    60,     7,     8,
       9,   394,   462,   463,    10,    11,    12,    13,   226,   233,
     236,    14,    15,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   229,   110,   431,   111,   112,   113,
      58,   231,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    59,    60,   241,   242,   133,   394,   336,
     318,   114,   250,   115,   116,   117,   273,   273,   348,   389,
     -97,   -97,    59,    60,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   268,   269,   251,   252,   274,
     285,    58,   318,   291,   292,   294,   175,   300,   293,   304,
     176,   303,   177,   305,    59,    60,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   306,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   307,     4,     5,     6,   140,   141,    58,   142,   308,
       7,     8,   143,   309,   310,   312,   144,   145,   314,   146,
      59,   147,   315,    14,    15,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   349,   360,    67,    68,
     364,   370,    58,   258,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    59,   147,   371,   378,   338,
     273,    58,    75,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    59,    60,   330,   386,   387,   390,
      58,   253,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    59,   147,   391,   396,   397,   398,    58,
     258,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,   147,   399,   404,   410,   406,    58,   333,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    59,   147,   405,   411,   413,   417,    58,   318,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      59,    60,   421,   423,   383,   424,    58,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   425,    59,
      60,   426,   427,   -98,    58,   433,   434,   437,   438,   441,
     442,   443,   446,   447,   449,   456,   448,    59,   147,   450,
     451,   455,   457,   458,   459,   460,   461,   464,   467,   468,
     469,   470,   471,   240,   103,   299,   217,   118,   255,   408,
     402,   256,   372,   422,   129,   290,    81,     0,   271,   272,
     219
};

static const yytype_int16 yycheck[] =
{
       7,    83,   150,    33,   142,   130,   131,   132,    15,     9,
     142,    13,   273,   142,     7,    97,   140,   141,    83,   143,
      83,     7,   275,   276,   277,     3,     7,    83,     7,     7,
      77,     9,    83,    77,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    75,    15,
      16,    17,     9,     9,     9,    82,   329,    12,   331,   144,
     145,   144,   145,   148,    77,   148,    10,    10,   144,   145,
     172,    77,   148,   144,   145,     9,    77,   148,    77,    77,
       9,     9,     9,    12,    12,    12,   254,   172,   301,   172,
     275,   259,   119,    65,   262,   253,   172,   359,    77,   126,
     258,   172,    15,    16,   253,    77,   258,   275,   276,   277,
     391,    77,    12,   140,   141,   142,   143,   390,   220,   146,
      77,    77,    77,   143,   146,     6,   270,    59,    12,     5,
      11,    65,     6,    77,    77,    65,     6,    59,    60,     9,
     402,   326,    12,    77,    25,    77,   408,    77,    77,    77,
      77,    25,   365,    12,    15,    16,    17,   325,   326,   327,
     328,   329,    12,   331,    77,     7,   334,     9,    13,   219,
     315,    71,    15,    16,    17,   333,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    71,    58,    59,
      60,    61,    62,    63,    64,    12,    66,    67,    68,   301,
       6,     6,    72,    73,    65,    75,    76,    77,    65,    79,
      80,    70,    71,   381,    11,   278,    77,   385,     3,    69,
      77,    71,   390,   250,     0,   252,   253,     6,     3,    14,
       9,   258,   295,    12,    77,    10,     6,    15,    16,    17,
      11,    19,     6,   270,    10,    11,   273,    15,    16,    17,
      16,     6,    69,    70,     9,    25,   424,    12,    64,    64,
      25,    25,    77,   365,    15,    16,    17,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    77,    58,
      59,    60,    61,    62,    63,    64,     3,    66,    67,    68,
       8,   318,    51,    72,    73,    12,    75,    76,    77,    77,
      79,    80,    57,    58,    59,    60,   333,     3,     6,    77,
       3,    66,    67,    68,    65,     8,    12,    72,    73,    74,
      75,   348,     6,     6,    79,    80,    77,    25,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     6,
       3,    25,    25,     3,    11,    63,    64,    15,    16,    17,
       6,    14,   379,     9,    14,     3,    12,     3,    76,    77,
       8,     7,   389,     9,   391,    77,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      76,    57,    58,    59,    60,     6,     6,     9,     9,    77,
      66,    67,    68,    15,    16,     3,    72,    73,    74,    75,
       8,    59,    60,    79,    80,    25,    15,    16,    17,     6,
      68,    77,     9,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    59,    60,    59,    60,    61,    62,
      63,    64,     3,    68,    13,    68,    57,    58,    59,    60,
      75,    12,   119,    76,    77,    66,    67,    68,    77,   126,
      10,    72,    73,    74,    75,    15,    65,    13,    79,    80,
      57,    58,    59,    60,    50,    51,     7,    53,    77,    66,
      67,    68,    13,    77,     3,    72,    73,    74,    75,     8,
      10,    51,    79,    80,    78,    15,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    10,   141,     3,
     143,    78,    15,    63,     8,    50,    51,    50,    51,    57,
      58,    59,    60,    78,     8,    11,    76,    77,    66,    67,
      68,    81,    15,    16,    72,    73,    74,    75,    78,    51,
      51,    79,    80,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    78,    47,     8,    49,    50,    51,
      63,    78,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    76,    77,     6,    78,    77,    81,    63,
      64,    47,     7,    49,    50,    51,     7,     7,     9,     9,
      11,    11,    76,    77,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,   144,   145,     6,     3,   148,
      11,    63,    64,     6,     8,     6,     3,    77,    10,    77,
       7,     6,     9,    77,    76,    77,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     6,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    77,    58,    59,    60,    61,    62,    63,    64,     6,
      66,    67,    68,    51,    51,     6,    72,    73,    77,    75,
      76,    77,    10,    79,    80,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    78,    78,    59,    60,
       6,     6,    63,    64,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    76,    77,     8,    81,    77,
       7,    63,    64,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    76,    77,    77,    64,     8,    10,
      63,    64,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    76,    77,     7,     6,     6,    17,    63,
      64,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    76,    77,    25,    19,     6,    25,    63,    64,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    76,    77,    81,     6,     6,    77,    63,    64,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      76,    77,    77,     6,    77,    10,    63,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    10,    76,
      77,    64,    64,    11,    63,    10,    10,    78,     6,    12,
      78,     6,    12,    77,    10,     6,    77,    76,    77,    77,
      77,    10,    12,     6,     6,    12,     6,     6,     6,     6,
      77,    77,     6,   120,    45,   220,    92,    59,   140,   359,
     355,   140,   318,   379,    75,   172,    21,    -1,   146,   146,
      94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    57,    58,    59,    60,    66,    67,    68,
      72,    73,    74,    75,    79,    80,    86,    90,    91,    97,
     132,   137,   138,   139,   140,   141,   142,   143,   144,   146,
     147,   148,   149,   150,   151,   152,    10,    77,    84,    85,
      77,    59,    77,     7,    77,     7,    77,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    63,    76,
      77,    83,    92,    93,    94,    95,    77,    59,    60,   141,
     148,   148,    77,   142,    13,    64,    95,   131,   148,     6,
      25,   143,     5,    11,     6,    25,     6,    11,     6,   149,
       0,    25,     3,    10,    11,    77,     6,    11,    25,    77,
      87,     6,    25,    87,     6,    25,    51,    50,    51,    53,
      47,    49,    50,    51,    47,    49,    50,    51,    93,    13,
      76,    77,     6,    25,    77,    77,    13,    77,   136,   131,
      15,    16,    17,    77,   130,    78,    95,    96,     6,    12,
      61,    62,    64,    68,    72,    73,    75,    77,    86,    91,
      95,    97,    98,    99,   100,   101,   111,   112,   113,   118,
     119,   120,   121,   122,   123,   126,   127,   128,   129,   132,
     133,   134,   135,   144,    78,     3,     7,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    77,   124,   145,    78,    10,    84,    12,   150,
      11,    12,    77,    86,    88,    89,    78,     3,     8,    78,
       8,    78,    51,    51,    50,    51,    51,    50,    51,    96,
      92,     6,    78,    96,     3,    14,   130,   130,     9,   130,
       7,     6,     3,    64,    95,    99,   112,   120,    64,    95,
     120,   127,    95,    98,   119,   126,   120,   127,   133,   133,
      61,   121,   128,     7,   133,    15,    16,    17,    65,    77,
     110,   118,   125,     6,    25,    11,     6,    25,     6,    12,
     134,     6,     8,    10,     6,     3,    12,    12,    12,    89,
      77,     3,    12,     6,    77,    77,     6,    77,     6,    51,
      51,    14,     6,    14,    77,    10,     8,    63,    64,    95,
     114,   115,   116,   117,    95,    95,    15,    16,    17,    15,
      77,    15,    77,    64,    95,     8,    63,   117,    77,   110,
     118,   125,   118,   125,     9,   118,   125,   124,     9,    78,
      12,    69,    70,   102,   103,   104,   105,   106,   107,   108,
      78,    12,    77,   124,     6,     3,    12,    12,    88,   130,
       6,     8,   114,    15,    16,    17,    19,    77,    81,     3,
       8,    15,     9,    77,     9,    15,    64,     8,     8,     9,
      10,     7,    10,    15,    81,    95,     6,     6,    17,    25,
      12,    71,   108,   109,    19,    81,    25,    12,   104,   109,
       6,     6,    12,     6,    15,    16,    77,    77,     9,    15,
      16,    77,   116,     6,    10,    10,    64,    64,    10,   118,
     125,     8,   117,    10,    10,    10,    15,    78,     6,    12,
     109,    12,    78,     6,    12,   109,    12,    77,    77,    10,
      77,    77,     6,    64,     8,    10,     6,    12,     6,     6,
      12,     6,    15,    16,     6,     6,    64,     6,     6,    77,
      77,     6
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
    {(yyval.sn) = newAttribute((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 66 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (1)].sn), NULL);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 69 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 70 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 73 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (3)].sn);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 74 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (4)].sn);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 75 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 78 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 79 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 82 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 83 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 86 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 87 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 91 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 92 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), NULL, (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 93 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 94 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 95 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 96 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 99 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setEnumSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 100 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setEnumSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 103 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 104 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 107 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 108 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 111 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 112 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 115 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 116 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 119 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 120 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 123 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 124 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 125 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 126 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 127 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 128 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 129 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), enum_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 130 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), value_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 131 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), reference_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 134 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn), NULL, NULL);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 135 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 136 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn), NULL, NULL);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 139 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 140 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 143 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 144 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 147 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setFieldSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 148 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setFieldSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 152 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 155 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 156 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setGetterIncRef((yyval.sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 159 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 160 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 163 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 166 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 167 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterDecRef((yyval.sn));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 170 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 171 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 174 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 175 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 178 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 181 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 182 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 183 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 184 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), list_property);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 185 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 186 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 189 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 193 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 194 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 195 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 196 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(4) - (6)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 197 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 198 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 199 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 200 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (7)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (7)].sn)); setPropertySetter((yyvsp[(1) - (7)].sn), (yyvsp[(4) - (7)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 201 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (7)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (7)].sn)); setPropertySetter((yyvsp[(1) - (7)].sn), (yyvsp[(3) - (7)].sn)); setPropertyCandidate((yyval.sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 204 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 205 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 209 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 210 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 211 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 212 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 213 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 214 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 215 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 216 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 217 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 218 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 221 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 222 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 225 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 226 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 229 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 230 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 233 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 234 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 235 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 236 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 237 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 238 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 241 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 242 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 243 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 244 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 245 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 246 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 249 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 250 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 253 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 254 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 255 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 256 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 259 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 260 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 263 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 264 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 306 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 307 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 308 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 309 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 313 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 314 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 315 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 316 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 317 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 320 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 321 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 324 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 325 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 326 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 329 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 330 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 333 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 334 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 335 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 338 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 339 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 340 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 341 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 342 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 345 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 346 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 349 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 350 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 351 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 352 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 353 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 354 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 355 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 356 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 357 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 358 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 361 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 362 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 365 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 366 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 367 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 368 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 371 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 372 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 375 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 378 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 379 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 380 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 381 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 384 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 385 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 388 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 389 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 392 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 393 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 396 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 397 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 400 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 401 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 404 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 405 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 409 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 410 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 411 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 412 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 415 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 418 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 419 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 420 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 421 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 425 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 426 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 427 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 428 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 429 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 430 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 431 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 432 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 435 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 436 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 439 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 440 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 441 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 442 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 445 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 446 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 449 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 450 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3626 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



