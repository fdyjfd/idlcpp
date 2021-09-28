/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "D:/idlcpp/src/idlcpp.y"

#include "yyfuncs.h"
#include <stddef.h>

#line 76 "D:/idlcpp/src/idlcpp.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "idlcpp.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* ','  */
  YYSYMBOL_4_ = 4,                         /* '.'  */
  YYSYMBOL_5_ = 5,                         /* ':'  */
  YYSYMBOL_6_ = 6,                         /* ';'  */
  YYSYMBOL_7_ = 7,                         /* '('  */
  YYSYMBOL_8_ = 8,                         /* ')'  */
  YYSYMBOL_9_ = 9,                         /* '['  */
  YYSYMBOL_10_ = 10,                       /* ']'  */
  YYSYMBOL_11_ = 11,                       /* '{'  */
  YYSYMBOL_12_ = 12,                       /* '}'  */
  YYSYMBOL_13_ = 13,                       /* '<'  */
  YYSYMBOL_14_ = 14,                       /* '>'  */
  YYSYMBOL_15_ = 15,                       /* '*'  */
  YYSYMBOL_16_ = 16,                       /* '&'  */
  YYSYMBOL_17_ = 17,                       /* '+'  */
  YYSYMBOL_18_ = 18,                       /* '^'  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '/'  */
  YYSYMBOL_21_ = 21,                       /* '%'  */
  YYSYMBOL_22_ = 22,                       /* '|'  */
  YYSYMBOL_23_ = 23,                       /* '~'  */
  YYSYMBOL_24_ = 24,                       /* '!'  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_ADD_ASSIGN = 26,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 27,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 28,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 29,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 30,                /* MOD_ASSIGN  */
  YYSYMBOL_BIT_XOR_ASSIGN = 31,            /* BIT_XOR_ASSIGN  */
  YYSYMBOL_BIT_AND_ASSIGN = 32,            /* BIT_AND_ASSIGN  */
  YYSYMBOL_BIT_OR_ASSIGN = 33,             /* BIT_OR_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 34,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 35,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT = 36,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 37,               /* RIGHT_SHIFT  */
  YYSYMBOL_EQUAL = 38,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 39,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 40,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 41,             /* GREATER_EQUAL  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_INC = 44,                       /* INC  */
  YYSYMBOL_DEC = 45,                       /* DEC  */
  YYSYMBOL_BOOL = 46,                      /* BOOL  */
  YYSYMBOL_CHAR = 47,                      /* CHAR  */
  YYSYMBOL_WCHAR_T = 48,                   /* WCHAR_T  */
  YYSYMBOL_SHORT = 49,                     /* SHORT  */
  YYSYMBOL_LONG = 50,                      /* LONG  */
  YYSYMBOL_INT = 51,                       /* INT  */
  YYSYMBOL_FLOAT = 52,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 53,                    /* DOUBLE  */
  YYSYMBOL_SIGNED = 54,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 55,                  /* UNSIGNED  */
  YYSYMBOL_STRING_T = 56,                  /* STRING_T  */
  YYSYMBOL_NAMESPACE = 57,                 /* NAMESPACE  */
  YYSYMBOL_ENUM = 58,                      /* ENUM  */
  YYSYMBOL_CLASS = 59,                     /* CLASS  */
  YYSYMBOL_STRUCT = 60,                    /* STRUCT  */
  YYSYMBOL_STATIC = 61,                    /* STATIC  */
  YYSYMBOL_VIRTUAL = 62,                   /* VIRTUAL  */
  YYSYMBOL_VOID = 63,                      /* VOID  */
  YYSYMBOL_CONST = 64,                     /* CONST  */
  YYSYMBOL_OPERATOR = 65,                  /* OPERATOR  */
  YYSYMBOL_TYPEDEF = 66,                   /* TYPEDEF  */
  YYSYMBOL_TYPENAME = 67,                  /* TYPENAME  */
  YYSYMBOL_ABSTRACT = 68,                  /* ABSTRACT  */
  YYSYMBOL_GET = 69,                       /* GET  */
  YYSYMBOL_SET = 70,                       /* SET  */
  YYSYMBOL_CANDIDATE = 71,                 /* CANDIDATE  */
  YYSYMBOL_NOMETA = 72,                    /* NOMETA  */
  YYSYMBOL_NOCODE = 73,                    /* NOCODE  */
  YYSYMBOL_EXPORT = 74,                    /* EXPORT  */
  YYSYMBOL_OVERRIDE = 75,                  /* OVERRIDE  */
  YYSYMBOL_SCOPE = 76,                     /* SCOPE  */
  YYSYMBOL_IDENTIFY = 77,                  /* IDENTIFY  */
  YYSYMBOL_STRING = 78,                    /* STRING  */
  YYSYMBOL_U8STRING = 79,                  /* U8STRING  */
  YYSYMBOL_TEMPLATE = 80,                  /* TEMPLATE  */
  YYSYMBOL_DELEGATE = 81,                  /* DELEGATE  */
  YYSYMBOL_82_ = 82,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_primitive = 84,                 /* primitive  */
  YYSYMBOL_attribute = 85,                 /* attribute  */
  YYSYMBOL_attributeList = 86,             /* attributeList  */
  YYSYMBOL_attributes = 87,                /* attributes  */
  YYSYMBOL_identifyList = 88,              /* identifyList  */
  YYSYMBOL_enumerator = 89,                /* enumerator  */
  YYSYMBOL_enumeratorList = 90,            /* enumeratorList  */
  YYSYMBOL_enum_0 = 91,                    /* enum_0  */
  YYSYMBOL_enum = 92,                      /* enum  */
  YYSYMBOL_scopeName = 93,                 /* scopeName  */
  YYSYMBOL_scopeNameList_0 = 94,           /* scopeNameList_0  */
  YYSYMBOL_scopeNameList = 95,             /* scopeNameList  */
  YYSYMBOL_typeName_0 = 96,                /* typeName_0  */
  YYSYMBOL_typeName = 97,                  /* typeName  */
  YYSYMBOL_typeNameList = 98,              /* typeNameList  */
  YYSYMBOL_typeAlias = 99,                 /* typeAlias  */
  YYSYMBOL_field_0 = 100,                  /* field_0  */
  YYSYMBOL_field_1 = 101,                  /* field_1  */
  YYSYMBOL_field_2 = 102,                  /* field_2  */
  YYSYMBOL_field = 103,                    /* field  */
  YYSYMBOL_getter_0 = 104,                 /* getter_0  */
  YYSYMBOL_getter_1 = 105,                 /* getter_1  */
  YYSYMBOL_getter = 106,                   /* getter  */
  YYSYMBOL_setter_0 = 107,                 /* setter_0  */
  YYSYMBOL_setter_1 = 108,                 /* setter_1  */
  YYSYMBOL_setter_2 = 109,                 /* setter_2  */
  YYSYMBOL_setter = 110,                   /* setter  */
  YYSYMBOL_candidate = 111,                /* candidate  */
  YYSYMBOL_property_0 = 112,               /* property_0  */
  YYSYMBOL_property_1 = 113,               /* property_1  */
  YYSYMBOL_property_2 = 114,               /* property_2  */
  YYSYMBOL_property = 115,                 /* property  */
  YYSYMBOL_parameter_0 = 116,              /* parameter_0  */
  YYSYMBOL_parameter_1 = 117,              /* parameter_1  */
  YYSYMBOL_parameter = 118,                /* parameter  */
  YYSYMBOL_parameterList = 119,            /* parameterList  */
  YYSYMBOL_method_0 = 120,                 /* method_0  */
  YYSYMBOL_method_1 = 121,                 /* method_1  */
  YYSYMBOL_method_2 = 122,                 /* method_2  */
  YYSYMBOL_method_3 = 123,                 /* method_3  */
  YYSYMBOL_method_4 = 124,                 /* method_4  */
  YYSYMBOL_method = 125,                   /* method  */
  YYSYMBOL_operatorSign = 126,             /* operatorSign  */
  YYSYMBOL_operator_0 = 127,               /* operator_0  */
  YYSYMBOL_operator_1 = 128,               /* operator_1  */
  YYSYMBOL_operator_2 = 129,               /* operator_2  */
  YYSYMBOL_operator_3 = 130,               /* operator_3  */
  YYSYMBOL_operator = 131,                 /* operator  */
  YYSYMBOL_delegate_0 = 132,               /* delegate_0  */
  YYSYMBOL_delegate_1 = 133,               /* delegate_1  */
  YYSYMBOL_delegate = 134,                 /* delegate  */
  YYSYMBOL_classMember_0 = 135,            /* classMember_0  */
  YYSYMBOL_classMember = 136,              /* classMember  */
  YYSYMBOL_classMemberList = 137,          /* classMemberList  */
  YYSYMBOL_templateParameterList = 138,    /* templateParameterList  */
  YYSYMBOL_templateParameters = 139,       /* templateParameters  */
  YYSYMBOL_class_0 = 140,                  /* class_0  */
  YYSYMBOL_class_1 = 141,                  /* class_1  */
  YYSYMBOL_class_2 = 142,                  /* class_2  */
  YYSYMBOL_class_3 = 143,                  /* class_3  */
  YYSYMBOL_class_4 = 144,                  /* class_4  */
  YYSYMBOL_class_5 = 145,                  /* class_5  */
  YYSYMBOL_class = 146,                    /* class  */
  YYSYMBOL_tokenList = 147,                /* tokenList  */
  YYSYMBOL_templateClassInstance_0 = 148,  /* templateClassInstance_0  */
  YYSYMBOL_templateClassInstance = 149,    /* templateClassInstance  */
  YYSYMBOL_namespaceMember_0 = 150,        /* namespaceMember_0  */
  YYSYMBOL_namespaceMember = 151,          /* namespaceMember  */
  YYSYMBOL_namespaceMemberList = 152,      /* namespaceMemberList  */
  YYSYMBOL_namespace = 153,                /* namespace  */
  YYSYMBOL_program = 154                   /* program  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  484

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    66,    67,    68,    71,    72,
      75,    76,    77,    80,    81,    84,    85,    88,    89,    93,
      94,    95,    96,    97,    98,   101,   102,   105,   106,   109,
     110,   113,   114,   117,   118,   121,   122,   123,   126,   127,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   141,
     142,   143,   146,   147,   150,   151,   154,   155,   159,   162,
     163,   166,   167,   170,   173,   174,   177,   178,   181,   182,
     185,   188,   189,   190,   191,   192,   193,   196,   197,   198,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   212,
     213,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   229,   230,   233,   234,   237,   238,   241,   242,   243,
     244,   245,   246,   249,   250,   251,   252,   253,   254,   257,
     258,   261,   262,   263,   264,   267,   268,   271,   272,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   314,   315,   316,   317,   321,
     322,   323,   324,   325,   328,   329,   332,   333,   334,   337,
     338,   341,   342,   343,   346,   347,   348,   349,   350,   353,
     354,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   369,   370,   373,   374,   375,   376,   379,   380,   383,
     386,   387,   388,   389,   392,   393,   396,   397,   400,   401,
     404,   405,   408,   409,   412,   413,   417,   418,   419,   420,
     423,   426,   427,   428,   429,   433,   434,   435,   436,   437,
     438,   439,   440,   443,   444,   447,   448,   449,   450,   453,
     454,   457,   458
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "','", "'.'", "':'",
  "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'>'", "'*'",
  "'&'", "'+'", "'^'", "'-'", "'/'", "'%'", "'|'", "'~'", "'!'", "'='",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "BIT_XOR_ASSIGN", "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "LEFT_SHIFT_ASSIGN",
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
  "namespaceMember", "namespaceMemberList", "namespace", "program", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-103)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* primitive: VOID  */
#line 31 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_void);}
#line 1709 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 3: /* primitive: BOOL  */
#line 32 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_bool);}
#line 1715 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 4: /* primitive: CHAR  */
#line 33 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_char);}
#line 1721 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 5: /* primitive: SIGNED CHAR  */
#line 34 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_schar);}
#line 1727 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 6: /* primitive: UNSIGNED CHAR  */
#line 35 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_uchar);}
#line 1733 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 7: /* primitive: WCHAR_T  */
#line 36 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_wchar_t);}
#line 1739 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 8: /* primitive: SHORT  */
#line 37 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_short);}
#line 1745 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 9: /* primitive: SHORT INT  */
#line 38 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_short);}
#line 1751 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 10: /* primitive: SIGNED SHORT  */
#line 39 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_short);}
#line 1757 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 11: /* primitive: SIGNED SHORT INT  */
#line 40 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_short);}
#line 1763 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 12: /* primitive: UNSIGNED SHORT  */
#line 41 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_ushort);}
#line 1769 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 13: /* primitive: UNSIGNED SHORT INT  */
#line 42 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_ushort);}
#line 1775 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 14: /* primitive: LONG  */
#line 43 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_long);}
#line 1781 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 15: /* primitive: LONG INT  */
#line 44 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_long);}
#line 1787 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 16: /* primitive: SIGNED LONG  */
#line 45 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_long);}
#line 1793 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 17: /* primitive: SIGNED LONG INT  */
#line 46 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_long);}
#line 1799 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 18: /* primitive: UNSIGNED LONG  */
#line 47 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_ulong);}
#line 1805 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 19: /* primitive: UNSIGNED LONG INT  */
#line 48 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_ulong);}
#line 1811 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 20: /* primitive: LONG LONG  */
#line 49 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_longlong);}
#line 1817 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 21: /* primitive: LONG LONG INT  */
#line 50 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_longlong);}
#line 1823 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 22: /* primitive: SIGNED LONG LONG  */
#line 51 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_longlong);}
#line 1829 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 23: /* primitive: SIGNED LONG LONG INT  */
#line 52 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-3].sn), pt_longlong);}
#line 1835 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 24: /* primitive: UNSIGNED LONG LONG  */
#line 53 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-2].sn), pt_ulonglong);}
#line 1841 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 25: /* primitive: UNSIGNED LONG LONG INT  */
#line 54 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[-3].sn), pt_ulonglong);}
#line 1847 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 26: /* primitive: INT  */
#line 55 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_int);}
#line 1853 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 27: /* primitive: SIGNED INT  */
#line 56 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_int);}
#line 1859 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 28: /* primitive: SIGNED  */
#line 57 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_int);}
#line 1865 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 29: /* primitive: UNSIGNED INT  */
#line 58 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_uint);}
#line 1871 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 30: /* primitive: UNSIGNED  */
#line 59 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_uint);}
#line 1877 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 31: /* primitive: FLOAT  */
#line 60 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_float);}
#line 1883 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 32: /* primitive: DOUBLE  */
#line 61 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_double);}
#line 1889 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 33: /* primitive: LONG DOUBLE  */
#line 62 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newPrimitiveType((yyvsp[-1].sn), pt_long_double);}
#line 1895 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 34: /* primitive: STRING_T  */
#line 63 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newPrimitiveType((yyvsp[0].sn), pt_string_t);}
#line 1901 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 35: /* attribute: IDENTIFY  */
#line 66 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newAttribute((yyvsp[0].sn), NULL, 0);}
#line 1907 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 36: /* attribute: IDENTIFY '=' STRING  */
#line 67 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newAttribute((yyvsp[-2].sn), (yyvsp[0].sn), 0);}
#line 1913 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 37: /* attribute: IDENTIFY '=' U8STRING  */
#line 68 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newAttribute((yyvsp[-2].sn), (yyvsp[0].sn), 1);}
#line 1919 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 38: /* attributeList: attribute  */
#line 71 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newAttributeList(NULL, (yyvsp[0].sn));}
#line 1925 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 39: /* attributeList: attributeList ',' attribute  */
#line 72 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newAttributeList((yyvsp[-2].sn), (yyvsp[0].sn));}
#line 1931 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 40: /* attributes: '[' attributeList ']'  */
#line 75 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn);}
#line 1937 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 41: /* attributes: '[' attributeList ',' ']'  */
#line 76 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-2].sn);}
#line 1943 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 42: /* attributes: '[' ']'  */
#line 77 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = NULL;}
#line 1949 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 43: /* identifyList: IDENTIFY  */
#line 80 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newIdentifyList(NULL, NULL, (yyvsp[0].sn));}
#line 1955 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 44: /* identifyList: identifyList ',' IDENTIFY  */
#line 81 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newIdentifyList((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 1961 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 45: /* enumerator: IDENTIFY  */
#line 84 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newEnumerator(NULL, (yyvsp[0].sn));}
#line 1967 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 46: /* enumerator: attributes IDENTIFY  */
#line 85 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newEnumerator((yyvsp[-1].sn), (yyvsp[0].sn));}
#line 1973 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 47: /* enumeratorList: enumerator  */
#line 88 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newEnumeratorList(NULL, NULL, (yyvsp[0].sn));}
#line 1979 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 48: /* enumeratorList: enumeratorList ',' enumerator  */
#line 89 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newEnumeratorList((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 1985 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 49: /* enum_0: ENUM IDENTIFY '{' enumeratorList '}'  */
#line 93 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = newEnum((yyvsp[-4].sn), NULL, (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 1991 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 50: /* enum_0: ENUM IDENTIFY '{' enumeratorList ',' '}'  */
#line 94 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = newEnum((yyvsp[-5].sn), NULL, (yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[0].sn));}
#line 1997 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 51: /* enum_0: ENUM IDENTIFY '{' '}'  */
#line 95 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newEnum((yyvsp[-3].sn), NULL, (yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2003 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 52: /* enum_0: ENUM CLASS IDENTIFY '{' enumeratorList '}'  */
#line 96 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = newEnum((yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2009 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 53: /* enum_0: ENUM CLASS IDENTIFY '{' enumeratorList ',' '}'  */
#line 97 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = newEnum((yyvsp[-6].sn), (yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[0].sn));}
#line 2015 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 54: /* enum_0: ENUM CLASS IDENTIFY '{' '}'  */
#line 98 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newEnum((yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2021 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 55: /* enum: enum_0 ';'  */
#line 101 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-1].sn); setEnumSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2027 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 56: /* enum: enum_0 '=' STRING ';'  */
#line 102 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-3].sn); setNativeName((yyval.sn), (yyvsp[-1].sn)); setEnumSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2033 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 57: /* scopeName: IDENTIFY  */
#line 105 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newScopeName((yyvsp[0].sn), NULL, NULL, NULL);}
#line 2039 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 58: /* scopeName: IDENTIFY '<' typeNameList '>'  */
#line 106 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newScopeName((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2045 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 59: /* scopeNameList_0: scopeName  */
#line 109 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newScopeNameList(NULL, (yyvsp[0].sn));}
#line 2051 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 60: /* scopeNameList_0: scopeNameList_0 SCOPE scopeName  */
#line 110 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newScopeNameList((yyvsp[-2].sn), (yyvsp[0].sn));}
#line 2057 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 61: /* scopeNameList: scopeNameList_0  */
#line 113 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2063 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 62: /* scopeNameList: SCOPE scopeNameList_0  */
#line 114 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setScopeNameListGlobal((yyval.sn));}
#line 2069 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 63: /* typeName_0: primitive  */
#line 117 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2075 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 64: /* typeName_0: scopeNameList  */
#line 118 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newTypeName((yyvsp[0].sn));}
#line 2081 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 65: /* typeName: typeName_0  */
#line 121 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2087 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 66: /* typeName: NOCODE typeName_0  */
#line 122 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setTypeNameFilter((yyval.sn), (yyvsp[-1].sn));}
#line 2093 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 67: /* typeName: NOMETA typeName_0  */
#line 123 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setTypeNameFilter((yyval.sn), (yyvsp[-1].sn));}
#line 2099 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 68: /* typeNameList: typeName  */
#line 126 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTypeNameList(NULL, NULL, (yyvsp[0].sn));}
#line 2105 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 69: /* typeNameList: typeNameList ',' typeName  */
#line 127 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTypeNameList((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2111 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 70: /* typeAlias: TYPEDEF typeName IDENTIFY ';'  */
#line 130 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = newTypedef((yyvsp[-3].sn), (yyvsp[-1].sn), (yyvsp[-2].sn));}
#line 2117 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 71: /* typeAlias: TYPENAME IDENTIFY ';'  */
#line 131 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTypeDeclaration((yyvsp[-1].sn), primitive_type);}
#line 2123 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 72: /* typeAlias: ENUM IDENTIFY ';'  */
#line 132 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newTypeDeclaration((yyvsp[-1].sn), enum_type);}
#line 2129 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 73: /* typeAlias: STRUCT IDENTIFY ';'  */
#line 133 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTypeDeclaration((yyvsp[-1].sn), value_type);}
#line 2135 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 74: /* typeAlias: CLASS IDENTIFY ';'  */
#line 134 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTypeDeclaration((yyvsp[-1].sn), reference_type);}
#line 2141 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 75: /* typeAlias: TYPENAME IDENTIFY '=' STRING ';'  */
#line 135 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newTypeDeclaration((yyvsp[-3].sn), primitive_type); setNativeName((yyval.sn), (yyvsp[-1].sn));}
#line 2147 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 76: /* typeAlias: ENUM IDENTIFY '=' STRING ';'  */
#line 136 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newTypeDeclaration((yyvsp[-3].sn), enum_type); setNativeName((yyval.sn), (yyvsp[-1].sn));}
#line 2153 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 77: /* typeAlias: STRUCT IDENTIFY '=' STRING ';'  */
#line 137 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newTypeDeclaration((yyvsp[-3].sn), value_type); setNativeName((yyval.sn), (yyvsp[-1].sn));}
#line 2159 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 78: /* typeAlias: CLASS IDENTIFY '=' STRING ';'  */
#line 138 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newTypeDeclaration((yyvsp[-3].sn), reference_type); setNativeName((yyval.sn), (yyvsp[-1].sn));}
#line 2165 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 79: /* field_0: typeName IDENTIFY  */
#line 141 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newField((yyvsp[-1].sn), NULL, (yyvsp[0].sn), NULL, NULL);}
#line 2171 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 80: /* field_0: typeName IDENTIFY '[' ']'  */
#line 142 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newField((yyvsp[-3].sn), NULL, (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2177 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 81: /* field_0: typeName '*' IDENTIFY  */
#line 143 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newField((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn), NULL, NULL);}
#line 2183 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 82: /* field_1: field_0  */
#line 146 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2189 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 83: /* field_1: CONST field_0  */
#line 147 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setFieldConstant((yyval.sn), (yyvsp[-1].sn));}
#line 2195 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 84: /* field_2: field_1  */
#line 150 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2201 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 85: /* field_2: STATIC field_1  */
#line 151 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setFieldStatic((yyval.sn), (yyvsp[-1].sn));}
#line 2207 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 86: /* field: field_2 ';'  */
#line 154 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-1].sn); setFieldSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2213 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 87: /* field: field_2 '=' STRING ';'  */
#line 155 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-3].sn); setNativeName((yyval.sn), (yyvsp[-1].sn)); setFieldSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2219 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 88: /* getter_0: GET  */
#line 159 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newGetterSetter((yyvsp[0].sn));}
#line 2225 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 89: /* getter_1: getter_0  */
#line 162 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2231 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 90: /* getter_1: getter_0 '+'  */
#line 163 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn); setGetterIncRef((yyval.sn));}
#line 2237 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 91: /* getter: getter_1  */
#line 166 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2243 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 92: /* getter: getter_1 '=' STRING  */
#line 167 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-2].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[0].sn));}
#line 2249 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 93: /* setter_0: SET  */
#line 170 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newGetterSetter((yyvsp[0].sn));}
#line 2255 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 94: /* setter_1: setter_0  */
#line 173 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2261 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 95: /* setter_1: setter_0 '-'  */
#line 174 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn); setSetterDecRef((yyval.sn));}
#line 2267 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 96: /* setter_2: setter_1  */
#line 177 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2273 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 97: /* setter_2: setter_1 '?'  */
#line 178 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn); setSetterAllowNull((yyval.sn));}
#line 2279 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 98: /* setter: setter_2  */
#line 181 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2285 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 99: /* setter: setter_2 '=' STRING  */
#line 182 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-2].sn); setGetterSetterNativeName((yyval.sn), (yyvsp[0].sn));}
#line 2291 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 100: /* candidate: CANDIDATE  */
#line 185 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2297 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 101: /* property_0: IDENTIFY  */
#line 188 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newProperty((yyvsp[0].sn), simple_property);}
#line 2303 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 102: /* property_0: IDENTIFY '[' ']'  */
#line 189 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newProperty((yyvsp[-2].sn), fixed_array_property);}
#line 2309 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 103: /* property_0: IDENTIFY '[' '?' ']'  */
#line 190 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newProperty((yyvsp[-3].sn), dynamic_array_property);}
#line 2315 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 104: /* property_0: IDENTIFY '[' '*' ']'  */
#line 191 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newProperty((yyvsp[-3].sn), list_property);}
#line 2321 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 105: /* property_0: IDENTIFY '[' typeName ']'  */
#line 192 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newProperty((yyvsp[-3].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[-1].sn), NULL);}
#line 2327 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 106: /* property_0: IDENTIFY '[' typeName '*' ']'  */
#line 193 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newProperty((yyvsp[-4].sn), map_property); setMapPropertyKeyType((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2333 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 107: /* property_1: typeName property_0  */
#line 196 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setPropertyType((yyval.sn), (yyvsp[-1].sn), NULL);}
#line 2339 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 108: /* property_1: typeName '*' property_0  */
#line 197 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setPropertyType((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2345 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 109: /* property_1: typeName '&' property_0  */
#line 198 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setPropertyType((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2351 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 110: /* property_2: property_1 '{' '}' ';'  */
#line 201 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[-3].sn);}
#line 2357 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 111: /* property_2: property_1 '{' getter '}' ';'  */
#line 202 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[-4].sn); setPropertyGetter((yyval.sn), (yyvsp[-2].sn));}
#line 2363 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 112: /* property_2: property_1 '{' setter '}' ';'  */
#line 203 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[-4].sn); setPropertySetter((yyval.sn), (yyvsp[-2].sn));}
#line 2369 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 113: /* property_2: property_1 '{' getter setter '}' ';'  */
#line 204 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-5].sn); setPropertyGetter((yyval.sn), (yyvsp[-3].sn)); setPropertySetter((yyvsp[-5].sn), (yyvsp[-2].sn));}
#line 2375 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 114: /* property_2: property_1 '{' setter getter '}' ';'  */
#line 205 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-5].sn); setPropertyGetter((yyval.sn), (yyvsp[-2].sn)); setPropertySetter((yyvsp[-5].sn), (yyvsp[-3].sn));}
#line 2381 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 115: /* property_2: property_1 '{' getter candidate '}' ';'  */
#line 206 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-5].sn); setPropertyGetter((yyval.sn), (yyvsp[-3].sn)); setPropertyCandidate((yyval.sn));}
#line 2387 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 116: /* property_2: property_1 '{' setter candidate '}' ';'  */
#line 207 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-5].sn); setPropertySetter((yyval.sn), (yyvsp[-3].sn)); setPropertyCandidate((yyval.sn));}
#line 2393 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 117: /* property_2: property_1 '{' getter setter candidate '}' ';'  */
#line 208 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = (yyvsp[-6].sn); setPropertyGetter((yyval.sn), (yyvsp[-4].sn)); setPropertySetter((yyvsp[-6].sn), (yyvsp[-3].sn)); setPropertyCandidate((yyval.sn));}
#line 2399 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 118: /* property_2: property_1 '{' setter getter candidate '}' ';'  */
#line 209 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = (yyvsp[-6].sn); setPropertyGetter((yyval.sn), (yyvsp[-3].sn)); setPropertySetter((yyvsp[-6].sn), (yyvsp[-4].sn)); setPropertyCandidate((yyval.sn));}
#line 2405 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 119: /* property: property_2  */
#line 212 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2411 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 120: /* property: STATIC property_2  */
#line 213 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setPropertyModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2417 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 121: /* parameter_0: typeName IDENTIFY  */
#line 217 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-1].sn), NULL, NULL, (yyvsp[0].sn));}
#line 2423 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 122: /* parameter_0: typeName '&' IDENTIFY  */
#line 218 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2429 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 123: /* parameter_0: typeName '*' IDENTIFY  */
#line 219 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2435 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 124: /* parameter_0: typeName '-' IDENTIFY  */
#line 220 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2441 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 125: /* parameter_0: typeName '*' '&' IDENTIFY  */
#line 221 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2447 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 126: /* parameter_0: typeName '*' '*' IDENTIFY  */
#line 222 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2453 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 127: /* parameter_0: typeName '+' '&' IDENTIFY  */
#line 223 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2459 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 128: /* parameter_0: typeName '+' '*' IDENTIFY  */
#line 224 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameter((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2465 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 129: /* parameter_0: typeName '+' '[' ']' '&' IDENTIFY  */
#line 225 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newParameter((yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-1].sn), (yyvsp[0].sn)); setParameterArray((yyval.sn));}
#line 2471 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 130: /* parameter_0: typeName '+' '[' ']' '*' IDENTIFY  */
#line 226 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newParameter((yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-1].sn), (yyvsp[0].sn)); setParameterArray((yyval.sn));}
#line 2477 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 131: /* parameter_1: parameter_0  */
#line 229 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2483 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 132: /* parameter_1: CONST parameter_0  */
#line 230 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setParameterConst((yyval.sn), (yyvsp[-1].sn));}
#line 2489 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 133: /* parameter: parameter_1  */
#line 233 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2495 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 134: /* parameter: parameter_1 '?'  */
#line 234 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn); setParameterAllowNull((yyval.sn));}
#line 2501 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 135: /* parameterList: parameter  */
#line 237 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newParameterList(NULL, NULL, (yyvsp[0].sn));}
#line 2507 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 136: /* parameterList: parameterList ',' parameter  */
#line 238 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newParameterList((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2513 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 137: /* method_0: IDENTIFY '(' ')'  */
#line 241 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newMethod((yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn), NULL);}
#line 2519 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 138: /* method_0: IDENTIFY '(' VOID ')'  */
#line 242 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newMethod((yyvsp[-3].sn), (yyvsp[-2].sn), NULL, (yyvsp[0].sn), NULL);}
#line 2525 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 139: /* method_0: IDENTIFY '(' parameterList ')'  */
#line 243 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newMethod((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn), NULL);}
#line 2531 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 140: /* method_0: IDENTIFY '(' ')' CONST  */
#line 244 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newMethod((yyvsp[-3].sn), (yyvsp[-2].sn), NULL, (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2537 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 141: /* method_0: IDENTIFY '(' VOID ')' CONST  */
#line 245 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newMethod((yyvsp[-4].sn), (yyvsp[-3].sn), NULL, (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2543 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 142: /* method_0: IDENTIFY '(' parameterList ')' CONST  */
#line 246 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = newMethod((yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2549 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 143: /* method_1: method_0  */
#line 249 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2555 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 144: /* method_1: typeName method_0  */
#line 250 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodResult((yyval.sn), (yyvsp[-1].sn), NULL);}
#line 2561 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 145: /* method_1: typeName '&' method_0  */
#line 251 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setMethodResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2567 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 146: /* method_1: typeName '*' method_0  */
#line 252 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setMethodResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2573 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 147: /* method_1: typeName '+' method_0  */
#line 253 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setMethodResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2579 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 148: /* method_1: typeName '+' '[' ']' method_0  */
#line 254 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodResult((yyval.sn), (yyvsp[-4].sn), (yyvsp[-3].sn)); setMethodResultArray((yyval.sn));}
#line 2585 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 149: /* method_2: method_1  */
#line 257 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2591 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 150: /* method_2: CONST method_1  */
#line 258 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodResultConst((yyval.sn), (yyvsp[-1].sn));}
#line 2597 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 151: /* method_3: method_2  */
#line 261 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2603 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 152: /* method_3: ABSTRACT method_2  */
#line 262 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2609 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 153: /* method_3: VIRTUAL method_2  */
#line 263 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2615 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 154: /* method_3: STATIC method_2  */
#line 264 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2621 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 155: /* method_4: method_3  */
#line 267 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2627 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 156: /* method_4: OVERRIDE method_3  */
#line 268 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMethodOverride((yyval.sn));}
#line 2633 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 157: /* method: method_4 ';'  */
#line 271 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-1].sn); setMethodSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2639 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 158: /* method: method_4 '=' STRING ';'  */
#line 272 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-3].sn); setNativeName((yyval.sn), (yyvsp[-1].sn)); setMethodSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2645 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 195: /* operator_0: OPERATOR operatorSign '(' ')' ';'  */
#line 314 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newOperator((yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), NULL, (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2651 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 196: /* operator_0: OPERATOR operatorSign '(' parameterList ')' ';'  */
#line 315 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = newOperator((yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2657 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 197: /* operator_0: OPERATOR operatorSign '(' ')' CONST ';'  */
#line 316 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newOperator((yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-3].sn), NULL, (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2663 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 198: /* operator_0: OPERATOR operatorSign '(' parameterList ')' CONST ';'  */
#line 317 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = newOperator((yyvsp[-6].sn), (yyvsp[-5].sn), (yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2669 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 199: /* operator_1: typeName operator_0  */
#line 321 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setOperatorResult((yyval.sn), (yyvsp[-1].sn), NULL);}
#line 2675 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 200: /* operator_1: typeName '&' operator_0  */
#line 322 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2681 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 201: /* operator_1: typeName '*' operator_0  */
#line 323 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2687 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 202: /* operator_1: typeName '+' operator_0  */
#line 324 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2693 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 203: /* operator_1: typeName '+' '[' ']' operator_0  */
#line 325 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setOperatorResult((yyval.sn), (yyvsp[-4].sn), (yyvsp[-3].sn)); setOperatorResultArray((yyval.sn));}
#line 2699 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 204: /* operator_2: operator_1  */
#line 328 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2705 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 205: /* operator_2: CONST operator_1  */
#line 329 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setOperatorResultConst((yyval.sn), (yyvsp[-1].sn));}
#line 2711 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 206: /* operator_3: operator_2  */
#line 332 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2717 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 207: /* operator_3: ABSTRACT operator_2  */
#line 333 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2723 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 208: /* operator_3: VIRTUAL operator_2  */
#line 334 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2729 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 209: /* operator: operator_3  */
#line 337 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2735 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 210: /* operator: OVERRIDE operator_3  */
#line 338 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setOperatorOverride((yyval.sn));}
#line 2741 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 211: /* delegate_0: IDENTIFY '(' ')' ';'  */
#line 341 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newDelegate((yyvsp[-3].sn), (yyvsp[-2].sn), NULL, (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2747 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 212: /* delegate_0: IDENTIFY '(' VOID ')' ';'  */
#line 342 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newDelegate((yyvsp[-4].sn), (yyvsp[-3].sn), NULL, (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2753 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 213: /* delegate_0: IDENTIFY '(' parameterList ')' ';'  */
#line 343 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newDelegate((yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2759 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 214: /* delegate_1: typeName delegate_0  */
#line 346 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setDelegateResult((yyval.sn), (yyvsp[-1].sn), NULL);}
#line 2765 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 215: /* delegate_1: typeName '&' delegate_0  */
#line 347 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setDelegateResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2771 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 216: /* delegate_1: typeName '*' delegate_0  */
#line 348 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setDelegateResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2777 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 217: /* delegate_1: typeName '+' delegate_0  */
#line 349 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setDelegateResult((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn));}
#line 2783 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 218: /* delegate_1: typeName '+' '[' ']' delegate_0  */
#line 350 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setDelegateResult((yyval.sn), (yyvsp[-4].sn), (yyvsp[-3].sn)); setDelegateResultArray((yyval.sn));}
#line 2789 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 219: /* delegate: DELEGATE delegate_1  */
#line 353 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setDelegateKeyword((yyval.sn), (yyvsp[-1].sn));}
#line 2795 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 220: /* delegate: DELEGATE CONST delegate_1  */
#line 354 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setDelegateKeyword((yyval.sn), (yyvsp[-2].sn)); setDelegateResultConst((yyval.sn), (yyvsp[-1].sn));}
#line 2801 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 221: /* classMember_0: field  */
#line 357 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2807 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 222: /* classMember_0: property  */
#line 358 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2813 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 223: /* classMember_0: method  */
#line 359 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2819 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 224: /* classMember_0: operator  */
#line 360 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2825 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 225: /* classMember_0: class  */
#line 361 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2831 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 226: /* classMember_0: delegate  */
#line 362 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2837 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 227: /* classMember_0: enum  */
#line 363 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2843 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 228: /* classMember_0: typeAlias  */
#line 364 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2849 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 229: /* classMember_0: NOCODE classMember_0  */
#line 365 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMemberFilter((yyval.sn), (yyvsp[-1].sn));}
#line 2855 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 230: /* classMember_0: NOMETA classMember_0  */
#line 366 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMemberFilter((yyval.sn), (yyvsp[-1].sn));}
#line 2861 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 231: /* classMember: classMember_0  */
#line 369 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 2867 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 232: /* classMember: attributes classMember_0  */
#line 370 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setAttributeList((yyval.sn), (yyvsp[-1].sn));}
#line 2873 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 233: /* classMemberList: classMember  */
#line 373 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newClassMemberList(NULL, (yyvsp[0].sn));}
#line 2879 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 234: /* classMemberList: ';'  */
#line 374 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = NULL;}
#line 2885 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 235: /* classMemberList: classMemberList classMember  */
#line 375 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newClassMemberList((yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2891 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 236: /* classMemberList: classMemberList ';'  */
#line 376 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn);}
#line 2897 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 237: /* templateParameterList: IDENTIFY  */
#line 379 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTemplateParameterList(NULL, NULL, (yyvsp[0].sn));}
#line 2903 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 238: /* templateParameterList: templateParameterList ',' IDENTIFY  */
#line 380 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newTemplateParameterList((yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2909 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 239: /* templateParameters: TEMPLATE '<' templateParameterList '>'  */
#line 383 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = newTemplateParameters((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2915 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 240: /* class_0: CLASS IDENTIFY  */
#line 386 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newClass((yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2921 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 241: /* class_0: CLASS '(' identifyList ')' IDENTIFY  */
#line 387 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newClass((yyvsp[-4].sn), (yyvsp[-2].sn), (yyvsp[0].sn));}
#line 2927 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 242: /* class_0: STRUCT IDENTIFY  */
#line 388 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newClass((yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2933 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 243: /* class_0: STRUCT '(' identifyList ')' IDENTIFY  */
#line 389 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newClass((yyvsp[-4].sn), (yyvsp[-2].sn), (yyvsp[0].sn));}
#line 2939 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 244: /* class_1: class_0  */
#line 392 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2945 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 245: /* class_1: class_0 ':' typeNameList  */
#line 393 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-2].sn); setClassBaseList((yyval.sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2951 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 246: /* class_2: class_1 '{' '}'  */
#line 396 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-2].sn); setClassMemberList((yyval.sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 2957 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 247: /* class_2: class_1 '{' classMemberList '}'  */
#line 397 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[-3].sn); setClassMemberList((yyval.sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 2963 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 248: /* class_3: class_2 ';'  */
#line 400 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn); setClassSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2969 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 249: /* class_3: class_2 '=' STRING ';'  */
#line 401 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-3].sn); setNativeName((yyval.sn), (yyvsp[-1].sn)); setClassSemicolon((yyval.sn), (yyvsp[0].sn));}
#line 2975 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 250: /* class_4: class_3  */
#line 404 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2981 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 251: /* class_4: ABSTRACT class_3  */
#line 405 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setClassModifier((yyval.sn), (yyvsp[-1].sn));}
#line 2987 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 252: /* class_5: class_4  */
#line 408 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 2993 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 253: /* class_5: OVERRIDE class_4  */
#line 409 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setClassOverride((yyval.sn));}
#line 2999 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 254: /* class: class_5  */
#line 412 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 3005 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 255: /* class: templateParameters class_5  */
#line 413 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setClassTemplateParameters((yyval.sn), (yyvsp[-1].sn));}
#line 3011 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 256: /* tokenList: IDENTIFY  */
#line 417 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newTokenList(NULL, (yyvsp[0].sn));}
#line 3017 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 257: /* tokenList: operatorSign  */
#line 418 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                {(yyval.sn) = newTokenList(NULL, (yyvsp[0].sn));}
#line 3023 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 258: /* tokenList: tokenList ',' IDENTIFY  */
#line 419 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newTokenList((yyvsp[-2].sn), (yyvsp[0].sn));}
#line 3029 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 259: /* tokenList: tokenList ',' operatorSign  */
#line 420 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newTokenList((yyvsp[-2].sn), (yyvsp[0].sn));}
#line 3035 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 260: /* templateClassInstance_0: EXPORT IDENTIFY '<' typeNameList '>'  */
#line 423 "D:/idlcpp/src/idlcpp.y"
                                                                                                {(yyval.sn) = newTemplateClassInstance((yyvsp[-3].sn), (yyvsp[-1].sn));}
#line 3041 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 261: /* templateClassInstance: templateClassInstance_0 ';'  */
#line 426 "D:/idlcpp/src/idlcpp.y"
                                                                                                        {(yyval.sn) = (yyvsp[-1].sn);}
#line 3047 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 262: /* templateClassInstance: templateClassInstance_0 '{' '}' ';'  */
#line 427 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = (yyvsp[-3].sn);}
#line 3053 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 263: /* templateClassInstance: templateClassInstance_0 '{' tokenList '}' ';'  */
#line 428 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-4].sn); setTemplateClassInstanceTokenList((yyvsp[-4].sn), (yyvsp[-2].sn));}
#line 3059 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 264: /* templateClassInstance: templateClassInstance_0 '{' tokenList ',' '}' ';'  */
#line 429 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = (yyvsp[-5].sn); setTemplateClassInstanceTokenList((yyvsp[-5].sn), (yyvsp[-3].sn));}
#line 3065 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 265: /* namespaceMember_0: class  */
#line 433 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3071 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 266: /* namespaceMember_0: delegate  */
#line 434 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3077 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 267: /* namespaceMember_0: enum  */
#line 435 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3083 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 268: /* namespaceMember_0: templateClassInstance  */
#line 436 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3089 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 269: /* namespaceMember_0: typeAlias  */
#line 437 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3095 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 270: /* namespaceMember_0: namespace  */
#line 438 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn);}
#line 3101 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 271: /* namespaceMember_0: NOCODE namespaceMember_0  */
#line 439 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMemberFilter((yyval.sn), (yyvsp[-1].sn));}
#line 3107 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 272: /* namespaceMember_0: NOMETA namespaceMember_0  */
#line 440 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[0].sn); setMemberFilter((yyval.sn), (yyvsp[-1].sn));}
#line 3113 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 273: /* namespaceMember: namespaceMember_0  */
#line 443 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn);}
#line 3119 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 274: /* namespaceMember: attributes namespaceMember_0  */
#line 444 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = (yyvsp[0].sn); setAttributeList((yyval.sn), (yyvsp[-1].sn));}
#line 3125 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 275: /* namespaceMemberList: namespaceMember  */
#line 447 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newNamespaceMemberList(NULL, (yyvsp[0].sn));}
#line 3131 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 276: /* namespaceMemberList: ';'  */
#line 448 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = NULL;}
#line 3137 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 277: /* namespaceMemberList: namespaceMemberList namespaceMember  */
#line 449 "D:/idlcpp/src/idlcpp.y"
                                                                                                                        {(yyval.sn) = newNamespaceMemberList((yyvsp[-1].sn), (yyvsp[0].sn));}
#line 3143 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 278: /* namespaceMemberList: namespaceMemberList ';'  */
#line 450 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = (yyvsp[-1].sn);}
#line 3149 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 279: /* namespace: NAMESPACE IDENTIFY '{' '}'  */
#line 453 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                {(yyval.sn) = newNamespace((yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), NULL, (yyvsp[0].sn));}
#line 3155 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 280: /* namespace: NAMESPACE IDENTIFY '{' namespaceMemberList '}'  */
#line 454 "D:/idlcpp/src/idlcpp.y"
                                                                                                                {(yyval.sn) = newNamespace((yyvsp[-4].sn), (yyvsp[-3].sn), (yyvsp[-2].sn), (yyvsp[-1].sn), (yyvsp[0].sn));}
#line 3161 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 281: /* program: %empty  */
#line 457 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                                        {(yyval.sn) = newProgram(NULL); attachSyntaxTree((yyval.sn));}
#line 3167 "D:/idlcpp/src/idlcpp.y.c"
    break;

  case 282: /* program: namespaceMemberList  */
#line 458 "D:/idlcpp/src/idlcpp.y"
                                                                                                                                        {(yyval.sn) = newProgram((yyvsp[0].sn)); attachSyntaxTree((yyval.sn));}
#line 3173 "D:/idlcpp/src/idlcpp.y.c"
    break;


#line 3177 "D:/idlcpp/src/idlcpp.y.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

