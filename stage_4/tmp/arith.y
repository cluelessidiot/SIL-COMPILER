%{
	#include <stdio.h>
	#include <stdlib.h>
        #include "symboltable.h"
	#include "arith.h"
	#include "symboltable.c"
	
	#include "arith.c"

    	int yylex(void);
    	int yyerror(char const *);


%}

%union{
	struct tnode *no;
	struct  Gsymbol *ST;
	//char str;
}
%type <no> expr NUM program Slist Stmt ID
%type <no> InputStmt OutputStmt AsgStmt
%type <no>   Ifstmt Whilestmt DoWhileStmt Repeatstmt
%type <no> CONTINUE_L BRKP BREAK_L sp_comm I_D
%type <ST> DeclList Decl VarList 


%token NUM PLUS MINUS MUL DIV NEWLINE 
%token PBEGIN READ WRITE  PEND I_D 
%token IF then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL
%token GT GE LT LE EQ NE
%token DECL ENDDECL INT STR 
%token CONTINUE_L BRKP BREAK_L  AMPERSAND STAR
%left GT GE LT LE EQ NE
%left PLUS MINUS
%left MUL DIV
%%
program : PBEGIN Slist PEND      {$$=$2;//codeGen($2);
					//exit(1);
					//evaluate($2);
					
					inorder($2);
					}
	| PBEGIN PEND		{$$=NULL;}
	;
//variable declarations
Declarations :	DECL DeclList ENDDECL { PrintSymbolTable(); }
		| DECL ENDDECL { PrintSymbolTable(); }
		;
DeclList : DeclList Decl {  }
	   | Decl {  }
	   ;	
Decl : Type VarList ';' { current_type=NOTYPE; };

Type :  INT { current_type=INTEGER; }
	|STR { current_type=STRING; }
	;

VarList : VarList ',' ID {				int r=1,c=1;
							if($3->left)
								r=$3->left->val;
							if($3->right)
								c=$3->right->val;
							Install($3->varname,current_type,r*c,r,c);
							free($3); }
	  | ID 	{               int r=1,c=1;
				if($1->left)
					r=$1->left->val;
				if($1->right)
					c=$1->right->val;
				Install($1->varname,current_type,r*c,r,c);
				free($1); }
	  ;	
	
//conditional constructs........	
Ifstmt :IF '('expr')' then Slist Else Slist ENDIF ';'	{$$=createTree(0,0,NULL,NODE_IF,$3,$6,$8);}
	| IF '('expr')' then Slist ENDIF';'		{$$=createTree(0,0,NULL,NODE_IF,$3,$6,NULL);}
	;				
Whilestmt : WHILE '('expr')' DO Slist ENDWHILE';'	{$$=createTree(0,0,NULL,NODE_WHILE,$3,NULL,$6);}
	;
DoWhileStmt:DO Slist WHILE'('expr')'';'			{$$=createTree(0,0,NULL,NODE_DOWHILE,$2,NULL,$5);}
	;		
Repeatstmt:UNTIL Slist REPEAT'('expr')'';'		{$$=createTree(0,0,NULL,NODE_REPEAT,$2,NULL,$5);}
	;		
//types of statement...................	
Slist : Slist Stmt 		{$$ = createTree(0,0,NULL,NODE_CONN,$1,NULL,$2);
				}
	| Stmt			{$$=$1;}
	|Declarations { $$=createTree(0,NOTYPE,NULL,DECL_STMT,NULL,NULL,NULL);}
	;
	
Stmt : InputStmt 		{$$=$1;}
	| OutputStmt 		{$$=$1;}
	| AsgStmt		{$$=$1;}
	| Ifstmt		{$$=$1;}
	| Whilestmt		{$$=$1;}
	| DoWhileStmt		{$$=$1;}
	| Repeatstmt		{$$=$1;}
	| sp_comm 		{$$=$1;}
	;
	

InputStmt : READ'('ID')'';'	{$$ = createTree(0,0,NULL,NODE_READ,$3,NULL,NULL);}
	;

OutputStmt : WRITE'('expr')'';'	{$$ = createTree(0,0,NULL,NODE_WRITE,$3,NULL,NULL);}
	;
	
AsgStmt : ID'='expr';' 		{ $$ = createTree(0,0,NULL,NODE_ASSGN,$1,NULL,$3);
				}
	;	

sp_comm : BRKP';' 		{$$=createTree(0,0,NULL,N_BRKP,NULL,NULL,NULL);}
	   | BREAK_L ';'	{$$=createTree(0,0,NULL,N_BREAK,NULL,NULL,NULL);}
	   | CONTINUE_L ';'	{$$=createTree(0,0,NULL,N_CONTINUE,NULL,NULL,NULL);}
	   ;	
//expressions..............	
expr : expr PLUS expr		{$$ = createTree(0,INTEGER,'+',NODE_EX,$1,NULL,$3);}
	 | expr MINUS expr  	{$$ = createTree(0,INTEGER,'-',NODE_EX,$1,NULL,$3);}
	 | expr MUL expr	{$$ = createTree(0,INTEGER,'*',NODE_EX,$1,NULL,$3);}
	 | expr DIV expr	{$$ = createTree(0,INTEGER,'/',NODE_EX,$1,NULL,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | expr GT expr		{$$ = createTree(0,BOOLE,NULL,N_GT,$1,NULL,$3);}		
	 | expr GE expr		{$$ = createTree(0,BOOLE,NULL,N_GE,$1,NULL,$3);}
	 | expr LT expr		{$$ = createTree(0,BOOLE,NULL,N_LT,$1,NULL,$3);}
	 | expr LE expr		{$$ = createTree(0,BOOLE,NULL,N_LE,$1,NULL,$3);}
	 | expr EQ expr		{$$ = createTree(0,BOOLE,NULL,N_EQ,$1,NULL,$3);}
	 | expr NE expr		{$$ = createTree(0,BOOLE,NULL,N_NE,$1,NULL,$3);}
	 | NUM			{$$ = $1;}
	 | ID			{$$ = $1;}
	 | AMPERSAND I_D	{ $$=createTree($2->val,$2->type,$2->varname,ADDRESS_OP,$2->left,$2->mid,$2->right); 
	 			free($2); }
	 ;
ID	: I_D		 {$$=$1;
			}
	| STAR I_D     { $$=createTree($2->val,$2->type,$2->varname,VAR_POINTER,$2->left,$2->mid,$2->right);
				free($2); }
	| I_D'[' expr ']' { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->mid,$1->right);
				//free($3);
				free($1); }
	| I_D'[' expr ']''[' expr ']' { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->mid,$6);
									free($1);}
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
