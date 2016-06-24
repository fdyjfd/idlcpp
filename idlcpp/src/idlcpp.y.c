
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
     IDENTIFY = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"

	struct SyntaxNode* sn;



/* Line 214 of yacc.c  */
#line 172 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 184 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"

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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   782

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNRULES -- Number of states.  */
#define YYNSTATES  389

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      13,    25,    14,     2,     2,     2,     2,     2,     2,     2,
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
      68,    69,    70,    71,    72,    73,    74,    75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    20,
      23,    25,    28,    31,    34,    38,    42,    44,    47,    49,
      52,    54,    56,    58,    61,    63,    65,    69,    76,    84,
      90,    92,    95,    98,   100,   105,   107,   111,   113,   116,
     118,   120,   122,   126,   131,   135,   139,   143,   147,   149,
     152,   155,   159,   165,   167,   170,   172,   175,   177,   180,
     183,   185,   190,   196,   202,   209,   216,   218,   223,   229,
     235,   242,   249,   252,   256,   260,   265,   270,   274,   278,
     283,   288,   290,   293,   295,   298,   301,   304,   308,   312,
     317,   322,   329,   334,   339,   346,   348,   351,   353,   357,
     362,   368,   374,   381,   383,   386,   390,   394,   398,   404,
     406,   409,   411,   414,   417,   420,   422,   425,   427,   430,
     433,   435,   437,   439,   441,   443,   445,   447,   449,   451,
     453,   455,   457,   459,   461,   464,   467,   469,   471,   473,
     475,   477,   479,   481,   483,   485,   487,   489,   491,   493,
     495,   497,   499,   501,   503,   505,   507,   513,   520,   527,
     535,   538,   542,   546,   550,   556,   558,   561,   563,   566,
     569,   571,   574,   576,   579,   582,   584,   586,   588,   590,
     592,   594,   596,   598,   601,   604,   607,   610,   613,   616,
     619,   622,   624,   628,   632,   635,   641,   644,   650,   652,
     655,   657,   661,   666,   672,   674,   677,   679,   682,   684,
     687,   690,   692,   694,   698,   702,   708,   711,   716,   722,
     729,   731,   734,   737,   739,   741,   743,   745,   747,   749,
     752,   755,   758,   761,   764,   767,   772,   778,   780,   783,
     786,   787
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     131,     0,    -1,    46,    -1,    47,    -1,    54,    47,    -1,
      55,    47,    -1,    48,    -1,    49,    -1,    54,    49,    -1,
      55,    49,    -1,    50,    -1,    54,    50,    -1,    55,    50,
      -1,    50,    50,    -1,    54,    50,    50,    -1,    55,    50,
      50,    -1,    51,    -1,    54,    51,    -1,    54,    -1,    55,
      51,    -1,    55,    -1,    52,    -1,    53,    -1,    50,    53,
      -1,    62,    -1,    75,    -1,    78,     3,    75,    -1,    57,
      75,    11,    78,    12,     6,    -1,    57,    75,    11,    78,
       3,    12,     6,    -1,    57,    75,    11,    12,     6,    -1,
      79,    -1,    71,    79,    -1,    70,    79,    -1,    75,    -1,
      75,    13,    85,    14,    -1,    81,    -1,    82,    74,    81,
      -1,    82,    -1,    74,    82,    -1,    77,    -1,    83,    -1,
      84,    -1,    85,     3,    84,    -1,    65,    84,    75,     6,
      -1,    66,    75,     6,    -1,    57,    75,     6,    -1,    59,
      75,     6,    -1,    58,    75,     6,    -1,    86,    -1,    71,
      86,    -1,    70,    86,    -1,    84,    75,     6,    -1,    84,
      75,     9,    10,     6,    -1,    88,    -1,    63,    88,    -1,
      89,    -1,    60,    89,    -1,    90,    -1,    71,    90,    -1,
      70,    90,    -1,    68,    -1,    68,     7,    84,     8,    -1,
      68,     7,    84,    15,     8,    -1,    68,     7,    84,    16,
       8,    -1,    68,     7,    63,    84,    15,     8,    -1,    68,
       7,    63,    84,    16,     8,    -1,    69,    -1,    69,     7,
      84,     8,    -1,    69,     7,    84,    15,     8,    -1,    69,
       7,    84,    16,     8,    -1,    69,     7,    63,    84,    15,
       8,    -1,    69,     7,    63,    84,    16,     8,    -1,    84,
      75,    -1,    84,    15,    75,    -1,    84,    16,    75,    -1,
      63,    84,    15,    75,    -1,    63,    84,    16,    75,    -1,
      94,    92,     6,    -1,    94,    93,     6,    -1,    94,    92,
      93,     6,    -1,    94,    93,    92,     6,    -1,    95,    -1,
      60,    95,    -1,    96,    -1,    71,    96,    -1,    70,    96,
      -1,    84,    75,    -1,    84,    15,    75,    -1,    84,    16,
      75,    -1,    84,    15,    15,    75,    -1,    84,    17,    15,
      75,    -1,    84,    17,     9,    10,    15,    75,    -1,    84,
      15,    16,    75,    -1,    84,    17,    16,    75,    -1,    84,
      17,     9,    10,    16,    75,    -1,    98,    -1,    63,    98,
      -1,    99,    -1,   100,     3,    99,    -1,    75,     7,     8,
       6,    -1,    75,     7,   100,     8,     6,    -1,    75,     7,
       8,    63,     6,    -1,    75,     7,   100,     8,    63,     6,
      -1,   101,    -1,    84,   101,    -1,    84,    16,   101,    -1,
      84,    15,   101,    -1,    84,    17,   101,    -1,    84,    17,
       9,    10,   101,    -1,   102,    -1,    63,   102,    -1,   103,
      -1,    67,   103,    -1,    61,   103,    -1,    60,   103,    -1,
     104,    -1,    73,   104,    -1,   105,    -1,    71,   105,    -1,
      70,   105,    -1,    18,    -1,    19,    -1,    15,    -1,    20,
      -1,    21,    -1,    17,    -1,    16,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    13,    -1,    14,    -1,     3,
      -1,     9,    10,    -1,     7,     8,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    36,    -1,    37,    -1,    34,    -1,    35,
      -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,
      -1,    43,    -1,    44,    -1,    45,    -1,    64,   107,     7,
       8,     6,    -1,    64,   107,     7,   100,     8,     6,    -1,
      64,   107,     7,     8,    63,     6,    -1,    64,   107,     7,
     100,     8,    63,     6,    -1,    84,   108,    -1,    84,    16,
     108,    -1,    84,    15,   108,    -1,    84,    17,   108,    -1,
      84,    17,     9,    10,   108,    -1,   109,    -1,    63,   109,
      -1,   110,    -1,    67,   110,    -1,    61,   110,    -1,   111,
      -1,    73,   111,    -1,   112,    -1,    71,   112,    -1,    70,
     112,    -1,    91,    -1,    97,    -1,   106,    -1,   113,    -1,
     123,    -1,    80,    -1,    87,    -1,     6,    -1,   114,    91,
      -1,   114,    97,    -1,   114,   106,    -1,   114,   113,    -1,
     114,   123,    -1,   114,    80,    -1,   114,    87,    -1,   114,
       6,    -1,    75,    -1,   115,     3,    75,    -1,    13,   115,
      14,    -1,    58,    75,    -1,    58,    75,     7,    75,     8,
      -1,    59,    75,    -1,    59,    75,     7,    75,     8,    -1,
     117,    -1,   117,   116,    -1,   118,    -1,   118,     5,    85,
      -1,   119,    11,    12,     6,    -1,   119,    11,   114,    12,
       6,    -1,   120,    -1,    67,   120,    -1,   121,    -1,    73,
     121,    -1,   122,    -1,    71,   122,    -1,    70,   122,    -1,
      75,    -1,   107,    -1,   124,     3,    75,    -1,   124,     3,
     107,    -1,    72,    75,    13,    85,    14,    -1,   125,     6,
      -1,   125,    11,    12,     6,    -1,   125,    11,   124,    12,
       6,    -1,   125,    11,   124,     3,    12,     6,    -1,   126,
      -1,    71,   126,    -1,    70,   126,    -1,   123,    -1,    80,
      -1,   127,    -1,    87,    -1,   130,    -1,     6,    -1,   128,
     123,    -1,   128,    80,    -1,   128,   127,    -1,   128,    87,
      -1,   128,   130,    -1,   128,     6,    -1,    56,    75,    11,
      12,    -1,    56,    75,    11,   128,    12,    -1,   129,    -1,
      71,   129,    -1,    70,   129,    -1,    -1,   128,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    52,    53,    56,    57,    58,
      61,    62,    63,    66,    67,    70,    71,    74,    75,    78,
      79,    82,    83,    86,    87,    88,    89,    90,    93,    94,
      95,    98,    99,   102,   103,   106,   107,   110,   111,   112,
     115,   116,   117,   118,   119,   120,   123,   124,   125,   126,
     127,   128,   132,   133,   134,   135,   136,   140,   141,   142,
     143,   147,   148,   151,   152,   153,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   167,   168,   171,   172,   175,
     176,   177,   178,   181,   182,   183,   184,   185,   186,   189,
     190,   193,   194,   195,   196,   199,   200,   203,   204,   205,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   247,   248,   249,   250,
     254,   255,   256,   257,   258,   261,   262,   265,   266,   267,
     270,   271,   274,   275,   276,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   298,   299,   302,   305,   306,   307,   308,   311,   312,
     315,   316,   319,   320,   323,   324,   327,   328,   331,   332,
     333,   336,   337,   338,   339,   342,   345,   346,   347,   348,
     351,   352,   353,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   370,   371,   374,   375,   376,
     379,   380
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
  "$accept", "primitive", "identityList", "enum_0", "enum", "scopeName",
  "scopeNameList_0", "scopeNameList", "typeName", "typeNameList",
  "typeAlias_0", "typeAlias", "field_0", "field_1", "field_2", "field",
  "getter", "setter", "property_0", "property_1", "property_2", "property",
  "parameter_0", "parameter", "parameterList", "method_0", "method_1",
  "method_2", "method_3", "method_4", "method", "operatorSign",
  "operator_0", "operator_1", "operator_2", "operator_3", "operator_4",
  "operator", "classMemberList", "templateParameterList",
  "templateParameters", "class_0", "class_1", "class_2", "class_3",
  "class_4", "class_5", "class", "tokenList", "templateClassInstance_0",
  "templateClassInstance_1", "templateClassInstance",
  "namespaceMemberList", "namespace_0", "namespace", "program", 0
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
     302,   303,   304,   305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   105,   105,   106,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   116,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     123,   124,   124,   124,   124,   125,   126,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   130,   130,   130,
     131,   131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     2,     2,
       1,     2,     2,     2,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     1,     3,     6,     7,     5,
       1,     2,     2,     1,     4,     1,     3,     1,     2,     1,
       1,     1,     3,     4,     3,     3,     3,     3,     1,     2,
       2,     3,     5,     1,     2,     1,     2,     1,     2,     2,
       1,     4,     5,     5,     6,     6,     1,     4,     5,     5,
       6,     6,     2,     3,     3,     4,     4,     3,     3,     4,
       4,     1,     2,     1,     2,     2,     2,     3,     3,     4,
       4,     6,     4,     4,     6,     1,     2,     1,     3,     4,
       5,     5,     6,     1,     2,     3,     3,     3,     5,     1,
       2,     1,     2,     2,     2,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     6,     6,     7,
       2,     3,     3,     3,     5,     1,     2,     1,     2,     2,
       1,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     2,     5,     2,     5,     1,     2,
       1,     3,     4,     5,     1,     2,     1,     2,     1,     2,
       2,     1,     1,     3,     3,     5,     2,     4,     5,     6,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     4,     5,     1,     2,     2,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     240,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,   224,    48,   226,   198,   200,     0,
     204,   206,   208,   223,     0,   220,   225,   241,   237,   227,
       0,     0,     0,   194,   196,     2,     3,     6,     7,    10,
      16,    21,    22,    18,    20,    24,     0,    33,    39,    35,
      37,    40,     0,     0,     0,     0,   205,    32,    50,   210,
     222,   239,    31,    49,   209,   221,   238,     0,   207,     0,
     199,     0,     0,   216,     0,   234,   230,   232,   229,   231,
     233,     1,     0,    45,     0,    47,     0,    46,     0,    13,
      23,     4,     8,    11,    17,     5,     9,    12,    19,    38,
       0,     0,     0,    44,   194,   196,     0,   191,     0,    41,
     201,   182,     0,     0,     0,     0,     0,     0,     0,     0,
      33,   180,     0,   181,    53,    55,    57,   175,     0,    81,
      83,   176,   103,   109,   111,   115,   117,   177,   165,   167,
     170,   172,   178,     0,   179,   133,     0,     0,     0,   131,
     132,   122,   126,   125,   120,   121,   123,   124,   127,   128,
     129,   130,   136,   137,   138,   139,   140,   141,   142,   143,
     146,   147,   144,   145,   148,   149,   150,   151,   152,   153,
     154,   155,   211,   212,     0,   235,     0,     0,    25,     0,
       0,     0,    14,    15,     0,    36,    43,     0,     0,   193,
       0,   202,     0,     0,    56,    82,   114,     0,     0,   113,
     169,     0,    54,   110,   166,   112,   168,    59,    85,   119,
     174,    58,    84,   118,   173,     0,   116,   171,     0,     0,
       0,     0,     0,    72,   104,   160,    60,    66,     0,     0,
     190,     0,   188,   189,   183,   184,   185,   186,   187,   135,
     134,   217,     0,     0,   236,    29,     0,     0,   195,   197,
      34,   215,   192,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      97,     0,    73,   106,   162,    74,   105,   161,     0,   107,
     163,     0,    51,     0,     0,     0,    77,     0,    78,     0,
     203,     0,   213,   214,   218,     0,    26,    27,     0,     0,
       0,    75,    76,     0,     0,    99,     0,    96,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,   219,    28,     0,   101,     0,     0,    87,
      88,     0,     0,     0,    98,   100,     0,   108,   164,     0,
       0,    52,     0,    61,     0,     0,     0,    67,     0,     0,
      89,    92,     0,    90,    93,   102,   156,     0,     0,     0,
       0,    62,    63,     0,     0,    68,    69,     0,     0,   158,
     157,     0,    64,    65,    70,    71,    91,    94,   159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    48,   189,    13,    14,    49,    50,    51,   122,   110,
      15,    16,   124,   125,   126,   127,   238,   239,   128,   129,
     130,   131,   279,   280,   281,   132,   133,   134,   135,   136,
     137,   183,   235,   138,   139,   140,   141,   142,   143,   108,
      70,    17,    18,    19,    20,    21,    22,    23,   184,    24,
      25,    26,    27,    28,    29,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -203
static const yytype_int16 yypact[] =
{
     207,  -203,   -44,    37,    96,   117,   131,   152,    57,   228,
     228,   194,   223,  -203,  -203,  -203,  -203,    36,    90,    72,
    -203,  -203,  -203,  -203,   184,  -203,  -203,   447,  -203,  -203,
      97,   201,   205,   301,   303,  -203,  -203,  -203,  -203,    14,
    -203,  -203,  -203,   123,   255,  -203,   208,   263,  -203,  -203,
     225,  -203,   216,   291,   240,   242,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,   290,  -203,   250,
    -203,   131,   355,  -203,   217,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,    78,  -203,    11,  -203,   319,  -203,   320,  -203,
    -203,  -203,  -203,   316,  -203,  -203,  -203,   328,  -203,   225,
     131,   208,   390,  -203,   391,   392,   131,  -203,    31,  -203,
     397,  -203,   405,   599,   617,   707,   581,   521,   521,   551,
     162,  -203,    39,  -203,  -203,  -203,  -203,  -203,   243,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,   385,  -203,  -203,   411,   414,   421,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,   135,  -203,   314,   443,  -203,   185,
     446,   449,  -203,  -203,    48,  -203,  -203,    54,   396,  -203,
     131,  -203,   707,    24,  -203,  -203,  -203,   707,   125,  -203,
    -203,   457,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   635,  -203,  -203,   415,   -48,
       2,    -3,   520,    26,  -203,  -203,   468,   469,    18,    20,
    -203,   485,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,   315,   486,  -203,  -203,    17,   487,  -203,  -203,
    -203,  -203,  -203,  -203,    27,   419,   422,     6,     5,     5,
     491,   112,   127,    26,   707,    43,    22,   131,   192,  -203,
    -203,   220,   491,  -203,  -203,   491,  -203,  -203,   489,  -203,
    -203,   493,  -203,   492,   653,   671,  -203,   495,  -203,   503,
    -203,   504,  -203,  -203,  -203,   505,  -203,  -203,   440,   441,
     512,   491,   491,   450,   450,  -203,   518,  -203,    58,   451,
     137,  -203,   689,    41,     5,   433,   522,   131,    55,   131,
     202,  -203,  -203,  -203,  -203,   450,  -203,   455,   456,  -203,
    -203,   556,   502,   510,  -203,  -203,   583,  -203,  -203,    42,
     267,  -203,   298,  -203,   582,   584,   347,  -203,   585,   600,
    -203,  -203,   349,  -203,  -203,  -203,  -203,   601,    76,   607,
     608,  -203,  -203,   609,   611,  -203,  -203,   516,   545,  -203,
    -203,   615,  -203,  -203,  -203,  -203,  -203,  -203,  -203
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,     8,   -26,   523,   576,  -203,    -6,   115,
      10,   -20,  -113,   524,   251,   480,   399,   403,  -203,   529,
     257,   514,   381,   337,   335,  -110,  -111,  -103,   557,   259,
     532,  -202,  -193,  -101,   182,   558,   265,   535,  -203,  -203,
    -203,  -203,  -203,  -203,    -5,    13,    12,   -19,  -203,  -203,
     379,   -22,   612,   383,   -18,  -203
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      52,    76,   212,    56,   213,    79,   288,    77,    78,    80,
     206,   209,   234,   215,   214,   310,   232,    57,    62,    58,
      63,    59,    64,   187,   296,    68,   298,   282,   315,   305,
     291,    31,   292,   228,   198,   293,   284,   287,   290,   265,
     266,   267,   308,   309,   267,   199,   121,   345,   366,    69,
     303,   200,   123,   144,   229,   230,   231,   200,   313,   314,
     267,   232,   260,   353,    89,   109,   232,    90,   261,   232,
     354,   355,   270,   337,   338,   284,   287,   285,   284,   287,
     270,   270,   380,    72,     1,   316,   188,   237,   236,   212,
     185,   213,   306,   234,   109,    71,   213,    81,   234,   233,
     109,   234,   273,   232,   346,   367,   214,   203,   208,   211,
     208,    56,    32,   208,   233,    54,    55,   242,   270,   283,
     286,   289,   206,   243,   248,    57,    62,    58,    63,    59,
      64,   348,    68,   339,     2,     3,     4,     5,   252,   381,
     268,   269,   231,     6,     7,     8,   341,   253,     9,    10,
      11,    12,   342,   343,   234,   283,   286,   289,   283,   286,
      76,   283,   286,   213,    79,   234,    77,    78,    80,   228,
      91,    33,    92,    93,    94,   100,   232,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   311,   256,   232,
      73,   232,    34,    45,   263,    74,   264,   257,   283,   286,
     270,   208,   312,   283,   286,    46,    47,   318,   319,   320,
     357,    83,    82,     1,   347,   194,    84,   358,   359,   275,
     145,   197,   278,   322,   146,   347,   147,    53,   323,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,     2,     3,     4,     5,   321,   275,    67,
     322,   278,     6,     7,     8,   368,   100,     9,    10,    11,
      12,    54,    55,    47,     2,     3,     4,     5,   328,   330,
       8,   102,   182,     6,     7,     8,   210,   103,   216,   101,
      11,    12,    95,   106,    96,    97,    98,    85,    86,    87,
      88,   236,   237,   369,   370,   104,   278,   105,   145,   278,
      75,   352,   146,   356,   147,   107,   254,   301,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   111,   373,   374,   377,   378,   192,   112,   217,   221,
       2,     3,     4,     5,   218,   222,   219,   223,   193,     6,
       7,     8,   220,   224,     9,    10,    11,    12,    60,    65,
     302,   240,    61,    66,   190,   191,   196,   241,    86,    88,
     200,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   201,     3,     4,     5,   113,   114,    45,   115,   249,
       6,     7,   116,   276,   250,   117,   118,   251,   119,    46,
     120,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   349,     3,     4,     5,   113,   114,    45,   115,   255,
       6,     7,   116,    75,   258,   117,   118,   259,   119,    46,
     120,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   262,   271,   272,   231,   294,   295,    45,   277,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    46,
      47,   300,   304,   307,   282,    45,   277,   285,   228,   324,
     325,   331,   326,     2,     3,     4,     5,    46,    47,   332,
     333,   334,     6,     7,     8,   311,   312,     9,    10,    11,
      12,   232,   335,   145,   336,   270,   340,   146,   351,   147,
     360,   361,   273,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   362,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   363,     3,     4,
       5,   113,   114,    45,   115,   364,     6,     7,   116,   365,
     371,   386,   372,   375,   119,    46,   120,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   379,   376,    54,
      55,   225,   114,    45,   207,   382,   383,   384,   116,   385,
     387,   388,    99,   244,   195,    46,   120,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   204,   299,    54,
      55,   297,   205,    45,   207,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    46,   120,   245,   317,   344,
     350,    45,   202,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    46,   120,   246,   226,   227,   247,    45,
     207,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    46,   120,     0,   186,     0,     0,    45,   274,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    46,
     120,     0,     0,     0,     0,    45,   327,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    46,    47,     0,
       0,     0,     0,    45,   329,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    46,    47,     0,     0,     0,
       0,    45,   277,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    46,    47,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,   120
};

static const yytype_int16 yycheck[] =
{
       6,    27,   115,     8,   115,    27,     9,    27,    27,    27,
     113,   114,   122,   116,   115,     9,    64,     9,    10,     9,
      10,     9,    10,    12,     6,    12,     6,    75,     6,    12,
     232,    75,     6,     7,     3,     9,   229,   230,   231,    15,
      16,    17,    15,    16,    17,    14,    72,     6,     6,    13,
     252,     3,    72,    72,    15,    16,    17,     3,    15,    16,
      17,    64,    14,     8,    50,    71,    64,    53,    14,    64,
      15,    16,    75,    15,    16,   268,   269,    75,   271,   272,
      75,    75,     6,    11,     6,    63,    75,    69,    68,   202,
      12,   202,    75,   203,   100,     5,   207,     0,   208,    75,
     106,   211,    75,    64,    63,    63,   207,   113,   114,   115,
     116,   116,    75,   119,    75,    58,    59,   143,    75,   229,
     230,   231,   225,   143,   143,   117,   118,   117,   118,   117,
     118,   324,   119,    75,    56,    57,    58,    59,     3,    63,
      15,    16,    17,    65,    66,    67,     9,    12,    70,    71,
      72,    73,    15,    16,   264,   265,   266,   267,   268,   269,
     186,   271,   272,   274,   186,   275,   186,   186,   186,     7,
      47,    75,    49,    50,    51,    13,    64,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    75,     3,    64,
       6,    64,    75,    62,   200,    11,   202,    12,   308,   309,
      75,   207,    75,   313,   314,    74,    75,    15,    16,    17,
       8,     6,    11,     6,   324,   100,    11,    15,    16,   225,
       3,   106,   228,     3,     7,   335,     9,    75,     8,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    56,    57,    58,    59,    75,   274,    75,
       3,   277,    65,    66,    67,     8,    13,    70,    71,    72,
      73,    58,    59,    75,    56,    57,    58,    59,   294,   295,
      67,    75,    75,    65,    66,    67,   114,     6,   116,    74,
      72,    73,    47,    13,    49,    50,    51,     6,     7,     6,
       7,    68,    69,    15,    16,    75,   322,    75,     3,   325,
       6,   327,     7,   329,     9,    75,    12,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     6,    15,    16,    15,    16,    50,    12,   117,   118,
      56,    57,    58,    59,   117,   118,   117,   118,    50,    65,
      66,    67,   117,   118,    70,    71,    72,    73,     9,    10,
      75,     6,     9,    10,    75,    75,     6,    12,     7,     7,
       3,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     6,    57,    58,    59,    60,    61,    62,    63,     8,
      65,    66,    67,     8,    10,    70,    71,     6,    73,    74,
      75,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     8,    57,    58,    59,    60,    61,    62,    63,     6,
      65,    66,    67,     6,     8,    70,    71,     8,    73,    74,
      75,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    75,    15,    16,    17,     7,     7,    62,    63,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,     6,     6,     6,    75,    62,    63,    75,     7,    10,
       7,     6,    10,    56,    57,    58,    59,    74,    75,     6,
       6,     6,    65,    66,    67,    75,    75,    70,    71,    72,
      73,    64,    10,     3,     6,    75,    75,     7,     6,     9,
      75,    75,    75,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    10,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    75,    57,    58,
      59,    60,    61,    62,    63,    75,    65,    66,    67,     6,
       8,    75,     8,     8,    73,    74,    75,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     6,     8,    58,
      59,    60,    61,    62,    63,     8,     8,     8,    67,     8,
      75,     6,    46,   143,   101,    74,    75,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   113,   239,    58,
      59,   238,   113,    62,    63,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    74,    75,   143,   277,   322,
     325,    62,    63,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    74,    75,   143,   119,   119,   143,    62,
      63,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    74,    75,    -1,    82,    -1,    -1,    62,    63,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,    -1,    -1,    -1,    -1,    62,    63,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    74,    75,    -1,
      -1,    -1,    -1,    62,    63,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    74,    75,    -1,    -1,    -1,
      -1,    62,    63,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    74,    75,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    56,    57,    58,    59,    65,    66,    67,    70,
      71,    72,    73,    79,    80,    86,    87,   117,   118,   119,
     120,   121,   122,   123,   125,   126,   127,   128,   129,   130,
     131,    75,    75,    75,    75,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    62,    74,    75,    77,    81,
      82,    83,    84,    75,    58,    59,   120,    79,    86,   122,
     126,   129,    79,    86,   122,   126,   129,    75,   121,    13,
     116,     5,    11,     6,    11,     6,    80,    87,   123,   127,
     130,     0,    11,     6,    11,     6,     7,     6,     7,    50,
      53,    47,    49,    50,    51,    47,    49,    50,    51,    82,
      13,    74,    75,     6,    75,    75,    13,    75,   115,    84,
      85,     6,    12,    60,    61,    63,    67,    70,    71,    73,
      75,    80,    84,    87,    88,    89,    90,    91,    94,    95,
      96,    97,   101,   102,   103,   104,   105,   106,   109,   110,
     111,   112,   113,   114,   123,     3,     7,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    75,   107,   124,    12,   128,    12,    75,    78,
      75,    75,    50,    50,    85,    81,     6,    85,     3,    14,
       3,     6,    63,    84,    89,    95,   103,    63,    84,   103,
     110,    84,    88,   102,   109,   103,   110,    90,    96,   105,
     112,    90,    96,   105,   112,    60,   104,   111,     7,    15,
      16,    17,    64,    75,   101,   108,    68,    69,    92,    93,
       6,    12,    80,    87,    91,    97,   106,   113,   123,     8,
      10,     6,     3,    12,    12,     6,     3,    12,     8,     8,
      14,    14,    75,    84,    84,    15,    16,    17,    15,    16,
      75,    15,    16,    75,    63,    84,     8,    63,    84,    98,
      99,   100,    75,   101,   108,    75,   101,   108,     9,   101,
     108,   107,     6,     9,     7,     7,     6,    93,     6,    92,
       6,    12,    75,   107,     6,    12,    75,     6,    15,    16,
       9,    75,    75,    15,    16,     6,    63,    98,    15,    16,
      17,    75,     3,     8,    10,     7,    10,    63,    84,    63,
      84,     6,     6,     6,     6,    10,     6,    15,    16,    75,
      75,     9,    15,    16,    99,     6,    63,   101,   108,     8,
     100,     6,    84,     8,    15,    16,    84,     8,    15,    16,
      75,    75,    10,    75,    75,     6,     6,    63,     8,    15,
      16,     8,     8,    15,    16,     8,     8,    15,    16,     6,
       6,    63,     8,     8,     8,     8,    75,    75,     6
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
#line 27 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_bool);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 28 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_char);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 29 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_schar);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 30 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uchar);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 31 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_wchar_t);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 32 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_short);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 33 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_short);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 34 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ushort);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 35 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_long);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 36 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 37 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_ulong);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 38 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_longlong);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 39 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_longlong);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 40 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (3)].sn), pt_ulonglong);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 41 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 42 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_int);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 43 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_int);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 44 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_uint);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 45 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_uint);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 46 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_float);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 47 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_double);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 48 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (2)].sn), pt_long_double);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 49 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newPrimitiveType((yyvsp[(1) - (1)].sn), pt_void);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 52 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentityList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 53 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newIdentityList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 56 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 57 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 58 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newEnum((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 61 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 62 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 63 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 66 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 67 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeName((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 70 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 71 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newScopeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 74 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 75 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setScopeNameListGlobal((yyval.sn));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 78 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 79 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeName((yyvsp[(1) - (1)].sn));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 82 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 83 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeNameList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 86 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypedef((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 87 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), primitive_type);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 88 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), enum_type);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 89 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), value_type);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 90 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTypeDeclaration((yyvsp[(2) - (3)].sn), reference_type);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 93 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 94 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 95 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 98 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), NULL, NULL, (yyvsp[(3) - (3)].sn));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 99 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newField((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 102 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 103 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldConstant((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 106 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 107 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setFieldStatic((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 110 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 111 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 112 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 115 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 116 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 117 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 118 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 119 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 120 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 123 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (1)].sn), NULL, NULL, NULL);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 124 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 125 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 126 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 127 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 128 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newGetterSetter((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 132 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty(NULL, (yyvsp[(1) - (2)].sn), NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 133 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty(NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 134 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty(NULL, (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 135 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 136 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProperty((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 140 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertyGetter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 141 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setPropertySetter((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 142 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 143 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setPropertyGetter((yyvsp[(1) - (4)].sn), (yyvsp[(3) - (4)].sn)); setPropertySetter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 147 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 148 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setPropertyModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 151 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 152 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 153 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 156 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (2)].sn), NULL, NULL, (yyvsp[(2) - (2)].sn));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 157 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 158 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (3)].sn), NULL, (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 159 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 160 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 161 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 162 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 163 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 164 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameter((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn)); setParameterArray((yyval.sn));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 167 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 168 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setParameterConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 171 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 172 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 175 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 176 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 177 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), NULL, (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 178 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newMethod((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 181 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 182 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 183 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 184 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 185 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 186 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setMethodResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setMethodResultArray((yyval.sn));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 189 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 190 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 193 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 194 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 195 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 196 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 199 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 200 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setMethodOverride((yyval.sn));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 203 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 204 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 205 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 247 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), NULL, (yyvsp[(4) - (5)].sn), NULL, (yyvsp[(5) - (5)].sn));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 248 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), NULL, (yyvsp[(6) - (6)].sn));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 249 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (6)].sn), (yyvsp[(2) - (6)].sn), (yyvsp[(3) - (6)].sn), NULL, (yyvsp[(4) - (6)].sn), (yyvsp[(5) - (6)].sn), (yyvsp[(6) - (6)].sn));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 250 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newOperator((yyvsp[(1) - (7)].sn), (yyvsp[(2) - (7)].sn), (yyvsp[(3) - (7)].sn), (yyvsp[(4) - (7)].sn), (yyvsp[(5) - (7)].sn), (yyvsp[(6) - (7)].sn), (yyvsp[(7) - (7)].sn));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 254 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (2)].sn), NULL);;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 255 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 256 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 257 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(3) - (3)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn));;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 258 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(5) - (5)].sn); setOperatorResult((yyval.sn), (yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn)); setOperatorResultArray((yyval.sn));;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 261 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 262 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorResultConst((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 265 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 266 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 267 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 270 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 271 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setOperatorOverride((yyval.sn));;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 274 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 275 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 276 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 280 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 281 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 282 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 283 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 284 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 285 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 286 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 287 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 288 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 289 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 290 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 291 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 292 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 293 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 294 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClassMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 295 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 298 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 299 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameterList((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 302 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateParameters((yyvsp[(1) - (3)].sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 305 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn), NULL);;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 306 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 307 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn), NULL);;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 308 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newClass((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 311 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 312 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn); setClassTemplateParameters((yyval.sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 315 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 316 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (3)].sn); setClassBaseList((yyval.sn), (yyvsp[(2) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 319 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (4)].sn), NULL, (yyvsp[(3) - (4)].sn), (yyvsp[(4) - (4)].sn));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 320 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setClassMemberList((yyval.sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 323 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 324 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassModifier((yyval.sn), (yyvsp[(1) - (2)].sn));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 327 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 328 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setClassOverride((yyval.sn));;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 331 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 332 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 333 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 336 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 337 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 338 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 339 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTokenList((yyvsp[(1) - (3)].sn), (yyvsp[(3) - (3)].sn));;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 342 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newTemplateClassInstance((yyvsp[(2) - (5)].sn), (yyvsp[(4) - (5)].sn));;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 345 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 346 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (4)].sn);;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 347 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (5)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (5)].sn), (yyvsp[(3) - (5)].sn));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 348 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (6)].sn); setTemplateClassInstanceTokenList((yyvsp[(1) - (6)].sn), (yyvsp[(3) - (6)].sn));;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 351 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 352 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 353 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 356 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 357 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 358 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 359 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 360 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[(1) - (1)].sn));;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 361 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = NULL;;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 362 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 363 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 364 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 365 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 366 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespaceMemberList((yyvsp[(1) - (2)].sn), (yyvsp[(2) - (2)].sn));;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 367 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (2)].sn);;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 370 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (4)].sn), (yyvsp[(2) - (4)].sn), (yyvsp[(3) - (4)].sn), NULL, (yyvsp[(4) - (4)].sn));;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 371 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newNamespace((yyvsp[(1) - (5)].sn), (yyvsp[(2) - (5)].sn), (yyvsp[(3) - (5)].sn), (yyvsp[(4) - (5)].sn), (yyvsp[(5) - (5)].sn));;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 374 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(1) - (1)].sn);;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 375 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoCode((yyval.sn));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 376 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = (yyvsp[(2) - (2)].sn); setNoMeta((yyval.sn));;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 379 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 380 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y"
    {(yyval.sn) = newProgram((yyvsp[(1) - (1)].sn)); attachSyntaxTree((yyval.sn));;}
    break;



/* Line 1455 of yacc.c  */
#line 3276 "D:\\GitHub\\idlcpp\\idlcpp\\src\\idlcpp.y.c"
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



