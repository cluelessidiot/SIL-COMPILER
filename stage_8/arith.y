%{
#include<stdio.h>
#include<stdlib.h>
#include "arith.c"
#define YYSTYPE tnode *
int yyerror(char const *);
int yylex(void);
void createSymbolTableEntry(tnode *);
void createParamNode(TypeTable * , char *, int );
void addParam(param *);
void createLsymbolEntries(param *);
void argcheck(char *, tnode *, param *, int);
void paramcheck(char *);
void addfield();
MemberFuncList *checkMemberFunc(ClassTable *, char *);

%}

%token NUM TXT PLUS MINUS MUL DIV ASSIGN 
%token WRITE READ ID BEGINTK END EQ NE
%token  LT GT LE GE IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE BREAKTK CONTINUETK
%token  BRKPTK REPEAT UNTIL DECL ENDDECL 
%token INT STR ADDRTK MAINTK RETURN ANDTK ORTK NOTTK
%token  TUPLE TYPETK ENDTYPE NULLTK ALLOC INITIALIZE 
%token FREE MOD CLASS ENDCLASS DELETE NEW EXTENDS SELF 
%left PLUS MINUS
%left MUL DIV MOD
%left LT GT LE GE EQ NE
%left NOTTK
%left ANDTK ORTK
%%

Program : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock
		| TypeDefBlock ClassDefBlock GDeclBlock MainBlock
		| TypeDefBlock ClassDefBlock MainBlock
		;

ClassDefBlock : CLASS ClassDefList ENDCLASS { sp++; }
				|  {  }
				;
				
ClassDefList : ClassDefList ClassDef {  }
			  | ClassDef {  }
			  ;
			  
ClassDef : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' { createVfuncTable(); currclass=NULL; };

Cname : ID { currclass=CInstall($1->varname,NULL); free($1); }
	  | ID EXTENDS ID { currclass=CInstall($1->varname, $3->varname); free($1); free($3); }
	  ;
	  
Fieldlists : Fieldlists Fld {  }
			| {  }
			;
			
Fld : ID ID ';' { Class_Finstall(currclass, $1->varname, $2->varname); free($1); free($2); };

MethodDecl : MethodDecl Mdecl {  }
			| Mdecl {  }
			;
			
Mdecl : ID ID '(' ParamList ')' ';' { Class_Minstall(currclass, $2->varname, TLookup($1->varname), paramlist); paramlist=NULL; };

MethodDefns : MethodDefns FDef {  }
			| FDef {  }
			;
			

TypeDefBlock : TYPETK TypeDefList ENDTYPE { printTypeTable(); }
			  | { /*Typedef can be null*/printTypeTable(); }
			  ;
			  
TypeDefList : TypeDefList TypeDef {  }
			 | TypeDef {  }
			 ;
			 
TypeDef : ID '{' {TInstall($1->varname,0,NULL);} FieldDeclList '}' { TypeTable *ttable=TLookup($1->varname);
																	 //fieldcheck(fieldlist);
																	 ttable->fields=fieldlist;
																	 fieldlist=NULL;
																	 ttable->size=getSize(ttable);};

FieldDeclList : FieldDeclList FieldDecl { addfield(); }
				| FieldDecl { field->fieldIndex=0; fieldlist=field; field=NULL; }
				;
FieldDecl : Type ID ';' { field=(FieldList *)malloc(sizeof(FieldList)); field->name=$2->varname; field->type=$1->type; field->next=NULL; };

GDeclBlock : DECL GDeclList ENDDECL { print_symbol_table(); }
			| DECL ENDDECL {  }
			;
			
GDeclList : GDeclList GDecl {  }
	   | GDecl {  }
	   ;

GDecl : Type GidList ';' { currtype=NULL; }
		| Tuple ID '(' ParamList ')' GidList ';' { currtype=NULL; paramlist=NULL; declclass=NULL; }
		;

Tuple : TUPLE { currtype = TLookup("tuple"); declclass=NULL;};

GidList : GidList ',' Gid {  }
		| Gid {  }
		;
		
Gid : Iden { createSymbolTableEntry($1); }
	| Id1 '(' ParamList ')' { Install($1->varname,currtype,0,0,0,paramlist,flabel++); /*currtype=NULL*/; paramlist=NULL;
								if($1->nodetype==POINTER){ Gsymbol *p= Lookup($1->varname); p->pointer=1; }}
	;

FDefBlock : FDefBlock FDef {  }
		  | FDef{  }
		  ;
		  
FDef : Type ID '(' ParamList ')' '{' LDeclBlock Body '}' { //createLsymbolEntries(paramlist);  
															paramcheck($2->varname);
															print_local_table();
															CodeGenerate($8, $2->varname);
															initialize_local_table();
															paramlist=NULL;
															
															};

ParamList : ParamList ',' Param { addParam(parameter); parameter=NULL; }
		  | Param { addParam(parameter), parameter=NULL; }
		  | {  }
		  ;

Param : Type Id1 { createParamNode($1->type,$2->varname,$2->nodetype); currtype=oldtype; };

Type : ID { oldtype=currtype; currtype=TLookup($1->varname);
			oldclass=declclass; declclass=CLookup($1->varname); 
			if(declclass!=NULL){
				$$=createTree(0,NULL,$1->varname,CLASSNODE,NULL,NULL,NULL);
			}else{
				$$=createTree(0,currtype,$1->varname,TYPE,NULL,NULL,NULL);
			}
			};

LDeclBlock : DECL LDeclList ENDDECL { createLsymbolEntries(paramlist);   }
			| DECL ENDDECL { createLsymbolEntries(paramlist);   }
			| { createLsymbolEntries(paramlist);   }
			;
			
LDeclList : LDeclList LDecl {  }
	   | LDecl {   }
	   ;

LDecl : Type IdList ';' { currtype=NULL; };

IdList : IdList ',' Id1 { LInstall($3->varname, currtype,local_binding++, $3->nodetype==POINTER ? 1 : 0); }
		| Id1 { LInstall($1->varname, currtype,local_binding++, $1->nodetype==POINTER ? 1 : 0); }
		;

Body : BEGINTK Slist RetStmt END { $$=createTree(0,NULL,NULL,CONN,$2,NULL,$3); }
	   |  BEGINTK RetStmt END { $$=$2; }
	   ;

RetStmt : RETURN expr ';' { $$=createTree(0,$2->type,NULL,RET, $2, NULL, NULL); };

MainBlock : Type MAINTK '(' ')' '{' LDeclBlock Body '}'  { if($1->type != TLookup("int")){
																yyerror("Function Main expects integer return type");
																exit(1);
															}
														print_local_table();
														CodeGenerate($7, "main");
														initialize_local_table();
														paramlist=NULL;};

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

PlainStmt : BRKPTK ';' 		{$$=createTree(0,NULL,NULL,BRKP,NULL,NULL,NULL);}
	   | BREAKTK ';'	{$$=createTree(0,NULL,NULL,BREAK,NULL,NULL,NULL);}
	   | CONTINUETK ';'	{$$=createTree(0,NULL,NULL,CONTINUE,NULL,NULL,NULL);}
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
	| expr ANDTK expr	{ $$=createTree(0,TLookup("bool"),NULL,AND,$1,NULL,$3); }
	| expr ORTK expr	{ $$=createTree(0,TLookup("bool"),NULL,OR,$1,NULL,$3); }
	| NOTTK expr		{ $$=createTree(0,TLookup("bool"),NULL,NOT,$2,NULL,NULL); }
	| NUM {$$=$1;}
	| TXT {$$=$1;}
	| Iden {$$=$1; typecheck($$);}
	| ADDRTK Iden { typecheck($2); $$=createTree($2->val,$2->type,$2->varname,ADDR,$2->left,$2->middle,$2->right); free($2); }
	| ID '(' ArgList ')' {  argcheck($1->varname, $3, NULL, 0);
							$$=createTree($1->val, NULL,$1->varname, FUNCTION, $3, NULL, NULL); free($1); }
	| NULLTK { $$=createTree(0,TLookup("null"),NULL,NULLNODE,NULL,NULL,NULL); }
	| INITIALIZE '(' ')' { $$=createTree(0,TLookup("int"),NULL,INITNODE,NULL,NULL,NULL); }
	| FREE '(' Iden ')' { typecheck($3); $$=createTree(0,TLookup("int"),NULL,FREENODE,$3,NULL,NULL); }
	| ALLOC '(' ')' { $$=createTree(0,TLookup("null"),NULL,ALLOCNODE,NULL,NULL,NULL); }
	| DELETE '(' Iden ')' { typecheck($3); $$=createTree(0,TLookup("int"),NULL,FREENODE,$3,NULL,NULL); }
	| NEW '(' ID ')' 	{ $$=createTree(0,NULL,NULL,NEWNODE,NULL,NULL,NULL); $$->ctype=CLookup($3->varname); }
	| FieldFunction { $$=$1; }
	;

ArgList : ArgList ',' expr { $3->middle=$1; $$=$3; }
		| { $$=NULL; }
		| expr {$$=$1;}
		;

Iden :ID '[' expr ']'  { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->middle,$1->right); 
				
				 }
	| ID '[' expr ']' '[' expr ']' { $$=createTree($3->val,$1->type,$1->varname,$1->nodetype,$3,$1->middle,$6); //typecheck($$);
									free($1);}
	| Id1 { $$=$1; }
	;

Id1 : ID 		  { $$=$1;}
	| MUL ID { $$=createTree($2->val,$2->type,$2->varname,POINTER,$2->left,$2->middle,$2->right);
				free($2); }
	| Field { $$=$1; }
	;
	
Field : ID '.' ID { typecheck($1);
					if($1->type==TLookup("tuple")){
						Gsymbol *p= Lookup($1->varname);
						TupleList *list= p->tuplelist;
						while(list!=NULL){
							if(!strcmp(list->name,$3->varname)){
								$1->type=list->type;
								$1->nodetype=TUPLEFIELD;
								$1->tuplefield=$3;
								$$=$1;
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
						if($1->type==TLookup("int") || $1->type==TLookup("str")){
							yyerror("invalid field access");
							exit(1);
						}
						f=FLookup($1->type,$3->varname);
						if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type",line,$3->varname,$1->type->name);
							exit(1);
						}
						if($1->ctype !=NULL){
							fprintf(stderr,"error, %d: Cannot access private variable from a class\n",line);
							exit(1);
						}
						$1->nodetype=FIELD;
						$1->field=$3;
						$3->type=f->type;
						$3->val=f->fieldIndex;
						$1->type=$3->type;
						$$=$1;
					}
					
				  }
		| Field '.' ID { tnode *t1; FieldList *f;
						 t1=$1;
						 while(t1->field!=NULL)
							 t1=t1->field;
						 if(t1->ctype!=NULL){
							 fprintf(stderr,"error, %d : Cannot access private variables of a class\n",line);
							 exit(1);
						 }
						 f=FLookup(t1->type,$3->varname);
						 if(f==NULL){
							fprintf(stderr,"error, %d: No field named %s in %s type\n",line,$3->varname,t1->type->name);
							exit(1);
						 }
						 t1->nodetype=FIELD;
						 t1->field=$3;
						 $3->type=f->type;
						 $3->val=f->fieldIndex;
						 $1->type=$3->type;
						 $$=$1;
						 }
		| SELF '.' ID { FieldList *flist;
						//Gsymbol *gs;
						if(currclass==NULL){
							fprintf(stderr,"error, %d:self can only be used inside a class definition\n",line);
							exit(1);
						}
						else
							flist=currclass->memberfield;
						while(flist!=NULL){
							if(!strcmp($3->varname,flist->name))
								break;
							flist=flist->next;
						}
						if(flist==NULL){
							fprintf(stderr,"error, %d:Undeclared variable %s inside the class %s\n",line,$3->varname,currclass->name);
							exit(1);
						}
						$$=createTree(0,NULL,"self",FIELD,NULL,NULL,NULL);
						$$->field=$3;
						$3->val=flist->fieldIndex;
						$3->type=flist->type;
						$3->ctype=flist->ctype;
						$$->type=flist->type;
						$$->ctype=flist->ctype;
						$$->Gentry=(Gsymbol *)LLookup("self");
						}
		;
		
FieldFunction : SELF '.' ID '(' ArgList ')'	{ if(currclass==NULL){ fprintf(stderr,"error %d : self can only be used inside a class definition\n",line); exit(1);}
											  MemberFuncList *mfunc=checkMemberFunc(currclass, $3->varname);
											  $$=createTree(0,NULL,"self",FIELDFUNCTION,NULL,NULL,NULL);
											  $3->type=mfunc->type;
											  argcheck($3->varname, $5, mfunc->paramlist, 1);
											  $$->type=$3->type;
											  $$->ctype=currclass;
											  $$->field=$3;
											  $$->Gentry=(Gsymbol *)LLookup("self");
											  $3->left=$5;}
			  | ID '.' ID '(' ArgList ')' 	{ typecheck($1);
											  MemberFuncList *mfunc=checkMemberFunc($1->ctype, $3->varname);
											  $$=createTree(0,NULL,$1->varname,FIELDFUNCTION,NULL,NULL,NULL);
											  $3->type=mfunc->type;
											  argcheck($3->varname, $5, mfunc->paramlist, 1);
											  $$->type=$3->type;
											  $$->ctype=$1->ctype;
											  $$->field=$3;
											  $$->Gentry=$1->Gentry;
											  $3->left=$5; }
			  | Field '.' ID '(' ArgList ')'{ tnode *tmp;
											  MemberFuncList *mfunc;
											  tmp=$1;
											  tmp=tmp->field;
											  if(tmp->field!=NULL){
												  fprintf(stderr,"error %d : illegal member function access\n",line);
												  exit(1);
											  }
											  mfunc=checkMemberFunc(tmp->ctype, $3->varname);
											  $1->nodetype=FIELDFUNCTION;
											  $$=$1;
											  $3->type=mfunc->type;
											  argcheck($3->varname, $5, mfunc->paramlist, 1);
											  $$->type=$3->type;
											  
											  tmp->field=$3;
											  $3->left=$5;
											}
			  ;
%%

int yyerror(char const *s){
	fprintf(stderr,"error, %d : %s\n",line,s);
	return 1;
}

void createSymbolTableEntry(tnode *t){
		int r=1,c=1, l=1;
		Gsymbol *p;
		if(t->left)
			r=t->left->val;
		if(t->right)
			c=t->right->val;
		if(currtype==TLookup("tuple")){
			TupleList *list=paramlist;
			int size=0;
			while(list!=NULL){
				size++;
				list=list->next;
			}
			r=size;
		}
		if(declclass!=NULL){
			Install(t->varname,currtype,2,r,c,NULL,-1);
		}
		else
			Install(t->varname,currtype,r*c,r,c,NULL,-1);
		//printf("%s %d\n",t->varname,t->nodetype);
		p=Lookup(t->varname);
		if(t->nodetype == POINTER){
			p->pointer=1;
		}
		else
			p->pointer=0;
		
		if(currtype==TLookup("tuple")){
			p->tuplelist=paramlist;
		}
		else
			p->tuplelist=NULL;
		free(t);
}

void createParamNode(TypeTable *type, char *name, int nodetype){
	param *tmp, *newnode;
	newnode=(param *)malloc(sizeof(param));
	newnode->type=type;
	newnode->name=(char *)malloc((strlen(name)+1)*sizeof(char));
	strcpy(newnode->name,name);
	if(nodetype==POINTER)
		newnode->pointer=1;
	else
		newnode->pointer=0;
	parameter=newnode;
}

void addParam(param *p){
	if(p==NULL){
		yyerror("parameter error");
		exit(1);
	}
	p->next=paramlist;
	paramlist=p;
}

void createLsymbolEntries(param *p){
	param *tmp;
	Lsymbol *lsymbol;
	int binding=-2;
	tmp=p;
	while(tmp!=NULL){
		tmp=tmp->next;
		binding--;
	}
	if(currclass!=NULL){
		binding-=2;
		lsymbol=LInstall("self", NULL, binding, 0);
		binding+=2;
	}
	while(p!=NULL){
		lsymbol=LInstall(p->name, p->type,binding, p->pointer);
		binding=binding+1;
		p=p->next;
	}
}

void paramcheck(char *fname){
	Gsymbol *p;
	param *decl,*decl2, *def;
	MemberFuncList *mfunc;
	int count1,count2;
	count1=0;
	if(currclass==NULL){
		p=Lookup(fname);
		if(p==NULL){
			yyerror("Undeclared Function");
			exit(1);
		}
		
		decl2=p->paramlist;
	}else{
		mfunc=currclass->vfuncptr;
		while(mfunc!=NULL){
			if(!strcmp(mfunc->name, fname))
				break;
			mfunc=mfunc->next;
		}
		if(mfunc==NULL){
			fprintf(stderr,"error, %d: Undeclared function %s inside class %s\n",line,fname,currclass->name);
			exit(1);
		}
		decl2=mfunc->paramlist;
	}
	decl=decl2;
	while(decl!=NULL){
		count1++;
		decl=decl->next;
	}
	def=paramlist;
	count2=0;
	while(def!=NULL){
		count2++;
		def=def->next;
	}
	if(count1!=count2){
		yyerror("Parameters count mismatch with declaration");
		exit(1);
	}
	def=paramlist;
	decl=decl2;
	while(def!=NULL && decl!=NULL){
		if(def->type != decl->type || def->pointer!=decl->pointer){
			yyerror("Parameter Type mismatch with declaration");
			exit(1);
		}
		if(strcmp(def->name, decl->name)){
			yyerror("Parameter name mismatch with declaration");
			exit(1);
		}
		def=def->next;
		decl=decl->next;
	}
}

void argcheck(char *fname, tnode *t, param *paramlist, int flag){
	Gsymbol *p;
	tnode *tmp;
	param *decl, *decl2;
	int count1, count2;
	if(flag==0){
		p=Lookup(fname);
		if(p==NULL){
			yyerror("Undeclared Function");
			exit(1);
		}
		decl2=p->paramlist;
	}else
		decl2=paramlist;
	decl=decl2;
	count1=0;
	while(decl!=NULL){
		count1++;
		decl=decl->next;
	}
	count2=0;
	tmp=t;
	while(tmp!=NULL){
		count2++;
		tmp=tmp->middle;
	}
	if(count1 != count2){
		yyerror("Arguments count mismatch with function definition");
		exit(1);
	}
	tmp=t;
	decl=decl2;
	
	while(tmp!=NULL && decl!=NULL){
		if(tmp->type != decl->type){
			yyerror("Argument type mismatch with definition");
			exit(1);
		}
		if(decl->pointer==1){
			if(!(tmp->nodetype==ADDR) && !(tmp->nodetype== VAR && tmp->Gentry->pointer==1)){
				yyerror("Arguments type mismatch with definition pointer declaration");
				exit(1);
			}
		}
		tmp=tmp->middle;
		decl=decl->next;
	}
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

MemberFuncList *checkMemberFunc(ClassTable *class, char *name){
	MemberFuncList *mfunc=NULL;
	if(class==NULL){
		fprintf(stderr,"error, %d : Member functions can only be accessed through class variables\n",line);
		exit(1);
	}
	mfunc=class->vfuncptr;
	while(mfunc!=NULL){
		if(!strcmp(mfunc->name,name))
			break;
		mfunc=mfunc->next;
	}
	if(mfunc==NULL){
		fprintf(stderr,"error, %d : Member function %s not defined inside %s class\n",line,name,class->name);
		exit(1);
	}
	return mfunc;
}
