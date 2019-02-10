%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	int letterct=0;
	int wrdct=0;
	int flt=0;
	int numct=0;
%}
dot    [.]	
number [0-9]+
word [A-Za-z]+ 
letter [A-Z|a-z]
space [\t ]
newline [\n]
newlinep [\n]+
char [A-Za-z0-9 \t]+
charn [A-Z|a-z|0-9| |\t|\n]+
%%
 
[/][/]{char}{newline} {printf("single %s",yytext);}
[/][*]{charn}[*][/] {printf("double %s",yytext);}
{word}{newline} { }
%%
 
int main()
{
	yylex();
	printf("%d %d",numct,flt);
	return 1;
}
