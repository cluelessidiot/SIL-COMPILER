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
    NUM = 258,
    PLUS = 259,
    MINUS = 260,
    MUL = 261,
    DIV = 262,
    NEWLINE = 263,
    PBEGIN = 264,
    READ = 265,
    WRITE = 266,
    PEND = 267,
    I_D = 268,
    IF = 269,
    then = 270,
    Else = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    REPEAT = 276,
    UNTIL = 277,
    GT = 278,
    GE = 279,
    LT = 280,
    LE = 281,
    EQ = 282,
    NE = 283,
    DECL = 284,
    ENDDECL = 285,
    INT = 286,
    STR = 287,
    CONTINUE_L = 288,
    BRKP = 289,
    BREAK_L = 290,
    AMPERSAND = 291,
    STAR = 292
  };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define NEWLINE 263
#define PBEGIN 264
#define READ 265
#define WRITE 266
#define PEND 267
#define I_D 268
#define IF 269
#define then 270
#define Else 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define REPEAT 276
#define UNTIL 277
#define GT 278
#define GE 279
#define LT 280
#define LE 281
#define EQ 282
#define NE 283
#define DECL 284
#define ENDDECL 285
#define INT 286
#define STR 287
#define CONTINUE_L 288
#define BRKP 289
#define BREAK_L 290
#define AMPERSAND 291
#define STAR 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "arith.y" /* yacc.c:1909  */

	struct tnode *no;
	struct  Gsymbol *ST;
	//char str;

#line 134 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
