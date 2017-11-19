
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
     NAMESPACE = 288,
     ENUM = 289,
     CLASS = 290,
     STRUCT = 291,
     STATIC = 292,
     VIRTUAL = 293,
     VOID = 294,
     CONST = 295,
     OPERATOR = 296,
     TYPEDEF = 297,
     PRIMITIVE = 298,
     ABSTRACT = 299,
     GET = 300,
     SET = 301,
     NOMETA = 302,
     NOCODE = 303,
     EXPORT = 304,
     OVERRIDE = 305,
     SCOPE = 306,
     IDENTIFY = 307,
     STRING = 308,
     TEMPLATE = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 174 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 186 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   858

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  257
/* YYNRULES -- Number of states.  */
#define YYNSTATES  434

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      13,    25,    14,    78,     2,     2,     2,     2,     2,     2,
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
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    20,
      23,    27,    30,    34,    36,    39,    42,    46,    49,    53,
      56,    60,    64,    69,    73,    78,    80,    83,    85,    88,
      90,    92,    94,    97,    99,   103,   105,   109,   113,   118,
     121,   123,   126,   128,   132,   138,   145,   150,   153,   158,
     160,   165,   167,   171,   173,   176,   178,   180,   182,   186,
     191,   195,   199,   203,   207,   213,   219,   225,   231,   234,
     239,   243,   245,   248,   250,   253,   256,   261,   263,   268,
     274,   280,   287,   294,   296,   300,   302,   307,   313,   319,
     326,   333,   335,   338,   340,   344,   346,   350,   354,   357,
     361,   365,   370,   375,   379,   383,   388,   393,   395,   398,
     401,   405,   409,   414,   419,   426,   431,   436,   443,   445,
     448,   450,   453,   455,   459,   463,   468,   473,   478,   484,
     490,   492,   495,   499,   503,   507,   513,   515,   518,   520,
     523,   526,   529,   531,   534,   537,   542,   544,   546,   548,
     550,   552,   554,   556,   558,   560,   562,   564,   566,   568,
     570,   573,   576,   578,   580,   582,   584,   586,   588,   590,
     592,   594,   596,   598,   600,   602,   604,   606,   608,   610,
     612,   614,   616,   622,   629,   636,   644,   647,   651,   655,
     659,   665,   667,   670,   672,   675,   678,   680,   683,   685,
     687,   689,   691,   693,   695,   697,   700,   703,   705,   708,
     710,   712,   715,   718,   720,   724,   729,   732,   738,   741,
     747,   749,   753,   757,   762,   765,   770,   772,   775,   777,
     780,   782,   785,   787,   789,   793,   797,   803,   806,   811,
     817,   824,   826,   828,   830,   832,   834,   837,   840,   842,
     845,   847,   849,   852,   855,   860,   866,   867
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     142,     0,    -1,    46,    -1,    47,    -1,    54,    47,    -1,
      55,    47,    -1,    48,    -1,    49,    -1,    49,    51,    -1,
      54,    49,    -1,    54,    49,    51,    -1,    55,    49,    -1,
      55,    49,    51,    -1,    50,    -1,    50,    51,    -1,    54,
      50,    -1,    54,    50,    51,    -1,    55,    50,    -1,    55,
      50,    51,    -1,    50,    50,    -1,    50,    50,    51,    -1,
      54,    50,    50,    -1,    54,    50,    50,    51,    -1,    55,
      50,    50,    -1,    55,    50,    50,    51,    -1,    51,    -1,
      54,    51,    -1,    54,    -1,    55,    51,    -1,    55,    -1,
      52,    -1,    53,    -1,    50,    53,    -1,    62,    -1,    75,
      25,    76,    -1,    81,    -1,    82,     3,    81,    -1,     9,
      82,    10,    -1,     9,    82,     3,    10,    -1,     9,    10,
      -1,    75,    -1,    83,    75,    -1,    84,    -1,    85,     3,
      84,    -1,    57,    75,    11,    85,    12,    -1,    57,    75,
      11,    85,     3,    12,    -1,    57,    75,    11,    12,    -1,
      86,     6,    -1,    86,    25,    76,     6,    -1,    75,    -1,
      75,    13,    92,    14,    -1,    88,    -1,    89,    74,    88,
      -1,    89,    -1,    74,    89,    -1,    80,    -1,    90,    -1,
      91,    -1,    92,     3,    91,    -1,    65,    91,    75,     6,
      -1,    66,    75,     6,    -1,    57,    75,     6,    -1,    59,
      75,     6,    -1,    58,    75,     6,    -1,    66,    75,    25,
      76,     6,    -1,    57,    75,    25,    76,     6,    -1,    59,
      75,    25,    76,     6,    -1,    58,    75,    25,    76,     6,
      -1,    91,    75,    -1,    91,    75,     9,    10,    -1,    91,
      15,    75,    -1,    94,    -1,    63,    94,    -1,    95,    -1,
      60,    95,    -1,    96,     6,    -1,    96,    25,    76,     6,
      -1,    68,    -1,    68,     7,    91,     8,    -1,    68,     7,
      91,    15,     8,    -1,    68,     7,    91,    16,     8,    -1,
      68,     7,    63,    91,    15,     8,    -1,    68,     7,    63,
      91,    16,     8,    -1,    98,    -1,    98,    25,    76,    -1,
      69,    -1,    69,     7,    91,     8,    -1,    69,     7,    91,
      15,     8,    -1,    69,     7,    91,    16,     8,    -1,    69,
       7,    63,    91,    15,     8,    -1,    69,     7,    63,    91,
      16,     8,    -1,   100,    -1,   100,    78,    -1,   101,    -1,
     101,    25,    76,    -1,    75,    -1,    75,     9,    10,    -1,
      75,    11,    12,    -1,    91,   103,    -1,    91,    15,   103,
      -1,    91,    16,   103,    -1,    63,    91,    15,   103,    -1,
      63,    91,    16,   103,    -1,   104,    99,     6,    -1,   104,
     102,     6,    -1,   104,    99,   102,     6,    -1,   104,   102,
      99,     6,    -1,   105,    -1,    60,   105,    -1,    91,    75,
      -1,    91,    15,    75,    -1,    91,    16,    75,    -1,    91,
      15,    15,    75,    -1,    91,    17,    15,    75,    -1,    91,
      17,     9,    10,    15,    75,    -1,    91,    15,    16,    75,
      -1,    91,    17,    16,    75,    -1,    91,    17,     9,    10,
      16,    75,    -1,   107,    -1,    63,   107,    -1,   108,    -1,
     108,    78,    -1,   109,    -1,   110,     3,   109,    -1,    75,
       7,     8,    -1,    75,     7,    62,     8,    -1,    75,     7,
     110,     8,    -1,    75,     7,     8,    63,    -1,    75,     7,
      62,     8,    63,    -1,    75,     7,   110,     8,    63,    -1,
     111,    -1,    91,   111,    -1,    91,    16,   111,    -1,    91,
      15,   111,    -1,    91,    17,   111,    -1,    91,    17,     9,
      10,   111,    -1,   112,    -1,    63,   112,    -1,   113,    -1,
      67,   113,    -1,    61,   113,    -1,    60,   113,    -1,   114,
      -1,    73,   114,    -1,   115,     6,    -1,   115,    25,    76,
       6,    -1,    18,    -1,    19,    -1,    15,    -1,    20,    -1,
      21,    -1,    17,    -1,    16,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    13,    -1,    14,    -1,     3,    -1,
       9,    10,    -1,     7,     8,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    36,    -1,    37,    -1,    34,    -1,    35,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,
      43,    -1,    44,    -1,    45,    -1,    64,   117,     7,     8,
       6,    -1,    64,   117,     7,   110,     8,     6,    -1,    64,
     117,     7,     8,    63,     6,    -1,    64,   117,     7,   110,
       8,    63,     6,    -1,    91,   118,    -1,    91,    16,   118,
      -1,    91,    15,   118,    -1,    91,    17,   118,    -1,    91,
      17,     9,    10,   118,    -1,   119,    -1,    63,   119,    -1,
     120,    -1,    67,   120,    -1,    61,   120,    -1,   121,    -1,
      73,   121,    -1,    97,    -1,   106,    -1,   116,    -1,   122,
      -1,   134,    -1,    87,    -1,    93,    -1,    71,   123,    -1,
      70,   123,    -1,   123,    -1,    83,   123,    -1,   124,    -1,
       6,    -1,   125,   124,    -1,   125,     6,    -1,    75,    -1,
     126,     3,    75,    -1,    77,    13,   126,    14,    -1,    58,
      75,    -1,    58,     7,    75,     8,    75,    -1,    59,    75,
      -1,    59,     7,    75,     8,    75,    -1,   128,    -1,   128,
       5,    92,    -1,   129,    11,    12,    -1,   129,    11,   125,
      12,    -1,   130,     6,    -1,   130,    25,    76,     6,    -1,
     131,    -1,    67,   131,    -1,   132,    -1,    73,   132,    -1,
     133,    -1,   127,   133,    -1,    75,    -1,   117,    -1,   135,
       3,    75,    -1,   135,     3,   117,    -1,    72,    75,    13,
      92,    14,    -1,   136,     6,    -1,   136,    11,    12,     6,
      -1,   136,    11,   135,    12,     6,    -1,   136,    11,   135,
       3,    12,     6,    -1,   134,    -1,    87,    -1,   137,    -1,
      93,    -1,   141,    -1,    71,   138,    -1,    70,   138,    -1,
     138,    -1,    83,   138,    -1,   139,    -1,     6,    -1,   140,
     139,    -1,   140,     6,    -1,    56,    75,    11,    12,    -1,
      56,    75,    11,   140,    12,    -1,    -1,   140,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    29,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    63,    66,    67,    70,    71,    72,
      75,    76,    79,    80,    84,    85,    86,    89,    90,    93,
      94,    97,    98,   101,   102,   105,   106,   109,   110,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   124,   125,
     126,   129,   130,   133,   134,   137,   138,   142,   143,   144,
     145,   146,   147,   151,   152,   155,   156,   157,   158,   159,
     160,   163,   164,   167,   168,   171,   172,   173,   176,   177,
     178,   179,   180,   183,   184,   185,   186,   189,   190,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   205,   206,
     209,   210,   213,   214,   217,   218,   219,   220,   221,   222,
     225,   226,   227,   228,   229,   230,   233,   234,   237,   238,
     239,   240,   243,   244,   247,   248,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   290,   291,   292,   293,   297,   298,   299,   300,
     301,   304,   305,   308,   309,   310,   313,   314,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   328,   329,   332,
     333,   334,   335,   338,   339,   342,   345,   346,   347,   348,
     351,   352,   355,   356,   359,   360,   363,   364,   367,   368,
     371,   372,   376,   377,   378,   379,   382,   385,   386,   387,
     388,   391,   392,   393,   394,   395,   396,   397,   400,   401,
     404,   405,   406,   407,   410,   411,   414,   415
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
  "UNSIGNED", "NAMESPACE", "ENUM", "CLASS", "STRUCT", "STATIC", "VIRTUAL",
  "VOID", "CONST", "OPERATOR", "TYPEDEF", "PRIMITIVE", "ABSTRACT", "GET",
  "SET", "NOMETA", "NOCODE", "EXPORT", "OVERRIDE", "SCOPE", "IDENTIFY",
  "STRING", "TEMPLATE", "'?'", "$accept", "primitive", "attribute",
  "attributeList", "attributes", "enumerator", "enumeratorList", "enum_0",
  "enum", "scopeName", "scopeNameList_0", "scopeNameList", "typeName",
  "typeNameList", "typeAlias", "field_0", "field_1", "field_2", "field",
  "getter_0", "getter", "setter_0", "setter_1", "setter", "property_0",
  "property_1", "property_2", "property", "parameter_0", "parameter_1",
  "parameter", "parameterList", "method_0", "method_1", "method_2",
  "method_3", "method_4", "method", "operatorSign", "operator_0",
  "operator_1", "operator_2", "operator_3", "operator", "classMember_0",
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
     302,   303,   304,   305,   306,   307,   308,   309,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   118,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   128,   128,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   135,   135,   136,   137,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     140,   140,   140,   140,   141,   141,   142,   142
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     2,     2,
       3,     2,     3,     1,     2,     2,     3,     2,     3,     2,
       3,     3,     4,     3,     4,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     3,     4,     2,
       1,     2,     1,     3,     5,     6,     4,     2,     4,     1,
       4,     1,     3,     1,     2,     1,     1,     1,     3,     4,
       3,     3,     3,     3,     5,     5,     5,     5,     2,     4,
       3,     1,     2,     1,     2,     2,     4,     1,     4,     5,
       5,     6,     6,     1,     3,     1,     4,     5,     5,     6,
       6,     1,     2,     1,     3,     1,     3,     3,     2,     3,
       3,     4,     4,     3,     3,     4,     4,     1,     2,     2,
       3,     3,     4,     4,     6,     4,     4,     6,     1,     2,
       1,     2,     1,     3,     3,     4,     4,     4,     5,     5,
       1,     2,     3,     3,     3,     5,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     6,     7,     2,     3,     3,     3,
       5,     1,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     2,     1,
       1,     2,     2,     1,     3,     4,     2,     5,     2,     5,
       1,     3,     3,     4,     2,     4,     1,     2,     1,     2,
       1,     2,     1,     1,     3,     3,     5,     2,     4,     5,
       6,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     2,     2,     4,     5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     256,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   244,     0,
     220,     0,     0,   226,   228,   230,   241,     0,   243,   248,
     250,   257,   245,     0,    39,     0,    35,     0,     0,     0,
       0,   216,     0,   218,     2,     3,     6,     7,    13,    25,
      30,    31,    27,    29,    33,     0,    49,    55,    51,    53,
      56,     0,     0,     0,     0,   227,   247,   246,     0,   229,
       0,   249,    47,     0,   231,     0,     0,   224,     0,   237,
       0,   253,   252,     1,     0,     0,    37,     0,    61,     0,
       0,     0,    63,     0,     0,    62,     0,     8,    19,    14,
      32,     4,     9,    15,    26,     5,    11,    17,    28,    54,
       0,     0,     0,    60,     0,   216,   218,     0,   213,     0,
       0,    57,   221,   210,   222,     0,     0,     0,     0,     0,
       0,     0,    49,     0,   203,     0,   204,    71,    73,     0,
     198,     0,   107,   199,   130,   136,   138,   142,     0,   200,
     191,   193,   196,   201,   207,   209,     0,   202,     0,   159,
       0,     0,     0,   157,   158,   148,   152,   151,   146,   147,
     149,   150,   153,   154,   155,   156,   162,   163,   164,   165,
     166,   167,   168,   169,   172,   173,   170,   171,   174,   175,
     176,   177,   178,   179,   180,   181,   232,   233,     0,    34,
      38,    36,   254,     0,    46,    40,     0,    42,     0,     0,
       0,     0,     0,     0,    20,    10,    21,    16,    12,    23,
      18,     0,    52,    59,     0,     0,     0,   215,    48,     0,
       0,     0,    74,   108,   141,     0,     0,   140,   195,     0,
      72,   137,   192,   139,   194,   206,   205,     0,   143,   197,
       0,   208,     0,     0,     0,     0,    68,    98,   131,   186,
      75,     0,    77,    85,    83,     0,    91,    93,     0,   144,
       0,   212,   223,   211,   225,   161,   160,   238,     0,     0,
     255,    41,     0,    44,    65,   217,    67,   219,    66,    22,
      24,    50,    64,   236,   214,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,   124,    33,
       0,     0,   118,   120,   122,     0,    70,    99,   133,   188,
      95,   100,   132,   187,     0,   134,   189,     0,     0,     0,
       0,     0,     0,     0,   103,     0,    92,     0,   104,     0,
       0,     0,   234,   235,   239,    45,    43,     0,     0,     0,
     101,   102,     0,     0,     0,   127,   125,   119,     0,     0,
       0,   109,   121,     0,   126,     0,     0,     0,    69,    97,
      76,     0,     0,     0,     0,    84,   105,    94,   106,   145,
     240,     0,    69,   128,     0,     0,   110,   111,     0,     0,
       0,   123,   129,    96,   135,   190,     0,     0,     0,    78,
       0,     0,     0,    86,     0,     0,   112,   115,     0,   113,
     116,   182,     0,     0,     0,     0,    79,    80,     0,     0,
      87,    88,     0,     0,   184,   183,     0,    81,    82,    89,
      90,   114,   117,   185
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    57,    36,    37,    15,   207,   208,    16,    17,    58,
      59,    60,   135,   122,    18,   137,   138,   139,   140,   264,
     265,   266,   267,   268,   257,   141,   142,   143,   312,   313,
     314,   315,   144,   145,   146,   147,   148,   149,   197,   259,
     150,   151,   152,   153,   154,   155,   156,   119,    19,    20,
      21,    22,    23,    24,    25,    26,   198,    27,    28,    29,
      30,    31,    32,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -235
static const yytype_int16 yypact[] =
{
     459,  -235,     5,   -42,   -30,    10,    16,   753,    -3,   361,
     781,   781,     7,   252,   130,   781,    31,  -235,  -235,   175,
     159,   164,    37,  -235,  -235,  -235,  -235,   213,  -235,  -235,
    -235,   487,  -235,   194,  -235,   177,  -235,   135,   224,    38,
     157,    48,   170,   111,  -235,  -235,  -235,   202,   110,  -235,
    -235,  -235,   304,   450,  -235,   229,   197,  -235,  -235,   239,
    -235,   240,   124,    17,    18,  -235,  -235,  -235,   317,  -235,
     283,  -235,  -235,   291,  -235,   753,   138,  -235,   347,  -235,
     243,  -235,  -235,  -235,   365,    25,  -235,   235,  -235,     4,
     376,   399,  -235,   384,   456,  -235,   404,  -235,   353,  -235,
    -235,  -235,   421,   378,  -235,  -235,   431,   385,  -235,   239,
     753,   229,   492,  -235,   426,  -235,  -235,   753,  -235,    27,
     501,  -235,   491,  -235,  -235,   645,   663,   770,   363,   583,
     583,   615,   155,   583,  -235,   142,  -235,  -235,  -235,   129,
    -235,   371,  -235,  -235,  -235,  -235,  -235,  -235,   131,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   396,  -235,   502,  -235,
     503,   499,   504,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   136,  -235,
    -235,  -235,  -235,   418,  -235,  -235,   437,  -235,   143,   507,
     439,   513,   445,   515,  -235,  -235,   472,  -235,  -235,   477,
    -235,    33,  -235,  -235,   516,    62,   458,  -235,  -235,   753,
     770,   214,  -235,  -235,  -235,   770,   150,  -235,  -235,   417,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,   681,  -235,  -235,
     287,  -235,    76,    77,    13,   582,    39,  -235,  -235,  -235,
    -235,   461,   527,   528,   514,    28,   460,   517,    34,  -235,
     464,  -235,  -235,  -235,  -235,  -235,  -235,  -235,   356,   535,
    -235,  -235,    19,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   221,   473,   474,    23,
      78,    78,   540,    76,    77,   209,   770,   328,   493,   542,
     753,   331,  -235,   483,  -235,   323,    46,  -235,  -235,  -235,
     172,  -235,  -235,  -235,   541,  -235,  -235,   548,   552,   551,
     569,   699,   717,   500,  -235,   571,  -235,   508,  -235,   572,
     573,   574,  -235,  -235,  -235,  -235,  -235,   473,   474,   576,
    -235,  -235,   577,   553,   553,  -235,   520,  -235,    11,   564,
     305,  -235,  -235,   735,   525,   580,    78,   519,   410,  -235,
    -235,   753,   282,   753,   301,  -235,  -235,  -235,  -235,  -235,
    -235,   553,  -235,  -235,   584,   596,  -235,  -235,   637,   597,
     604,  -235,  -235,  -235,  -235,  -235,    53,   349,   471,  -235,
     643,   644,   488,  -235,   647,   672,  -235,  -235,   490,  -235,
    -235,  -235,   586,    65,   673,   675,  -235,  -235,   676,   677,
    -235,  -235,   611,   612,  -235,  -235,   682,  -235,  -235,  -235,
    -235,  -235,  -235,  -235
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,   616,  -235,   -75,   420,  -235,  -235,   -69,   592,
     649,  -235,    -7,   -59,   -55,  -125,   581,  -235,  -235,  -235,
     453,  -235,  -235,   440,  -214,  -235,   598,  -235,   412,  -235,
     377,   357,  -127,  -124,  -116,   608,  -235,  -235,  -226,  -234,
    -122,   123,   610,  -235,   199,   601,  -235,  -235,  -235,  -235,
    -235,  -235,    -5,    -2,   723,   -34,  -235,  -235,  -235,   312,
     -25,   671,  -235,  -235
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -97
static const yytype_int16 yytable[] =
{
      61,   133,   240,   241,    65,   242,    82,   134,   258,   234,
     237,    69,   243,     2,   206,    34,   204,    40,   319,   323,
     326,   136,   324,    42,    40,    42,   384,   385,     2,   327,
     226,   345,   349,    38,   334,   200,   229,    72,   317,   321,
     338,   227,   157,    77,    88,    39,   250,   291,   328,    89,
     329,   221,   343,   250,    92,   365,    73,   329,   225,   411,
     134,   134,    78,    90,   134,   229,   319,   323,   121,   319,
     323,   425,    62,    93,   136,   136,   293,   255,   136,   205,
      35,   133,    68,   317,   321,    41,   386,   134,   302,   350,
     351,    43,   115,   116,   205,   157,   157,   263,   302,   157,
      35,   136,   262,   121,   258,   240,   241,   -95,   -95,   258,
     121,   241,   258,   242,   -95,   -95,   412,    95,   231,   236,
     239,   236,   157,    65,   236,   318,   322,   325,   426,    69,
     113,   234,   395,   350,   351,   260,    96,   269,    85,   278,
     255,   255,   255,    70,   123,    86,   282,     2,   279,   114,
     124,   316,   320,   302,   261,   283,   270,   252,   253,   254,
      98,    99,   250,   100,    75,   300,   301,   254,   110,   258,
     318,   322,   325,   318,   322,    76,   318,   322,    82,   250,
     258,   365,   241,   329,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    83,     4,     5,     6,   125,   126,
      54,   127,    84,     7,     8,   128,   255,   206,   129,   130,
     110,   131,    55,   132,   255,    14,   250,   256,   352,    79,
     318,   322,   295,   296,    80,   302,   318,   322,   236,   297,
     298,   299,    91,    63,    64,    87,   347,   348,   299,   394,
     307,     1,     9,   311,     2,    94,   159,   202,    13,   238,
     160,   244,   161,    97,   394,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   256,
     399,     3,     4,     5,     6,   308,   305,   400,   401,   307,
       7,     8,     9,   311,    56,    10,    11,    12,    13,   403,
      63,    64,    14,   111,   388,   112,   404,   405,   196,     9,
     389,   390,    66,    67,   372,   374,   363,    71,   245,   246,
     117,   364,   251,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   353,   354,   299,   358,   359,   360,   309,
     310,   101,   363,   102,   103,   104,   311,   413,   118,   159,
     311,    55,    56,   160,   398,   161,   402,   120,   341,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   271,   302,   214,     2,   361,   210,   272,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    63,
      64,    63,    64,   158,    81,    54,   235,     2,   216,   217,
     280,   342,   303,   304,   254,   219,   220,    55,   132,   262,
     263,   199,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   209,     4,     5,     6,   125,   126,    54,   127,
     211,     7,     8,   128,   212,     1,   129,   130,     2,   131,
      55,   132,   215,    14,     3,     4,     5,     6,   -96,   -96,
     213,   255,   218,     7,     8,     9,   414,   415,    10,    11,
      12,    13,   305,    81,   229,    14,     2,   105,   223,   106,
     107,   108,   224,   418,   419,   422,   423,   228,   274,   276,
     277,   275,   281,   284,   285,     3,     4,     5,     6,   286,
     287,   288,   292,   289,     7,     8,     9,   396,   290,    10,
      11,    12,    13,   294,   331,   332,    14,   330,   336,   333,
     340,   344,   337,     3,     4,     5,     6,   250,   316,   320,
     356,   366,     7,     8,     9,   367,   355,    10,    11,    12,
      13,   362,   368,   369,    14,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   370,   375,   376,   378,   379,
     380,    54,   310,   383,   377,   159,   381,   382,   392,   160,
     393,   161,   424,    55,    56,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   302,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   387,
       4,     5,     6,   125,   126,    54,   127,   408,     7,     8,
     128,   416,   417,   129,   130,   420,   131,    55,   132,   406,
      14,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   407,   409,    63,    64,   247,   126,    54,   235,   410,
     421,   427,   128,   428,   429,   430,   431,   432,   433,    55,
     132,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   201,   346,   222,   109,   335,   232,    54,   230,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
     132,   339,   357,   233,   397,    54,   235,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    55,   132,   248,
     391,   249,    74,    54,   306,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    55,   132,   273,   203,     0,
       0,    54,   371,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    55,    56,     0,     0,     0,     0,    54,
     373,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    55,    56,     0,     0,     0,     0,    54,   310,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      56,     0,     0,     0,     0,    54,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    55,    56,     0,
       0,     0,    54,     0,     0,     0,     0,     3,     4,     5,
       6,     0,     0,     0,    55,   132,     7,     8,     9,     0,
       0,    10,    11,    12,    13,     0,     0,     0,    14
};

static const yytype_int16 yycheck[] =
{
       7,    76,   127,   127,     9,   127,    31,    76,   135,   125,
     126,    13,   128,     9,    89,    10,    12,     7,   252,   253,
     254,    76,     9,     7,     7,     7,    15,    16,     9,   255,
       3,    12,     9,    75,     6,    10,     3,     6,   252,   253,
       6,    14,    76,     6,     6,    75,     7,    14,     9,    11,
      11,   110,   278,     7,     6,     9,    25,    11,   117,     6,
     129,   130,    25,    25,   133,     3,   300,   301,    75,   303,
     304,     6,    75,    25,   129,   130,    14,    64,   133,    75,
      75,   156,    75,   297,   298,    75,    75,   156,    75,   303,
     304,    75,    75,    75,    75,   129,   130,    69,    75,   133,
      75,   156,    68,   110,   231,   230,   230,    68,    69,   236,
     117,   235,   239,   235,    68,    69,    63,     6,   125,   126,
     127,   128,   156,   128,   131,   252,   253,   254,    63,   131,
       6,   247,   366,   347,   348,     6,    25,     6,     3,     3,
      64,    64,    64,    13,     6,    10,     3,     9,    12,    25,
      12,    75,    75,    75,    25,    12,    25,    15,    16,    17,
      50,    51,     7,    53,     5,    15,    16,    17,    13,   296,
     297,   298,   299,   300,   301,    11,   303,   304,   203,     7,
     307,     9,   306,    11,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,    57,    58,    59,    60,    61,
      62,    63,    25,    65,    66,    67,    64,   282,    70,    71,
      13,    73,    74,    75,    64,    77,     7,    75,     9,     6,
     347,   348,   229,   230,    11,    75,   353,   354,   235,    15,
      16,    17,    75,    58,    59,    11,    15,    16,    17,   366,
     247,     6,    67,   250,     9,    75,     3,    12,    73,   126,
       7,   128,     9,    51,   381,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    75,
       8,    56,    57,    58,    59,     8,    75,    15,    16,   306,
      65,    66,    67,   310,    75,    70,    71,    72,    73,     8,
      58,    59,    77,    74,     9,    75,    15,    16,    75,    67,
      15,    16,    10,    11,   331,   332,     3,    15,   129,   130,
      13,     8,   133,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    15,    16,    17,    15,    16,    17,    62,
      63,    47,     3,    49,    50,    51,   363,     8,    75,     3,
     367,    74,    75,     7,   371,     9,   373,    76,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     6,    75,    51,     9,    75,     8,    12,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    58,
      59,    58,    59,    76,     6,    62,    63,     9,    50,    51,
      12,    75,    15,    16,    17,    50,    51,    74,    75,    68,
      69,    76,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    76,    57,    58,    59,    60,    61,    62,    63,
      76,    65,    66,    67,     8,     6,    70,    71,     9,    73,
      74,    75,    51,    77,    56,    57,    58,    59,    68,    69,
      76,    64,    51,    65,    66,    67,    15,    16,    70,    71,
      72,    73,    75,     6,     3,    77,     9,    47,     6,    49,
      50,    51,    76,    15,    16,    15,    16,     6,     6,    10,
       6,     8,    75,     6,    75,    56,    57,    58,    59,     6,
      75,     6,     6,    51,    65,    66,    67,     8,    51,    70,
      71,    72,    73,    75,     7,     7,    77,    76,    78,    25,
      76,     6,    25,    56,    57,    58,    59,     7,    75,    75,
       8,    10,    65,    66,    67,     7,    63,    70,    71,    72,
      73,    78,    10,    12,    77,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     6,    76,     6,     6,     6,
       6,    62,    63,    63,    76,     3,    10,    10,    63,     7,
      10,     9,     6,    74,    75,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    75,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    75,
      57,    58,    59,    60,    61,    62,    63,    10,    65,    66,
      67,     8,     8,    70,    71,     8,    73,    74,    75,    75,
      77,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    75,    75,    58,    59,    60,    61,    62,    63,    75,
       8,     8,    67,     8,     8,     8,    75,    75,     6,    74,
      75,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    85,   282,   111,    55,   265,   125,    62,    63,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,   268,   310,   125,   367,    62,    63,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    74,    75,   131,
     363,   131,    19,    62,    63,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    74,    75,   156,    87,    -1,
      -1,    62,    63,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    74,    75,    -1,    -1,    -1,    -1,    62,
      63,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    74,    75,    -1,    -1,    -1,    -1,    62,    63,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,    -1,    -1,    -1,    -1,    62,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    74,    75,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    74,    75,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    56,    57,    58,    59,    65,    66,    67,
      70,    71,    72,    73,    77,    83,    86,    87,    93,   127,
     128,   129,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,    10,    75,    81,    82,    75,    75,
       7,    75,     7,    75,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    62,    74,    75,    80,    88,    89,
      90,    91,    75,    58,    59,   131,   138,   138,    75,   132,
      13,   138,     6,    25,   133,     5,    11,     6,    25,     6,
      11,     6,   139,     0,    25,     3,    10,    11,     6,    11,
      25,    75,     6,    25,    75,     6,    25,    51,    50,    51,
      53,    47,    49,    50,    51,    47,    49,    50,    51,    89,
      13,    74,    75,     6,    25,    75,    75,    13,    75,   126,
      76,    91,    92,     6,    12,    60,    61,    63,    67,    70,
      71,    73,    75,    83,    87,    91,    93,    94,    95,    96,
      97,   104,   105,   106,   111,   112,   113,   114,   115,   116,
     119,   120,   121,   122,   123,   124,   125,   134,    76,     3,
       7,     9,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    75,   117,   135,    76,
      10,    81,    12,   140,    12,    75,    83,    84,    85,    76,
       8,    76,     8,    76,    51,    51,    50,    51,    51,    50,
      51,    92,    88,     6,    76,    92,     3,    14,     6,     3,
      63,    91,    95,   105,   113,    63,    91,   113,   120,    91,
      94,   112,   119,   113,   120,   123,   123,    60,   114,   121,
       7,   123,    15,    16,    17,    64,    75,   103,   111,   118,
       6,    25,    68,    69,    98,    99,   100,   101,   102,     6,
      25,     6,    12,   124,     6,     8,    10,     6,     3,    12,
      12,    75,     3,    12,     6,    75,     6,    75,     6,    51,
      51,    14,     6,    14,    75,    91,    91,    15,    16,    17,
      15,    16,    75,    15,    16,    75,    63,    91,     8,    62,
      63,    91,   107,   108,   109,   110,    75,   103,   111,   118,
      75,   103,   111,   118,     9,   111,   118,   117,     9,    11,
      76,     7,     7,    25,     6,   102,    78,    25,     6,    99,
      76,    12,    75,   117,     6,    12,    84,    15,    16,     9,
     103,   103,     9,    15,    16,    63,     8,   107,    15,    16,
      17,    75,    78,     3,     8,     9,    10,     7,    10,    12,
       6,    63,    91,    63,    91,    76,     6,    76,     6,     6,
       6,    10,    10,    63,    15,    16,    75,    75,     9,    15,
      16,   109,    63,    10,   111,   118,     8,   110,    91,     8,
      15,    16,    91,     8,    15,    16,    75,    75,    10,    75,
      75,     6,    63,     8,    15,    16,     8,     8,    15,    16,
       8,     8,    15,    16,     6,     6,    63,     8,     8,     8,
       8,    75,    75,     6
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
#line 29 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_bool);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 30 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_char);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 31 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_schar);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 32 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uchar);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 33 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_wchar_t);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 34 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_short);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 35 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 36 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 37 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_short);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 38 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ushort);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 39 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ushort);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 40 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_long);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 41 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 42 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 43 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_long);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 44 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ulong);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 45 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulong);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 46 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_longlong);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 47 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 48 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 49 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_longlong);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 50 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulonglong);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 51 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (4)].sn), pt_ulonglong);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 52 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 53 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_int);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 54 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 55 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uint);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 56 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_uint);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 57 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_float);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 58 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_double);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 59 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long_double);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 60 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_void);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 63 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttribute((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 66 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 67 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 70 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (3)].sn);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 71 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (4)].sn);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 72 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 75 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 76 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 79 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 80 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 84 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 85 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 86 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 89 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setEnumSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 90 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setEnumSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 93 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 94 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 97 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 98 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 101 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 102 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 105 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 106 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 109 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 110 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 113 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 114 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 115 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 116 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 117 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 118 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 119 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), enum_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 120 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), value_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 121 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), reference_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 124 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn), NULL, NULL);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 125 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 126 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn), NULL, NULL);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 129 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 130 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 133 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 134 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 137 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setFieldSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 138 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setFieldSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 142 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 143 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 144 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 145 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 146 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 147 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 151 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 152 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 155 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 156 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 157 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 158 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 159 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 160 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 163 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 164 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 167 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 168 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 171 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), not_array);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 172 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 173 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), dynamic_array);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 176 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 177 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 178 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 179 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 180 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 183 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertyGetter((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 184 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertySetter((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 185 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyval.sn), (yyvsp[(2) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 186 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 189 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 190 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 194 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 195 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 196 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 197 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 198 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 199 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 200 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 201 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 202 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 205 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 206 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 209 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 210 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 213 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 214 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 217 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 218 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 219 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 220 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 221 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 222 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 225 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 226 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 227 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 228 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 229 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 230 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 233 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 234 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 237 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 238 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 239 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 240 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 243 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 244 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 247 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 248 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 290 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 291 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 292 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 293 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 297 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 298 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 299 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 300 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 301 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 304 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 305 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 308 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 309 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 310 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 313 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 314 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 317 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 318 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 319 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 320 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 321 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 322 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 323 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 324 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 325 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 328 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 329 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 332 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 333 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 334 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 335 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 338 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 339 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 342 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 345 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 346 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 347 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 348 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 351 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 352 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 355 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 356 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 359 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 360 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 363 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 364 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 367 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 368 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 371 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 372 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 376 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 377 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 378 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 379 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 382 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 385 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 386 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 387 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 388 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 391 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 392 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 393 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 394 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 395 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 396 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 397 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 400 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 401 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 404 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 405 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 406 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 407 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 410 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 411 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 414 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 415 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3435 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



