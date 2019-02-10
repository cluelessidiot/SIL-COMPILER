%{

	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>

	
%}

%%

[a-zA-Z]+	{
			yylval.str = strdup(yytext);
			return ID;
		}
"+" 		{return PLUS;}
"-" 		{return MINUS;}	
"*" 		{return *yytext;}
"/"		{return *yytext;}
[ \t] 		{}
[()] 		{return *yytext;}
[\n] 		{return END;}
. 		{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void){
	return 1;
}
