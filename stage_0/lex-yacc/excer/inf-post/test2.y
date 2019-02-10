%{
	#include <stdio.h>
	#include <stdlib.h>
	
	int yylex(void);
	
%}

%union{
	char *str;
}

%token ID PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%type <str> ID

%%

program : expr END		{printf("\n"); exit(1);}
	;
	
expr : exprplus PLUS expr       {}//printf("+ ");}
	| exprminus MINUS expr 	{}//printf("- ");}
	| exprmul MUL expr 	{}//printf("* ");}
	| exprdiv DIV expr 	{}//printf("/ ");}
	| '(' expr ')' 		
	| ID 			{printf(" %s ",$1);}
	;
exprplus: ID                    {printf("+ %s",$1);}
	;	
exprmul: ID                    {printf("* %s",$1);}
	;
exprdiv: ID                    {printf("/ %s",$1);}
	;	
exprminus:ID                    {printf("- %s",$1);}
	;	

%%

yyerror(char const *s){
	printf("yyerror %s",s);
}


int main(void){
	yyparse();
	return 0;
}
