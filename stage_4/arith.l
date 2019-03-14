%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "arith.h"
	#include "y.tab.h"
	
	
	int number;
	int line=0;
	
	

%}

%%

[0-9]+	{number = atoi(yytext);yylval.no = createTree(number,INTEGER,NULL,NODE_CONSTANT,NULL,NULL,NULL); return NUM;}
"begin" {return PBEGIN;}   //begin-end construct 
"end" 	{return PEND;}
"read"	{return READ;}
"write"	{return	WRITE;}
"if"	{return IF;} //conditional constructs
"then"	{return then;}
"else"	{return Else;}
"endif" {return ENDIF;}
"breakpoint" {return BRKP; }
"break" {return BREAK_L;}
"continue" {return CONTINUE_L;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
"until" {return UNTIL;}
"repeat" {return REPEAT;}
"decl"   {return DECL;}
"enddecl"   {return ENDDECL;}
"int"	{return INT;}
"str" {return STR;}
"&"	{return AMPERCANT;}
[a-zA-Z][a-zA-Z0-9]* {yylval.no=createTree(0,NOTYPE,yytext,NODE_VAR,NULL,NULL,NULL); return ID;}
","      {return *yytext;}
";"	{return *yytext;}
"="	{return *yytext;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"<"	{return LT;} // boolean constucts
"<="	{return LE;}
">"	{return GT;}
">="	{return GE;}
"=="	{return EQ;}
"!=" 	{return NE;}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{line++;}
"["     {return *yytext;}
"]"	{return *yytext;}
.	{yyerror("unknown character\n");
         printf("%s line %d",yytext,line);
         exit(1);}

%%

int yywrap(void) {
	return 1;
}
