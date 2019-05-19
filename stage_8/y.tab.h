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
    TXT = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    ASSIGN = 264,
    WRITE = 265,
    READ = 266,
    ID = 267,
    BEGINTK = 268,
    END = 269,
    EQ = 270,
    NE = 271,
    LT = 272,
    GT = 273,
    LE = 274,
    GE = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    BREAKTK = 283,
    CONTINUETK = 284,
    BRKPTK = 285,
    REPEAT = 286,
    UNTIL = 287,
    DECL = 288,
    ENDDECL = 289,
    INT = 290,
    STR = 291,
    ADDRTK = 292,
    MAINTK = 293,
    RETURN = 294,
    ANDTK = 295,
    ORTK = 296,
    NOTTK = 297,
    TUPLE = 298,
    TYPETK = 299,
    ENDTYPE = 300,
    NULLTK = 301,
    ALLOC = 302,
    INITIALIZE = 303,
    FREE = 304,
    MOD = 305,
    CLASS = 306,
    ENDCLASS = 307,
    DELETE = 308,
    NEW = 309,
    EXTENDS = 310,
    SELF = 311
  };
#endif
/* Tokens.  */
#define NUM 258
#define TXT 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define ASSIGN 264
#define WRITE 265
#define READ 266
#define ID 267
#define BEGINTK 268
#define END 269
#define EQ 270
#define NE 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define BREAKTK 283
#define CONTINUETK 284
#define BRKPTK 285
#define REPEAT 286
#define UNTIL 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define ADDRTK 292
#define MAINTK 293
#define RETURN 294
#define ANDTK 295
#define ORTK 296
#define NOTTK 297
#define TUPLE 298
#define TYPETK 299
#define ENDTYPE 300
#define NULLTK 301
#define ALLOC 302
#define INITIALIZE 303
#define FREE 304
#define MOD 305
#define CLASS 306
#define ENDCLASS 307
#define DELETE 308
#define NEW 309
#define EXTENDS 310
#define SELF 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
