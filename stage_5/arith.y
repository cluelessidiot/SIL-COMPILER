%{
	#include <stdio.h>
	#include <stdlib.h>
        #include "symboltable.h"
	#include "arith.h"
	#include "symboltable.c"
	
	#include "arith.c"

    	int yylex(void);
    	int yyerror(char const *);

struct Paramstruct *ParamList=NULL;
%}

%union{
	struct tnode *no;
	
	//char str;
}
%type <no> expr NUM  Slist Stmt 
%type <no> InputStmt OutputStmt AsgStmt
%type <no>  ID Ifstmt Whilestmt DoWhileStmt Repeatstmt I_D
%type <no> CONTINUE_L BRKP BREAK_L sp_comm ID_declr
%type <no> Body GDeclBlock FDefBlock MainBlock GDeclList LDeclBlock LDecList FDef Call_Arg Ret_urn
%token MTOKEN
%token NUM PLUS MINUS MUL DIV NEWLINE 
%token PBEGIN READ WRITE  PEND ID 
%token IF then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL
%token GT GE LT LE EQ NE
%token DECL ENDDECL INT STR STAR AMPERCANT RETURN TUPLE
%token CONTINUE_L BRKP BREAK_L  
%left GT GE LT LE EQ NE
%left PLUS MINUS
%left MUL DIV
%%
 //program skeleton........................
Program : GDeclBlock FDefBlock MainBlock {}
		| GDeclBlock MainBlock	{}
		| MainBlock		{}
		;

GDeclBlock : DECL GDeclList ENDDECL { PrintSymbolTable();header_printer(); funct_open=1;}
			| DECL ENDDECL { /* No Action */ }
			;
			
GDeclList : GDeclList GDecl { /* No Action */ }
	   | GDecl { /* No Action */ }
	   ;

GDecl : Type GidList ';' {current_type=NOTYPE;}
	//:Tuple ID '(' ParamList ')' GidList ';'{}
	;
//Tuple : TUPLE { currtype = TLookup("tuple");};
//	;
GidList : GidList ',' Gid {} 
	| Gid {}
	;
 	
Gid 	: ID_declr	         {}
	| ID '('Param_List')' 	{ Install($1->varname,current_type,-1,-1,-1,Phead,0); Phead=NULL; }
	;
 //function declaration part...............
 FDefBlock : FDefBlock FDef { totalCount=0; Lhead=NULL; parambinding=-2; printf("function declaration over...\n"); }
		  | FDef{ totalCount=0; Lhead=NULL; parambinding=-2; }
		  ;
		  
FDef : Type ID '(' Param_List ')' '{' LDeclBlock Body '}' {	declrflag=1;                        
											  check_param_eqvlnce(Phead,GLookup($2->varname)->paramlist); 
                                                                                   printf("%s",$2->varname);
                                                                                   printf("000000000000000 %d 0000000000000000\n",totalCount);
                                                                                    Code_Create($8,$2->varname);
                                                                                    Phead=NULL;
                                                                                    ParamList=NULL;
                                                                                    totalCount=0;
                                                                                    
							 }
		;

Param_List : Param_List ',' Param  {  }
		  | Param { }
		  ;

Param : Type ID { 
		if(funct_open==0) //int global declaration of function we cant allow to parameter with same name....
                  { 
                   if(PLookup($2->varname,Phead)==NULL)
                   PInstall($2->varname,current_type,0);
                   else
                   {printf("repeated Declaration of Variable %s in function parameter Declaration\n",$2->varname);
                   exit(1);
                    }
                   } 
                  else
                  {
                    PInstall($2->varname,current_type,0);
                    parambinding--;
                    LInstall($2->varname,current_type, parambinding);
                  } 
                    
                    }
	;  


 //  local declaration part
LDeclBlock :DECL LDecList ENDDECL { declrflag=0;printf("Local declarations.....\n");print_local_table();} 
	   | DECL ENDDECL {declrflag=0;printf("endecl....decl \n");}
	   ;

LDecList : LDecList LDecl {}
	| LDecl  {}
	;

LDecl : Type IdList';' {printf("Type ID List.....\n");} 
	;

IdList : IdList ',' ID {  LInstall($3->varname,current_type,0);} 
	| ID {LInstall($1->varname,current_type,0); }
	;

//main block
MainBlock: INT MTOKEN '('')''{'LDeclBlock Body'}' {
														print_local_table();
														Code_Create($7, "main");
														
														ParamList=NULL;}
	;
		
Body :PBEGIN Slist Ret_urn PEND      {$$=createTree(0,NULL,NULL,NODE_CONN,$2,NULL,$3);}
	;
Ret_urn : RETURN expr ';' { $$=createTree(0,$2->type,NULL,N_RET, $2, NULL, NULL); };	
//variable declarations
Declarations :	DECL DeclList ENDDECL { //PrintSymbolTable(); declrflag=0;
					 }
		| DECL ENDDECL { //PrintSymbolTable();
					 }
		;

DeclList : DeclList Decl {  declrflag=0;}
	   | Decl { declrflag=0;  }
	   ;	
Decl : Type VarList ';' { current_type=NOTYPE; };

Type :  INT { current_type=INTEGER; declrflag=1; }
	|STR { current_type=STRING; declrflag=1; }
	;

VarList : VarList ',' ID_declr {}
	  | ID_declr 	{}
	  ;

ID_declr	: ID {  Install($1->varname,current_type,1,1,0,NULL,-1);  }   
	  |ID'['expr']' { 
	     Install($1->varname,current_type,evaluate($3),evaluate($3),0,NULL,-1); }
	  | ID '['expr']''['expr']'{Install(	$1->varname,current_type,evaluate($3)*evaluate($6),evaluate($3),evaluate($6),NULL,-1); 	}
	  | MUL ID {	Install($2->varname,current_type,1,1,0,NULL,-1); }
	  ;	
I_D	: ID {  $$=$1; }   
	  |ID'['expr']'               { $$=createTree(0,NOTYPE,$1->varname,NODE_VAR,$3,NULL,NULL);   }
	  | ID '['expr']''['expr']'   { $$=createTree(0,NOTYPE,$1->varname,NODE_VAR,$3,NULL,$6);}
	  | MUL ID                    { printf("in y %s",$2->varname);$$=createTree(0,NOTYPE,$2->varname,POINTER,NULL,NULL,NULL);       }
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
Slist : Slist Stmt 		{$$ = createTree(0,0,NULL,NODE_CONN,$1,NULL,$2);}
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
	

InputStmt : READ'('I_D')'';'	{$$ = createTree(0,0,NULL,NODE_READ,$3,NULL,NULL);}
	;

OutputStmt : WRITE'('expr')'';'	{$$ = createTree(0,0,NULL,NODE_WRITE,$3,NULL,NULL);}
	;
	
AsgStmt : I_D'='expr';' 		{$$ = createTree(0,0,'=',NODE_ASSGN,$1,NULL,$3);}
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
	 | I_D			{$$ = $1;}
	 | ID'('')'             { $$=createTree($1->val, NULL,$1->varname,N_FNCT, NULL, NULL, NULL);  }
	 | ID '('Call_Arg')'    { function_call_verify($3,GLookup($1->varname));
	                          $$=createTree($1->val, NULL,$1->varname,N_FNCT, $3, NULL, NULL);}
	 | AMPERCANT ID         {$$ = createTree($2->val,$2->type,$2->varname,AMPER,NULL,NULL,NULL);}
	 ;
Call_Arg : Call_Arg ',' expr{$3->mid=$1;$$=$3;}
	 | expr   {$$=$1;}
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
	
	yyparse();
	answer_storer();
	return 0;
}
