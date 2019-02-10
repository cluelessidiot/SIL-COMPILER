%{
          #include <stdio.h> 
	  #include "y.tab.h"
%}

%%
[a-z|A-Z]	{  //printf("ddcd");
//printf("%d",*yytext);
          yylval = *yytext;
          return CHARS;
        }
"+"	  return *yytext;
"-"	  return *yytext;
"*"	  return *yytext;
"/"	  return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;

%%

yywrap()
{
	return 1;
}
