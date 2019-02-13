%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "arith.h"
	#include "arith.c"
    	int yylex(void);
    	int yyerror(char const *);


%}

%union{
	struct tnode *no;
	//char str;
}
%type <no> expr NUM program Slist Stmt InputStmt OutputStmt AsgStmt ID
%token NUM PLUS MINUS MUL DIV NEWLINE PBEGIN READ WRITE  PEND ID
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND      {$$=$2;codeGen($2);
                                      
					//evaluate($2);
					//inorder($2);
					}
	| PBEGIN PEND		{$$=NULL;}
	;
Slist : Slist Stmt 		{$$ = createTree(0,0,NULL,NODE_CONN,$1,$2);}
	| Stmt			{$$=$1;}
	;
Stmt : InputStmt 		{$$=$1;}
	| OutputStmt 		{$$=$1;}
	| AsgStmt		{$$=$1;}
	;

InputStmt : READ'('ID')'';'	{$$ = createTree(0,0,NULL,NODE_READ,$3,NULL);}
	;

OutputStmt : WRITE'('expr')'';'	{$$ = createTree(0,0,NULL,NODE_WRITE,$3,NULL);}
	;
	
AsgStmt : ID'='expr';' 		{$$ = createTree(0,0,'=',NODE_ASSGN,$1,$3);}
	;	
	
expr : expr PLUS expr		{$$ = createTree(0,0,'+',NODE_EX,$1,$3);}
	 | expr MINUS expr  	{$$ = createTree(0,0,'-',NODE_EX,$1,$3);}
	 | expr MUL expr	{$$ = createTree(0,0,'*',NODE_EX,$1,$3);}
	 | expr DIV expr	{$$ = createTree(0,0,'/',NODE_EX,$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM		{$$ = $1;}
	 | ID		{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc,char* argv[]) {
if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
}
 xsm_file=fopen("arith.xsm","w");
	header_printer();
	yyparse();
	answer_storer();
	return 0;
}
