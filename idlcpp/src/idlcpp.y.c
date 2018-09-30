
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
#line 1 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"

#include "yyfuncs.h"


/* Line 189 of yacc.c  */
#line 78 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
     NOMETA = 303,
     NOCODE = 304,
     EXPORT = 305,
     OVERRIDE = 306,
     SCOPE = 307,
     IDENTIFY = 308,
     STRING = 309,
     TEMPLATE = 310,
     DELEGATE = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 176 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#define YYLAST   1071

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  275
/* YYNRULES -- Number of states.  */
#define YYNSTATES  475

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,     2,     2,    21,    16,     2,
       7,     8,    15,    18,     3,    19,     4,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     6,
      13,    25,    14,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     9,     2,    10,    17,     2,     2,     2,     2,     2,
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
      78,    79
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    17,    19,
      22,    25,    29,    32,    36,    38,    41,    44,    48,    51,
      55,    58,    62,    66,    71,    75,    80,    82,    85,    87,
      90,    92,    94,    96,    99,   101,   105,   107,   111,   115,
     120,   123,   125,   128,   130,   134,   140,   147,   152,   159,
     167,   173,   176,   181,   183,   188,   190,   194,   196,   199,
     201,   203,   205,   209,   214,   218,   222,   226,   230,   236,
     242,   248,   254,   257,   262,   266,   268,   271,   273,   276,
     279,   284,   286,   291,   297,   303,   310,   317,   319,   323,
     325,   330,   336,   342,   349,   356,   358,   361,   363,   367,
     369,   373,   378,   383,   389,   392,   396,   400,   405,   410,
     414,   418,   423,   428,   430,   433,   436,   440,   444,   449,
     454,   461,   466,   471,   478,   480,   483,   485,   488,   490,
     494,   498,   503,   508,   513,   519,   525,   527,   530,   534,
     538,   542,   548,   550,   553,   555,   558,   561,   564,   566,
     569,   572,   577,   579,   581,   583,   585,   587,   589,   591,
     593,   595,   597,   599,   601,   603,   605,   608,   611,   613,
     615,   617,   619,   621,   623,   625,   627,   629,   631,   633,
     635,   637,   639,   641,   643,   645,   647,   649,   651,   657,
     664,   671,   679,   682,   686,   690,   694,   700,   702,   705,
     707,   710,   713,   715,   718,   723,   729,   735,   738,   742,
     746,   750,   756,   759,   763,   765,   767,   769,   771,   773,
     775,   777,   779,   782,   785,   787,   790,   792,   794,   797,
     800,   802,   806,   811,   814,   820,   823,   829,   831,   835,
     839,   844,   847,   852,   854,   857,   859,   862,   864,   867,
     869,   871,   875,   879,   885,   888,   893,   899,   906,   908,
     910,   912,   914,   916,   918,   921,   924,   926,   929,   931,
     933,   936,   939,   944,   950,   951
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     147,     0,    -1,    63,    -1,    46,    -1,    47,    -1,    54,
      47,    -1,    55,    47,    -1,    48,    -1,    49,    -1,    49,
      51,    -1,    54,    49,    -1,    54,    49,    51,    -1,    55,
      49,    -1,    55,    49,    51,    -1,    50,    -1,    50,    51,
      -1,    54,    50,    -1,    54,    50,    51,    -1,    55,    50,
      -1,    55,    50,    51,    -1,    50,    50,    -1,    50,    50,
      51,    -1,    54,    50,    50,    -1,    54,    50,    50,    51,
      -1,    55,    50,    50,    -1,    55,    50,    50,    51,    -1,
      51,    -1,    54,    51,    -1,    54,    -1,    55,    51,    -1,
      55,    -1,    52,    -1,    53,    -1,    50,    53,    -1,    56,
      -1,    76,    25,    77,    -1,    83,    -1,    84,     3,    83,
      -1,     9,    84,    10,    -1,     9,    84,     3,    10,    -1,
       9,    10,    -1,    76,    -1,    85,    76,    -1,    86,    -1,
      87,     3,    86,    -1,    58,    76,    11,    87,    12,    -1,
      58,    76,    11,    87,     3,    12,    -1,    58,    76,    11,
      12,    -1,    58,    59,    76,    11,    87,    12,    -1,    58,
      59,    76,    11,    87,     3,    12,    -1,    58,    59,    76,
      11,    12,    -1,    88,     6,    -1,    88,    25,    77,     6,
      -1,    76,    -1,    76,    13,    94,    14,    -1,    90,    -1,
      91,    75,    90,    -1,    91,    -1,    75,    91,    -1,    82,
      -1,    92,    -1,    93,    -1,    94,     3,    93,    -1,    66,
      93,    76,     6,    -1,    67,    76,     6,    -1,    58,    76,
       6,    -1,    60,    76,     6,    -1,    59,    76,     6,    -1,
      67,    76,    25,    77,     6,    -1,    58,    76,    25,    77,
       6,    -1,    60,    76,    25,    77,     6,    -1,    59,    76,
      25,    77,     6,    -1,    93,    76,    -1,    93,    76,     9,
      10,    -1,    93,    15,    76,    -1,    96,    -1,    64,    96,
      -1,    97,    -1,    61,    97,    -1,    98,     6,    -1,    98,
      25,    77,     6,    -1,    69,    -1,    69,     7,    93,     8,
      -1,    69,     7,    93,    15,     8,    -1,    69,     7,    93,
      16,     8,    -1,    69,     7,    64,    93,    15,     8,    -1,
      69,     7,    64,    93,    16,     8,    -1,   100,    -1,   100,
      25,    77,    -1,    70,    -1,    70,     7,    93,     8,    -1,
      70,     7,    93,    15,     8,    -1,    70,     7,    93,    16,
       8,    -1,    70,     7,    64,    93,    15,     8,    -1,    70,
       7,    64,    93,    16,     8,    -1,   102,    -1,   102,    80,
      -1,   103,    -1,   103,    25,    77,    -1,    76,    -1,    76,
       9,    10,    -1,    76,     9,    80,    10,    -1,    76,    11,
      93,    12,    -1,    76,    11,    93,    15,    12,    -1,    93,
     105,    -1,    93,    15,   105,    -1,    93,    16,   105,    -1,
      64,    93,    15,   105,    -1,    64,    93,    16,   105,    -1,
     106,   101,     6,    -1,   106,   104,     6,    -1,   106,   101,
     104,     6,    -1,   106,   104,   101,     6,    -1,   107,    -1,
      61,   107,    -1,    93,    76,    -1,    93,    15,    76,    -1,
      93,    16,    76,    -1,    93,    15,    15,    76,    -1,    93,
      17,    15,    76,    -1,    93,    17,     9,    10,    15,    76,
      -1,    93,    15,    16,    76,    -1,    93,    17,    16,    76,
      -1,    93,    17,     9,    10,    16,    76,    -1,   109,    -1,
      64,   109,    -1,   110,    -1,   110,    80,    -1,   111,    -1,
     112,     3,   111,    -1,    76,     7,     8,    -1,    76,     7,
      63,     8,    -1,    76,     7,   112,     8,    -1,    76,     7,
       8,    64,    -1,    76,     7,    63,     8,    64,    -1,    76,
       7,   112,     8,    64,    -1,   113,    -1,    93,   113,    -1,
      93,    16,   113,    -1,    93,    15,   113,    -1,    93,    17,
     113,    -1,    93,    17,     9,    10,   113,    -1,   114,    -1,
      64,   114,    -1,   115,    -1,    68,   115,    -1,    62,   115,
      -1,    61,   115,    -1,   116,    -1,    74,   116,    -1,   117,
       6,    -1,   117,    25,    77,     6,    -1,    18,    -1,    19,
      -1,    15,    -1,    20,    -1,    21,    -1,    17,    -1,    16,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    13,
      -1,    14,    -1,     3,    -1,     9,    10,    -1,     7,     8,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    36,    -1,    37,
      -1,    34,    -1,    35,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    65,   119,     7,     8,     6,    -1,    65,   119,     7,
     112,     8,     6,    -1,    65,   119,     7,     8,    64,     6,
      -1,    65,   119,     7,   112,     8,    64,     6,    -1,    93,
     120,    -1,    93,    16,   120,    -1,    93,    15,   120,    -1,
      93,    17,   120,    -1,    93,    17,     9,    10,   120,    -1,
     121,    -1,    64,   121,    -1,   122,    -1,    68,   122,    -1,
      62,   122,    -1,   123,    -1,    74,   123,    -1,    76,     7,
       8,     6,    -1,    76,     7,    63,     8,     6,    -1,    76,
       7,   112,     8,     6,    -1,    93,   125,    -1,    93,    16,
     125,    -1,    93,    15,   125,    -1,    93,    17,   125,    -1,
      93,    17,     9,    10,   125,    -1,    79,   126,    -1,    79,
      64,   126,    -1,    99,    -1,   108,    -1,   118,    -1,   124,
      -1,   139,    -1,   127,    -1,    89,    -1,    95,    -1,    72,
     128,    -1,    71,   128,    -1,   128,    -1,    85,   128,    -1,
     129,    -1,     6,    -1,   130,   129,    -1,   130,     6,    -1,
      76,    -1,   131,     3,    76,    -1,    78,    13,   131,    14,
      -1,    59,    76,    -1,    59,     7,    76,     8,    76,    -1,
      60,    76,    -1,    60,     7,    76,     8,    76,    -1,   133,
      -1,   133,     5,    94,    -1,   134,    11,    12,    -1,   134,
      11,   130,    12,    -1,   135,     6,    -1,   135,    25,    77,
       6,    -1,   136,    -1,    68,   136,    -1,   137,    -1,    74,
     137,    -1,   138,    -1,   132,   138,    -1,    76,    -1,   119,
      -1,   140,     3,    76,    -1,   140,     3,   119,    -1,    73,
      76,    13,    94,    14,    -1,   141,     6,    -1,   141,    11,
      12,     6,    -1,   141,    11,   140,    12,     6,    -1,   141,
      11,   140,     3,    12,     6,    -1,   139,    -1,   127,    -1,
      89,    -1,   142,    -1,    95,    -1,   146,    -1,    72,   143,
      -1,    71,   143,    -1,   143,    -1,    85,   143,    -1,   144,
      -1,     6,    -1,   145,   144,    -1,   145,     6,    -1,    57,
      76,    11,    12,    -1,    57,    76,    11,   145,    12,    -1,
      -1,   145,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    65,    68,    69,    72,    73,
      74,    77,    78,    81,    82,    86,    87,    88,    89,    90,
      91,    94,    95,    98,    99,   102,   103,   106,   107,   110,
     111,   114,   115,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   129,   130,   131,   134,   135,   138,   139,   142,
     143,   147,   148,   149,   150,   151,   152,   156,   157,   160,
     161,   162,   163,   164,   165,   168,   169,   172,   173,   176,
     177,   178,   179,   180,   183,   184,   185,   186,   187,   190,
     191,   192,   193,   196,   197,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   212,   213,   216,   217,   220,   221,
     224,   225,   226,   227,   228,   229,   232,   233,   234,   235,
     236,   237,   240,   241,   244,   245,   246,   247,   250,   251,
     254,   255,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   297,   298,
     299,   300,   304,   305,   306,   307,   308,   311,   312,   315,
     316,   317,   320,   321,   324,   325,   326,   329,   330,   331,
     332,   333,   336,   337,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   352,   353,   356,   357,   358,   359,
     362,   363,   366,   369,   370,   371,   372,   375,   376,   379,
     380,   383,   384,   387,   388,   391,   392,   395,   396,   400,
     401,   402,   403,   406,   409,   410,   411,   412,   416,   417,
     418,   419,   420,   421,   422,   423,   426,   427,   430,   431,
     432,   433,   436,   437,   440,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "','", "'.'", "':'", "';'", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'<'", "'>'", "'*'", "'&'", "'^'", "'+'",
  "'-'", "'/'", "'%'", "'|'", "'~'", "'!'", "'='", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "BIT_XOR_ASSIGN",
  "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "LEFT_SHIFT", "RIGHT_SHIFT", "EQUAL", "NOT_EQUAL",
  "LESS_EQUAL", "GREATER_EQUAL", "AND", "OR", "INC", "DEC", "BOOL", "CHAR",
  "WCHAR_T", "SHORT", "LONG", "INT", "FLOAT", "DOUBLE", "SIGNED",
  "UNSIGNED", "STRING_T", "NAMESPACE", "ENUM", "CLASS", "STRUCT", "STATIC",
  "VIRTUAL", "VOID", "CONST", "OPERATOR", "TYPEDEF", "PRIMITIVE",
  "ABSTRACT", "GET", "SET", "NOMETA", "NOCODE", "EXPORT", "OVERRIDE",
  "SCOPE", "IDENTIFY", "STRING", "TEMPLATE", "DELEGATE", "'?'", "$accept",
  "primitive", "attribute", "attributeList", "attributes", "enumerator",
  "enumeratorList", "enum_0", "enum", "scopeName", "scopeNameList_0",
  "scopeNameList", "typeName", "typeNameList", "typeAlias", "field_0",
  "field_1", "field_2", "field", "getter_0", "getter", "setter_0",
  "setter_1", "setter", "property_0", "property_1", "property_2",
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
      93,   123,   125,    60,    62,    42,    38,    94,    43,    45,
      47,    37,   124,   126,    33,    61,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   100,   100,   101,   101,   102,
     102,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   106,   106,   106,   106,   106,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   126,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   130,   130,
     131,   131,   132,   133,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   140,   141,   142,   142,   142,   142,   143,   143,
     143,   143,   143,   143,   143,   143,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     2,     3,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     4,
       2,     1,     2,     1,     3,     5,     6,     4,     6,     7,
       5,     2,     4,     1,     4,     1,     3,     1,     2,     1,
       1,     1,     3,     4,     3,     3,     3,     3,     5,     5,
       5,     5,     2,     4,     3,     1,     2,     1,     2,     2,
       4,     1,     4,     5,     5,     6,     6,     1,     3,     1,
       4,     5,     5,     6,     6,     1,     2,     1,     3,     1,
       3,     4,     4,     5,     2,     3,     3,     4,     4,     3,
       3,     4,     4,     1,     2,     2,     3,     3,     4,     4,
       6,     4,     4,     6,     1,     2,     1,     2,     1,     3,
       3,     4,     4,     4,     5,     5,     1,     2,     3,     3,
       3,     5,     1,     2,     1,     2,     2,     2,     1,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       6,     7,     2,     3,     3,     3,     5,     1,     2,     1,
       2,     2,     1,     2,     4,     5,     5,     2,     3,     3,
       3,     5,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     1,     1,     2,     2,
       1,     3,     4,     2,     5,     2,     5,     1,     3,     3,
       4,     2,     4,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     3,     5,     2,     4,     5,     6,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     1,     1,
       2,     2,     4,     5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     274,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   262,
     259,     0,   237,     0,     0,   243,   245,   247,   258,     0,
     261,   266,   268,   275,   263,     0,    40,     0,    36,     0,
       0,     0,     0,     0,   233,     0,   235,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
      53,    59,    55,    57,    60,     0,     0,     0,     0,   244,
     265,   264,     0,   246,     0,     0,     0,   212,   267,    51,
       0,   248,     0,     0,   241,     0,   254,     0,   271,   270,
       1,     0,     0,    38,     0,     0,    65,     0,     0,     0,
      67,     0,     0,    66,     0,     9,    20,    15,    33,     5,
      10,    16,    27,     6,    12,    18,    29,    58,     0,     0,
       0,    64,     0,   233,   235,     0,   230,     0,   213,     0,
       0,     0,     0,   207,     0,    61,   238,   227,   239,     0,
       0,     0,     0,     0,     0,     0,    53,     0,   220,     0,
     221,    75,    77,     0,   214,     0,   113,   215,   136,   142,
     144,   148,     0,   216,   197,   199,   202,   217,   219,   224,
     226,     0,   218,     0,   165,     0,     0,     0,   163,   164,
     154,   158,   157,   152,   153,   155,   156,   159,   160,   161,
     162,   168,   169,   170,   171,   172,   173,   174,   175,   178,
     179,   176,   177,   180,   181,   182,   183,   184,   185,   186,
     187,   249,   250,     0,    35,    39,    37,   272,     0,     0,
      47,    41,     0,    43,     0,     0,     0,     0,     0,     0,
      21,    11,    22,    17,    13,    24,    19,     0,    56,    63,
       0,     0,     0,   232,   209,   208,     0,   210,     0,    52,
       0,     0,     0,    78,   114,   147,     0,     0,   146,   201,
       0,    76,   143,   198,   145,   200,   223,   222,     0,   149,
     203,     0,   225,     0,     0,     0,     0,    72,   104,   137,
     192,    79,     0,    81,    89,    87,     0,    95,    97,     0,
     150,     0,   229,   240,   228,   242,   167,   166,   255,     0,
       0,   273,    50,     0,    42,     0,    45,    69,   234,    71,
     236,    70,    23,    25,    54,    68,   253,   231,     0,     0,
       2,     0,     0,   124,   126,   128,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,     0,
     130,     2,     0,    74,   105,   139,   194,    99,   106,   138,
     193,     0,   140,   195,     0,     0,     0,     0,     0,     0,
       0,   109,     0,    96,     0,   110,     0,     0,     0,   251,
     252,   256,     0,    48,    46,    44,   211,   204,     0,   125,
       0,     0,     0,   115,   127,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,   133,   131,   132,     0,     0,
       0,    73,     0,     0,    80,     0,     0,     0,     0,    88,
     111,    98,   112,   151,   257,    49,   205,     0,     0,   116,
     117,     0,     0,     0,   129,   206,     0,    73,   134,   135,
     100,   141,   196,     0,     0,   101,   102,     0,     0,    82,
       0,     0,     0,    90,     0,     0,   118,   121,     0,   119,
     122,   188,     0,     0,   103,     0,     0,    83,    84,     0,
       0,    91,    92,     0,     0,   190,   189,     0,    85,    86,
      93,    94,   120,   123,   191
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    38,    39,    16,   223,   224,    17,    18,    62,
      63,    64,   149,   136,    19,   151,   152,   153,   154,   285,
     286,   287,   288,   289,   278,   155,   156,   157,   323,   324,
     325,   326,   158,   159,   160,   161,   162,   163,   212,   280,
     164,   165,   166,   167,   133,    77,    20,   169,   170,   171,
     127,    21,    22,    23,    24,    25,    26,    27,    28,   213,
      29,    30,    31,    32,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -265
static const yytype_int16 yypact[] =
{
     432,  -265,    16,   -45,   -31,    23,    29,   963,    11,   380,
     992,   992,    37,   264,   128,   746,   992,    35,  -265,  -265,
    -265,   248,   150,   182,    53,  -265,  -265,  -265,  -265,   314,
    -265,  -265,  -265,   487,  -265,   203,  -265,   217,  -265,   222,
     237,   184,    52,   218,    56,   226,   201,  -265,  -265,  -265,
     258,   420,  -265,  -265,  -265,   430,   435,  -265,  -265,   241,
     321,  -265,  -265,   252,  -265,   262,   208,    31,    32,  -265,
    -265,  -265,   341,  -265,   274,   963,   230,  -265,  -265,  -265,
     289,  -265,   963,   225,  -265,   305,  -265,   144,  -265,  -265,
    -265,   370,    47,  -265,   385,   375,  -265,    34,   383,   382,
    -265,   390,   394,  -265,   401,  -265,   458,  -265,  -265,  -265,
     462,   437,  -265,  -265,   464,   444,  -265,   252,   963,   241,
     477,  -265,   448,  -265,  -265,   963,  -265,    62,  -265,   421,
     421,    10,   516,  -265,   524,  -265,   533,  -265,  -265,   777,
     808,   981,   715,   650,   650,   684,    59,   650,  -265,   194,
    -265,  -265,  -265,   210,  -265,   438,  -265,  -265,  -265,  -265,
    -265,  -265,   211,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,   309,  -265,   531,  -265,   540,   539,   544,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,    61,  -265,  -265,  -265,  -265,   460,    38,
    -265,  -265,   475,  -265,   212,   546,   480,   551,   488,   557,
    -265,  -265,   528,  -265,  -265,   529,  -265,   215,  -265,  -265,
     572,   216,   506,  -265,  -265,  -265,   571,  -265,   521,  -265,
     963,   981,   235,  -265,  -265,  -265,   981,   327,  -265,  -265,
     459,  -265,  -265,  -265,  -265,  -265,  -265,  -265,   839,  -265,
    -265,   554,  -265,   162,   163,    44,   649,   143,  -265,  -265,
    -265,  -265,   509,   576,   580,   563,    55,   510,   564,    48,
    -265,   514,  -265,  -265,  -265,  -265,  -265,  -265,  -265,   392,
     586,  -265,  -265,   307,  -265,    39,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,   421,   588,
     587,   963,   250,  -265,   518,  -265,   371,  -265,   313,   523,
     535,    18,   193,   193,   605,   162,   163,    60,   981,   320,
     549,   606,   446,   185,  -265,  -265,  -265,   505,  -265,  -265,
    -265,   609,  -265,  -265,   608,    13,   963,   610,   870,   901,
     543,  -265,   615,  -265,   545,  -265,   617,   618,   619,  -265,
    -265,  -265,    40,  -265,  -265,  -265,  -265,  -265,   620,  -265,
     206,   552,   330,  -265,  -265,   932,   621,   523,   535,   632,
    -265,  -265,   633,   568,   568,  -265,   581,   582,    15,   193,
     585,   452,   637,    17,  -265,   963,   297,   963,   325,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,   574,   575,  -265,
    -265,   643,   578,   579,  -265,  -265,   568,  -265,  -265,  -265,
    -265,  -265,  -265,   189,   447,  -265,  -265,   645,   486,  -265,
     651,   687,   525,  -265,   699,   707,  -265,  -265,   527,  -265,
    -265,  -265,   713,   234,  -265,   712,   719,  -265,  -265,   733,
     734,  -265,  -265,   647,   673,  -265,  -265,   744,  -265,  -265,
    -265,  -265,  -265,  -265,  -265
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,   659,  -265,   -82,  -250,   534,  -265,   -73,   635,
     696,  -265,    -7,   -81,   -59,  -124,   634,  -265,  -265,  -265,
     467,  -265,  -265,   471,  -239,  -265,   638,  -265,   451,  -265,
     373,  -264,  -131,  -132,  -128,   631,  -265,  -265,  -243,  -253,
    -125,   306,   636,  -265,  -127,   705,   -43,   318,   611,  -265,
    -265,  -265,  -265,  -265,  -265,    -3,     0,   762,   -41,  -265,
    -265,  -265,   337,   -28,   690,  -265,  -265
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -101
static const yytype_int16 yytable[] =
{
      65,   147,   244,   245,   247,    89,    69,   342,    76,   262,
     148,   255,   258,    73,   264,   222,   263,   261,   279,   246,
     346,   350,   353,   401,   150,   430,    36,   389,    41,   436,
      43,    40,   437,   354,   344,   348,    45,   237,    43,    45,
     168,    79,   172,     2,   241,    42,   220,     2,     2,     2,
     302,   374,   415,   351,   365,   375,   370,   215,    96,    84,
      80,   361,   100,    97,   299,   242,   271,   271,    76,   392,
     148,   148,   118,   300,   148,   135,   243,    98,    85,   346,
     350,   101,   346,   350,   150,   150,   132,    66,   150,   147,
     344,   348,    37,   402,   334,   402,   390,   391,   148,    44,
     168,   168,   172,   172,   168,    46,   172,   123,   124,   276,
     221,   135,   150,    72,   221,   221,   221,   283,   135,   262,
     334,   279,   375,    37,   262,   284,   279,   261,   168,   279,
     172,   263,   252,   257,   260,   257,   434,   222,   257,    69,
     255,    74,   345,   349,   352,    73,   432,   174,   390,   391,
     271,   175,   355,   176,   356,    82,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      89,   376,   271,    83,   398,   451,   356,   279,   345,   349,
     352,   345,   349,    90,   345,   349,   262,   103,   279,   273,
     274,   275,   -99,   -99,   121,   305,   281,   290,   250,   250,
     211,   417,   418,   222,   306,    92,   104,   276,   276,   314,
     316,   137,    93,   122,     2,   282,   291,   138,   343,   347,
     466,   322,    91,   327,   328,   129,   130,   131,    94,   257,
     329,   330,   331,   452,   -99,   -99,   345,   349,   276,   276,
      95,   339,   345,   349,   322,   380,   381,   382,   431,   334,
     277,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   419,     4,     5,     6,   139,   140,    58,   141,
     222,     7,     8,   142,    99,   431,   143,   144,   467,   145,
      59,   146,   102,    14,    15,   439,   132,    67,    68,   105,
     372,   277,   440,   441,   322,   292,     9,    60,     2,   373,
      86,   293,    13,    67,    68,    87,   383,   119,   387,   388,
     331,   339,     9,   443,   118,   393,   394,   331,   120,   421,
     444,   445,   332,   333,   275,   422,   423,    70,    71,   403,
     126,   406,   408,    78,   125,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   134,     4,     5,     6,
     139,   140,    58,   141,   385,     7,     8,   142,   322,   386,
     143,   144,   173,   145,    59,   146,   219,    14,    15,   337,
     226,     1,   276,   322,     2,   174,   334,   217,   438,   175,
     442,   176,   228,   334,   368,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     1,    67,
      68,     2,     3,     4,     5,     6,   259,   214,   265,   385,
     385,     7,     8,     9,   397,   453,    10,    11,    12,    13,
     225,   266,   267,    14,    15,   272,    88,   227,   369,     2,
     106,   107,   301,   108,   335,   336,   275,   109,   229,   110,
     111,   112,   113,   239,   114,   115,   116,   232,   233,     3,
       4,     5,     6,    88,   235,   236,     2,   132,     7,     8,
       9,   455,   456,    10,    11,    12,    13,   283,   284,   230,
      14,    15,   271,   231,   398,   234,   356,     3,     4,     5,
       6,  -100,  -100,   248,   276,   240,     7,     8,     9,   319,
     249,    10,    11,    12,    13,   337,   250,   295,    14,    15,
     459,   460,   463,   464,     3,     4,     5,     6,   296,   297,
     298,   304,   307,     7,     8,     9,   308,   309,    10,    11,
      12,    13,   340,   311,   310,    14,    15,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   315,   312,
     313,   318,   317,   358,   320,   321,   357,   359,   360,   364,
     363,   367,   371,   433,   377,   378,    59,    60,   384,   343,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   347,   271,   395,   396,   400,   404,   341,   321,   399,
     409,   410,   411,   412,   413,   414,   416,   425,   420,    59,
      60,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   426,   427,   334,   428,   429,   435,    58,   321,
     446,   447,   174,   448,   449,   450,   175,   454,   176,   457,
      59,    60,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   458,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   461,     4,     5,
       6,   139,   140,    58,   141,   462,     7,     8,   142,   465,
     468,   143,   144,   472,   145,    59,   146,   469,    14,    15,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   470,   471,    67,    68,   268,   140,    58,   256,   473,
     474,   216,   142,   303,   238,   117,   366,   362,   424,    59,
     146,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   379,   253,    67,    68,   269,   254,    58,   256,
     128,   270,   294,    81,   218,     0,     0,     0,     0,     0,
      59,   146,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,    58,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
      58,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,   146,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,    58,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,   146,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,    58,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,   146,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,    58,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,   407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,    58,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    58,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     3,
       4,     5,     6,     0,     0,     0,    59,   146,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,     0,     0,
      14,    15
};

static const yytype_int16 yycheck[] =
{
       7,    83,   129,   130,   131,    33,     9,   271,    15,   141,
      83,   139,   140,    13,   142,    97,   141,   141,   149,     9,
     273,   274,   275,    10,    83,    10,    10,     9,    59,    12,
       7,    76,    15,   276,   273,   274,     7,   118,     7,     7,
      83,     6,    83,     9,   125,    76,    12,     9,     9,     9,
      12,    12,    12,     9,     6,   305,   299,    10,     6,     6,
      25,     6,     6,    11,     3,     3,     7,     7,    75,     9,
     143,   144,    13,    12,   147,    82,    14,    25,    25,   332,
     333,    25,   335,   336,   143,   144,    76,    76,   147,   171,
     329,   330,    76,    80,    76,    80,   335,   336,   171,    76,
     143,   144,   143,   144,   147,    76,   147,    76,    76,    65,
      76,   118,   171,    76,    76,    76,    76,    69,   125,   251,
      76,   252,   372,    76,   256,    70,   257,   251,   171,   260,
     171,   256,   139,   140,   141,   142,   400,   219,   145,   142,
     268,    13,   273,   274,   275,   145,   399,     3,   387,   388,
       7,     7,     9,     9,    11,     5,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     218,   318,     7,    11,     9,     6,    11,   328,   329,   330,
     331,   332,   333,     0,   335,   336,   338,     6,   339,    15,
      16,    17,    69,    70,     6,     3,     6,     6,     3,     3,
      76,    15,    16,   305,    12,     3,    25,    65,    65,    14,
      14,     6,    10,    25,     9,    25,    25,    12,    76,    76,
       6,   248,    25,   250,   251,    15,    16,    17,    11,   256,
      15,    16,    17,    64,    69,    70,   387,   388,    65,    65,
      76,   268,   393,   394,   271,    15,    16,    17,   399,    76,
      76,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    76,    58,    59,    60,    61,    62,    63,    64,
     372,    66,    67,    68,    76,   426,    71,    72,    64,    74,
      75,    76,    76,    78,    79,     8,    76,    59,    60,    51,
       3,    76,    15,    16,   321,     6,    68,    76,     9,    12,
       6,    12,    74,    59,    60,    11,    76,    75,    15,    16,
      17,   338,    68,     8,    13,    15,    16,    17,    76,     9,
      15,    16,    15,    16,    17,    15,    16,    10,    11,   356,
      76,   358,   359,    16,    13,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    77,    58,    59,    60,
      61,    62,    63,    64,     3,    66,    67,    68,   385,     8,
      71,    72,    77,    74,    75,    76,    11,    78,    79,    76,
       8,     6,    65,   400,     9,     3,    76,    12,   405,     7,
     407,     9,     8,    76,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     6,    59,
      60,     9,    57,    58,    59,    60,   140,    77,   142,     3,
       3,    66,    67,    68,     8,     8,    71,    72,    73,    74,
      77,   143,   144,    78,    79,   147,     6,    77,    76,     9,
      50,    51,    12,    53,    15,    16,    17,    47,    77,    49,
      50,    51,    47,     6,    49,    50,    51,    50,    51,    57,
      58,    59,    60,     6,    50,    51,     9,    76,    66,    67,
      68,    15,    16,    71,    72,    73,    74,    69,    70,    51,
      78,    79,     7,    51,     9,    51,    11,    57,    58,    59,
      60,    69,    70,     7,    65,    77,    66,    67,    68,     8,
       6,    71,    72,    73,    74,    76,     3,     6,    78,    79,
      15,    16,    15,    16,    57,    58,    59,    60,     8,    10,
       6,    76,     6,    66,    67,    68,    76,     6,    71,    72,
      73,    74,     8,     6,    76,    78,    79,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     6,    51,
      51,    10,    76,     7,    63,    64,    77,     7,    25,    25,
      80,    77,     6,     8,     6,     8,    75,    76,    80,    76,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    76,     7,    64,     8,     7,     6,    63,    64,    10,
      77,     6,    77,     6,     6,     6,     6,     6,    76,    75,
      76,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    10,    10,    76,    64,    64,    10,    63,    64,
      76,    76,     3,    10,    76,    76,     7,    12,     9,     8,
      75,    76,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     8,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     8,    58,    59,
      60,    61,    62,    63,    64,     8,    66,    67,    68,     6,
       8,    71,    72,    76,    74,    75,    76,     8,    78,    79,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     8,     8,    59,    60,    61,    62,    63,    64,    76,
       6,    92,    68,   219,   119,    59,   289,   286,   385,    75,
      76,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,   321,   139,    59,    60,   145,   139,    63,    64,
      75,   145,   171,    21,    94,    -1,    -1,    -1,    -1,    -1,
      75,    76,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    75,    76,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    75,    76,    66,    67,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    57,    58,    59,    60,    66,    67,    68,
      71,    72,    73,    74,    78,    79,    85,    88,    89,    95,
     127,   132,   133,   134,   135,   136,   137,   138,   139,   141,
     142,   143,   144,   145,   146,   147,    10,    76,    83,    84,
      76,    59,    76,     7,    76,     7,    76,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    63,    75,
      76,    82,    90,    91,    92,    93,    76,    59,    60,   136,
     143,   143,    76,   137,    13,    64,    93,   126,   143,     6,
      25,   138,     5,    11,     6,    25,     6,    11,     6,   144,
       0,    25,     3,    10,    11,    76,     6,    11,    25,    76,
       6,    25,    76,     6,    25,    51,    50,    51,    53,    47,
      49,    50,    51,    47,    49,    50,    51,    91,    13,    75,
      76,     6,    25,    76,    76,    13,    76,   131,   126,    15,
      16,    17,    76,   125,    77,    93,    94,     6,    12,    61,
      62,    64,    68,    71,    72,    74,    76,    85,    89,    93,
      95,    96,    97,    98,    99,   106,   107,   108,   113,   114,
     115,   116,   117,   118,   121,   122,   123,   124,   127,   128,
     129,   130,   139,    77,     3,     7,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    76,   119,   140,    77,    10,    83,    12,   145,    11,
      12,    76,    85,    86,    87,    77,     8,    77,     8,    77,
      51,    51,    50,    51,    51,    50,    51,    94,    90,     6,
      77,    94,     3,    14,   125,   125,     9,   125,     7,     6,
       3,    64,    93,    97,   107,   115,    64,    93,   115,   122,
      93,    96,   114,   121,   115,   122,   128,   128,    61,   116,
     123,     7,   128,    15,    16,    17,    65,    76,   105,   113,
     120,     6,    25,    69,    70,   100,   101,   102,   103,   104,
       6,    25,     6,    12,   129,     6,     8,    10,     6,     3,
      12,    12,    12,    87,    76,     3,    12,     6,    76,     6,
      76,     6,    51,    51,    14,     6,    14,    76,    10,     8,
      63,    64,    93,   109,   110,   111,   112,    93,    93,    15,
      16,    17,    15,    16,    76,    15,    16,    76,    64,    93,
       8,    63,   112,    76,   105,   113,   120,    76,   105,   113,
     120,     9,   113,   120,   119,     9,    11,    77,     7,     7,
      25,     6,   104,    80,    25,     6,   101,    77,    12,    76,
     119,     6,     3,    12,    12,    86,   125,     6,     8,   109,
      15,    16,    17,    76,    80,     3,     8,    15,    16,     9,
     105,   105,     9,    15,    16,    64,     8,     8,     9,    10,
       7,    10,    80,    93,     6,    64,    93,    64,    93,    77,
       6,    77,     6,     6,     6,    12,     6,    15,    16,    76,
      76,     9,    15,    16,   111,     6,    10,    10,    64,    64,
      10,   113,   120,     8,   112,    10,    12,    15,    93,     8,
      15,    16,    93,     8,    15,    16,    76,    76,    10,    76,
      76,     6,    64,     8,    12,    15,    16,     8,     8,    15,
      16,     8,     8,    15,    16,     6,     6,    64,     8,     8,
       8,     8,    76,    76,     6
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
#line 30 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_void);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 31 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_bool);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 32 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_char);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 33 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_schar);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 34 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uchar);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 35 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_wchar_t);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 36 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_short);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 37 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 38 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 39 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_short);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 40 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ushort);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 41 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ushort);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 42 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_long);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 43 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 44 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 45 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_long);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 46 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ulong);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 47 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulong);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 48 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_longlong);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 49 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 50 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 51 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_longlong);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 52 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulonglong);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 53 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_ulonglong);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 54 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 55 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_int);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 56 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 57 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uint);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 58 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_uint);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 59 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_float);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 60 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_double);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 61 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long_double);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 62 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_string_t);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 65 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 68 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 69 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 72 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (3)].sn);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 73 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (4)].sn);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 74 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 77 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 78 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 81 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 82 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 86 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 87 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), NULL, (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 88 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 89 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 90 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 91 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 94 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setEnumSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 95 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setEnumSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 98 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 99 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 102 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 103 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 106 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 107 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 110 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 111 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 114 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 115 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 118 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 119 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 120 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 121 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 122 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 123 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 124 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), enum_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 125 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), value_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 126 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), reference_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 129 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn), NULL, NULL);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 130 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 131 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn), NULL, NULL);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 134 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 135 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 138 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 139 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 142 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setFieldSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 143 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setFieldSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 147 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 148 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 149 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 150 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 151 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 152 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 156 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 157 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 160 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 161 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 162 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 163 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 164 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 165 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 168 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 169 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 172 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 173 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 176 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 177 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 178 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 179 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 180 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 183 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 184 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 185 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 186 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 187 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 190 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertyGetter((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 191 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertySetter((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 192 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyval.sn), (yyvsp[(2) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 193 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 196 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 197 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 201 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 202 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 203 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 204 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 205 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 206 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 207 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 208 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 209 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 212 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 213 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 216 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 217 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 220 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 221 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 224 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 225 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 226 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 227 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 228 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 229 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 232 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 233 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 234 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 235 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 236 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 237 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 240 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 241 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 244 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 245 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 246 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 247 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 250 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 251 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 254 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 255 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 297 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 298 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 299 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 300 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 304 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 305 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 306 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 307 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 308 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 311 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 312 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 315 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 316 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 317 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 320 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 321 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 324 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 325 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 326 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 329 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 330 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 331 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 332 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 333 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 336 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 337 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 340 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 341 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 342 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 343 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 344 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 345 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 346 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 347 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 348 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 349 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 352 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 353 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 356 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 357 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 358 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 359 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 362 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 363 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 366 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 369 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 370 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 371 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 372 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 375 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 376 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 379 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 380 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 383 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 384 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 387 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 388 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 391 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 392 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 395 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 396 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 400 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 401 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 402 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 403 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 406 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 409 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 410 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 411 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 412 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 416 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 417 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 418 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 419 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 420 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 421 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 422 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 423 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 426 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 427 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 430 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 431 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 432 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 433 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 436 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 437 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 440 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 441 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3639 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



