%{
#include<stdio.h>
#include<stdlib.h>

#include "arith.c"

#include "symboltable.c"
#include "function_helper.c"
#define YYSTYPE tnode *
int yyerror(char const *);
int yylex(void);
%}

%token NUM STRNG PLUS MINUS MUL DIV 
%token ASSIGN WRITE READ ID PBEGIN PEND 
%token EQ NE LT GT LE GE IF THEN ELSE ENDIF WHILE DO ENDWHILE 
%token BREAK_L CONTINUE_L BRKP_L REPEAT UNTIL DECL ENDDECL
%token INT STR AMPERCANT MTOKEN RETURN AND_ OR_ NOT_ TUPLE 
%token TYPE_ST ENDTYPE NULLTK 
%token ALLOC INITIALIZE FREE MOD
%left PLUS MINUS
%left MUL DIV MOD
%left LT GT LE GE EQ NE
%left NOT_
%left AND_ OR_
%%

Program : TypeDefBlock GDeclBlock FDefBlock MainBlock
		| TypeDefBlock GDeclBlock MainBlock
		| TypeDefBlock MainBlock
		;

TypeDefBlock : TYPE_ST TypeDefList ENDTYPE { printTypeTable(); }
			  | { printTypeTable(); }
			  ;
			  
TypeDefList : TypeDefList TypeDef {  }
			 | TypeDef {  }
			 ;
			 
TypeDef : ID '{' {TInstall($1->varname,0,NULL);} FieldDeclList '}' { type_table_configure($1->varname);
								/*  TypeTable *type_table=TLookup($1->varname);
								  fieldcheck(fieldlist);
								  type_table->fields=fieldlist;
								  fieldlist=NULL;
								  type_table->size=getSize(type_table);*/
								};
																	 

FieldDeclList : FieldDeclList FieldDecl { addfield(); }
				| FieldDecl { field->fieldIndex=0; fieldlist=field; field=NULL; }
				;
FieldDecl : Type ID ';' { field=(FieldList *)malloc(sizeof(FieldList)); field->name=$2->varname; field->type=$1->type; field->next=NULL; };

GDeclBlock : DECL GDeclList ENDDECL { print_symbol_table(); }
			| DECL ENDDECL {  }
			;
			
GDeclList : GDeclList GDecl {  }
	   | GDecl { }
	   ;

GDecl : Type GidList ';' { currtype=NULL; }
		| Tuple ID '(' ParamList ')' GidList ';' { currtype=NULL; paramlist=NULL; }
		;

Tuple : TUPLE { currtype = TLookup("tuple");};

GidList : GidList ',' Gid {  }
		| Gid {  }
		;
		
Gid : Iden { createSymbolTableEntry($1); }
	| Id1 '(' ParamList ')' { GInstall($1->varname,currtype,0,0,0,paramlist,flabel++);
				 //for filling pointer field in pointer returned function..... 
				 paramlist=NULL;
				if($1->nodetype==POINTER){ 
					Gsymbol *p= GLookup($1->varname); 
					p->pointer=1; }	}
	;

FDefBlock : FDefBlock FDef {  }
		  | FDef{  }
		  ;
		  
FDef : Type ID '(' ParamList ')' '{' LDeclBlock Body '}' {                       function_call($8,$2->varname);
											
															
															};

ParamList : ParamList ',' Param { create_param_list(parameter); parameter=NULL; }
		  | Param { create_param_list(parameter), parameter=NULL; }
		  | {  }
		  ;

Param : Type Id1 { createParamNode($1->type,$2->varname,$2->nodetype); currtype=oldtype; };

Type : ID { oldtype=currtype; currtype=TLookup($1->varname); $$=createTree(0,currtype,$1->varname,TYPE,NULL,NULL,NULL); };

LDeclBlock : DECL LDeclList ENDDECL { createLsymbolEntries(paramlist);   }
			| DECL ENDDECL { createLsymbolEntries(paramlist);   }
			| { createLsymbolEntries(paramlist);   }
			;
			
LDeclList : LDeclList LDecl { }
	   | LDecl {  }
	   ;

LDecl : Type IdList ';' { currtype=NULL; };

IdList : IdList ',' Id1 { LInstall($3->varname, currtype,local_binding++, $3->nodetype==POINTER ? 1 : 0); }
		| Id1 { LInstall($1->varname, currtype,local_binding++, $1->nodetype==POINTER ? 1 : 0); }
		;

Body : PBEGIN Slist RetStmt PEND { $$=createTree(0,NULL,NULL,CONN,$2,NULL,$3); };

RetStmt : RETURN expr ';' { $$=createTree(0,$2->type,NULL,RET, $2, NULL, NULL); };

MainBlock : Type MTOKEN '(' ')' '{' LDeclBlock Body '}'  { if($1->type != TLookup("int")){
											yyerror("Main expects integer return type");
											exit(1);
											}
															char *marg="main";
															function_call($7,marg);
							};

Slist : Slist Stmt {$$=createTree(0,NULL,NULL,CONN,$1,NULL,$2);}
	| Stmt {$$=$1;}
	;


Stmt : 	InputStmt 	{$$=$1;}
	| OutputStmt 	{$$=$1;}
	| AsgStmt 		{$$=$1;}
	| IfStmt 		{$$=$1;}
	| WhileStmt 	{$$=$1;}
	| DoWhileStmt	{$$=$1;}
	| UntilStmt 	{$$=$1;}
	| PlainStmt 	{$$=$1;}
	;

InputStmt : READ '(' Iden ')' ';' {typecheck($3); $$=createTree(0,NULL,NULL,READOP,$3,NULL,NULL);}	
			;

OutputStmt : WRITE '(' expr ')' ';' {$$=createTree(0,NULL,NULL,WRITEOP,$3,NULL,NULL);};

AsgStmt : Iden ASSIGN expr ';' {typecheck($1); $$=createTree(0,NULL,NULL,ASS,$1,NULL,$3);};

IfStmt : IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';' {$$=createTree(0,NULL,NULL,IFSTMT,$3,$6,$8);}
	| IF '(' expr ')' THEN Slist ENDIF ';' {$$=createTree(0,NULL,NULL,IFSTMT,$3,$6,NULL);}
	;
	
WhileStmt : WHILE '(' expr ')' DO Slist ENDWHILE ';' {$$=createTree(0,NULL,NULL,WHILESTMT,$3,NULL,$6);};

DoWhileStmt : DO Slist WHILE '(' expr ')' ';' { $$=createTree(0,NULL,NULL,DOWHILESTMT,$2,NULL,$5); };

UntilStmt : REPEAT Slist UNTIL expr ';' { $$=createTree(0,NULL,NULL,UNTILSTMT,$2,NULL,$4); };

PlainStmt : BRKP_L ';' 		{$$=createTree(0,NULL,NULL,BRKP,NULL,NULL,NULL);}
	   | BREAK_L ';'	{$$=createTree(0,NULL,NULL,BREAK,NULL,NULL,NULL);}
	   | CONTINUE_L ';'	{$$=createTree(0,NULL,NULL,CONTINUE,NULL,NULL,NULL);}
	   ;

expr :	expr PLUS expr 	  {$$=createTree(0,TLookup("int"),NULL,PLUSOP,$1,NULL,$3);}
	| expr MINUS expr {$$=createTree(0,TLookup("int"),NULL,MINUSOP,$1,NULL,$3);}
	| expr MUL expr   {$$=createTree(0,TLookup("int"),NULL,MULOP,$1,NULL,$3);}
	| expr DIV expr   {$$=createTree(0,TLookup("int"),NULL,DIVOP,$1,NULL,$3);}
	| expr MOD expr   {$$=createTree(0,TLookup("int"),NULL,MODOP,$1,NULL,$3); }
	| '(' expr ')' {$$=$2;}
	| expr LT expr {$$=createTree(0,TLookup("bool"),NULL,LTOP,$1,NULL,$3);}
	| expr GT expr {$$=createTree(0,TLookup("bool"),NULL,GTOP,$1,NULL,$3);}
	| expr LE expr {$$=createTree(0,TLookup("bool"),NULL,LEOP,$1,NULL,$3);}
	| expr GE expr {$$=createTree(0,TLookup("bool"),NULL,GEOP,$1,NULL,$3);}
	| expr EQ expr {$$=createTree(0,TLookup("bool"),NULL,EQOP,$1,NULL,$3);}
	| expr NE expr {$$=createTree(0,TLookup("bool"),NULL,NEOP,$1,NULL,$3);}
	| expr AND_ expr	{ $$=createTree(0,TLookup("bool"),NULL,AND,$1,NULL,$3); }
	| expr OR_ expr	{ $$=createTree(0,TLookup("bool"),NULL,OR,$1,NULL,$3); }
	| NOT_ expr		{ $$=createTree(0,TLookup("bool"),NULL,NOT,$2,NULL,NULL); }
	| NUM {$$=$1;}
	| STRNG {$$=$1;}
	| Iden {$$=$1; typecheck($$);}  //for array variable,pointer variable
	| AMPERCANT Iden { typecheck($2); $$=createTree($2->val,$2->type,$2->varname,ADDR,$2->left,$2->middle,$2->right);  }
	| ID '(' ')' { $$=createTree($1->val, NULL,$1->varname, FUNCTION, NULL, NULL, NULL);  }
	| ID '(' ArgList ')' {  			argcheck($1->varname, $3);
							$$=createTree($1->val, NULL,$1->varname, FUNCTION, $3, NULL, NULL); 
			     }
			     //for dynamic mem allocation
	| NULLTK { $$=createTree(0,TLookup("null"),NULL,NULLNODE,NULL,NULL,NULL); }
	| INITIALIZE '(' ')' { $$=createTree(0,TLookup("int"),NULL,INITNODE,NULL,NULL,NULL); }
	| FREE '(' Iden ')' { typecheck($3); $$=createTree(0,TLookup("int"),NULL,FREENODE,$3,NULL,NULL); }
	| ALLOC '(' ')' { $$=createTree(0,TLookup("null"),NULL,ALLOCNODE,NULL,NULL,NULL); }
	;

ArgList : ArgList ',' expr { $3->middle=$1; $$=$3; }
		| expr { $$=$1; }
		;

//fior arreay and pointer.......
Iden :ID '[' expr ']'  { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->middle,$1->right); }
	| ID '[' expr ']' '[' expr ']' { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->middle,$6);}
	| Id1 { $$=$1; }
	;

Id1 : ID 		  { $$=$1;}
	| MUL ID { $$=createTree($2->val,$2->type,$2->varname,POINTER,$2->left,$2->middle,$2->right);
				free($2); }
	| Field { $$=$1; }
	;
	
Field : ID '.' ID { typecheck($1);  tuple_type_check($1,$3,$$);
					
					
				  }
		| Field '.' ID { tnode *t1; FieldList *f;
						 t1=$1;
						 while(t1->field!=NULL)
							 t1=t1->field;
						 f=FLookup(t1->type,$3->varname);
						 if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type",line,$3->varname,t1->type->name);
							exit(1);
						 }
						 t1->nodetype=FIELD;
						 t1->field=$3;
						 $3->type=f->type;
						 $3->val=f->fieldIndex;
						 $1->type=$3->type;
						 $$=$1;
						 }
		;
%%

int yyerror(char const *s){
	fprintf(stderr,"error, %d : %s\n",line,s);
	return 1;
}






void addfield(){
	FieldList *tmp=fieldlist;
	while(tmp!=NULL){
		if(!strcmp(tmp->name,field->name)){
			yyerror("Field Redeclared in type declaration");
			exit(1);
		}
		tmp=tmp->next;
	}
	field->fieldIndex=fieldlist->fieldIndex+1; 
	field->next=fieldlist; 
	fieldlist=field;
	field=NULL;
}
void type_table_configure(char *name)
{
								  TypeTable *type_table=TLookup(name);
								  //fieldcheck(fieldlist);
								  type_table->fields=fieldlist;
								  fieldlist=NULL;
								  type_table->size=getSize(type_table);

}
void function_call(tnode *t,char *name)
{
											if(strcmp(name,"main")!=0)
											paramcheck(name);
											print_local_table();
											CodeGenerate(t, name);
											Lsymbol_table=NULL;
											local_binding=1;
											paramlist=NULL;
}
void tuple_type_check (tnode *t,tnode *q,tnode * r)
{
	if(t->type==TLookup("tuple")){
		Gsymbol *p= GLookup(t->varname);
		TupleList *list= p->tuplelist;
		while(list!=NULL){
				if(!strcmp(list->name,q->varname)){
					t->type=list->type;
					t->nodetype=TUPLEFIELD;
					t->tuplefield=q;
					r=t;
					break;
					}
				list=list->next;
				}
		if(list==NULL){
				yyerror("Invalid  Attribute for tuple type");
				exit(1);
			       }
								
	}
	else{
		FieldList *f;
		if(t->type==TLookup("int") || t->type==TLookup("str")){
		    yyerror("invalid field access");
		    exit(1);
		}
		f=FLookup(t->type,q->varname);
		if(f==NULL){
			    fprintf(stderr,"error, %d: No field named %s in %s type",line,q->varname,t->type->name);
			    exit(1);
		           }
			t->nodetype=FIELD;
			t->field=q;
			q->type=f->type;
			q->val=f->fieldIndex;
			t->type=q->type;
			r=t;
					}

}
int main(int argc, char *argv[]){
	
	extern int reg;
	char ch;
	if(argc==3){
		yyin=fopen(argv[1],"r");
		out=fopen(argv[2],"w+");
	}else if(argc==2){
		yyin=stdin;
		out=fopen(argv[1],"w+");
	}
	else{
		yyin=stdin;
		out=stdout;
	}
	reg=0;
	xsm_file=fopen(".xsm_file","w");
	TypeTableCreate();
	yyparse();
	generateCode();
	
	
	fclose(xsm_file);
	xsm_file=fopen(".xsm_file","r");
	while((ch=fgetc(xsm_file))!=EOF){
		fputc(ch, out);
	}
	fclose(out);
	fclose(yyin);
	
	return 0;
}

