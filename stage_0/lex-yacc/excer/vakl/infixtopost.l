%{
          #include <stdio.h> 
	  #include "y.tab.h"
	  #include<stdlib.h>
	//  #define YYSTYPE char*
	  //#define YYSTYPE_IS_DECLARED 1
	//  typedef  char* YYSTYPE;
%}

%%
[0-9]+	{  //printf("ddcd");
//printf("testing ..%sx\n",yytext);
     //printf("type of %s",typeof(yylval)==int);
         printf("%d ",atoi(yytext));
         yylval=atoi(yytext);
         printf(" %d",yylval);
         //printf("\n%s 	",yylval);
          return DIGIT;
        }
"+"	  return *yytext;
"-"	  return *yytext;
"*"	  return *yytext;
"/"	  return *yytext;
[()]	  return *yytext;
"\n"      return *yytext;

%%

yywrap()
{
	return 1;
}
