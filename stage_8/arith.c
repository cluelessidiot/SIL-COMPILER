#include<string.h>
#include"data.h"
extern int yyparse(void);
extern int yyerror(char const *s);

#include "type.c"


int reg, line=1, label=0,flabel=1, sp=4095, declflag=0, local_binding=1;
#include "class.c"
TypeTable *currtype=NULL, *oldtype=NULL;
FILE *temp,*yyin,*out;
Gsymbol *symbol_table=NULL;
Lsymbol *Lsymbol_table = NULL;
param *parameter=NULL, *paramlist=NULL;
FieldList *fieldlist=NULL, *field=NULL;

reg_index codeGen(tnode *t);

void initialize_local_table(){
	Lsymbol_table=NULL;
	local_binding=1;
}

struct Lsymbol *LLookup(char *name){
	Lsymbol *tmp=Lsymbol_table;
	while(tmp){
		if(!strcmp(name,tmp->name)){
			return tmp;
		}
		tmp=tmp->next;
	}
	return NULL;
}

struct Lsymbol *LInstall(char *name, TypeTable *type,int binding, int pointer){
	Lsymbol *tmp, *newnode;
	if(LLookup(name)!=NULL){
		fprintf(stderr,"error , %d : %s redefined\n",line,name);
		exit(1);
	}
	if((strcmp("self",name)!=0) && type==NULL){
		fprintf(stderr,"error , %d : Undefined type for %s \n",line,name);
		exit(1);
	}
	newnode = (Lsymbol *)malloc(sizeof(Lsymbol));
	newnode->name=(char *)malloc((strlen(name)+1)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->pointer=pointer;
	newnode->next=Lsymbol_table;
	newnode->binding=binding;
	Lsymbol_table=newnode;
	return newnode;
}


struct Gsymbol *Lookup(char *name){
	Gsymbol *tmp=symbol_table;
	while(tmp){
	    if(!strcmp(name,tmp->name)){
	    	return tmp;
	    }
	    tmp=tmp->next;
	}
	return NULL;
}

void Install(char *name, TypeTable *type, int size, int rows, int cols, struct param *paramlist, int flabel){
	Gsymbol *tmp, *newnode;
	if(Lookup(name)!=NULL){
		fprintf(stderr,"error , %d : %s redefined\n",line,name);
		exit(1);
	}
			
	if(declclass==NULL && type==NULL){
		fprintf(stderr,"error , %d : Undefined type for %s \n",line,name);
		exit(1);
	}
	newnode = (Gsymbol *)malloc(sizeof(Gsymbol));
	tmp=symbol_table;
	symbol_table=newnode;
	newnode->next=tmp;
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->ctype=declclass;
	newnode->size=size;
	if(flabel==-1)
		newnode->binding=sp;
	else
		newnode->binding=-1;
	newnode->rows=rows;
	newnode->cols=cols;
	newnode->paramlist=paramlist;
	newnode->flabel=flabel;
	newnode->pointer=0;
	newnode->tuplelist=NULL;
	newnode->tuplename=NULL;
	sp=sp+size;
}

void print_symbol_table(){
	char *name;
	Gsymbol *tmp=symbol_table;
	printf("Name\t\tType\tSize\tBinding\tFlabel\tPointer\n");
	printf("------------------------------------------------------\n");
	while(tmp){
		if(tmp->type!=NULL)
			name=tmp->type->name;
		else if(tmp->ctype!=NULL)
			name=tmp->ctype->name;
		else{
			name=(char *)malloc(15*sizeof(char));
			strcpy(name,"undefined");
		}
		printf("%s\t\t%s\t%d\t%d\t%d\t%d\n",tmp->name,name,tmp->size,tmp->binding,tmp->flabel,tmp->pointer);
		tmp=tmp->next;
	}
}

void print_local_table(){
	char *name;
	Lsymbol *tmp=Lsymbol_table;
	printf("\nName\tType\tBinding\n");
	printf("--------------------------\n");
	while(tmp){
		if(tmp->type!=NULL)
			name=tmp->type->name;
		else if(currclass!=NULL)
			name=currclass->name;
		else{
			name=(char *)malloc(15*sizeof(char));
			strcpy(name,"undefined");
		}
		printf("%s\t%s\t%d\n",tmp->name,name,tmp->binding);
		tmp=tmp->next;
	}
}	

void typecheck(struct tnode *t){
	
	switch(t->nodetype){
		case PLUSOP:
		case MINUSOP:
		case DIVOP:
		case MULOP:
		case MODOP:
			if((t->left->type != TLookup("int")) || (t->right->type != TLookup("int"))){
				yyerror("Type Mismatch - Expected Integer");
				exit(1);
			}
			break;
		case EQOP:
		case NEOP:{
			if(t->right->type==TLookup("null")){
				if(t->left->type==TLookup("int") || t->left->type==TLookup("str") || t->left->type==TLookup("tuple")){
					yyerror("Invalid comparision between NULL and non user defined type");
					exit(1);
				}
			}
			else if(t->left->type != t->right->type){
				yyerror("Type Mismatch both arguments arguments are expected to be of same type");
				exit(1);
			}
			break;
		}
		case GEOP:
		case LEOP:
		case GTOP:
		case LTOP:
			if(!((t->left->type == TLookup("int"))&&(t->right->type == TLookup("int")))&& !((t->left->type == TLookup("str"))&&(t->right->type == TLookup("str")))){
				yyerror("Type Mismatch - Expected Integer or string on both operands");
				exit(1);
			}
			break;
		case AND:
		case OR:{
			if(t->left->type != TLookup("bool") || t->right->type != TLookup("bool")){
				yyerror("Type mismatch - Expected boolean type");
				exit(1);
			}
			break;
		}
		case NOT:{
			if(t->left->type != TLookup("bool")){
				yyerror("Type Mismatch - NOT expects boolean type");
				exit(1);
			}
			break;
		}
		case ASS:{
			if(t->left->ctype!=NULL){
				/*if(t->right->nodetype==NEWNODE){
					if(t->left->ctype != t->right->ctype){
						yyerror("type mismatch for new function");
						exit(1);
					}
				}*/
				if(t->right->ctype==NULL || t->left->ctype==NULL){
					yyerror("Invalid assignment for class type objects");
					exit(1);
				}
				ClassTable *tmp;
				tmp=t->right->ctype;
				while(tmp!=NULL){
					if(t->left->ctype==tmp)
						break;
					tmp=tmp->parent;
				}
				if(tmp==NULL){
					yyerror("A class variable can only be assigned to object of its descendent types only");
					exit(1);
				}
			}
			else{
				if(t->right->nodetype==NULLNODE || t->right->nodetype==ALLOCNODE){
					if(t->left->type==TLookup("int") || t->left->type==TLookup("str") || t->left->type==TLookup("tuple")){
						yyerror("Invalid assignment to non user defined type variable");
						exit(1);
					}
				}
				else if(t->left->type != t->right->type){
					yyerror("type mismatch for assignment operator");
					//fprintf(stderr,"%s = %s",t->left->type->name,t->right->type->name);
					exit(1);
				}
				if(t->left->nodetype==VAR && t->left->Gentry->pointer==1){
					if(!(t->right->nodetype==ADDR) && !((t->right->nodetype== VAR || t->right->nodetype==FUNCTION) && t->right->Gentry->pointer==1)){
						yyerror("type mismatch : invalid assignment to pointer variable");
						printf("%d %d %d",t->left->Gentry->pointer,t->right->nodetype,t->right->Gentry->pointer);
						exit(1);
					}
				}
			}
			break;}
		case WRITEOP:
			if((t->left->type != TLookup("int")) && (t->left->type != TLookup("str"))){
				yyerror("Invalid argument type to Write() function");
				exit(1);
			}
			break;
		case IFSTMT:
			if(t->left->type != TLookup("bool")){
				yyerror("Invalid expression inside if");
				exit(1);
			}
			break;
		case WHILESTMT:
			if(t->left->type != TLookup("bool")){
				yyerror("Invalid expression inside while");
				exit(1);
			}
			break;
		
		case DOWHILESTMT:
			if(t->right->type != TLookup("bool")){
				yyerror("Invalid expression inside while");
				exit(1);
			}
			break;
		
		case UNTILSTMT:
			if(t->right->type != TLookup("bool")){
				yyerror("Invalid expression after until");
				exit(1);
			}
			break;
		
		case POINTER:	
		case ADDR:
		case VAR: {
			Gsymbol *p;
			TypeTable *type;
			p=(Gsymbol *)LLookup(t->varname);
			if (p==NULL)
				p=Lookup(t->varname);
			//type=TLookup(t->varname);
			if(declflag==0){
			
			if(p==NULL){// && type==NULL){
				yyerror("Undeclared Identifier");
				fprintf(stderr,"\b\t%s\n",t->varname);
				exit(1);
			}
			if(p!=NULL){
			if( (t->left && ((t->left->val) >= (p->rows))) || (t->right && ((t->right->val) >= (p->cols)))){
				yyerror("Array Out of bounds");
				fprintf(stderr,"\b\t%s\n",t->varname);
				exit(1);
			}
			if(t->nodetype==POINTER && p->pointer!=1){
				yyerror("* operator must be on a pointer variable");
				exit(1);
			}
			t->type=p->type;
			t->ctype=p->ctype;
			t->Gentry=p;
			break;
			}}
			else if(declflag == 1){
				if(t->left && (t->left->nodetype != CONS)){
					yyerror("Array size must be a constant");
					exit(1);
				}
				if(t->right && (t->right->nodetype != CONS)){
					yyerror("Array size must be a constant");
					exit(1);
				}
				
			}
			break;
		}
		case TYPE:{
			if(t->type==NULL){
				yyerror("Undeclared Type --typecheck");
				fprintf(stderr,"%s\n",t->varname);
				exit(1);
			}
			break;
		}
		case CLASSNODE:{
			t->ctype=declclass;
			break;
		}
		case FUNCTION:{
			Gsymbol *p;
			p=Lookup(t->varname);
			if(p==NULL){
				yyerror("Undeclared Function");
				exit(1);
			}
			t->type=p->type;
			t->Gentry=p;
			break;
		}
		case FREENODE:{
			if(t->left->type==TLookup("int") || t->left->type==TLookup("str") || t->left->type==TLookup("tuple")){
					yyerror("Free is to be called only on a user defined type variable");
					exit(1);
			}
			break;
		}
		
	}
}
		

struct tnode* createTree(int val, TypeTable *type, char *c,int nodetype, struct tnode *l, struct tnode *m, struct tnode *r){

	tnode *newnode=(tnode *)malloc(sizeof(tnode));
	newnode->val=val;
	newnode->type=type;
	newnode->Gentry=NULL;
	if(c!=NULL){
		newnode->varname=(char *)malloc((strlen(c)+2)*sizeof(char));
		/*if(nodetype==CONS && type==STRING)
			strncpy(newnode->varname ,c+1,strlen(c)-1);
		else*/
			strcpy(newnode->varname,c);
	}else{
		newnode->varname=NULL;
	}
	newnode->nodetype=nodetype;
	newnode->left=l;
	newnode->right=r;
	newnode->middle=m;
	newnode->tuplefield=NULL;
	newnode->field=NULL;
	newnode->ctype=NULL;
	if(nodetype!=VAR && nodetype!=POINTER)// && nodetype!= ADDR)
		typecheck(newnode);
	return newnode;
}

reg_index getReg(){
    if(reg<20)
    	return reg++;
    else{
    	printf("Out of Registers\n");
    	exit(1);
    }
}

void freeReg(){
    if(reg>0){
    	reg--;
    }
}

int getLabel(){
	return label++;
}

void getbinding(reg_index p, tnode *t){
	//printf("\n test %s - %s - %d\n",t->type->name,t->Gentry->name, t->Gentry->binding);
	if(t->Gentry==NULL) printf("null\n");
	if(t->Gentry->binding >= 4095){
		fprintf(temp,"MOV R%d, %d\n",p,t->Gentry->binding);
	}
	else{
		fprintf(temp,"MOV R%d, BP\n",p);
		fprintf(temp,"ADD R%d, %d\n",p,t->Gentry->binding);
	}
}

reg_index getAddr(tnode *t){
	int n=0,factor=1;
	reg_index p,q,r;
	if(t==NULL){
		printf("Null passed to getAddr\n");
	}
	if(t->nodetype == POINTER){ //Pointer type variable.
		p=getReg();
		//fprintf(temp,"MOV R%d, %d\n",p,t->Gentry->binding);
		getbinding(p,t);
		fprintf(temp,"MOV R%d, [R%d]\n",p,p);
		return p;
	}
	if(t->nodetype == TUPLEFIELD){
		int b=0;
		TupleList *list = t->Gentry->tuplelist;
		while(list!=NULL){
			if(!strcmp(list->name,t->tuplefield->varname)){
				break;
			}
			list=list->next;
			b++;
		}
		p=getReg();
		getbinding(p,t);
		fprintf(temp,"ADD R%d, %d\n",p,b);
		return p;
	}
	if(t->nodetype==FIELD){
		int addr;
		tnode *tmp;
		r=getReg();
		getbinding(r,t);
		fprintf(temp,"MOV R%d, [R%d]\n",r,r);
		tmp=t->field;
		while(tmp!=NULL){
			fprintf(temp,"ADD R%d, %d\n",r,tmp->val);
			if(tmp->field!=NULL)
				fprintf(temp,"MOV R%d, [R%d]\n",r,r);
			tmp=tmp->field;
		}
		return r;
	}		
		
	if(t->left){
		p=codeGen(t->left);
		factor=t->Gentry->cols;
		n++;
	}
	if(t->right){
		q=codeGen(t->right);
		n++;
	}
	
	if(n==2){
		fprintf(temp,"MUL R%d, %d\n",p,factor);
		fprintf(temp,"ADD R%d, R%d\n",p,q);
		getbinding(q,t);
		fprintf(temp,"ADD R%d, R%d\n",p,q);
		freeReg();
	}
	else if(n==1){
		q=getReg();
		getbinding(q,t);
		fprintf(temp,"ADD R%d, R%d\n",p,q);
		freeReg();
	}
	else if(n==0){
		p=getReg();
		//fprintf(temp,"MOV R%d, %d\n",p,t->Gentry->binding);
		getbinding(p,t);
	}
		
	return p;
}

reg_index codeGen(tnode *t){
	
	reg_index p,q,r,s;
	int l,m,n,oldloop,oldblabel,oldclabel;
	static int loop=NOLOOP,blabel=-1,clabel=-1;
	switch(t->nodetype){
		case CONN:{
			if(t->left)
			    p=codeGen(t->left);
			    freeReg();
			if(t->right)
			    p=codeGen(t->right);
			    return p;
			break;
		}
		case CONS:{
			p=getReg();
			if(t->type==TLookup("int"))
				fprintf(temp,"MOV R%d, %d\n",p,t->val);
			else if(t->type==TLookup("str"))
				fprintf(temp,"MOV R%d, %s\n",p,t->varname);
			return p;
			break;
		}
		case POINTER:
		case TUPLEFIELD:
		case FIELD:
		case VAR:{
			p=getAddr(t);
			//p=getReg();
			fprintf(temp,"MOV R%d, [R%d]\n",p,p);
			return p;
			break;
		}   
		case ASS:{
			if(t->left->type==TLookup("tuple")){ // For tuple variables
				r=getReg();
				p=getAddr(t->left);
				q=getAddr(t->right);
				l=t->left->Gentry->size;
				m=0;
				while(m<l){
					fprintf(temp,"MOV R%d, [R%d]\n",r,q);
					fprintf(temp,"MOV [R%d], R%d\n",p,r);
					m++;
					if(m<l){
						fprintf(temp,"ADD R%d, 1\n",p);
						fprintf(temp,"ADD R%d, 1\n",q);
					}
				}
				freeReg();
				freeReg();
				return r;
			}
			else if(t->left->ctype!=NULL){ //for class type variables
				if(t->right->nodetype==NEWNODE)
				{
					ClassTable *cclass=t->right->ctype;
					int index=cclass->class_index;
					index=index*8 + 4096;//base address of vfunc table
					p=getAddr(t->left);
					q=codeGen(t->right);
					fprintf(temp,"MOV [R%d], R%d\n",p,q);
					fprintf(temp,"ADD R%d, 1\n",p);
					fprintf(temp,"MOV [R%d], %d\n",p,index);
					freeReg();
					return p;
				}
				else{
					p=getAddr(t->left);
					q=getAddr(t->right);
					r=getReg();
					fprintf(temp,"MOV R%d, [R%d]\n",r,q);
					fprintf(temp,"MOV [R%d], R%d\n",p,r);
					fprintf(temp,"ADD R%d, 1\n",p);
					fprintf(temp,"ADD R%d, 1\n",q);
					fprintf(temp,"MOV R%d, [R%d]\n",r,q);
					fprintf(temp,"MOV [R%d], R%d\n",p,r);
					freeReg();
					freeReg();
					return p;
				}
			}
			// Others
			p=getAddr(t->left);
			q=codeGen(t->right);
			fprintf(temp,"MOV [R%d], R%d\n",p,q);
			freeReg();
			return p;
			break;
		}
		case READOP:{
			
			p=getReg();
			q=getAddr(t->left);
			n=0;
			while(n<p){
			    fprintf(temp,"PUSH R%d\n",n);
		    	n++;
			}
			fprintf(temp,"MOV R%d, \"Read\"\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"MOV R%d, -1\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			//fprintf(temp,"MOV R%d, %d\n",p,l);
			fprintf(temp,"PUSH R%d\n",q);
			freeReg();
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"CALL 0\n");
			fprintf(temp,"POP R%d\n",p);
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			n=p-1;
			while(n>=0){
			    fprintf(temp,"POP R%d\n",n);
		 	    n--;
			}
			return p;
			break;
		}
		case WRITEOP:{
			p=getReg();
			q=codeGen(t->left);
			n=0;
			while(n<p){
		    	    fprintf(temp,"PUSH R%d\n",n);
		    	    n++;
			}
			fprintf(temp,"MOV R%d, \"Write\"\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"MOV R%d, -2\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			//fprintf(temp,"MOV R%d, %d\n",p,l);
			fprintf(temp,"PUSH R%d\n",q);
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"CALL 0\n");
			fprintf(temp,"POP R%d\n",p);
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			n=p-1;
			while(n>=0){
		    	    fprintf(temp,"POP R%d\n",n);
		    	    n--;
			}
			freeReg();
			return p;
			break;
		}
	    case PLUSOP:{
	    	p=codeGen(t->left);
		   	q=codeGen(t->right);
	        fprintf(temp,"ADD R%d, R%d\n",p,q);
	        freeReg();
	        return p;
    	   	break;
    	}
    	case MINUSOP:{
    	   	p=codeGen(t->left);
		   	q=codeGen(t->right);
    	   	fprintf(temp,"SUB R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case MULOP:{
    		p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(temp,"MUL R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case DIVOP:{
    		p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(temp,"DIV R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		} 
		case MODOP:{
			p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(temp,"MOD R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case IFSTMT:{
    	        	l=getLabel();
    	        	p=codeGen(t->left);
    	        	fprintf(temp,"JZ R%d, L%d\n",p,l);
    	        	freeReg();
    	        	q=codeGen(t->middle);
    	        	if(t->right){
    	        		m=getLabel();
    	        		fprintf(temp,"JMP L%d\n",m);
    	        	}
    	        	fprintf(temp,"L%d:\n",l);
    	        	if(t->right){
    	        		freeReg();
    	        		q=codeGen(t->right);
    	        		fprintf(temp,"L%d:\n",m);
    	        	}
    	        	return q;
    	        	break;
		}
    	case WHILESTMT:{
    	        	l=getLabel();
    	        	m=getLabel();
    	        	oldloop=loop;
    	        	oldblabel=blabel;
    	        	oldclabel=clabel;
    	        	loop=WHILELOOP;
    	        	blabel=m;
    	        	clabel=l;
    	        	fprintf(temp,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	fprintf(temp,"JZ R%d, L%d\n",p,m);
    	        	q=codeGen(t->right);
    	        	freeReg();
    	        	fprintf(temp,"JMP L%d\n",l);
    	        	fprintf(temp,"L%d:\n",m);
    	        	loop=oldloop;
    	        	blabel=oldblabel;
    	        	clabel=oldclabel;
    	        	return p;
    	        	break;
		}
    	case DOWHILESTMT:{
    	        	l=getLabel();
    	        	m=getLabel();
    	        	n=getLabel();
    	        	oldloop=loop;
    	        	oldblabel=blabel;
    	        	oldclabel=clabel;
    	        	loop=DOWHILELOOP;
    	        	blabel=n;
    	        	clabel=m;
    	        	fprintf(temp,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	freeReg();
    	        	fprintf(temp,"L%d:\n",m);
    	        	q=codeGen(t->right);
    	        	fprintf(temp,"JNZ R%d, L%d\n",q,l);
    	        	fprintf(temp,"L%d:\n",n);
    	        	loop=oldloop;
    	        	blabel=oldblabel;
    	        	clabel=oldclabel;
    	        	return q;
    	        	break;
		}
    	case UNTILSTMT:{
    	        	l=getLabel();
    	        	m=getLabel();
    	        	n=getLabel();
    	        	oldloop=loop;
    	        	oldblabel=blabel;
    	        	oldclabel=clabel;
    	        	loop=UNTILLOOP;
    	        	blabel=n;
    	        	clabel=m;
    	        	fprintf(temp,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	freeReg();
    	        	fprintf(temp,"L%d:\n",m);
    	        	q=codeGen(t->right);
    	        	fprintf(temp,"JZ R%d, L%d\n",q,l);
    	        	fprintf(temp,"L%d:\n",n);
    	        	loop=oldloop;
    	        	blabel=oldblabel;
    	        	clabel=oldclabel;
    	        	return q;
    	        	break;
		}
    	case EQOP:{
    	        p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        fprintf(temp,"EQ R%d, R%d\n",p,q);
    	        freeReg();
    	        return p;
    	        break;
		}
    	case NEOP:{
    	        p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        fprintf(temp,"NE R%d, R%d\n",p,q);
    	        freeReg();
    	        return p;
    	        break;
		}
    	case LTOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(temp,"LT R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case LEOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(temp,"LE R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case GTOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(temp,"GT R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case GEOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(temp,"GE R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case BRKP:{
    	        	p=getReg();
    	        	fprintf(temp,"BRKP\n");
    	        	return p;
    	        	break;
		}
    	case BREAK:{
    	        	p=getReg();
    	        	if(loop!=NOLOOP)
    	        		fprintf(temp,"JMP L%d\n",blabel);
    	        	return p;
    	        	break;
		}
    	case CONTINUE:{
    	        	p=getReg();
    	        	if(loop!=NOLOOP)
    	        		fprintf(temp,"JMP L%d\n",clabel);
    	        	return p;
    	        	break;
		}
    	case DECLSTMT:{
    	        	p=getReg();
    	        	return p;
    	        	break;
		}
    	case ADDR:{
			p=getAddr(t);
			return p;
			break;
		}
		case FUNCTION:{
			tnode *arg;
			Gsymbol *ptr;
			p=getReg();
			l=0;
			while(l<p){
				fprintf(temp,"PUSH R%d\n",l);
				l++;
			}
			arg=t->left;
			while(arg!=NULL){
				q=codeGen(arg);
				fprintf(temp,"PUSH R%d\n",q);
				freeReg();
				arg=arg->middle;
			}
			fprintf(temp,"PUSH R0\n"); //space for return value.
			ptr=t->Gentry;
			fprintf(temp,"CALL F%d\n",ptr->flabel);
			fprintf(temp,"POP R%d\n",p); // return value.
			arg=t->left;
			r=getReg();
			while(arg!=NULL){
				fprintf(temp,"POP R%d\n",r);
				arg=arg->middle;
			}
			freeReg();
			l=p-1;
			while(l>=0){
				fprintf(temp,"POP R%d\n",l);
				l--;
			}
			return p;
			break;
		}
		case RET:{
			int i;
			p=codeGen(t->left);
			q=getReg();
			fprintf(temp,"MOV R%d, BP\n",q);
			fprintf(temp,"SUB R%d, 2\n",q);
			fprintf(temp,"MOV [R%d], R%d\n",q,p);
			
			//pop local variables
			i=1;
			while(i<local_binding){
				fprintf(temp,"POP R%d\n",p);
				i++;
			}
			freeReg();
			//set bp to old value
			fprintf(temp,"POP BP\n");
			fprintf(temp,"RET\n");
			return p;
		}
		case AND:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			fprintf(temp,"JZ R%d, L%d\n",p,l);
			q=codeGen(t->right);
			fprintf(temp,"JZ R%d, L%d\n",q,l);
			fprintf(temp,"MOV R%d, 1\n",p);
			fprintf(temp,"JMP L%d\n",m);
			fprintf(temp,"L%d:\n",l);
			fprintf(temp,"MOV R%d, 0\n",p);
			fprintf(temp,"L%d:\n",m);
			freeReg();
			return p;
		}
		case OR:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			fprintf(temp,"JNZ R%d, L%d\n",p,l);
			q=codeGen(t->right);
			fprintf(temp,"JNZ R%d, L%d\n",q,l);
			fprintf(temp,"MOV R%d, 0\n",p);
			fprintf(temp,"JMP L%d\n",m);
			fprintf(temp,"L%d:\n",l);
			fprintf(temp,"MOV R%d, 1\n",p);
			fprintf(temp,"L%d:\n",m);
			freeReg();
			return p;
		}
		case NOT:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			fprintf(temp,"JZ R%d, L%d\n",p,l);
			fprintf(temp,"MOV R%d, 0\n",p);
			fprintf(temp,"JMP L%d\n",m);
			fprintf(temp,"L%d:\n",l);
			fprintf(temp,"MOV R%d, 1\n",p);
			fprintf(temp,"L%d:\n",m);
			return p;
		}
		case INITNODE:{
			p=getReg();
			n=0;
			while(n<p){
				fprintf(temp,"PUSH R%d\n",n);
				n++;
			}
			fprintf(temp,"MOV R%d, \"Heapset\"\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"CALL 0\n");
			fprintf(temp,"POP R%d\n",p);
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			n=p-1;
			while(n>=0){
				fprintf(temp,"POP R%d\n",n);
				n--;
			}
			return p;
			break;
		}
		case NEWNODE:
		case ALLOCNODE:{
			p=getReg();
			n=0;
			while(n<p){
				fprintf(temp,"PUSH R%d\n",n);
				n++;
			}
			fprintf(temp,"MOV R%d, \"Alloc\"\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"MOV R%d, 8\n",p);			// Allocating 8 words for each alloc call
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"CALL 0\n");
			fprintf(temp,"POP R%d\n",p);
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			n=p-1;
			while(n>=0){
				fprintf(temp,"POP R%d\n",n);
				n--;
			}
			return p;
			break;
		}
		case FREENODE:{
			p=getReg();
			q=codeGen(t->left);
			n=0;
			while(n<p){
				fprintf(temp,"PUSH R%d\n",n);
				n++;
			}
			fprintf(temp,"MOV R%d, \"Free\"\n",p);
			fprintf(temp,"PUSH R%d\n",p);
			fprintf(temp,"PUSH R%d\n",q);
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"PUSH R0\n");
			fprintf(temp,"CALL 0\n");
			fprintf(temp,"POP R%d\n",p);
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			fprintf(temp,"POP R0\n");
			n=p-1;
			while(n>=0){
				fprintf(temp,"POP R%d\n",n);
				n--;
			}
			freeReg();
			return p;
			break;
		}
		case NULLNODE:{
			p=getReg();
			fprintf(temp,"MOV R%d, 0\n",p);
			return p;
			break;
		}
		case FIELDFUNCTION:{
			tnode *tmp=t;
			MemberFuncList *mfunc;
			p=getReg();
			r=getReg();
			fprintf(temp,"BRKP\n");
			getbinding(p,t);
fprintf(temp,"BRKP\n");
			while(tmp->field->field!=NULL){
				fprintf(temp,"MOV R%d, [R%d]\n",p,p);
				fprintf(temp,"ADD R%d, %d\n",p,tmp->field->val);
				tmp=tmp->field;
			}
			
			if(tmp->ctype ==NULL){
				printf("null, %s\n",tmp->varname);
			}
			mfunc=tmp->ctype->vfuncptr;
			tmp=tmp->field;
			while(mfunc!=NULL){
				if(!strcmp(mfunc->name,tmp->varname))
					break;
				mfunc=mfunc->next;
			}
			fprintf(temp,"BRKP\n");
			fprintf(temp,"MOV R%d, R%d\n",r,p);
			fprintf(temp,"ADD R%d, 1\n",r);
			fprintf(temp,"MOV R%d, [R%d]\n",r,r);// base address of vfunc table
			
			fprintf(temp,"MOV R%d, [R%d]\n",p,p); //getting heap address
			
			// code for FUNCTION
			tnode *arg;
			l=0;
			while(l<p){
				fprintf(temp,"PUSH R%d\n",l);
				l++;
			}
			arg=tmp->left;
			fprintf(temp,"PUSH R%d\n",p); //Pushing self address
			fprintf(temp,"PUSH R%d\n",r); //pushing base address of vfunc table
			while(arg!=NULL){
				q=codeGen(arg);
				fprintf(temp,"PUSH R%d\n",q);
				freeReg();
				arg=arg->middle;
			}
			fprintf(temp,"PUSH R0\n"); //space for return value.
			fprintf(temp,"ADD R%d, %d\n",r,mfunc->funcposition); 	//entry in vfunc table corresponding to that function.
			fprintf(temp,"MOV R%d, [R%d]\n",r,r);			//calling address of the function
			fprintf(temp,"CALL R%d\n",r);
			fprintf(temp,"POP R%d\n",p); // return value.
			arg=tmp->left;
			
			while(arg!=NULL){
				fprintf(temp,"POP R%d\n",r);
				arg=arg->middle;
			}
			fprintf(temp,"POP R%d\n",r); //popping self address
			fprintf(temp,"POP R%d\n",r);
			freeReg();
			l=p-1;
			while(l>=0){
				fprintf(temp,"POP R%d\n",l);
				l--;
			}
			return p;
			break;
		}
	}
	
	return p;
		    
}

void generateCode(){
	
	fprintf(out,"MOV SP, %d\n",sp);
	fprintf(out,"CALL F0\n");
	fprintf(out,"MOV R1, \"Exit\"\nPUSH R1\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n");
	//yyparse();
}

void createVfuncTable(){
	int i, a[8]={-1}, index;
	MemberFuncList *mfunc;
	mfunc=currclass->vfuncptr;
	index=currclass->class_index;
	while(mfunc!=NULL){
		if(mfunc->funcposition < 8)
			a[mfunc->funcposition]=mfunc->flabel;
		mfunc=mfunc->next;
	}
	printf(">>>>> cname %s-----------\n",currclass->name);
	for (i=0;i<8;i++){
		if(a[i]>0)
			fprintf(out,"MOV R0, F%d\n",a[i]);
		fprintf(out,"PUSH R0\n");
		printf("F%d ",a[i]);
	}
	sp+=8;	
	
}

void CodeGenerate(tnode *t, char *fname){
	int i,l;
	i=1;
	if(!strcmp(fname, "main")){
		l=0;
	}else if(currclass!=NULL){
		MemberFuncList *mfunc;
		mfunc=currclass->vfuncptr;
		while(mfunc!=NULL){
			if(!strcmp(mfunc->name,fname))
				break;
			mfunc=mfunc->next;
		}
		l=mfunc->flabel;
	}
	else{
		l=(Lookup(fname))->flabel;
	}
	fprintf(temp,"F%d:\n",l);
	fprintf(temp,"PUSH BP\n");
	fprintf(temp,"MOV BP, SP\n");
	while(i<local_binding){
		fprintf(temp,"PUSH R0\n");
		i++;
	}
	i=codeGen(t);
	freeReg();
	printf("%s -- %d %d\n",fname,i,reg);
	
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
	temp=fopen(".temp","w");
	TypeTableCreate();
	fprintf(out,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	fprintf(out,"MOV SP, %d\n",sp);
	yyparse();
	
	generateCode();
	
	
	fclose(temp);
	temp=fopen(".temp","r");
	while((ch=fgetc(temp))!=EOF){
		fputc(ch, out);
	}
	fclose(out);
	fclose(yyin);
	
	return 0;
}

