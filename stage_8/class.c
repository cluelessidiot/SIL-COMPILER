ClassTable *class_table = NULL;
ClassTable *currclass=NULL, *oldclass=NULL, *declclass=NULL;
int class_index=0;

struct ClassTable *CLookup(char *name){
	ClassTable *tmp=class_table;
	if(name==NULL)
		return NULL;
	while(tmp!=NULL){
		if(!strcmp(name,tmp->name))
			return tmp;
		tmp=tmp->next;
	}
	return tmp;
}

struct ClassTable * CInstall(char *name, char *parent){
	ClassTable *p;
	ClassTable *new=(ClassTable *)malloc(sizeof(ClassTable));
	new->name=name;
	//settiong classtable data ...........................
	new->memberfield=NULL;
	new->vfuncptr = NULL;
	new->fieldcount=0;
	new->methodcount=0;
	new->class_index=class_index++;
	new->next=class_table;
	class_table=new;
	p=CLookup(parent);
	new->parent=p;
	//if parent is present...................................
	if(p != NULL){
		MemberFuncList *nvfunc,*tvfunc=NULL,*pvfunc=p->vfuncptr;
		FieldList *nfields,*tfields=NULL,*pfields=p->memberfield;
		//copying parent field and method......................
		new->fieldcount=p->fieldcount;
		new->methodcount = p->methodcount;
		while(pvfunc!=NULL){
			nvfunc=(MemberFuncList *)malloc(sizeof(MemberFuncList));
			nvfunc->name=pvfunc->name;
			nvfunc->type=pvfunc->type;
			nvfunc->paramlist=pvfunc->paramlist;
			nvfunc->funcposition=pvfunc->funcposition;
			nvfunc->flabel=pvfunc->flabel;
			nvfunc->next=NULL;
			if(tvfunc!=NULL)
				tvfunc->next=nvfunc;
			if(new->vfuncptr==NULL)
				new->vfuncptr=nvfunc;
			tvfunc=nvfunc;
			pvfunc=pvfunc->next;
		}
		while(pfields!=NULL){
			nfields=(FieldList *)malloc(sizeof(FieldList));
			nfields->name=pfields->name;
			nfields->fieldIndex=pfields->fieldIndex;
			nfields->type=pfields->type;
			nfields->ctype=pfields->ctype;
			if(tfields!=NULL)
				tfields->next=nfields;
			if(new->memberfield==NULL)
				new->memberfield=nfields;
			tfields=nfields;
			pfields=pfields->next;
		}
	}
		
	return new;
	
}


void Class_Finstall (ClassTable *cptr, char *typename, char *name){
	FieldList *nfield, *field=cptr->memberfield;
	TypeTable *type=NULL;
	ClassTable *ctype=NULL;
	int fieldindex;
	nfield=(FieldList *)malloc(sizeof(FieldList));
	//checking for type....
	type=TLookup(typename);
	ctype=CLookup(typename);
	nfield->name=name;
	//if none exists......
	if(type==NULL && ctype==NULL){
		fprintf(stderr,"error, %d : Undefined type %s for %s\n",line,typename,name);
		exit(1);
	}
	nfield->type=type;
	nfield->ctype=ctype;
	if(field==NULL)
		fieldindex=0;
	else
		fieldindex=field->fieldIndex +1;
	if(ctype!=NULL)	//reserving one more word for class type variable
		fieldindex++;
	nfield->fieldIndex=fieldindex;
	nfield->next=field;
	cptr->memberfield=nfield;
}

int hasSameSignature(param *p1, param *p2){
	while(p1!=NULL && p2!=NULL){
	
		if(p1->type!=p2->type)
			return 0;
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL || p2!=NULL)
		return 0;
	return 1;	
}

void Class_Minstall (ClassTable *cptr, char *name, TypeTable *type, param *paramlist){
	MemberFuncList *nfunc, *tmp, *func=cptr->vfuncptr;
	int funcposition;
	tmp=func;
	while(tmp!=NULL){
		if(!strcmp(tmp->name,name)){
			if(hasSameSignature(paramlist,tmp->paramlist)==1){
				//Overridden method
				tmp->flabel=flabel++;
				tmp->paramlist=paramlist;
				return;
			}
			else{	//Overloading --currently not permitted
				yyerror("Function redefined");
				exit(1);
			}
		}
		tmp=tmp->next;
	}
	
	nfunc=(MemberFuncList *)malloc(sizeof(MemberFuncList));
	if(func==NULL)
		funcposition=0;
	else
		funcposition=func->funcposition +1;
	
	nfunc->funcposition=funcposition;
	nfunc->name=name;
	nfunc->type=type;
	nfunc->paramlist=paramlist;
	nfunc->flabel=flabel++;
	nfunc->next=func;
	cptr->vfuncptr=nfunc;
	
}

