
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
#line 6 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 176 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#define YYLAST   1002

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNRULES -- Number of states.  */
#define YYNSTATES  453

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
      90,    92,    94,    96,    99,   101,   105,   107,   109,   113,
     117,   122,   125,   127,   131,   133,   136,   138,   142,   148,
     155,   160,   167,   175,   181,   184,   189,   191,   196,   198,
     202,   204,   207,   209,   211,   213,   217,   222,   226,   230,
     234,   238,   244,   250,   256,   262,   265,   270,   274,   276,
     279,   281,   284,   287,   292,   294,   296,   300,   302,   304,
     307,   309,   313,   315,   319,   324,   329,   334,   340,   343,
     347,   352,   358,   364,   371,   378,   380,   383,   386,   390,
     394,   399,   404,   411,   416,   421,   428,   430,   433,   435,
     438,   440,   444,   448,   453,   458,   463,   469,   475,   477,
     480,   484,   488,   492,   498,   500,   503,   505,   508,   511,
     514,   516,   519,   522,   527,   529,   531,   533,   535,   537,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   558,
     561,   563,   565,   567,   569,   571,   573,   575,   577,   579,
     581,   583,   585,   587,   589,   591,   593,   595,   597,   599,
     601,   607,   614,   621,   629,   632,   636,   640,   644,   650,
     652,   655,   657,   660,   663,   665,   668,   673,   679,   685,
     688,   692,   696,   700,   706,   709,   713,   715,   717,   719,
     721,   723,   725,   727,   729,   732,   735,   737,   740,   742,
     744,   747,   750,   752,   756,   761,   764,   770,   773,   779,
     781,   785,   789,   794,   797,   802,   804,   807,   809,   812,
     814,   817,   819,   821,   825,   829,   835,   838,   843,   849,
     856,   858,   860,   862,   864,   866,   868,   871,   874,   876,
     879,   881,   883,   886,   889,   894,   900,   901
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     148,     0,    -1,    63,    -1,    46,    -1,    47,    -1,    54,
      47,    -1,    55,    47,    -1,    48,    -1,    49,    -1,    49,
      51,    -1,    54,    49,    -1,    54,    49,    51,    -1,    55,
      49,    -1,    55,    49,    51,    -1,    50,    -1,    50,    51,
      -1,    54,    50,    -1,    54,    50,    51,    -1,    55,    50,
      -1,    55,    50,    51,    -1,    50,    50,    -1,    50,    50,
      51,    -1,    54,    50,    50,    -1,    54,    50,    50,    51,
      -1,    55,    50,    50,    -1,    55,    50,    50,    51,    -1,
      51,    -1,    54,    51,    -1,    54,    -1,    55,    51,    -1,
      55,    -1,    52,    -1,    53,    -1,    50,    53,    -1,    56,
      -1,    76,    25,    77,    -1,    76,    -1,    83,    -1,    84,
       3,    83,    -1,     9,    84,    10,    -1,     9,    84,     3,
      10,    -1,     9,    10,    -1,    76,    -1,    86,     3,    76,
      -1,    76,    -1,    85,    76,    -1,    87,    -1,    88,     3,
      87,    -1,    58,    76,    11,    88,    12,    -1,    58,    76,
      11,    88,     3,    12,    -1,    58,    76,    11,    12,    -1,
      58,    59,    76,    11,    88,    12,    -1,    58,    59,    76,
      11,    88,     3,    12,    -1,    58,    59,    76,    11,    12,
      -1,    89,     6,    -1,    89,    25,    77,     6,    -1,    76,
      -1,    76,    13,    95,    14,    -1,    91,    -1,    92,    75,
      91,    -1,    92,    -1,    75,    92,    -1,    82,    -1,    93,
      -1,    94,    -1,    95,     3,    94,    -1,    66,    94,    76,
       6,    -1,    67,    76,     6,    -1,    58,    76,     6,    -1,
      60,    76,     6,    -1,    59,    76,     6,    -1,    67,    76,
      25,    77,     6,    -1,    58,    76,    25,    77,     6,    -1,
      60,    76,    25,    77,     6,    -1,    59,    76,    25,    77,
       6,    -1,    94,    76,    -1,    94,    76,     9,    10,    -1,
      94,    15,    76,    -1,    97,    -1,    64,    97,    -1,    98,
      -1,    61,    98,    -1,    99,     6,    -1,    99,    25,    77,
       6,    -1,    69,    -1,   101,    -1,   101,    25,    77,    -1,
      70,    -1,   103,    -1,   103,    80,    -1,   104,    -1,   104,
      25,    77,    -1,    76,    -1,    76,     9,    10,    -1,    76,
       9,    80,    10,    -1,    76,     9,    15,    10,    -1,    76,
       9,    94,    10,    -1,    76,     9,    94,    15,    10,    -1,
      94,   106,    -1,    94,    15,   106,    -1,   107,    11,    12,
       6,    -1,   107,    11,   102,    12,     6,    -1,   107,    11,
     105,    12,     6,    -1,   107,    11,   102,   105,    12,     6,
      -1,   107,    11,   105,   102,    12,     6,    -1,   108,    -1,
      61,   108,    -1,    94,    76,    -1,    94,    15,    76,    -1,
      94,    16,    76,    -1,    94,    15,    15,    76,    -1,    94,
      17,    15,    76,    -1,    94,    17,     9,    10,    15,    76,
      -1,    94,    15,    16,    76,    -1,    94,    17,    16,    76,
      -1,    94,    17,     9,    10,    16,    76,    -1,   110,    -1,
      64,   110,    -1,   111,    -1,   111,    80,    -1,   112,    -1,
     113,     3,   112,    -1,    76,     7,     8,    -1,    76,     7,
      63,     8,    -1,    76,     7,   113,     8,    -1,    76,     7,
       8,    64,    -1,    76,     7,    63,     8,    64,    -1,    76,
       7,   113,     8,    64,    -1,   114,    -1,    94,   114,    -1,
      94,    16,   114,    -1,    94,    15,   114,    -1,    94,    17,
     114,    -1,    94,    17,     9,    10,   114,    -1,   115,    -1,
      64,   115,    -1,   116,    -1,    68,   116,    -1,    62,   116,
      -1,    61,   116,    -1,   117,    -1,    74,   117,    -1,   118,
       6,    -1,   118,    25,    77,     6,    -1,    18,    -1,    19,
      -1,    15,    -1,    20,    -1,    21,    -1,    17,    -1,    16,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    13,
      -1,    14,    -1,     3,    -1,     9,    10,    -1,     7,     8,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    36,    -1,    37,
      -1,    34,    -1,    35,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    65,   120,     7,     8,     6,    -1,    65,   120,     7,
     113,     8,     6,    -1,    65,   120,     7,     8,    64,     6,
      -1,    65,   120,     7,   113,     8,    64,     6,    -1,    94,
     121,    -1,    94,    16,   121,    -1,    94,    15,   121,    -1,
      94,    17,   121,    -1,    94,    17,     9,    10,   121,    -1,
     122,    -1,    64,   122,    -1,   123,    -1,    68,   123,    -1,
      62,   123,    -1,   124,    -1,    74,   124,    -1,    76,     7,
       8,     6,    -1,    76,     7,    63,     8,     6,    -1,    76,
       7,   113,     8,     6,    -1,    94,   126,    -1,    94,    16,
     126,    -1,    94,    15,   126,    -1,    94,    17,   126,    -1,
      94,    17,     9,    10,   126,    -1,    79,   127,    -1,    79,
      64,   127,    -1,   100,    -1,   109,    -1,   119,    -1,   125,
      -1,   140,    -1,   128,    -1,    90,    -1,    96,    -1,    72,
     129,    -1,    71,   129,    -1,   129,    -1,    85,   129,    -1,
     130,    -1,     6,    -1,   131,   130,    -1,   131,     6,    -1,
      76,    -1,   132,     3,    76,    -1,    78,    13,   132,    14,
      -1,    59,    76,    -1,    59,     7,    86,     8,    76,    -1,
      60,    76,    -1,    60,     7,    86,     8,    76,    -1,   134,
      -1,   134,     5,    95,    -1,   135,    11,    12,    -1,   135,
      11,   131,    12,    -1,   136,     6,    -1,   136,    25,    77,
       6,    -1,   137,    -1,    68,   137,    -1,   138,    -1,    74,
     138,    -1,   139,    -1,   133,   139,    -1,    76,    -1,   120,
      -1,   141,     3,    76,    -1,   141,     3,   120,    -1,    73,
      76,    13,    95,    14,    -1,   142,     6,    -1,   142,    11,
      12,     6,    -1,   142,    11,   141,    12,     6,    -1,   142,
      11,   141,     3,    12,     6,    -1,   140,    -1,   128,    -1,
      90,    -1,   143,    -1,    96,    -1,   147,    -1,    72,   144,
      -1,    71,   144,    -1,   144,    -1,    85,   144,    -1,   145,
      -1,     6,    -1,   146,   145,    -1,   146,     6,    -1,    57,
      76,    11,    12,    -1,    57,    76,    11,   146,    12,    -1,
      -1,   146,    -1
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
     143,   144,   147,   148,   152,   156,   157,   160,   163,   164,
     167,   168,   171,   172,   173,   174,   175,   176,   179,   180,
     183,   184,   185,   186,   187,   190,   191,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   206,   207,   210,   211,
     214,   215,   218,   219,   220,   221,   222,   223,   226,   227,
     228,   229,   230,   231,   234,   235,   238,   239,   240,   241,
     244,   245,   248,   249,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     291,   292,   293,   294,   298,   299,   300,   301,   302,   305,
     306,   309,   310,   311,   314,   315,   318,   319,   320,   323,
     324,   325,   326,   327,   330,   331,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   346,   347,   350,   351,
     352,   353,   356,   357,   360,   363,   364,   365,   366,   369,
     370,   373,   374,   377,   378,   381,   382,   385,   386,   389,
     390,   394,   395,   396,   397,   400,   403,   404,   405,   406,
     410,   411,   412,   413,   414,   415,   416,   417,   420,   421,
     424,   425,   426,   427,   430,   431,   434,   435
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
  "primitive", "attribute", "attributeList", "attributes", "identifyList",
  "enumerator", "enumeratorList", "enum_0", "enum", "scopeName",
  "scopeNameList_0", "scopeNameList", "typeName", "typeNameList",
  "typeAlias", "field_0", "field_1", "field_2", "field", "getter_0",
  "getter", "setter_0", "setter_1", "setter", "property_0", "property_1",
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
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   102,   102,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   126,   126,   126,   127,
     127,   127,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   134,   134,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   141,   142,   143,   143,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   145,
     146,   146,   146,   146,   147,   147,   148,   148
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
       1,     2,     2,     4,     1,     1,     3,     1,     1,     2,
       1,     3,     1,     3,     4,     4,     4,     5,     2,     3,
       4,     5,     5,     6,     6,     1,     2,     2,     3,     3,
       4,     4,     6,     4,     4,     6,     1,     2,     1,     2,
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
     266,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   254,
     251,     0,   229,     0,     0,   235,   237,   239,   250,     0,
     253,   258,   260,   267,   255,     0,    41,    36,    37,     0,
       0,     0,     0,     0,   225,     0,   227,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
      56,    62,    58,    60,    63,     0,     0,     0,     0,   236,
     257,   256,     0,   238,     0,     0,     0,   204,   259,    54,
       0,   240,     0,     0,   233,     0,   246,     0,   263,   262,
       1,     0,     0,    39,     0,     0,    68,     0,     0,    42,
       0,    70,     0,     0,    69,     0,     9,    20,    15,    33,
       5,    10,    16,    27,     6,    12,    18,    29,    61,     0,
       0,     0,    67,     0,   225,   227,     0,   222,     0,   205,
       0,     0,     0,     0,   199,     0,    64,   230,   219,   231,
       0,     0,     0,     0,     0,     0,     0,    56,     0,   212,
       0,   213,    78,    80,     0,   206,     0,   105,   207,   128,
     134,   136,   140,     0,   208,   189,   191,   194,   209,   211,
     216,   218,     0,   210,     0,   157,     0,     0,     0,   155,
     156,   146,   150,   149,   144,   145,   147,   148,   151,   152,
     153,   154,   160,   161,   162,   163,   164,   165,   166,   167,
     170,   171,   168,   169,   172,   173,   174,   175,   176,   177,
     178,   179,   241,   242,     0,    35,    40,    38,   264,     0,
       0,    50,    44,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    21,    11,    22,    17,    13,    24,    19,     0,
      59,    66,     0,     0,     0,   224,   201,   200,     0,   202,
       0,    55,     0,     0,     0,    81,   106,   139,     0,     0,
     138,   193,     0,    79,   135,   190,   137,   192,   215,   214,
       0,   141,   195,     0,   217,     0,     0,     0,     0,    75,
      98,   129,   184,    82,     0,     0,   142,     0,   221,   232,
     220,   234,   159,   158,   247,     0,     0,   265,    53,     0,
      45,     0,    48,    72,    43,   226,    74,   228,    73,    23,
      25,    57,    71,   245,   223,     0,     0,     2,     0,     0,
     116,   118,   120,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,   122,     2,     0,    77,    99,
     131,   186,   130,   185,     0,   132,   187,     0,     0,     0,
       0,    84,    87,    85,     0,    88,    90,     0,     0,     0,
     243,   244,   248,     0,    51,    49,    47,   203,   196,     0,
     117,     0,     0,     0,   107,   119,     0,     0,     0,     0,
      77,     0,     0,   125,   123,   124,     0,     0,     0,    76,
       0,     0,     0,    83,   100,     0,     0,     0,    89,     0,
       0,     0,   143,   249,    52,   197,     0,     0,   108,   109,
       0,     0,     0,   121,   198,     0,    76,   126,   127,    93,
     133,   188,     0,     0,    95,    94,    96,     0,    86,   101,
       0,    91,   102,     0,   110,   113,     0,   111,   114,   180,
       0,     0,    97,   103,   104,     0,     0,   182,   181,     0,
     112,   115,   183
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    38,    39,    16,   100,   224,   225,    17,    18,
      62,    63,    64,   150,   137,    19,   152,   153,   154,   155,
     353,   354,   355,   356,   357,   280,   156,   157,   158,   320,
     321,   322,   323,   159,   160,   161,   162,   163,   164,   213,
     282,   165,   166,   167,   168,   134,    77,    20,   170,   171,
     172,   128,    21,    22,    23,    24,    25,    26,    27,    28,
     214,    29,    30,    31,    32,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -254
static const yytype_int16 yypact[] =
{
     480,  -254,    15,   -27,    89,    16,    19,   894,    -3,   370,
     923,   923,    81,   196,   223,   739,   923,    44,  -254,  -254,
    -254,   194,   180,   229,    52,  -254,  -254,  -254,  -254,   227,
    -254,  -254,  -254,   504,  -254,   261,  -254,   244,  -254,   184,
     284,   207,   136,   239,    53,   239,   135,  -254,  -254,  -254,
     252,   375,  -254,  -254,  -254,   310,   321,  -254,  -254,   251,
     327,  -254,  -254,   270,  -254,   282,   144,    20,    24,  -254,
    -254,  -254,   349,  -254,   290,   894,    40,  -254,  -254,  -254,
     296,  -254,   894,   150,  -254,   305,  -254,   371,  -254,  -254,
    -254,   361,    23,  -254,   264,   366,  -254,    25,   363,  -254,
      43,  -254,   367,   272,  -254,   369,  -254,   437,  -254,  -254,
    -254,   439,   382,  -254,  -254,   443,   385,  -254,   270,   894,
     251,   481,  -254,   418,  -254,  -254,   894,  -254,    38,  -254,
     424,   424,    11,   494,  -254,   496,  -254,   502,  -254,  -254,
     770,   801,   912,   708,   674,   674,   468,   138,   674,  -254,
     155,  -254,  -254,  -254,   182,  -254,   495,  -254,  -254,  -254,
    -254,  -254,  -254,   217,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,   238,  -254,   501,  -254,   500,   499,   505,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,    41,  -254,  -254,  -254,  -254,   425,
      26,  -254,  -254,   449,  -254,   146,   520,   457,   458,   529,
     465,   536,  -254,  -254,   498,  -254,  -254,   506,  -254,   149,
    -254,  -254,   539,   170,   484,  -254,  -254,  -254,   546,  -254,
     300,  -254,   894,   912,    46,  -254,  -254,  -254,   912,   176,
    -254,  -254,   242,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
     832,  -254,  -254,   576,  -254,    88,   172,     5,   673,   410,
    -254,  -254,  -254,  -254,   488,    48,  -254,   489,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,   436,   561,  -254,  -254,   262,
    -254,    27,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,   424,   563,   566,   894,    49,
    -254,   517,  -254,   274,  -254,   151,   503,   509,    12,   172,
     573,   195,    67,   912,   159,   534,   591,   325,   411,  -254,
    -254,  -254,  -254,  -254,   571,  -254,  -254,   593,   540,   595,
     596,  -254,  -254,   594,     1,   538,   610,    55,   630,   631,
    -254,  -254,  -254,    33,  -254,  -254,  -254,  -254,  -254,   635,
    -254,   139,   567,   263,  -254,  -254,   863,   636,   568,   637,
     573,   638,   509,  -254,   581,   582,   558,   172,   609,   639,
     643,   644,   319,  -254,  -254,   572,   660,   655,  -254,   592,
     662,   658,  -254,  -254,  -254,  -254,   598,   599,  -254,  -254,
     661,   601,   602,  -254,  -254,   509,  -254,  -254,  -254,  -254,
    -254,  -254,    34,   336,  -254,  -254,  -254,   669,  -254,  -254,
     675,  -254,  -254,   677,  -254,  -254,   426,  -254,  -254,  -254,
     713,    66,  -254,  -254,  -254,   663,   667,  -254,  -254,   725,
    -254,  -254,  -254
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,  -254,   652,  -254,   -82,   702,  -253,   531,  -254,   -65,
     645,   707,  -254,    -7,   -72,   -59,  -130,   629,  -254,  -254,
    -254,   413,  -254,  -254,   419,  -144,  -254,   634,  -254,   459,
    -254,   399,  -251,  -148,  -138,  -124,   632,  -254,  -254,   -46,
    -247,  -132,   224,   633,  -254,  -125,   701,   -51,   279,   608,
    -254,  -254,  -254,  -254,  -254,  -254,     0,    -2,   760,   -40,
    -254,  -254,  -254,   309,   -30,   688,  -254,  -254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const yytype_int16 yytable[] =
{
      65,   148,   281,    89,   264,   246,   247,   249,    76,    69,
     265,    73,   263,   396,   344,   223,   257,   260,   149,   266,
     248,   379,   337,    43,   151,    36,    45,    43,   341,   343,
     346,    45,   169,   216,     2,     2,     2,   221,   298,   365,
     439,   244,     2,   173,   295,   404,   227,   239,   366,    40,
      79,   228,   245,   296,   243,   130,   131,   132,    84,   101,
     350,   326,   327,   328,   371,   372,   373,   400,    76,    80,
     278,   352,   448,    66,   273,   136,   381,    85,   102,   149,
     149,   330,   341,   149,   341,   151,   151,   133,   330,   151,
     148,    37,    44,   169,   169,    46,   124,   169,   440,    37,
     125,   222,   222,   222,   173,   173,   281,   149,   173,   222,
     366,   281,   136,   151,   281,   264,   133,   351,   352,   136,
     264,   169,   279,   263,   351,   374,   265,   340,   342,   345,
     449,   339,   173,   254,   259,   262,   259,   423,   223,   259,
     421,   104,    96,    69,    73,   273,   257,    97,    41,   301,
     122,   119,   252,   278,   406,   407,   138,    72,   302,     2,
     105,    98,   139,   311,   338,    42,   378,   327,   328,   123,
     275,   276,   277,   252,   382,   327,   328,   281,   340,   342,
     345,   340,   339,   340,   313,    82,   281,    92,   283,    89,
     367,   329,   276,   277,    93,   264,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   284,     4,     5,
       6,   140,   141,    58,   142,   408,     7,     8,   143,   223,
     278,   144,   145,   286,   146,    59,   147,   332,    14,    15,
     340,   279,   347,    86,   340,   330,    74,   278,    87,   420,
      83,   278,   287,   319,   288,   324,   325,     2,   330,   361,
     289,   259,   330,    67,    68,    67,    68,   331,   276,   277,
     278,    90,     9,   334,     9,   363,   319,   420,    13,    91,
       1,   380,   410,     2,   364,   227,   218,   376,   411,   412,
     230,   223,   377,    95,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    94,     4,     5,     6,   140,
     141,    58,   142,   106,     7,     8,   143,   278,   316,   144,
     145,   319,   146,    59,   147,    99,    14,    15,   332,    70,
      71,     3,     4,     5,     6,    78,   334,    60,   376,   426,
       7,     8,     9,   385,   427,    10,    11,    12,    13,   376,
     119,   392,    14,    15,   441,   120,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   110,   121,   111,
     112,   113,   126,   317,   318,   261,   127,   267,   114,   319,
     115,   116,   117,   135,   175,    59,    60,   220,   176,   392,
     177,   319,   174,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   273,   273,   348,
     386,   -92,   -92,   268,   269,   107,   108,   274,   109,    67,
      68,    88,   234,   235,     2,   237,   238,   297,   215,   175,
     226,   445,   446,   176,   229,   177,   231,   212,   359,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     3,     4,     5,     6,     1,   241,   232,     2,
     233,     7,     8,     9,   236,   242,    10,    11,    12,    13,
     133,   250,   251,    14,    15,   252,   285,   291,   292,   293,
      88,   294,   360,     2,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   300,   303,    67,    68,   270,
     141,    58,   258,   304,   305,   306,   143,     3,     4,     5,
       6,   307,   308,    59,   147,   312,     7,     8,     9,   309,
     389,    10,    11,    12,    13,   390,   315,   310,    14,    15,
     314,     3,     4,     5,     6,   349,   358,   362,   419,   368,
       7,     8,     9,   390,   369,    10,    11,    12,    13,   338,
     273,   387,    14,    15,   335,   330,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   375,   383,   384,
     388,   393,   394,    58,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    59,    60,   422,   398,   395,
     391,    58,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    59,    60,   399,   402,   403,   391,   336,
     318,   405,   414,   409,   380,   417,   418,   415,   416,   428,
     -93,    59,    60,   424,   425,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   429,   430,   432,   431,
     433,   436,    58,   318,   434,   435,   175,   437,   438,   442,
     176,   443,   177,   444,    59,    60,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   447,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   452,     4,     5,     6,   140,   141,    58,   142,   450,
       7,     8,   143,   451,   217,   144,   145,   103,   146,    59,
     147,   299,    14,    15,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   240,   118,    67,    68,   255,
     401,    58,   258,   397,   256,   413,   129,   370,   271,   272,
     290,    81,   219,    59,   147,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,    58,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,    58,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,   147,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,   147,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,    58,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,   147,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    58,   318,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,    58,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    59,
      60,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       3,     4,     5,     6,     0,     0,     0,    59,   147,     7,
       8,     9,     0,     0,    10,    11,    12,    13,     0,     0,
       0,    14,    15
};

static const yytype_int16 yycheck[] =
{
       7,    83,   150,    33,   142,   130,   131,   132,    15,     9,
     142,    13,   142,    12,     9,    97,   140,   141,    83,   143,
       9,     9,   273,     7,    83,    10,     7,     7,   275,   276,
     277,     7,    83,    10,     9,     9,     9,    12,    12,    12,
       6,     3,     9,    83,     3,    12,     3,   119,   301,    76,
       6,     8,    14,    12,   126,    15,    16,    17,     6,     6,
      12,    15,    16,    17,    15,    16,    17,    12,    75,    25,
      65,    70,     6,    76,     7,    82,     9,    25,    25,   144,
     145,    76,   329,   148,   331,   144,   145,    76,    76,   148,
     172,    76,    76,   144,   145,    76,    76,   148,    64,    76,
      76,    76,    76,    76,   144,   145,   254,   172,   148,    76,
     363,   259,   119,   172,   262,   253,    76,    69,    70,   126,
     258,   172,    76,   253,    69,    76,   258,   275,   276,   277,
      64,   275,   172,   140,   141,   142,   143,   388,   220,   146,
     387,     6,     6,   143,   146,     7,   270,    11,    59,     3,
       6,    13,     3,    65,    15,    16,     6,    76,    12,     9,
      25,    25,    12,    14,    76,    76,    15,    16,    17,    25,
      15,    16,    17,     3,    15,    16,    17,   325,   326,   327,
     328,   329,   326,   331,    14,     5,   334,     3,     6,   219,
     315,    15,    16,    17,    10,   333,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    25,    58,    59,
      60,    61,    62,    63,    64,    76,    66,    67,    68,   301,
      65,    71,    72,     6,    74,    75,    76,    76,    78,    79,
     378,    76,   278,     6,   382,    76,    13,    65,    11,   387,
      11,    65,    25,   250,     6,   252,   253,     9,    76,   295,
      12,   258,    76,    59,    60,    59,    60,    15,    16,    17,
      65,     0,    68,   270,    68,     3,   273,   415,    74,    25,
       6,    76,     9,     9,    12,     3,    12,     3,    15,    16,
       8,   363,     8,    76,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    11,    58,    59,    60,    61,
      62,    63,    64,    51,    66,    67,    68,    65,     8,    71,
      72,   318,    74,    75,    76,    76,    78,    79,    76,    10,
      11,    57,    58,    59,    60,    16,   333,    76,     3,    10,
      66,    67,    68,     8,    15,    71,    72,    73,    74,     3,
      13,   348,    78,    79,     8,    75,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    47,    76,    49,
      50,    51,    13,    63,    64,   141,    76,   143,    47,   376,
      49,    50,    51,    77,     3,    75,    76,    11,     7,   386,
       9,   388,    77,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     7,     7,     9,
       9,    11,    11,   144,   145,    50,    51,   148,    53,    59,
      60,     6,    50,    51,     9,    50,    51,    12,    77,     3,
      77,    15,    16,     7,    77,     9,    77,    76,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    57,    58,    59,    60,     6,     6,    51,     9,
      51,    66,    67,    68,    51,    77,    71,    72,    73,    74,
      76,     7,     6,    78,    79,     3,    11,     6,     8,    10,
       6,     6,    76,     9,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    76,     6,    59,    60,    61,
      62,    63,    64,    76,    76,     6,    68,    57,    58,    59,
      60,    76,     6,    75,    76,     6,    66,    67,    68,    51,
      10,    71,    72,    73,    74,    15,    10,    51,    78,    79,
      76,    57,    58,    59,    60,    77,    77,     6,    10,     6,
      66,    67,    68,    15,     8,    71,    72,    73,    74,    76,
       7,    10,    78,    79,     8,    76,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    80,    64,     8,
       7,     6,     6,    63,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    75,    76,     8,    80,    25,
      80,    63,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    75,    76,    25,     6,     6,    80,    63,
      64,     6,     6,    76,    76,    64,    64,    10,    10,    77,
      11,    75,    76,    10,    10,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     6,    12,     6,    77,
      12,    10,    63,    64,    76,    76,     3,    76,    76,    10,
       7,     6,     9,     6,    75,    76,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     6,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     6,    58,    59,    60,    61,    62,    63,    64,    76,
      66,    67,    68,    76,    92,    71,    72,    45,    74,    75,
      76,   220,    78,    79,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,   120,    59,    59,    60,   140,
     357,    63,    64,   354,   140,   376,    75,   318,   146,   146,
     172,    21,    94,    75,    76,    46,    47,    48,    49,    50,
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
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    75,
      76,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    75,    76,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    57,    58,    59,    60,    66,    67,    68,
      71,    72,    73,    74,    78,    79,    85,    89,    90,    96,
     128,   133,   134,   135,   136,   137,   138,   139,   140,   142,
     143,   144,   145,   146,   147,   148,    10,    76,    83,    84,
      76,    59,    76,     7,    76,     7,    76,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    63,    75,
      76,    82,    91,    92,    93,    94,    76,    59,    60,   137,
     144,   144,    76,   138,    13,    64,    94,   127,   144,     6,
      25,   139,     5,    11,     6,    25,     6,    11,     6,   145,
       0,    25,     3,    10,    11,    76,     6,    11,    25,    76,
      86,     6,    25,    86,     6,    25,    51,    50,    51,    53,
      47,    49,    50,    51,    47,    49,    50,    51,    92,    13,
      75,    76,     6,    25,    76,    76,    13,    76,   132,   127,
      15,    16,    17,    76,   126,    77,    94,    95,     6,    12,
      61,    62,    64,    68,    71,    72,    74,    76,    85,    90,
      94,    96,    97,    98,    99,   100,   107,   108,   109,   114,
     115,   116,   117,   118,   119,   122,   123,   124,   125,   128,
     129,   130,   131,   140,    77,     3,     7,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    76,   120,   141,    77,    10,    83,    12,   146,
      11,    12,    76,    85,    87,    88,    77,     3,     8,    77,
       8,    77,    51,    51,    50,    51,    51,    50,    51,    95,
      91,     6,    77,    95,     3,    14,   126,   126,     9,   126,
       7,     6,     3,    64,    94,    98,   108,   116,    64,    94,
     116,   123,    94,    97,   115,   122,   116,   123,   129,   129,
      61,   117,   124,     7,   129,    15,    16,    17,    65,    76,
     106,   114,   121,     6,    25,    11,     6,    25,     6,    12,
     130,     6,     8,    10,     6,     3,    12,    12,    12,    88,
      76,     3,    12,     6,    76,    76,     6,    76,     6,    51,
      51,    14,     6,    14,    76,    10,     8,    63,    64,    94,
     110,   111,   112,   113,    94,    94,    15,    16,    17,    15,
      76,    15,    76,    64,    94,     8,    63,   113,    76,   106,
     114,   121,   114,   121,     9,   114,   121,   120,     9,    77,
      12,    69,    70,   101,   102,   103,   104,   105,    77,    12,
      76,   120,     6,     3,    12,    12,    87,   126,     6,     8,
     110,    15,    16,    17,    76,    80,     3,     8,    15,     9,
      76,     9,    15,    64,     8,     8,     9,    10,     7,    10,
      15,    80,    94,     6,     6,    25,    12,   105,    80,    25,
      12,   102,     6,     6,    12,     6,    15,    16,    76,    76,
       9,    15,    16,   112,     6,    10,    10,    64,    64,    10,
     114,   121,     8,   113,    10,    10,    10,    15,    77,     6,
      12,    77,     6,    12,    76,    76,    10,    76,    76,     6,
      64,     8,    10,     6,     6,    15,    16,     6,     6,    64,
      76,    76,     6
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
#line 156 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 157 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 160 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 163 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 164 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 167 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 168 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 171 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 172 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 173 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 174 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), list_property);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 175 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 176 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 179 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 180 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 183 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 184 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 185 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 186 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(4) - (6)].sn));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 187 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 191 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 195 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 196 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 197 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 198 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 199 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 200 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 201 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 202 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 203 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 206 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 207 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 210 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 211 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 214 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 215 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 218 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 219 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 220 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 221 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 222 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 223 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 226 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 227 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 228 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 229 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 230 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 231 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 234 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 235 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 238 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 239 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 240 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 241 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 244 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 245 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 248 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 249 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 291 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 292 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 293 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 294 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 298 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 299 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 300 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 301 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 302 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 305 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 306 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 309 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 310 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 311 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 314 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 315 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 318 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 319 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 320 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 323 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 324 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 325 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 326 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 327 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 330 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 331 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 334 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 335 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 336 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 337 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 338 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 339 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 340 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 341 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 342 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 343 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 346 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 347 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 350 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 351 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 352 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 353 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 356 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 357 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 360 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 363 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 364 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 365 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 366 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 369 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 370 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 373 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 374 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 377 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 378 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 381 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 382 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 385 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 386 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 389 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 390 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 394 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 395 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 396 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 397 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 400 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 403 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 404 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 405 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 406 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 410 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 411 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 412 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 413 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 414 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 415 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 416 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 417 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 420 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 421 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 424 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 425 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 426 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 427 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 430 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 431 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 434 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 435 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3554 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



