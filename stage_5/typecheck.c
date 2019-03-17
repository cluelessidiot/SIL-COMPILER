void typecheck(struct tnode *t){
	
	switch(t->nodetype){
		case PLUSOP:
		case MINUSOP:
		case DIVOP:
		case MULOP:
			if((t->left->type != TLookup("int")) || (t->right->type != TLookup("int"))){
				yyerror("Type Mismatch - Expected Integer");
				exit(1);
			}
			break;
		
		case GEOP:
		case LEOP:
		case GTOP:
		case LTOP:
		case EQOP:
		case NEOP:
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
			if(t->left->type != t->right->type){
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
			p=Lookup(t->varname);
			if(p==NULL){
				yyerror("Undeclared Function");
				exit(1);
			}
			t->type=p->type;
			t->Gentry=p;
			break;
		}
	}
}
		
