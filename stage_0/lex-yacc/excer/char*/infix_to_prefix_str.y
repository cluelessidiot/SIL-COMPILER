%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int yylex(void);
	char* joiner(char op,char *a,char *b);
	FILE *yyin;
%}

%union{
	char *str;
}

%token ID PLUS MINUS MUL DIV END
%left PLUS MINUS
%left '*' '/'
%type <str> ID expr program

%%

program : expr END		{printf("%s \n",$1); exit(1);}
	;
expr : expr PLUS expr 		{$$=joiner('+',$1,$3);}
	| expr MINUS expr	{$$=joiner('-',$1,$3);}
	| expr '*' expr 	{$$=joiner('*',$1,$3);}
	| expr '/' expr 	{$$=joiner('/',$1,$3);}
	| '(' expr ')'		{$$=$2;}
	| ID 			{$$=$1;}
	;

%%

yyerror(char const *s){
	printf("yyerror %s",s);
}

char* joiner(char op,char *a,char *b)
{
    char *x;
    x=(char*)malloc(sizeof(char));
    *x=op;
    //printf("%s\n",strcat(x,strcat(a,b)));
  return strcat(x,strcat(a,b));
}
int main(int argc,char* argv[]) {
if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
}

	yyparse();
	return 0;
}
