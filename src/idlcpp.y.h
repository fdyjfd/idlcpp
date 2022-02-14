/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_D_IDLCPP_SRC_IDLCPP_Y_H_INCLUDED
# define YY_YY_D_IDLCPP_SRC_IDLCPP_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD_ASSIGN = 258,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 259,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 260,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 261,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 262,              /* MOD_ASSIGN  */
    BIT_XOR_ASSIGN = 263,          /* BIT_XOR_ASSIGN  */
    BIT_AND_ASSIGN = 264,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 265,           /* BIT_OR_ASSIGN  */
    LEFT_SHIFT_ASSIGN = 266,       /* LEFT_SHIFT_ASSIGN  */
    RIGHT_SHIFT_ASSIGN = 267,      /* RIGHT_SHIFT_ASSIGN  */
    LEFT_SHIFT = 268,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 269,             /* RIGHT_SHIFT  */
    EQUAL = 270,                   /* EQUAL  */
    NOT_EQUAL = 271,               /* NOT_EQUAL  */
    LESS_EQUAL = 272,              /* LESS_EQUAL  */
    GREATER_EQUAL = 273,           /* GREATER_EQUAL  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    INC = 276,                     /* INC  */
    DEC = 277,                     /* DEC  */
    BOOL = 278,                    /* BOOL  */
    CHAR = 279,                    /* CHAR  */
    WCHAR_T = 280,                 /* WCHAR_T  */
    SHORT = 281,                   /* SHORT  */
    LONG = 282,                    /* LONG  */
    INT = 283,                     /* INT  */
    FLOAT = 284,                   /* FLOAT  */
    DOUBLE = 285,                  /* DOUBLE  */
    SIGNED = 286,                  /* SIGNED  */
    UNSIGNED = 287,                /* UNSIGNED  */
    STRING_T = 288,                /* STRING_T  */
    NAMESPACE = 289,               /* NAMESPACE  */
    ENUM = 290,                    /* ENUM  */
    CLASS = 291,                   /* CLASS  */
    STRUCT = 292,                  /* STRUCT  */
    STATIC = 293,                  /* STATIC  */
    VIRTUAL = 294,                 /* VIRTUAL  */
    VOID = 295,                    /* VOID  */
    CONST = 296,                   /* CONST  */
    OPERATOR = 297,                /* OPERATOR  */
    TYPEDEF = 298,                 /* TYPEDEF  */
    TYPENAME = 299,                /* TYPENAME  */
    ABSTRACT = 300,                /* ABSTRACT  */
    GET = 301,                     /* GET  */
    SET = 302,                     /* SET  */
    CANDIDATE = 303,               /* CANDIDATE  */
    NOMETA = 304,                  /* NOMETA  */
    NOCODE = 305,                  /* NOCODE  */
    EXPORT = 306,                  /* EXPORT  */
    OVERRIDE = 307,                /* OVERRIDE  */
    SCOPE = 308,                   /* SCOPE  */
    IDENTIFY = 309,                /* IDENTIFY  */
    STRING = 310,                  /* STRING  */
    U8STRING = 311,                /* U8STRING  */
    TEMPLATE = 312,                /* TEMPLATE  */
    DELEGATE = 313                 /* DELEGATE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 7 "D:/idlcpp/src/idlcpp.y"

	struct SyntaxNode* sn;

#line 126 "D:/idlcpp/src/idlcpp.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_D_IDLCPP_SRC_IDLCPP_Y_H_INCLUDED  */
