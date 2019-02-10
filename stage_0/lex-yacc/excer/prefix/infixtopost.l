%{
          #include <stdio.h> 
	  #include "y.tab.h"
	  #include<stdlib.h>
	  #define YYSTYPE char*
	  #define YYSTYPE_IS_DECLARED 1
	//  typedef  char* YYSTYPE;
%}

%%
[a-z]+	{  //printf("ddcd");
//printf("testing ..%sx\n",yytext);
     //printf("type of %s",typeof(yylval)==int);
         
         yylval=strdup(yytext);
         //printf("\n%s 	",yylval);
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
