void argcheck(char *, tnode *);
void paramcheck(char *);
void addParam(struct param_struct *);
void createParamNode(TypeTable * , char *, int );
void argcheck(char *fname, tnode *t){
	Gsymbol *p;
	tnode *tmp;
	struct param_struct *decl;
	int count1, count2;
	p=GLookup(fname);
	if(p==NULL){
		yyerror("Undeclared Function");
		exit(1);
	}
	tmp=t;
	decl=p->paramlist;
	count1=0;
	while(decl!=NULL){
		count1++;
		decl=decl->next;
	}
	count2=0;
	while(tmp!=NULL){
		count2++;
		tmp=tmp->middle;
	}
	if(count1 != count2){
		yyerror("Arguments count mismatch with function definition");
		exit(1);
	}
	tmp=t;
	decl=p->paramlist;
	
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
void createParamNode(TypeTable *type, char *name, int nodetype){
	struct param_struct *tmp, *newnode;
	newnode=(struct param_struct *)malloc(sizeof(struct param_struct));
	newnode->type=type;
	newnode->name=(char *)malloc((strlen(name)+1)*sizeof(char));
	strcpy(newnode->name,name);
	if(nodetype==POINTER)
		newnode->pointer=1;
	else
		newnode->pointer=0;
	parameter=newnode;
}

void create_param_list(struct param_struct *p){
	if(p==NULL){
		yyerror("parameter error");
		exit(1);
	}
	
	p->next=paramlist;
	paramlist=p;
}
void paramcheck(char *fname){
	Gsymbol *p;
	struct param_struct *decl, *def;
	int count1,count2;
	p=GLookup(fname);
	if(p==NULL){
		yyerror("Undeclared Function");
		exit(1);
	}
	count1=0;
	decl=p->paramlist;
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
	decl=p->paramlist;
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
