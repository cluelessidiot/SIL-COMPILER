%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	int letterct=0;
	int wrdct=0;
	int linect=0;
	int spct=0;
%}
	
number [0-9]+
word [A-Za-z]+ 
letter [A-Za-z]
space [\t ]
spacered [\t ]+
newline [\n]
newlinep [\n]+
%%
 
{number} {printf("Found : %d\n",atoi(yytext));}
{space} {wrdct++;}
{spacered} {spct++;}
{newline} {linect++;wrdct++;}
{letter} {letterct++;}
 /*{word} {wrdct++;letterct++;}*/
{newlinep} {return 0;}
%%
 
int main()
{
	yylex();
	printf("%d\n%d\n%d",letterct,wrdct,linect);
	return 1;
}
