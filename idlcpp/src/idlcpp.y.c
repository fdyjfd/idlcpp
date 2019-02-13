
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
#define YYLAST   941

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  272
/* YYNRULES -- Number of states.  */
#define YYNSTATES  459

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
       7,     8,    15,    17,     3,    19,     4,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     6,
      13,    25,    14,    80,     2,     2,     2,     2,     2,     2,
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
     279,   281,   284,   287,   292,   294,   296,   299,   301,   305,
     307,   309,   312,   314,   317,   319,   323,   325,   329,   334,
     339,   344,   350,   353,   357,   362,   368,   374,   381,   388,
     390,   393,   396,   400,   404,   408,   413,   418,   423,   428,
     435,   442,   444,   447,   449,   452,   454,   458,   462,   467,
     472,   477,   483,   489,   491,   494,   498,   502,   506,   512,
     514,   517,   519,   522,   525,   528,   530,   533,   536,   541,
     543,   545,   547,   549,   551,   553,   555,   557,   559,   561,
     563,   565,   567,   569,   572,   575,   577,   579,   581,   583,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   603,
     605,   607,   609,   611,   613,   615,   621,   628,   635,   643,
     646,   650,   654,   658,   664,   666,   669,   671,   674,   677,
     679,   682,   687,   693,   699,   702,   706,   710,   714,   720,
     723,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     746,   749,   751,   754,   756,   758,   761,   764,   766,   770,
     775,   778,   784,   787,   793,   795,   799,   803,   808,   811,
     816,   818,   821,   823,   826,   828,   831,   833,   835,   839,
     843,   849,   852,   857,   863,   870,   872,   874,   876,   878,
     880,   882,   885,   888,   890,   893,   895,   897,   900,   903,
     908,   914,   915
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     150,     0,    -1,    63,    -1,    46,    -1,    47,    -1,    54,
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
       6,    -1,    69,    -1,   101,    -1,   101,    17,    -1,   102,
      -1,   102,    25,    77,    -1,    70,    -1,   104,    -1,   104,
      19,    -1,   105,    -1,   105,    80,    -1,   106,    -1,   106,
      25,    77,    -1,    76,    -1,    76,     9,    10,    -1,    76,
       9,    80,    10,    -1,    76,     9,    15,    10,    -1,    76,
       9,    94,    10,    -1,    76,     9,    94,    15,    10,    -1,
      94,   108,    -1,    94,    15,   108,    -1,   109,    11,    12,
       6,    -1,   109,    11,   103,    12,     6,    -1,   109,    11,
     107,    12,     6,    -1,   109,    11,   103,   107,    12,     6,
      -1,   109,    11,   107,   103,    12,     6,    -1,   110,    -1,
      61,   110,    -1,    94,    76,    -1,    94,    16,    76,    -1,
      94,    15,    76,    -1,    94,    19,    76,    -1,    94,    15,
      16,    76,    -1,    94,    15,    15,    76,    -1,    94,    17,
      16,    76,    -1,    94,    17,    15,    76,    -1,    94,    17,
       9,    10,    16,    76,    -1,    94,    17,     9,    10,    15,
      76,    -1,   112,    -1,    64,   112,    -1,   113,    -1,   113,
      80,    -1,   114,    -1,   115,     3,   114,    -1,    76,     7,
       8,    -1,    76,     7,    63,     8,    -1,    76,     7,   115,
       8,    -1,    76,     7,     8,    64,    -1,    76,     7,    63,
       8,    64,    -1,    76,     7,   115,     8,    64,    -1,   116,
      -1,    94,   116,    -1,    94,    16,   116,    -1,    94,    15,
     116,    -1,    94,    17,   116,    -1,    94,    17,     9,    10,
     116,    -1,   117,    -1,    64,   117,    -1,   118,    -1,    68,
     118,    -1,    62,   118,    -1,    61,   118,    -1,   119,    -1,
      74,   119,    -1,   120,     6,    -1,   120,    25,    77,     6,
      -1,    17,    -1,    19,    -1,    15,    -1,    20,    -1,    21,
      -1,    18,    -1,    16,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    13,    -1,    14,    -1,     3,    -1,     9,
      10,    -1,     7,     8,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    36,    -1,    37,    -1,    34,    -1,    35,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    45,    -1,    65,   122,     7,     8,     6,
      -1,    65,   122,     7,   115,     8,     6,    -1,    65,   122,
       7,     8,    64,     6,    -1,    65,   122,     7,   115,     8,
      64,     6,    -1,    94,   123,    -1,    94,    16,   123,    -1,
      94,    15,   123,    -1,    94,    17,   123,    -1,    94,    17,
       9,    10,   123,    -1,   124,    -1,    64,   124,    -1,   125,
      -1,    68,   125,    -1,    62,   125,    -1,   126,    -1,    74,
     126,    -1,    76,     7,     8,     6,    -1,    76,     7,    63,
       8,     6,    -1,    76,     7,   115,     8,     6,    -1,    94,
     128,    -1,    94,    16,   128,    -1,    94,    15,   128,    -1,
      94,    17,   128,    -1,    94,    17,     9,    10,   128,    -1,
      79,   129,    -1,    79,    64,   129,    -1,   100,    -1,   111,
      -1,   121,    -1,   127,    -1,   142,    -1,   130,    -1,    90,
      -1,    96,    -1,    72,   131,    -1,    71,   131,    -1,   131,
      -1,    85,   131,    -1,   132,    -1,     6,    -1,   133,   132,
      -1,   133,     6,    -1,    76,    -1,   134,     3,    76,    -1,
      78,    13,   134,    14,    -1,    59,    76,    -1,    59,     7,
      86,     8,    76,    -1,    60,    76,    -1,    60,     7,    86,
       8,    76,    -1,   136,    -1,   136,     5,    95,    -1,   137,
      11,    12,    -1,   137,    11,   133,    12,    -1,   138,     6,
      -1,   138,    25,    77,     6,    -1,   139,    -1,    68,   139,
      -1,   140,    -1,    74,   140,    -1,   141,    -1,   135,   141,
      -1,    76,    -1,   122,    -1,   143,     3,    76,    -1,   143,
       3,   122,    -1,    73,    76,    13,    95,    14,    -1,   144,
       6,    -1,   144,    11,    12,     6,    -1,   144,    11,   143,
      12,     6,    -1,   144,    11,   143,     3,    12,     6,    -1,
     142,    -1,   130,    -1,    90,    -1,   145,    -1,    96,    -1,
     149,    -1,    72,   146,    -1,    71,   146,    -1,   146,    -1,
      85,   146,    -1,   147,    -1,     6,    -1,   148,   147,    -1,
     148,     6,    -1,    57,    76,    11,    12,    -1,    57,    76,
      11,   148,    12,    -1,    -1,   148,    -1
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
     166,   167,   170,   171,   174,   175,   178,   179,   180,   181,
     182,   183,   186,   187,   190,   191,   192,   193,   194,   197,
     198,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   214,   215,   218,   219,   222,   223,   226,   227,   228,
     229,   230,   231,   234,   235,   236,   237,   238,   239,   242,
     243,   246,   247,   248,   249,   252,   253,   256,   257,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   299,   300,   301,   302,   306,
     307,   308,   309,   310,   313,   314,   317,   318,   319,   322,
     323,   326,   327,   328,   331,   332,   333,   334,   335,   338,
     339,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   354,   355,   358,   359,   360,   361,   364,   365,   368,
     371,   372,   373,   374,   377,   378,   381,   382,   385,   386,
     389,   390,   393,   394,   397,   398,   402,   403,   404,   405,
     408,   411,   412,   413,   414,   418,   419,   420,   421,   422,
     423,   424,   425,   428,   429,   432,   433,   434,   435,   438,
     439,   442,   443
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
  "ABSTRACT", "GET", "SET", "NOMETA", "NOCODE", "EXPORT", "OVERRIDE",
  "SCOPE", "IDENTIFY", "STRING", "TEMPLATE", "DELEGATE", "'?'", "$accept",
  "primitive", "attribute", "attributeList", "attributes", "identifyList",
  "enumerator", "enumeratorList", "enum_0", "enum", "scopeName",
  "scopeNameList_0", "scopeNameList", "typeName", "typeNameList",
  "typeAlias", "field_0", "field_1", "field_2", "field", "getter_0",
  "getter_1", "getter", "setter_0", "setter_1", "setter_2", "setter",
  "property_0", "property_1", "property_2", "property", "parameter_0",
  "parameter_1", "parameter", "parameterList", "method_0", "method_1",
  "method_2", "method_3", "method_4", "method", "operatorSign",
  "operator_0", "operator_1", "operator_2", "operator_3", "operator",
  "delegate_0", "delegate_1", "delegate", "classMember_0", "classMember",
  "classMemberList", "templateParameterList", "templateParameters",
  "class_0", "class_1", "class_2", "class_3", "class_4", "class_5",
  "class", "tokenList", "templateClassInstance_0", "templateClassInstance",
  "namespaceMember_0", "namespaceMember", "namespaceMemberList",
  "namespace", "program", 0
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
      99,    99,   100,   100,   101,   102,   102,   103,   103,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   125,   125,   126,   126,   126,   127,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   134,   134,   135,
     136,   136,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   143,   143,
     144,   145,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   147,   148,   148,   148,   148,   149,
     149,   150,   150
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
       1,     2,     1,     2,     1,     3,     1,     3,     4,     4,
       4,     5,     2,     3,     4,     5,     5,     6,     6,     1,
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
     271,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   259,
     256,     0,   234,     0,     0,   240,   242,   244,   255,     0,
     258,   263,   265,   272,   260,     0,    41,    36,    37,     0,
       0,     0,     0,     0,   230,     0,   232,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
      56,    62,    58,    60,    63,     0,     0,     0,     0,   241,
     262,   261,     0,   243,     0,     0,     0,   209,   264,    54,
       0,   245,     0,     0,   238,     0,   251,     0,   268,   267,
       1,     0,     0,    39,     0,     0,    68,     0,     0,    42,
       0,    70,     0,     0,    69,     0,     9,    20,    15,    33,
       5,    10,    16,    27,     6,    12,    18,    29,    61,     0,
       0,     0,    67,     0,   230,   232,     0,   227,     0,   210,
       0,     0,     0,     0,   204,     0,    64,   235,   224,   236,
       0,     0,     0,     0,     0,     0,     0,    56,     0,   217,
       0,   218,    78,    80,     0,   211,     0,   109,   212,   133,
     139,   141,   145,     0,   213,   194,   196,   199,   214,   216,
     221,   223,     0,   215,     0,   162,     0,     0,     0,   160,
     161,   151,   155,   149,   154,   150,   152,   153,   156,   157,
     158,   159,   165,   166,   167,   168,   169,   170,   171,   172,
     175,   176,   173,   174,   177,   178,   179,   180,   181,   182,
     183,   184,   246,   247,     0,    35,    40,    38,   269,     0,
       0,    50,    44,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    21,    11,    22,    17,    13,    24,    19,     0,
      59,    66,     0,     0,     0,   229,   206,   205,     0,   207,
       0,    55,     0,     0,     0,    81,   110,   144,     0,     0,
     143,   198,     0,    79,   140,   195,   142,   197,   220,   219,
       0,   146,   200,     0,   222,     0,     0,     0,     0,    75,
     102,   134,   189,    82,     0,     0,   147,     0,   226,   237,
     225,   239,   164,   163,   252,     0,     0,   270,    53,     0,
      45,     0,    48,    72,    43,   231,    74,   233,    73,    23,
      25,    57,    71,   250,   228,     0,     0,     2,     0,     0,
     121,   123,   125,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,   127,     2,     0,    77,   103,
     136,   191,   135,   190,     0,   137,   192,     0,     0,     0,
       0,    84,    89,    85,    87,     0,    90,    92,    94,     0,
       0,     0,   248,   249,   253,     0,    51,    49,    47,   208,
     201,     0,   122,     0,     0,     0,     0,   111,   124,     0,
       0,     0,     0,    77,     0,     0,   130,   128,   129,     0,
       0,     0,    76,     0,     0,     0,    83,   104,    86,     0,
       0,     0,    91,    93,     0,     0,     0,   148,   254,    52,
     202,     0,     0,   113,   112,     0,     0,     0,   114,   126,
     203,     0,    76,   131,   132,    97,   138,   193,     0,     0,
      99,    98,   100,     0,    88,   105,     0,    95,   106,     0,
     116,   115,     0,   118,   117,   185,     0,     0,   101,   107,
     108,     0,     0,   187,   186,     0,   120,   119,   188
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    38,    39,    16,   100,   224,   225,    17,    18,
      62,    63,    64,   150,   137,    19,   152,   153,   154,   155,
     353,   354,   355,   356,   357,   358,   359,   280,   156,   157,
     158,   320,   321,   322,   323,   159,   160,   161,   162,   163,
     164,   213,   282,   165,   166,   167,   168,   134,    77,    20,
     170,   171,   172,   128,    21,    22,    23,    24,    25,    26,
      27,    28,   214,    29,    30,    31,    32,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -262
static const yytype_int16 yypact[] =
{
     419,  -262,    95,    69,    73,    19,    23,   833,    84,    10,
     862,   862,    88,   381,   135,   678,   862,   144,  -262,  -262,
    -262,   546,   167,   174,   151,  -262,  -262,  -262,  -262,   221,
    -262,  -262,  -262,   442,  -262,   249,  -262,   236,  -262,    18,
     267,   206,   141,   227,   159,   227,   182,  -262,  -262,  -262,
     269,    72,  -262,  -262,  -262,   534,   665,  -262,  -262,   251,
     329,  -262,  -262,   281,  -262,   288,   214,    26,    64,  -262,
    -262,  -262,   358,  -262,   363,   833,   239,  -262,  -262,  -262,
     394,  -262,   833,   150,  -262,   407,  -262,    22,  -262,  -262,
    -262,   441,    98,  -262,   265,   526,  -262,    65,   462,  -262,
     254,  -262,   463,   472,  -262,   481,  -262,   487,  -262,  -262,
    -262,   506,   396,  -262,  -262,   523,   445,  -262,   281,   833,
     251,   569,  -262,   499,  -262,  -262,   833,  -262,   261,  -262,
     504,   504,    82,   575,  -262,   580,  -262,   584,  -262,  -262,
     709,   740,   851,   647,   613,   613,   406,   372,   613,  -262,
     176,  -262,  -262,  -262,   242,  -262,   582,  -262,  -262,  -262,
    -262,  -262,  -262,   247,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   238,  -262,   601,  -262,   600,   599,   604,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   318,  -262,  -262,  -262,  -262,   364,
      75,  -262,  -262,   537,  -262,   460,   610,   541,   542,   616,
     594,   652,  -262,  -262,   627,  -262,  -262,   631,  -262,   262,
    -262,  -262,   677,   354,   614,  -262,  -262,  -262,   676,  -262,
     299,  -262,   833,   851,   264,  -262,  -262,  -262,   851,   243,
    -262,  -262,   253,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     771,  -262,  -262,   515,  -262,   293,   368,    77,   612,   710,
    -262,  -262,  -262,  -262,   628,   161,  -262,   632,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   374,   698,  -262,  -262,   461,
    -262,    91,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   504,   702,   705,   833,   219,
    -262,   638,  -262,   480,  -262,   344,   644,   660,    87,   368,
     731,   369,   371,   851,   350,   679,   732,   514,   728,  -262,
    -262,  -262,  -262,  -262,   734,  -262,  -262,   738,   479,   741,
     742,  -262,  -262,   729,   724,     2,   733,   670,   726,   101,
     760,   761,  -262,  -262,  -262,    92,  -262,  -262,  -262,  -262,
    -262,   762,  -262,   139,   693,   319,   694,  -262,  -262,   802,
     765,   699,   764,   731,   766,   660,  -262,   713,   714,   497,
     368,   548,   768,   770,   772,   509,  -262,  -262,  -262,   704,
     777,   785,  -262,  -262,   721,   793,   788,  -262,  -262,  -262,
    -262,   725,   730,  -262,  -262,   792,   735,   736,  -262,  -262,
    -262,   660,  -262,  -262,  -262,  -262,  -262,  -262,    67,   533,
    -262,  -262,  -262,   795,  -262,  -262,   801,  -262,  -262,   803,
    -262,  -262,   488,  -262,  -262,  -262,   804,   111,  -262,  -262,
    -262,   737,   752,  -262,  -262,   808,  -262,  -262,  -262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,   716,  -262,   -82,   784,  -183,   611,  -262,   -65,
     712,   774,  -262,    -7,    68,   -63,  -129,   690,  -262,  -262,
    -262,  -262,   477,  -262,  -262,  -262,   482,  -165,  -262,   700,
    -262,   520,  -262,   464,  -261,  -148,  -138,  -124,   695,  -262,
    -262,   -55,  -253,  -132,   286,   696,  -262,  -125,   769,   -56,
     444,   667,  -262,  -262,  -262,  -262,  -262,  -262,     0,    -2,
     824,   -51,  -262,  -262,  -262,   495,   -30,   767,  -262,  -262
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      65,   148,   281,    89,   264,   246,   247,   249,    76,    69,
     265,    73,   337,   263,   400,   223,   257,   260,   149,   266,
     151,    92,   341,   343,   346,   175,    43,   169,    93,   176,
      45,   177,   173,    43,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    76,    67,
      68,    45,   352,   445,     2,   136,   341,   221,   341,   149,
     149,   151,   151,   149,     2,   151,   344,   298,   169,   169,
     148,   248,   169,   173,   173,    44,   382,   173,   212,    46,
       2,     2,   124,   367,   409,    36,   281,   149,   216,   151,
     339,   281,   136,   405,   281,   264,   169,   454,   368,   136,
     264,   173,   107,   108,   263,   109,   265,   340,   342,   345,
     429,   446,    41,   254,   259,   262,   259,   427,   223,   259,
     125,   222,   278,    69,    73,    40,   257,    96,    74,    42,
      79,   222,    97,   330,   411,   412,   138,    84,   133,     2,
      66,   339,   139,   330,    72,   101,    98,   222,   222,    80,
     351,    37,    82,   350,    37,   455,    85,   281,   340,   342,
     345,   340,   368,   340,   102,    83,   281,   239,   104,    89,
     369,   275,   276,   277,   243,   264,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   105,     4,     5,
       6,   140,   141,    58,   142,   413,     7,     8,   143,   223,
     122,   144,   145,   347,   146,    59,   147,    86,    14,    15,
     351,   352,    87,   340,   373,   374,   375,   340,   376,   123,
     363,   278,   426,   319,   288,   324,   325,     2,   283,    90,
     289,   259,   279,   286,   130,   131,   132,   227,   329,   276,
     277,    91,   228,   334,   244,   252,   319,   284,   331,   276,
     277,     1,   287,   426,     2,   245,   311,   218,    94,   326,
     327,   328,    95,   223,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   377,     4,     5,     6,   140,
     141,    58,   142,    99,     7,     8,   143,   316,   278,   144,
     145,   319,   146,    59,   147,   133,    14,    15,   278,   330,
     106,   295,     3,     4,     5,     6,   334,    60,   415,   332,
     296,     7,     8,     9,   416,   417,    10,    11,    12,    13,
     279,   395,   119,    14,    15,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   120,   252,   278,   381,
     327,   328,   317,   318,   121,   385,   327,   328,   313,   338,
      88,   126,   319,     2,    59,    60,   297,   175,   273,   273,
     384,   176,   395,   177,   319,   119,   361,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     332,     3,     4,     5,     6,     1,   330,   261,     2,   267,
       7,     8,     9,   278,   278,    10,    11,    12,    13,   127,
      67,    68,    14,    15,   330,   383,   234,   235,    88,     9,
     362,     2,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   301,   365,    67,    68,   270,   141,    58,
     258,   135,   302,   366,   143,   227,     3,     4,     5,     6,
     230,    59,   147,   379,   174,     7,     8,     9,   380,   392,
      10,    11,    12,    13,   393,   237,   238,    14,    15,     3,
       4,     5,     6,   451,   452,    70,    71,   425,     7,     8,
       9,    78,   393,    10,    11,    12,    13,   379,   215,   432,
      14,    15,   388,   335,   433,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   379,   220,   232,   226,
     229,   447,    58,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    59,    60,   428,   233,   231,   394,
      58,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,    60,   236,   241,   242,   394,   336,   318,
     133,   110,   250,   111,   112,   113,   251,   252,   268,   269,
      59,    60,   274,   285,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    67,    68,   291,   292,   293,
     294,    58,   318,   300,     9,   175,   303,   304,   305,   176,
      13,   177,   306,    59,    60,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   308,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     307,     4,     5,     6,   140,   141,    58,   142,   309,     7,
       8,   143,   310,   312,   144,   145,   315,   146,    59,   147,
     314,    14,    15,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   364,   349,    67,    68,   370,   360,
      58,   258,   114,   371,   115,   116,   117,   273,   378,   348,
     338,   -96,    59,   147,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   273,   330,   389,   273,   -96,
     387,    58,    75,   386,   390,   391,   398,   396,   397,   399,
     403,   404,   402,    59,    60,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   407,   408,   410,   414,
     418,   420,    58,   253,   421,   383,   422,   423,   424,   -97,
     430,   434,   431,   435,    59,   147,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   436,   437,   438,
     439,   440,   442,    58,   258,   448,   441,   449,   217,   450,
     453,   443,   444,   456,   458,    59,   147,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   457,   103,
     255,   299,   240,   118,    58,   333,   406,   401,   372,   290,
     256,   271,   272,   419,   129,    81,    59,   147,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,   219,     0,     0,     0,    58,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    58,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     3,
       4,     5,     6,     0,     0,     0,    59,   147,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,     0,     0,
      14,    15
};

static const yytype_int16 yycheck[] =
{
       7,    83,   150,    33,   142,   130,   131,   132,    15,     9,
     142,    13,   273,   142,    12,    97,   140,   141,    83,   143,
      83,     3,   275,   276,   277,     3,     7,    83,    10,     7,
       7,     9,    83,     7,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    75,    59,
      60,     7,    70,     6,     9,    82,   329,    12,   331,   144,
     145,   144,   145,   148,     9,   148,     9,    12,   144,   145,
     172,     9,   148,   144,   145,    76,     9,   148,    76,    76,
       9,     9,    76,    12,    12,    10,   254,   172,    10,   172,
     275,   259,   119,    12,   262,   253,   172,     6,   301,   126,
     258,   172,    50,    51,   253,    53,   258,   275,   276,   277,
     391,    64,    59,   140,   141,   142,   143,   390,   220,   146,
      76,    76,    65,   143,   146,    76,   270,     6,    13,    76,
       6,    76,    11,    76,    15,    16,     6,     6,    76,     9,
      76,   326,    12,    76,    76,     6,    25,    76,    76,    25,
      69,    76,     5,    12,    76,    64,    25,   325,   326,   327,
     328,   329,   365,   331,    25,    11,   334,   119,     6,   219,
     315,    15,    16,    17,   126,   333,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    25,    58,    59,
      60,    61,    62,    63,    64,    76,    66,    67,    68,   301,
       6,    71,    72,   278,    74,    75,    76,     6,    78,    79,
      69,    70,    11,   381,    15,    16,    17,   385,    19,    25,
     295,    65,   390,   250,     6,   252,   253,     9,     6,     0,
      12,   258,    76,     6,    15,    16,    17,     3,    15,    16,
      17,    25,     8,   270,     3,     3,   273,    25,    15,    16,
      17,     6,    25,   421,     9,    14,    14,    12,    11,    15,
      16,    17,    76,   365,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    76,    58,    59,    60,    61,
      62,    63,    64,    76,    66,    67,    68,     8,    65,    71,
      72,   318,    74,    75,    76,    76,    78,    79,    65,    76,
      51,     3,    57,    58,    59,    60,   333,    76,     9,    76,
      12,    66,    67,    68,    15,    16,    71,    72,    73,    74,
      76,   348,    13,    78,    79,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    75,     3,    65,    15,
      16,    17,    63,    64,    76,    15,    16,    17,    14,    76,
       6,    13,   379,     9,    75,    76,    12,     3,     7,     7,
       9,     7,   389,     9,   391,    13,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      76,    57,    58,    59,    60,     6,    76,   141,     9,   143,
      66,    67,    68,    65,    65,    71,    72,    73,    74,    76,
      59,    60,    78,    79,    76,    76,    50,    51,     6,    68,
      76,     9,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     3,     3,    59,    60,    61,    62,    63,
      64,    77,    12,    12,    68,     3,    57,    58,    59,    60,
       8,    75,    76,     3,    77,    66,    67,    68,     8,    10,
      71,    72,    73,    74,    15,    50,    51,    78,    79,    57,
      58,    59,    60,    15,    16,    10,    11,    10,    66,    67,
      68,    16,    15,    71,    72,    73,    74,     3,    77,    10,
      78,    79,     8,     8,    15,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,    11,    51,    77,
      77,     8,    63,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    75,    76,     8,    51,    77,    80,
      63,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    75,    76,    51,     6,    77,    80,    63,    64,
      76,    47,     7,    49,    50,    51,     6,     3,   144,   145,
      75,    76,   148,    11,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    59,    60,     6,     8,    10,
       6,    63,    64,    76,    68,     3,     6,    76,    76,     7,
      74,     9,     6,    75,    76,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     6,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      76,    58,    59,    60,    61,    62,    63,    64,    51,    66,
      67,    68,    51,     6,    71,    72,    10,    74,    75,    76,
      76,    78,    79,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     6,    77,    59,    60,     6,    77,
      63,    64,    47,     8,    49,    50,    51,     7,    80,     9,
      76,    11,    75,    76,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     7,    76,     9,     7,    11,
       8,    63,    64,    64,    10,     7,    17,     6,     6,    25,
      80,    25,    19,    75,    76,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     6,     6,     6,    76,
      76,     6,    63,    64,    10,    76,    10,    64,    64,    11,
      10,    77,    10,     6,    75,    76,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    12,    77,     6,
      12,    76,    10,    63,    64,    10,    76,     6,    92,     6,
       6,    76,    76,    76,     6,    75,    76,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    76,    45,
     140,   220,   120,    59,    63,    64,   359,   355,   318,   172,
     140,   146,   146,   379,    75,    21,    75,    76,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    94,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
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
      71,    72,    73,    74,    78,    79,    85,    89,    90,    96,
     130,   135,   136,   137,   138,   139,   140,   141,   142,   144,
     145,   146,   147,   148,   149,   150,    10,    76,    83,    84,
      76,    59,    76,     7,    76,     7,    76,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    63,    75,
      76,    82,    91,    92,    93,    94,    76,    59,    60,   139,
     146,   146,    76,   140,    13,    64,    94,   129,   146,     6,
      25,   141,     5,    11,     6,    25,     6,    11,     6,   147,
       0,    25,     3,    10,    11,    76,     6,    11,    25,    76,
      86,     6,    25,    86,     6,    25,    51,    50,    51,    53,
      47,    49,    50,    51,    47,    49,    50,    51,    92,    13,
      75,    76,     6,    25,    76,    76,    13,    76,   134,   129,
      15,    16,    17,    76,   128,    77,    94,    95,     6,    12,
      61,    62,    64,    68,    71,    72,    74,    76,    85,    90,
      94,    96,    97,    98,    99,   100,   109,   110,   111,   116,
     117,   118,   119,   120,   121,   124,   125,   126,   127,   130,
     131,   132,   133,   142,    77,     3,     7,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    76,   122,   143,    77,    10,    83,    12,   148,
      11,    12,    76,    85,    87,    88,    77,     3,     8,    77,
       8,    77,    51,    51,    50,    51,    51,    50,    51,    95,
      91,     6,    77,    95,     3,    14,   128,   128,     9,   128,
       7,     6,     3,    64,    94,    98,   110,   118,    64,    94,
     118,   125,    94,    97,   117,   124,   118,   125,   131,   131,
      61,   119,   126,     7,   131,    15,    16,    17,    65,    76,
     108,   116,   123,     6,    25,    11,     6,    25,     6,    12,
     132,     6,     8,    10,     6,     3,    12,    12,    12,    88,
      76,     3,    12,     6,    76,    76,     6,    76,     6,    51,
      51,    14,     6,    14,    76,    10,     8,    63,    64,    94,
     112,   113,   114,   115,    94,    94,    15,    16,    17,    15,
      76,    15,    76,    64,    94,     8,    63,   115,    76,   108,
     116,   123,   116,   123,     9,   116,   123,   122,     9,    77,
      12,    69,    70,   101,   102,   103,   104,   105,   106,   107,
      77,    12,    76,   122,     6,     3,    12,    12,    87,   128,
       6,     8,   112,    15,    16,    17,    19,    76,    80,     3,
       8,    15,     9,    76,     9,    15,    64,     8,     8,     9,
      10,     7,    10,    15,    80,    94,     6,     6,    17,    25,
      12,   107,    19,    80,    25,    12,   103,     6,     6,    12,
       6,    15,    16,    76,    76,     9,    15,    16,    76,   114,
       6,    10,    10,    64,    64,    10,   116,   123,     8,   115,
      10,    10,    10,    15,    77,     6,    12,    77,     6,    12,
      76,    76,    10,    76,    76,     6,    64,     8,    10,     6,
       6,    15,    16,     6,     6,    64,    76,    76,     6
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
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 179 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 180 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 181 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), list_property);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 182 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 183 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 186 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 187 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 191 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 192 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 193 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(4) - (6)].sn));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 194 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 197 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 198 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 202 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 203 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 204 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 205 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 206 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 207 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 208 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 209 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 210 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 211 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 214 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 215 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 218 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 219 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 222 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 223 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 226 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 227 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 228 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 229 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 230 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 231 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 234 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 235 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 236 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 237 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 238 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 239 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 242 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 243 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 246 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 247 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 248 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 249 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 252 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 253 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 256 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 257 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 299 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 300 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 301 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 302 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 306 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 307 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 308 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 309 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 310 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 313 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 314 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 317 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 318 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 319 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 322 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 323 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 326 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 327 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 328 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 331 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 332 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 333 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 334 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 335 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 338 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 339 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 342 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 343 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 344 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 345 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 346 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 347 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 348 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 349 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 350 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 351 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 354 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 355 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 358 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 359 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 360 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 361 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 364 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 365 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 368 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 371 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 372 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 373 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 374 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 377 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 378 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 381 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 382 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 385 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 386 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 389 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 390 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 393 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 394 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 397 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 398 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 402 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 403 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 404 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 405 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 408 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 411 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 412 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 413 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 414 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 418 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 419 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 420 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 421 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 422 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 423 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 424 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 425 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 428 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 429 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 432 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 433 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 434 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 435 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 438 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 439 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 442 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 443 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3583 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



