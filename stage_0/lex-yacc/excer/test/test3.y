%{

	#include <stdio.h>
	#include <stdlib.h>
	
	#define YYSTYPE tnode *
	
	#include "test3.h"
	#include "test3.c"
	
	int yylex(void);
	
%}

%token ID PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
			$$ = $2;
			evaluate($1);
			printf("\n");
			exit(1);
		}
	;
	
expr : expr PLUS expr 		{$$ = makeOperatorNode('+',$1,$3);}
	| expr MINUS expr 	{$$ = makeOperatorNode('-',$1,$3);}
	| expr MUL expr 	{$$ = makeOperatorNode('*',$1,$3);}
	| expr DIV expr 	{$$ = makeOperatorNode('/',$1,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| ID			{$$ = $1;}
	;

%%

yyerror(char const *s){
	printf("yyerror %s",s);
}

int main(void){
	yyparse();
	return 0;
}
