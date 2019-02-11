%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
number [0-92]+
 
%%
 
{number} {if(atoi(yytext)%2==0)printf("Even : %d\n",atoi(yytext));else 
printf("odd : %d\n",atoi(yytext));}
 
%%
 
int main()
{
	yylex();
	return 1;
}
