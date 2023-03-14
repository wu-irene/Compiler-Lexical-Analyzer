/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    BREAK = 259,
    IFF = 260,
    FUNCTION = 261,
    BEGIN_BODY = 262,
    END_BODY = 263,
    ARRAY = 264,
    OF = 265,
    IF = 266,
    THEN = 267,
    ENDIF = 268,
    ELSE = 269,
    WHILE = 270,
    DO = 271,
    CONTINUE = 272,
    READ = 273,
    WRITE = 274,
    NOT = 275,
    TRUE = 276,
    FALSE = 277,
    RETURN = 278,
    MOD = 279,
    EQ = 280,
    NEQ = 281,
    LT = 282,
    GT = 283,
    LTE = 284,
    GTE = 285,
    SEMICOLON = 286,
    COLON = 287,
    COMMA = 288,
    L_SQUARE_BRACKET = 289,
    R_SQUARE_BRACKET = 290,
    EQUAL = 291,
    NUMBER = 292,
    PLUS = 293,
    MINUS = 294,
    MULT = 295,
    DIV = 296,
    L_PAREN = 297,
    R_PAREN = 298,
    ASSIGN = 299,
    INPUT = 300,
    OUTPUT = 301,
    IDENT = 302,
    VOID = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 115 "ppc_Final.y" /* yacc.c:1909  */

	char *op_val;
	int int_val;

#line 108 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
