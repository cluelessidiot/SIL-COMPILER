%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "arith.h"
	#include "y.tab.h"
	
	
	int number;
	
	

%}

%%

[0-9]+	{number = atoi(yytext);yylval.no = createTree(number,0,NULL,NODE_CONSTANT,NULL,NULL); return NUM;}
"begin" {return PBEGIN;}
"end" 	{return PEND;}
"read"	{return READ;}
"write"	{return	WRITE;}
[a-z]   {yylval.no=createTree(0,0,*yytext,NODE_VAR,NULL,NULL); return ID; }
";"	{return *yytext;}
"="	{return *yytext;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
