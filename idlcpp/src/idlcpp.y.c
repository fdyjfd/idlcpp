
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
#define YYLAST   1111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  279
/* YYNRULES -- Number of states.  */
#define YYNSTATES  486

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
     120,   123,   125,   129,   131,   134,   136,   140,   146,   153,
     158,   165,   173,   179,   182,   187,   189,   194,   196,   200,
     202,   205,   207,   209,   211,   215,   220,   224,   228,   232,
     236,   242,   248,   254,   260,   263,   268,   272,   274,   277,
     279,   282,   285,   290,   292,   297,   303,   309,   316,   323,
     325,   329,   331,   336,   342,   348,   355,   362,   364,   367,
     369,   373,   375,   379,   384,   389,   394,   400,   403,   407,
     411,   416,   421,   426,   432,   438,   445,   452,   454,   457,
     460,   464,   468,   473,   478,   485,   490,   495,   502,   504,
     507,   509,   512,   514,   518,   522,   527,   532,   537,   543,
     549,   551,   554,   558,   562,   566,   572,   574,   577,   579,
     582,   585,   588,   590,   593,   596,   601,   603,   605,   607,
     609,   611,   613,   615,   617,   619,   621,   623,   625,   627,
     629,   632,   635,   637,   639,   641,   643,   645,   647,   649,
     651,   653,   655,   657,   659,   661,   663,   665,   667,   669,
     671,   673,   675,   681,   688,   695,   703,   706,   710,   714,
     718,   724,   726,   729,   731,   734,   737,   739,   742,   747,
     753,   759,   762,   766,   770,   774,   780,   783,   787,   789,
     791,   793,   795,   797,   799,   801,   803,   806,   809,   811,
     814,   816,   818,   821,   824,   826,   830,   835,   838,   844,
     847,   853,   855,   859,   863,   868,   871,   876,   878,   881,
     883,   886,   888,   891,   893,   895,   899,   903,   909,   912,
     917,   923,   930,   932,   934,   936,   938,   940,   942,   945,
     948,   950,   953,   955,   957,   960,   963,   968,   974,   975
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
      -1,    76,    25,    77,    -1,    83,    -1,    84,     3,    83,
      -1,     9,    84,    10,    -1,     9,    84,     3,    10,    -1,
       9,    10,    -1,    76,    -1,    86,     3,    76,    -1,    76,
      -1,    85,    76,    -1,    87,    -1,    88,     3,    87,    -1,
      58,    76,    11,    88,    12,    -1,    58,    76,    11,    88,
       3,    12,    -1,    58,    76,    11,    12,    -1,    58,    59,
      76,    11,    88,    12,    -1,    58,    59,    76,    11,    88,
       3,    12,    -1,    58,    59,    76,    11,    12,    -1,    89,
       6,    -1,    89,    25,    77,     6,    -1,    76,    -1,    76,
      13,    95,    14,    -1,    91,    -1,    92,    75,    91,    -1,
      92,    -1,    75,    92,    -1,    82,    -1,    93,    -1,    94,
      -1,    95,     3,    94,    -1,    66,    94,    76,     6,    -1,
      67,    76,     6,    -1,    58,    76,     6,    -1,    60,    76,
       6,    -1,    59,    76,     6,    -1,    67,    76,    25,    77,
       6,    -1,    58,    76,    25,    77,     6,    -1,    60,    76,
      25,    77,     6,    -1,    59,    76,    25,    77,     6,    -1,
      94,    76,    -1,    94,    76,     9,    10,    -1,    94,    15,
      76,    -1,    97,    -1,    64,    97,    -1,    98,    -1,    61,
      98,    -1,    99,     6,    -1,    99,    25,    77,     6,    -1,
      69,    -1,    69,     7,    94,     8,    -1,    69,     7,    94,
      15,     8,    -1,    69,     7,    94,    16,     8,    -1,    69,
       7,    64,    94,    15,     8,    -1,    69,     7,    64,    94,
      16,     8,    -1,   101,    -1,   101,    25,    77,    -1,    70,
      -1,    70,     7,    94,     8,    -1,    70,     7,    94,    15,
       8,    -1,    70,     7,    94,    16,     8,    -1,    70,     7,
      64,    94,    15,     8,    -1,    70,     7,    64,    94,    16,
       8,    -1,   103,    -1,   103,    80,    -1,   104,    -1,   104,
      25,    77,    -1,    76,    -1,    76,     9,    10,    -1,    76,
       9,    80,    10,    -1,    76,     9,    15,    10,    -1,    76,
       9,    94,    10,    -1,    76,     9,    94,    15,    10,    -1,
      94,   106,    -1,    94,    15,   106,    -1,    94,    16,   106,
      -1,    64,    94,    15,   106,    -1,    64,    94,    16,   106,
      -1,   107,    11,    12,     6,    -1,   107,    11,   102,    12,
       6,    -1,   107,    11,   105,    12,     6,    -1,   107,    11,
     102,   105,    12,     6,    -1,   107,    11,   105,   102,    12,
       6,    -1,   108,    -1,    61,   108,    -1,    94,    76,    -1,
      94,    15,    76,    -1,    94,    16,    76,    -1,    94,    15,
      15,    76,    -1,    94,    17,    15,    76,    -1,    94,    17,
       9,    10,    15,    76,    -1,    94,    15,    16,    76,    -1,
      94,    17,    16,    76,    -1,    94,    17,     9,    10,    16,
      76,    -1,   110,    -1,    64,   110,    -1,   111,    -1,   111,
      80,    -1,   112,    -1,   113,     3,   112,    -1,    76,     7,
       8,    -1,    76,     7,    63,     8,    -1,    76,     7,   113,
       8,    -1,    76,     7,     8,    64,    -1,    76,     7,    63,
       8,    64,    -1,    76,     7,   113,     8,    64,    -1,   114,
      -1,    94,   114,    -1,    94,    16,   114,    -1,    94,    15,
     114,    -1,    94,    17,   114,    -1,    94,    17,     9,    10,
     114,    -1,   115,    -1,    64,   115,    -1,   116,    -1,    68,
     116,    -1,    62,   116,    -1,    61,   116,    -1,   117,    -1,
      74,   117,    -1,   118,     6,    -1,   118,    25,    77,     6,
      -1,    18,    -1,    19,    -1,    15,    -1,    20,    -1,    21,
      -1,    17,    -1,    16,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    13,    -1,    14,    -1,     3,    -1,     9,
      10,    -1,     7,     8,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    36,    -1,    37,    -1,    34,    -1,    35,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    45,    -1,    65,   120,     7,     8,     6,
      -1,    65,   120,     7,   113,     8,     6,    -1,    65,   120,
       7,     8,    64,     6,    -1,    65,   120,     7,   113,     8,
      64,     6,    -1,    94,   121,    -1,    94,    16,   121,    -1,
      94,    15,   121,    -1,    94,    17,   121,    -1,    94,    17,
       9,    10,   121,    -1,   122,    -1,    64,   122,    -1,   123,
      -1,    68,   123,    -1,    62,   123,    -1,   124,    -1,    74,
     124,    -1,    76,     7,     8,     6,    -1,    76,     7,    63,
       8,     6,    -1,    76,     7,   113,     8,     6,    -1,    94,
     126,    -1,    94,    16,   126,    -1,    94,    15,   126,    -1,
      94,    17,   126,    -1,    94,    17,     9,    10,   126,    -1,
      79,   127,    -1,    79,    64,   127,    -1,   100,    -1,   109,
      -1,   119,    -1,   125,    -1,   140,    -1,   128,    -1,    90,
      -1,    96,    -1,    72,   129,    -1,    71,   129,    -1,   129,
      -1,    85,   129,    -1,   130,    -1,     6,    -1,   131,   130,
      -1,   131,     6,    -1,    76,    -1,   132,     3,    76,    -1,
      78,    13,   132,    14,    -1,    59,    76,    -1,    59,     7,
      86,     8,    76,    -1,    60,    76,    -1,    60,     7,    86,
       8,    76,    -1,   134,    -1,   134,     5,    95,    -1,   135,
      11,    12,    -1,   135,    11,   131,    12,    -1,   136,     6,
      -1,   136,    25,    77,     6,    -1,   137,    -1,    68,   137,
      -1,   138,    -1,    74,   138,    -1,   139,    -1,   133,   139,
      -1,    76,    -1,   120,    -1,   141,     3,    76,    -1,   141,
       3,   120,    -1,    73,    76,    13,    95,    14,    -1,   142,
       6,    -1,   142,    11,    12,     6,    -1,   142,    11,   141,
      12,     6,    -1,   142,    11,   141,     3,    12,     6,    -1,
     140,    -1,   128,    -1,    90,    -1,   143,    -1,    96,    -1,
     147,    -1,    72,   144,    -1,    71,   144,    -1,   144,    -1,
      85,   144,    -1,   145,    -1,     6,    -1,   146,   145,    -1,
     146,     6,    -1,    57,    76,    11,    12,    -1,    57,    76,
      11,   146,    12,    -1,    -1,   146,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    65,    68,    69,    72,    73,
      74,    77,    78,    81,    82,    85,    86,    90,    91,    92,
      93,    94,    95,    98,    99,   102,   103,   106,   107,   110,
     111,   114,   115,   118,   119,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   133,   134,   135,   138,   139,   142,
     143,   146,   147,   151,   152,   153,   154,   155,   156,   160,
     161,   164,   165,   166,   167,   168,   169,   172,   173,   176,
     177,   180,   181,   182,   183,   184,   185,   188,   189,   190,
     191,   192,   195,   196,   197,   198,   199,   202,   203,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   218,   219,
     222,   223,   226,   227,   230,   231,   232,   233,   234,   235,
     238,   239,   240,   241,   242,   243,   246,   247,   250,   251,
     252,   253,   256,   257,   260,   261,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   303,   304,   305,   306,   310,   311,   312,   313,
     314,   317,   318,   321,   322,   323,   326,   327,   330,   331,
     332,   335,   336,   337,   338,   339,   342,   343,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   358,   359,
     362,   363,   364,   365,   368,   369,   372,   375,   376,   377,
     378,   381,   382,   385,   386,   389,   390,   393,   394,   397,
     398,   401,   402,   406,   407,   408,   409,   412,   415,   416,
     417,   418,   422,   423,   424,   425,   426,   427,   428,   429,
     432,   433,   436,   437,   438,   439,   442,   443,   446,   447
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
      82,    82,    82,    82,    82,    83,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   122,   122,   122,   122,
     122,   123,   123,   124,   124,   124,   125,   125,   126,   126,
     126,   127,   127,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     131,   131,   131,   131,   132,   132,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   141,   141,   142,   143,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   147,   147,   148,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     2,     3,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     4,
       2,     1,     3,     1,     2,     1,     3,     5,     6,     4,
       6,     7,     5,     2,     4,     1,     4,     1,     3,     1,
       2,     1,     1,     1,     3,     4,     3,     3,     3,     3,
       5,     5,     5,     5,     2,     4,     3,     1,     2,     1,
       2,     2,     4,     1,     4,     5,     5,     6,     6,     1,
       3,     1,     4,     5,     5,     6,     6,     1,     2,     1,
       3,     1,     3,     4,     4,     4,     5,     2,     3,     3,
       4,     4,     4,     5,     5,     6,     6,     1,     2,     2,
       3,     3,     4,     4,     6,     4,     4,     6,     1,     2,
       1,     2,     1,     3,     3,     4,     4,     4,     5,     5,
       1,     2,     3,     3,     3,     5,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     6,     7,     2,     3,     3,     3,
       5,     1,     2,     1,     2,     2,     1,     2,     4,     5,
       5,     2,     3,     3,     3,     5,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     2,     2,     1,     3,     4,     2,     5,     2,
       5,     1,     3,     3,     4,     2,     4,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     5,     2,     4,
       5,     6,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     1,     1,     2,     2,     4,     5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     278,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   266,
     263,     0,   241,     0,     0,   247,   249,   251,   262,     0,
     265,   270,   272,   279,   267,     0,    40,     0,    36,     0,
       0,     0,     0,     0,   237,     0,   239,     3,     4,     7,
       8,    14,    26,    31,    32,    28,    30,    34,     2,     0,
      55,    61,    57,    59,    62,     0,     0,     0,     0,   248,
     269,   268,     0,   250,     0,     0,     0,   216,   271,    53,
       0,   252,     0,     0,   245,     0,   258,     0,   275,   274,
       1,     0,     0,    38,     0,     0,    67,     0,     0,    41,
       0,    69,     0,     0,    68,     0,     9,    20,    15,    33,
       5,    10,    16,    27,     6,    12,    18,    29,    60,     0,
       0,     0,    66,     0,   237,   239,     0,   234,     0,   217,
       0,     0,     0,     0,   211,     0,    63,   242,   231,   243,
       0,     0,     0,     0,     0,     0,     0,    55,     0,   224,
       0,   225,    77,    79,     0,   218,     0,   117,   219,   140,
     146,   148,   152,     0,   220,   201,   203,   206,   221,   223,
     228,   230,     0,   222,     0,   169,     0,     0,     0,   167,
     168,   158,   162,   161,   156,   157,   159,   160,   163,   164,
     165,   166,   172,   173,   174,   175,   176,   177,   178,   179,
     182,   183,   180,   181,   184,   185,   186,   187,   188,   189,
     190,   191,   253,   254,     0,    35,    39,    37,   276,     0,
       0,    49,    43,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    21,    11,    22,    17,    13,    24,    19,     0,
      58,    65,     0,     0,     0,   236,   213,   212,     0,   214,
       0,    54,     0,     0,     0,    80,   118,   151,     0,     0,
     150,   205,     0,    78,   147,   202,   149,   204,   227,   226,
       0,   153,   207,     0,   229,     0,     0,     0,     0,    74,
     107,   141,   196,    81,     0,     0,   154,     0,   233,   244,
     232,   246,   171,   170,   259,     0,     0,   277,    52,     0,
      44,     0,    47,    71,    42,   238,    73,   240,    72,    23,
      25,    56,    70,   257,   235,     0,     0,     2,     0,     0,
     128,   130,   132,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,   134,     2,     0,
      76,   108,   143,   198,   101,   109,   142,   197,     0,   144,
     199,     0,     0,     0,     0,    83,    91,    89,     0,    97,
      99,     0,     0,     0,   255,   256,   260,     0,    50,    48,
      46,   215,   208,     0,   129,     0,     0,     0,   119,   131,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
     137,   135,   136,     0,     0,     0,    75,     0,     0,     0,
      82,   112,     0,     0,     0,     0,     0,    98,     0,     0,
       0,   155,   261,    51,   209,     0,     0,   120,   121,     0,
       0,     0,   133,   210,     0,    75,   138,   139,   102,   145,
     200,     0,     0,   104,   103,   105,     0,     0,     0,     0,
       0,    90,   113,     0,   100,   114,     0,   122,   125,     0,
     123,   126,   192,     0,     0,   106,     0,    84,     0,     0,
       0,    92,     0,     0,   115,   116,     0,     0,   194,   193,
       0,     0,     0,    85,    86,     0,     0,    93,    94,   124,
     127,   195,    87,    88,    95,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    38,    39,    16,   100,   224,   225,    17,    18,
      62,    63,    64,   150,   137,    19,   152,   153,   154,   155,
     357,   358,   359,   360,   361,   280,   156,   157,   158,   320,
     321,   322,   323,   159,   160,   161,   162,   163,   164,   213,
     282,   165,   166,   167,   168,   134,    77,    20,   170,   171,
     172,   128,    21,    22,    23,    24,    25,    26,    27,    28,
     214,    29,    30,    31,    32,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -265
static const yytype_int16 yypact[] =
{
     527,  -265,    11,   -53,   -22,    12,    18,  1003,    38,   198,
    1032,  1032,    83,   221,   116,   786,  1032,    53,  -265,  -265,
    -265,   104,   196,   236,   121,  -265,  -265,  -265,  -265,    55,
    -265,  -265,  -265,   550,  -265,   207,  -265,   268,  -265,   157,
     291,   240,    51,   257,   144,   257,   145,  -265,  -265,  -265,
     302,   134,  -265,  -265,  -265,   350,   355,  -265,  -265,   281,
     348,  -265,  -265,   290,  -265,   305,   148,    24,    26,  -265,
    -265,  -265,   365,  -265,   311,  1003,    54,  -265,  -265,  -265,
     321,  -265,  1003,   162,  -265,   326,  -265,   422,  -265,  -265,
    -265,   345,    45,  -265,   247,   407,  -265,    20,   347,  -265,
     224,  -265,   351,   309,  -265,   356,  -265,   376,  -265,  -265,
    -265,   418,   341,  -265,  -265,   419,   343,  -265,   290,  1003,
     281,   470,  -265,   400,  -265,  -265,  1003,  -265,    46,  -265,
     402,   402,    21,   472,  -265,   477,  -265,   481,  -265,  -265,
     817,   848,  1021,   491,   721,   721,   755,   255,   721,  -265,
     293,  -265,  -265,  -265,   151,  -265,   478,  -265,  -265,  -265,
    -265,  -265,  -265,   152,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,   288,  -265,   485,  -265,   489,   524,   529,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,   194,  -265,  -265,  -265,  -265,   414,
      27,  -265,  -265,   473,  -265,   232,   542,   476,   488,   547,
     492,   555,  -265,  -265,   444,  -265,  -265,   506,  -265,    50,
    -265,  -265,   559,   172,   493,  -265,  -265,  -265,   560,  -265,
     223,  -265,  1003,  1021,   166,  -265,  -265,  -265,  1021,   307,
    -265,  -265,   314,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
     879,  -265,  -265,   623,  -265,    90,   114,    41,   720,   410,
    -265,  -265,  -265,  -265,   494,    40,  -265,   495,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,   487,   567,  -265,  -265,   249,
    -265,    35,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,   402,   568,   569,  1003,   188,
    -265,   496,  -265,   324,  -265,   392,   499,   502,    31,   174,
     174,   572,    90,   114,    58,  1021,   399,   516,   573,   374,
     551,  -265,  -265,  -265,   258,  -265,  -265,  -265,   578,  -265,
    -265,   575,   587,   577,   583,   584,   585,   565,     2,   523,
     571,    10,   598,   606,  -265,  -265,  -265,    39,  -265,  -265,
    -265,  -265,  -265,   607,  -265,    19,   535,   359,  -265,  -265,
     910,   608,   499,   502,   609,  -265,  -265,   615,   554,   554,
    -265,   562,   563,   605,   174,   656,   621,   634,   635,   370,
    -265,  -265,   941,   972,   570,   640,   636,  -265,   588,   643,
     654,  -265,  -265,  -265,  -265,   612,   613,  -265,  -265,   672,
     614,   616,  -265,  -265,   554,  -265,  -265,  -265,  -265,  -265,
    -265,    52,   381,  -265,  -265,  -265,   673,  1003,   276,  1003,
     280,  -265,  -265,   678,  -265,  -265,   685,  -265,  -265,   267,
    -265,  -265,  -265,   687,    76,  -265,   395,  -265,   686,   688,
     397,  -265,   689,   692,  -265,  -265,   619,   625,  -265,  -265,
     707,   706,   708,  -265,  -265,   709,   710,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,   629,  -265,   -82,   670,  -245,   504,  -265,   -71,
     602,   666,  -265,    -7,   -81,   -59,  -129,   586,  -265,  -265,
    -265,   367,  -265,  -265,   372,  -234,  -265,   626,  -265,   460,
    -265,   406,  -264,  -134,  -135,  -123,   644,  -265,  -265,  -232,
    -249,  -132,   160,   645,  -265,  -126,   719,   -40,    17,   641,
    -265,  -265,  -265,  -265,  -265,  -265,    -6,    -2,   777,     8,
    -265,  -265,  -265,   360,   -31,   718,  -265,  -265
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      65,   148,    89,    69,   246,   247,   249,   264,    76,   339,
     265,    73,   149,   263,   405,   223,   281,   257,   260,    43,
     266,    36,   409,    40,   151,    45,   343,   347,   350,     2,
     248,    43,   221,    45,   415,   416,     2,    41,   239,   298,
     384,   341,   345,   169,     2,   243,   351,   369,     2,   244,
     348,   413,   354,   252,    42,   216,   370,    96,   452,    79,
     245,    86,    97,   365,   311,   273,    87,   387,    76,   130,
     131,   132,   356,   149,   149,   136,    98,   149,    80,   355,
     343,   347,   469,   343,   347,   151,   151,    37,    44,   151,
     148,   173,   341,   345,    46,   417,   222,   133,   385,   386,
     124,   149,   125,   222,   169,   169,   278,   331,   169,   355,
     356,   222,   136,   151,    66,   222,   453,   331,   264,   136,
     281,    37,   370,   264,   263,   281,   265,    84,   281,    74,
     133,   432,   169,   254,   259,   262,   259,    69,   223,   259,
     470,   342,   346,   349,    73,   430,    85,   257,   385,   386,
     101,   104,   173,   173,   122,   278,   173,   283,   286,    72,
      92,   268,   269,    67,    68,   274,   340,    93,   138,   102,
     105,     2,     9,   123,   139,   252,   284,   287,    13,   278,
     173,   326,   327,   328,   107,   108,   313,   109,    89,   371,
     344,   281,   342,   346,   349,   342,   346,   295,   342,   346,
     264,    82,   281,   375,   376,   377,   296,    90,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   223,
       4,     5,     6,   140,   141,    58,   142,   227,     7,     8,
     143,   316,   228,   144,   145,   301,   146,    59,   147,   278,
      14,    15,   279,   319,   302,   324,   325,    83,   342,   346,
     331,   259,   367,     1,   342,   346,     2,    67,    68,   218,
     429,   368,   273,   336,   378,   273,   319,   393,   119,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      67,    68,   466,   467,   457,   223,   317,   318,   461,     9,
     429,   458,   459,    91,   288,   462,   463,     2,    59,    60,
     289,   261,    94,   267,     3,     4,     5,     6,   275,   276,
     277,   319,   227,     7,     8,     9,    95,   230,    10,    11,
      12,    13,   329,   330,   277,    14,    15,   380,   336,   332,
     333,   277,   381,    99,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   399,     4,     5,     6,   140,
     141,    58,   142,   106,     7,     8,   143,    60,   278,   144,
     145,   119,   146,    59,   147,   120,    14,    15,   419,   279,
      70,    71,   278,   319,   420,   421,    78,   380,   126,   278,
     435,   121,   392,   331,   380,   436,   399,   127,   319,   454,
     334,   234,   235,   237,   238,   438,   440,   110,   135,   111,
     112,   113,   114,   174,   115,   116,   117,   382,   383,   328,
     471,   472,   475,   476,   388,   389,   328,   273,   220,   352,
      88,  -101,   215,     2,   226,   175,   297,   232,   229,   176,
     456,   177,   460,   231,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   334,   233,
     236,     3,     4,     5,     6,   331,   241,   242,   133,   250,
       7,     8,     9,   251,   252,    10,    11,    12,    13,   285,
     175,   291,    14,    15,   176,   309,   177,   292,   212,   363,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,     1,   293,   294,     2,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   303,   300,
      67,    68,   304,   306,    58,   258,    88,   310,   273,     2,
     393,   308,  -101,   364,   305,   312,    59,   147,   307,   314,
     315,   353,   362,   366,   372,   340,   379,   373,   344,   273,
     390,   391,   395,   400,     3,     4,     5,     6,   394,   401,
     404,   402,   403,     7,     8,     9,   408,   396,    10,    11,
      12,    13,   397,   407,   411,    14,    15,     3,     4,     5,
       6,   418,   412,   414,   423,   428,     7,     8,     9,   424,
     397,    10,    11,    12,    13,   425,   426,   427,    14,    15,
     331,   337,  -102,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   433,   434,   442,   441,   443,   445,
      58,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,    60,   431,   444,   446,   398,    58,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      59,    60,   449,   455,   464,   398,   338,   318,   447,   448,
     450,   465,   451,   468,   473,   479,   474,   477,    59,    60,
     478,   480,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   481,   482,   103,   483,   484,   485,    58,
     318,   217,   240,   175,   299,   118,   255,   176,   410,   177,
     406,    59,    60,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   256,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   374,     4,
       5,     6,   140,   141,    58,   142,   422,     7,     8,   143,
     271,   272,   144,   145,   129,   146,    59,   147,    81,    14,
      15,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   219,   290,    67,    68,   270,   141,    58,   258,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
      59,   147,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,    58,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
      58,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    59,   147,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,    58,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,   147,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,    58,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,   147,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,    58,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,    58,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,    58,   439,     0,     0,     0,
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
       7,    83,    33,     9,   130,   131,   132,   142,    15,   273,
     142,    13,    83,   142,    12,    97,   150,   140,   141,     7,
     143,    10,    12,    76,    83,     7,   275,   276,   277,     9,
       9,     7,    12,     7,    15,    16,     9,    59,   119,    12,
       9,   275,   276,    83,     9,   126,   278,    12,     9,     3,
       9,    12,    12,     3,    76,    10,   301,     6,     6,     6,
      14,     6,    11,   295,    14,     7,    11,     9,    75,    15,
      16,    17,    70,   144,   145,    82,    25,   148,    25,    69,
     329,   330,     6,   332,   333,   144,   145,    76,    76,   148,
     172,    83,   326,   327,    76,    76,    76,    76,   332,   333,
      76,   172,    76,    76,   144,   145,    65,    76,   148,    69,
      70,    76,   119,   172,    76,    76,    64,    76,   253,   126,
     254,    76,   367,   258,   253,   259,   258,     6,   262,    13,
      76,   395,   172,   140,   141,   142,   143,   143,   220,   146,
      64,   275,   276,   277,   146,   394,    25,   270,   382,   383,
       6,     6,   144,   145,     6,    65,   148,     6,     6,    76,
       3,   144,   145,    59,    60,   148,    76,    10,     6,    25,
      25,     9,    68,    25,    12,     3,    25,    25,    74,    65,
     172,    15,    16,    17,    50,    51,    14,    53,   219,   315,
      76,   325,   326,   327,   328,   329,   330,     3,   332,   333,
     335,     5,   336,    15,    16,    17,    12,     0,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   301,
      58,    59,    60,    61,    62,    63,    64,     3,    66,    67,
      68,     8,     8,    71,    72,     3,    74,    75,    76,    65,
      78,    79,    76,   250,    12,   252,   253,    11,   382,   383,
      76,   258,     3,     6,   388,   389,     9,    59,    60,    12,
     394,    12,     7,   270,    76,     7,   273,     9,    13,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      59,    60,    15,    16,     8,   367,    63,    64,     8,    68,
     424,    15,    16,    25,     6,    15,    16,     9,    75,    76,
      12,   141,    11,   143,    57,    58,    59,    60,    15,    16,
      17,   318,     3,    66,    67,    68,    76,     8,    71,    72,
      73,    74,    15,    16,    17,    78,    79,     3,   335,    15,
      16,    17,     8,    76,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,   352,    58,    59,    60,    61,
      62,    63,    64,    51,    66,    67,    68,    76,    65,    71,
      72,    13,    74,    75,    76,    75,    78,    79,     9,    76,
      10,    11,    65,   380,    15,    16,    16,     3,    13,    65,
      10,    76,     8,    76,     3,    15,   393,    76,   395,     8,
      76,    50,    51,    50,    51,   402,   403,    47,    77,    49,
      50,    51,    47,    77,    49,    50,    51,    15,    16,    17,
      15,    16,    15,    16,    15,    16,    17,     7,    11,     9,
       6,    11,    77,     9,    77,     3,    12,    51,    77,     7,
     437,     9,   439,    77,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    76,    51,
      51,    57,    58,    59,    60,    76,     6,    77,    76,     7,
      66,    67,    68,     6,     3,    71,    72,    73,    74,    11,
       3,     6,    78,    79,     7,    51,     9,     8,    76,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     6,    10,     6,     9,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     6,    76,
      59,    60,    76,     6,    63,    64,     6,    51,     7,     9,
       9,     6,    11,    76,    76,     6,    75,    76,    76,    76,
      10,    77,    77,     6,     6,    76,    80,     8,    76,     7,
      64,     8,     7,     6,    57,    58,    59,    60,    10,     6,
      25,     7,     7,    66,    67,    68,    25,    10,    71,    72,
      73,    74,    15,    80,     6,    78,    79,    57,    58,    59,
      60,    76,     6,     6,     6,    10,    66,    67,    68,    10,
      15,    71,    72,    73,    74,    10,    64,    64,    78,    79,
      76,     8,    11,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    10,    10,     6,    77,    12,     6,
      63,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    75,    76,     8,    77,    12,    80,    63,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      75,    76,    10,    10,     6,    80,    63,    64,    76,    76,
      76,     6,    76,     6,     8,    76,     8,     8,    75,    76,
       8,    76,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     6,     8,    45,     8,     8,     8,    63,
      64,    92,   120,     3,   220,    59,   140,     7,   361,     9,
     358,    75,    76,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   140,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   318,    58,
      59,    60,    61,    62,    63,    64,   380,    66,    67,    68,
     146,   146,    71,    72,    75,    74,    75,    76,    21,    78,
      79,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    94,   172,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
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
      16,    76,    15,    16,    76,    64,    94,     8,    63,   113,
      76,   106,   114,   121,    76,   106,   114,   121,     9,   114,
     121,   120,     9,    77,    12,    69,    70,   101,   102,   103,
     104,   105,    77,    12,    76,   120,     6,     3,    12,    12,
      87,   126,     6,     8,   110,    15,    16,    17,    76,    80,
       3,     8,    15,    16,     9,   106,   106,     9,    15,    16,
      64,     8,     8,     9,    10,     7,    10,    15,    80,    94,
       6,     6,     7,     7,    25,    12,   105,    80,    25,    12,
     102,     6,     6,    12,     6,    15,    16,    76,    76,     9,
      15,    16,   112,     6,    10,    10,    64,    64,    10,   114,
     121,     8,   113,    10,    10,    10,    15,    64,    94,    64,
      94,    77,     6,    12,    77,     6,    12,    76,    76,    10,
      76,    76,     6,    64,     8,    10,    94,     8,    15,    16,
      94,     8,    15,    16,     6,     6,    15,    16,     6,     6,
      64,    15,    16,     8,     8,    15,    16,     8,     8,    76,
      76,     6,     8,     8,     8,     8
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
#line 68 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 69 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newAttributeList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 72 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (3)].sn);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 73 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (4)].sn);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 74 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 77 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 78 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentifyList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 81 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 82 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumerator((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 85 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 86 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnumeratorList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 90 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 91 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), NULL, (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 92 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 93 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 94 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 95 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 98 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setEnumSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 99 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setEnumSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 102 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 103 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 106 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 107 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 110 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 111 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 114 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 115 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 118 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 119 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 122 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 123 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 124 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 125 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 126 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 127 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 128 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), enum_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 129 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), value_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 130 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (5)].sn), reference_type); setNativeName((yyval.sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 133 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn), NULL, NULL);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 134 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 135 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn), NULL, NULL);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 138 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 139 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 142 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 143 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 146 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setFieldSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 147 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setFieldSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 151 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 152 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 153 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 154 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 155 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 156 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 160 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 161 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 164 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 165 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 166 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 167 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 168 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 169 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 172 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 173 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setSetterAllowNull((yyval.sn));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 176 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 177 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 180 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (1)].sn), simple_property);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 181 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (3)].sn), fixed_array_property);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 182 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), dynamic_array_property);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 183 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), list_property);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 184 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 185 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (5)].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 188 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 189 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 190 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setPropertyType((yyval.sn), NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 191 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 192 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(4) - (4)].sn); setPropertyType((yyval.sn), (yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 195 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 196 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 197 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setPropertySetter((yyval.sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 198 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(3) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(4) - (6)].sn));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 199 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setPropertyGetter((yyval.sn), (yyvsp[(4) - (6)].sn)); setPropertySetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 202 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 203 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 207 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 208 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 209 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 210 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 211 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 212 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 213 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 214 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 215 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 218 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 219 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 222 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 223 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setParameterAllowNull((yyval.sn));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 226 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 227 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 230 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn), NULL);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 231 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 232 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn), NULL);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 233 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 234 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 235 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 238 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 239 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 240 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 241 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 242 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 243 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 246 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 247 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 250 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 251 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 252 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 253 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 256 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 257 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 260 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setMethodSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 261 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setMethodSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 303 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 304 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 305 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 306 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 310 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 311 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 312 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 313 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 314 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 317 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 318 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 321 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 322 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 323 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 326 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 327 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 330 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 331 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 332 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newDelegate((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 335 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 336 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 337 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 338 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 339 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setDelegateResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setDelegateResultArray((yyval.sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 342 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (2)].sn));}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 343 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setDelegateKeyword((yyval.sn), (yyvsp[(1) - (3)].sn)); setDelegateResultConst((yyval.sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 346 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 347 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 348 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 349 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 350 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 351 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 352 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 353 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 354 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 355 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 358 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 359 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 362 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 363 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 364 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 365 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 368 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 369 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 372 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 375 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 376 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 377 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 378 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 381 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 382 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 385 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (3)].sn), NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 386 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 389 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassSemicolon((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 390 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setNativeName((yyval.sn), (yyvsp[(3) - (4)].sn)); setClassSemicolon((yyval.sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 393 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 394 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 397 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 398 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 401 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 402 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 406 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 407 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 408 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 409 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 412 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 415 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 416 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 417 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 418 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 422 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 423 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 424 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 425 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 426 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 427 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 428 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 429 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFilter((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 432 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 433 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setAttributeList((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 436 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 437 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 438 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 439 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 442 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 443 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 446 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 447 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3680 "D:\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



