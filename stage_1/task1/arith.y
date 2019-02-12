%{
	#include <stdio.h>
	#include <stdlib.h>
	//#define YYSTYPE tnode *
	#include "arith.h"
         #include "arith.c"
    	int yylex(void);


%}

%union{
	struct tnode *no;
	//char str;
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				$$ = $2;
				header_printer();
				printf("Answer : %d \n",codeGen($1));
				answer_storer();
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = createTree(0,0,'+',$1,$3);}
	 | expr MINUS expr  	{$$ = createTree(0,0,'-',$1,$3);}
	 | expr MUL expr	{$$ = createTree(0,0,'*',$1,$3);}
	 | expr DIV expr	{$$ = createTree(0,0,'/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
 xsm_file=fopen("arith.xsm","w");
	yyparse();
	
	return 0;
}
