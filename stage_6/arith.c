#include<string.h>
#include"arith.h"
#include "dynamic_alloc.c"
extern int yyparse(void);
extern int yyerror(char const *s);

#include "type.c"
int SP=4096, declflag=0, local_binding=1;
int reg, line=1, label=0;
int flabel=1; 
TypeTable *currtype=NULL, *oldtype=NULL;
FILE *xsm_file,*yyin,*out;
Gsymbol *symbol_table=NULL;
Lsymbol *Lsymbol_table = NULL;
struct param_struct *parameter=NULL, *paramlist=NULL;
FieldList *fieldlist=NULL, *field=NULL;

reg_index codeGen(tnode *t);
struct Lsymbol *LLookup(char *name);
struct Lsymbol *LInstall(char *name, TypeTable *type,int binding, int pointer);
struct Gsymbol *GLookup(char *name);
void GInstall(char *name, TypeTable *type, int size, int rows, int cols,struct param_struct *paramlist, int flabel);
void print_symbol_table();
void print_local_table();


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
		case ASS:
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
			break;
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
			p=LLookup(t->varname);
			if (p==NULL)
				p=GLookup(t->varname);
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
		case FUNCTION:{
			Gsymbol *p;
			p=GLookup(t->varname);
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
	if(t->Gentry->binding >= 4095){
		fprintf(xsm_file,"MOV R%d, %d\n",p,t->Gentry->binding);
	}
	else{
		fprintf(xsm_file,"MOV R%d, BP\n",p);
		fprintf(xsm_file,"ADD R%d, %d\n",p,t->Gentry->binding);
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
		//fprintf(xsm_file,"MOV R%d, %d\n",p,t->Gentry->binding);
		getbinding(p,t);
		fprintf(xsm_file,"MOV R%d, [R%d]\n",p,p);
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
		fprintf(xsm_file,"ADD R%d, %d\n",p,b);
		return p;
	}
	if(t->nodetype==FIELD){
		int addr;
		tnode *tmp;
		r=getReg();
		getbinding(r,t);
		fprintf(xsm_file,"MOV R%d, [R%d]\n",r,r);
		tmp=t->field;
		while(tmp!=NULL){
			fprintf(xsm_file,"ADD R%d, %d\n",r,tmp->val);
			if(tmp->field!=NULL)
				fprintf(xsm_file,"MOV R%d, [R%d]\n",r,r);
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
		fprintf(xsm_file,"MUL R%d, %d\n",p,factor);
		fprintf(xsm_file,"ADD R%d, R%d\n",p,q);
		getbinding(q,t);
		fprintf(xsm_file,"ADD R%d, R%d\n",p,q);
		freeReg();
	}
	else if(n==1){
		q=getReg();
		getbinding(q,t);
		fprintf(xsm_file,"ADD R%d, R%d\n",p,q);
		freeReg();
	}
	else if(n==0){
		p=getReg();
		//fprintf(xsm_file,"MOV R%d, %d\n",p,t->Gentry->binding);
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
				fprintf(xsm_file,"MOV R%d, %d\n",p,t->val);
			else if(t->type==TLookup("str"))
				fprintf(xsm_file,"MOV R%d, %s\n",p,t->varname);
			return p;
			break;
		}
		case POINTER:
		case TUPLEFIELD:
		case FIELD:
		case VAR:{
			p=getAddr(t);
			//p=getReg();
			fprintf(xsm_file,"MOV R%d, [R%d]\n",p,p);
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
					fprintf(xsm_file,"MOV R%d, [R%d]\n",r,q);
					fprintf(xsm_file,"MOV [R%d], R%d\n",p,r);
					m++;
					if(m<l){
						fprintf(xsm_file,"ADD R%d, 1\n",p);
						fprintf(xsm_file,"ADD R%d, 1\n",q);
					}
				}
				freeReg();
				freeReg();
				return r;
			}
			// Others
			p=getAddr(t->left);
			q=codeGen(t->right);
			fprintf(xsm_file,"MOV [R%d], R%d\n",p,q);
			freeReg();
			return p;
			break;
		}
		case READOP:{
			
			p=getReg();
			q=getAddr(t->left);
			n=0;
			while(n<p){
			    fprintf(xsm_file,"PUSH R%d\n",n);
		    	n++;
			}
			xos_call_read(p,q,xsm_file);
			
			n=p-1;
			while(n>=0){
			    fprintf(xsm_file,"POP R%d\n",n);
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
		    	    fprintf(xsm_file,"PUSH R%d\n",n);
		    	    n++;
			}
			xos_call_write(p,q,xsm_file);
			
			n=p-1;
			while(n>=0){
		    	    fprintf(xsm_file,"POP R%d\n",n);
		    	    n--;
			}
			freeReg();
			return p;
			break;
		}
	    case PLUSOP:{
	    	p=codeGen(t->left);
		   	q=codeGen(t->right);
	        fprintf(xsm_file,"ADD R%d, R%d\n",p,q);
	        freeReg();
	        return p;
    	   	break;
    	}
    	case MINUSOP:{
    	   	p=codeGen(t->left);
		   	q=codeGen(t->right);
    	   	fprintf(xsm_file,"SUB R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case MULOP:{
    		p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(xsm_file,"MUL R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case DIVOP:{
    		p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(xsm_file,"DIV R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		} 
		case MODOP:{
			p=codeGen(t->left);
		  	q=codeGen(t->right);
    	   	fprintf(xsm_file,"MOD R%d, R%d\n",p,q);
    	   	freeReg();
    	   	return p;
    	   	break;
		}
    	case IFSTMT:{
    	        	l=getLabel();
    	        	p=codeGen(t->left);
    	        	fprintf(xsm_file,"JZ R%d, L%d\n",p,l);
    	        	freeReg();
    	        	q=codeGen(t->middle);
    	        	if(t->right){
    	        		m=getLabel();
    	        		fprintf(xsm_file,"JMP L%d\n",m);
    	        	}
    	        	fprintf(xsm_file,"L%d:\n",l);
    	        	if(t->right){
    	        		freeReg();
    	        		q=codeGen(t->right);
    	        		fprintf(xsm_file,"L%d:\n",m);
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
    	        	fprintf(xsm_file,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	fprintf(xsm_file,"JZ R%d, L%d\n",p,m);
    	        	q=codeGen(t->right);
    	        	freeReg();
    	        	fprintf(xsm_file,"JMP L%d\n",l);
    	        	fprintf(xsm_file,"L%d:\n",m);
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
    	        	fprintf(xsm_file,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	freeReg();
    	        	fprintf(xsm_file,"L%d:\n",m);
    	        	q=codeGen(t->right);
    	        	fprintf(xsm_file,"JNZ R%d, L%d\n",q,l);
    	        	fprintf(xsm_file,"L%d:\n",n);
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
    	        	fprintf(xsm_file,"L%d:\n",l);
    	        	p=codeGen(t->left);
    	        	freeReg();
    	        	fprintf(xsm_file,"L%d:\n",m);
    	        	q=codeGen(t->right);
    	        	fprintf(xsm_file,"JZ R%d, L%d\n",q,l);
    	        	fprintf(xsm_file,"L%d:\n",n);
    	        	loop=oldloop;
    	        	blabel=oldblabel;
    	        	clabel=oldclabel;
    	        	return q;
    	        	break;
		}
    	case EQOP:{
    	        p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        fprintf(xsm_file,"EQ R%d, R%d\n",p,q);
    	        freeReg();
    	        return p;
    	        break;
		}
    	case NEOP:{
    	        p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        fprintf(xsm_file,"NE R%d, R%d\n",p,q);
    	        freeReg();
    	        return p;
    	        break;
		}
    	case LTOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(xsm_file,"LT R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case LEOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(xsm_file,"LE R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case GTOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(xsm_file,"GT R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case GEOP:{
    	        	p=codeGen(t->left);
		    	q=codeGen(t->right);
    	        	fprintf(xsm_file,"GE R%d, R%d\n",p,q);
    	        	freeReg();
    	        	return p;
    	        	break;
		}
    	case BRKP:{
    	        	p=getReg();
    	        	fprintf(xsm_file,"BRKP\n");
    	        	return p;
    	        	break;
		}
    	case BREAK:{
    	        	p=getReg();
    	        	if(loop!=NOLOOP)
    	        		fprintf(xsm_file,"JMP L%d\n",blabel);
    	        	return p;
    	        	break;
		}
    	case CONTINUE:{
    	        	p=getReg();
    	        	if(loop!=NOLOOP)
    	        		fprintf(xsm_file,"JMP L%d\n",clabel);
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
				fprintf(xsm_file,"PUSH R%d\n",l);
				l++;
			}
			arg=t->left;
			while(arg!=NULL){
				q=codeGen(arg);
				fprintf(xsm_file,"PUSH R%d\n",q);
				freeReg();
				arg=arg->middle;
			}
			fprintf(xsm_file,"PUSH R0\n"); //space for return value.
			ptr=t->Gentry;
			fprintf(xsm_file,"CALL F%d\n",ptr->flabel);
			fprintf(xsm_file,"POP R%d\n",p); // return value.
			arg=t->left;
			r=getReg();
			while(arg!=NULL){
				fprintf(xsm_file,"POP R%d\n",r);
				arg=arg->middle;
			}
			freeReg();
			l=p-1;
			while(l>=0){
				fprintf(xsm_file,"POP R%d\n",l);
				l--;
			}
			return p;
			break;
		}
		case RET:{
			int i;
			p=codeGen(t->left);
			q=getReg();
			fprintf(xsm_file,"MOV R%d, BP\n",q);
			fprintf(xsm_file,"SUB R%d, 2\n",q);
			fprintf(xsm_file,"MOV [R%d], R%d\n",q,p);
			
			//pop local variables
			i=1;
			while(i<local_binding){
				fprintf(xsm_file,"POP R%d\n",p);
				i++;
			}
			freeReg();
			//set bp to old value
			fprintf(xsm_file,"POP BP\n");
			fprintf(xsm_file,"RET\n");
			return p;
		}
		case AND:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			fprintf(xsm_file,"JZ R%d, L%d\n",p,l);
			q=codeGen(t->right);
			fprintf(xsm_file,"JZ R%d, L%d\n",q,l);
			fprintf(xsm_file,"MOV R%d, 1\n",p);
			fprintf(xsm_file,"JMP L%d\n",m);
			fprintf(xsm_file,"L%d:\n",l);
			fprintf(xsm_file,"MOV R%d, 0\n",p);
			fprintf(xsm_file,"L%d:\n",m);
			freeReg();
			return p;
		}
		case OR:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			fprintf(xsm_file,"JNZ R%d, L%d\n",p,l);
			q=codeGen(t->right);
			fprintf(xsm_file,"JNZ R%d, L%d\n",q,l);
			fprintf(xsm_file,"MOV R%d, 0\n",p);
			fprintf(xsm_file,"JMP L%d\n",m);
			fprintf(xsm_file,"L%d:\n",l);
			fprintf(xsm_file,"MOV R%d, 1\n",p);
			fprintf(xsm_file,"L%d:\n",m);
			freeReg();
			return p;
		}
		case NOT:{
			l=getLabel();
			m=getLabel();
			p=codeGen(t->left);
			not(l,m,p,xsm_file);
			return p;
		}
		case INITNODE:{
			p=getReg();
			n=0;
			while(n<p){
				fprintf(xsm_file,"PUSH R%d\n",n);
				n++;
			}
			initialize(p,xsm_file);
			n=p-1;
			while(n>=0){
				fprintf(xsm_file,"POP R%d\n",n);
				n--;
			}
			return p;
			break;
		}
		case ALLOCNODE:{
			p=getReg();
			n=0;
			while(n<p){
				fprintf(xsm_file,"PUSH R%d\n",n);
				n++;
			}
			 alloc(p,xsm_file);
			
			n=p-1;
			while(n>=0){
				fprintf(xsm_file,"POP R%d\n",n);
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
				fprintf(xsm_file,"PUSH R%d\n",n);
				n++;
			}
			freenode(p,q,xsm_file);
			
			n=p-1;
			while(n>=0){
				fprintf(xsm_file,"POP R%d\n",n);
				n--;
			}
			freeReg();
			return p;
			break;
		}
		case NULLNODE:{
			p=getReg();
			fprintf(xsm_file,"MOV R%d, 0\n",p);
			return p;
			break;
		}
	}
	
	return p;
		    
}

void generateCode(){
	fprintf(out,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	fprintf(out,"MOV SP, %d\n",SP);
	fprintf(out,"CALL F0\n");
	fprintf(out,"MOV R1, \"Exit\"\nPUSH R1\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n");
	//yyparse();
}

void CodeGenerate(tnode *t, char *fname){
	int i,l;
	i=1;
	if(!strcmp(fname, "main")){
		l=0;
	}else{
		l=(GLookup(fname))->flabel;
	}
	fprintf(xsm_file,"F%d:\n",l);
	fprintf(xsm_file,"PUSH BP\n");
	fprintf(xsm_file,"MOV BP, SP\n");
	while(i<local_binding){
		fprintf(xsm_file,"PUSH R0\n");
		i++;
	}
	i=codeGen(t);
	freeReg();
	printf("%s -- %d %d\n",fname,i,reg);
	
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
	if(type==NULL){
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


struct Gsymbol *GLookup(char *name){
	Gsymbol *tmp=symbol_table;
	while(tmp){
	    if(!strcmp(name,tmp->name)){
	    	return tmp;
	    }
	    tmp=tmp->next;
	}
	return NULL;
}

void GInstall(char *name, TypeTable *type, int size, int rows, int cols,struct param_struct *paramlist, int flabel){
	Gsymbol *tmp, *newnode;
	if(GLookup(name)!=NULL){
		fprintf(stderr,"error , %d : %s redefined\n",line,name);
		exit(1);
	}
	if(type==NULL){
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
	newnode->size=size;
	if(flabel==-1)
		newnode->binding=SP;
	else
		newnode->binding=-1;
	newnode->rows=rows;
	newnode->cols=cols;
	newnode->paramlist=paramlist;
	newnode->flabel=flabel;
	newnode->pointer=0;
	newnode->tuplelist=NULL;
	newnode->tuplename=NULL;
	SP=SP+size;
}

void print_symbol_table(){
	
	Gsymbol *tmp=symbol_table;
	printf("Name\t\tType\tSize\tBinding\tFlabel\tPointer\n");
	printf("------------------------------------------------------\n");
	while(tmp){
		printf("%s\t\t%s\t%d\t%d\t%d\t%d\n",tmp->name,tmp->type->name,tmp->size,tmp->binding,tmp->flabel,tmp->pointer);
		tmp=tmp->next;
	}
}

void print_local_table(){
		
	Lsymbol *tmp=Lsymbol_table;
	printf("\nName\tType\tBinding\n");
	printf("--------------------------\n");
	while(tmp){
		printf("%s\t%s\t%d\n",tmp->name,tmp->type->name,tmp->binding);
		tmp=tmp->next;
	}
}	


