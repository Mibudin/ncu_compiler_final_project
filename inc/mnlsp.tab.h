/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_INC_MNLSP_TAB_H_INCLUDED
# define YY_YY_INC_MNLSP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 21 "src/mnlsp.y" /* yacc.c:1921  */

#include"mnlsp.hpp"

#line 52 "./inc/mnlsp.tab.h" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    BOOL_VAL = 260,
    LP = 261,
    RP = 262,
    PRINT_NUM_ID = 263,
    PRINT_BOOL_ID = 264,
    PLUS_ID = 265,
    MINUS_ID = 266,
    MULTIPLY_ID = 267,
    DIVIDE_ID = 268,
    MODULUS_ID = 269,
    GREATER_ID = 270,
    SMALLER_ID = 271,
    EQUAL_ID = 272,
    AND_ID = 273,
    OR_ID = 274,
    NOT_ID = 275,
    DEFINE_ID = 276,
    FUN_ID = 277,
    IF_ID = 278
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_MNLSP_TAB_H_INCLUDED  */
