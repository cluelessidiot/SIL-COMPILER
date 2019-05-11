void createSymbolTableEntry(tnode *);
void createLsymbolEntries(struct param_struct *);
void addfield();


void createLsymbolEntries(struct param_struct *p){
	struct param_struct *tmp;
	int binding=-2;
	tmp=p;
	while(tmp!=NULL){
		tmp=tmp->next;
		binding--;
	}
	while(p!=NULL){
		LInstall(p->name, p->type,binding, p->pointer);
		binding=binding+1;
		p=p->next;
	}
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
		GInstall(t->varname,currtype,r*c,r,c,NULL,-1);
		//printf("%s %d\n",t->varname,t->nodetype);
		p=GLookup(t->varname);
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
