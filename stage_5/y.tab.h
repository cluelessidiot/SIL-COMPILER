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
    MTOKEN = 258,
    NUM = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    NEWLINE = 264,
    PBEGIN = 265,
    READ = 266,
    WRITE = 267,
    PEND = 268,
    ID = 269,
    IF = 270,
    then = 271,
    Else = 272,
    ENDIF = 273,
    WHILE = 274,
    DO = 275,
    ENDWHILE = 276,
    REPEAT = 277,
    UNTIL = 278,
    GT = 279,
    GE = 280,
    LT = 281,
    LE = 282,
    EQ = 283,
    NE = 284,
    DECL = 285,
    ENDDECL = 286,
    INT = 287,
    STR = 288,
    STAR = 289,
    AMPERCANT = 290,
    RETURN = 291,
    TUPLE = 292,
    CONTINUE_L = 293,
    BRKP = 294,
    BREAK_L = 295
  };
#endif
/* Tokens.  */
#define MTOKEN 258
#define NUM 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define NEWLINE 264
#define PBEGIN 265
#define READ 266
#define WRITE 267
#define PEND 268
#define ID 269
#define IF 270
#define then 271
#define Else 272
#define ENDIF 273
#define WHILE 274
#define DO 275
#define ENDWHILE 276
#define REPEAT 277
#define UNTIL 278
#define GT 279
#define GE 280
#define LT 281
#define LE 282
#define EQ 283
#define NE 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define STAR 289
#define AMPERCANT 290
#define RETURN 291
#define TUPLE 292
#define CONTINUE_L 293
#define BRKP 294
#define BREAK_L 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "arith.y" /* yacc.c:1909  */

	struct tnode *no;
	
	//char str;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
