//#include<string.h>
//#include "data.h"

TypeTable *type_table=NULL;

/*
 * int
 * str
 * bool
 * void
 */

void TypeTableCreate(){
	TypeTable *new;
	int i=0;
	for(i=0;i<6;i++){
	new=(TypeTable *)malloc(sizeof(TypeTable));
	new->name=(char *)malloc(sizeof(char)*6);
	switch(i){
		case 0:
			strcpy(new->name,"int");
			new->size=1;
			break;
		case 1:
			strcpy(new->name,"str");
			new->size=1;
			break;
		case 2:
			strcpy(new->name,"bool");
			new->size=0;
			break;
		case 3:
			strcpy(new->name,"void");
			new->size=0;
			break;
		case 4:
			strcpy(new->name,"null");
			new->size=0;
			break;
		case 5:
			strcpy(new->name,"tuple");
			new->size=0;
			break;
	}
	new->fields=NULL;
	new->next=type_table;
	type_table=new;
	}
}

struct TypeTable *TLookup(char *name){
	TypeTable *tmp;
	tmp=type_table;
	while(tmp!=NULL){
		if(!strcmp(name,tmp->name))
			break;
		tmp=tmp->next;
	}
	return tmp;
}

struct TypeTable *TInstall (char *name, int size, struct FieldList *fields){
	TypeTable *t;
	t=TLookup(name);
	if(t!=NULL){
		yyerror("Multiple declarations of type");
		exit(1);
	}
	t=(TypeTable *)malloc(sizeof(TypeTable));
	t->name=name;
	t->size=size;
	t->fields=fields;
	t->next=type_table;
	type_table=t;
	return t;
}

struct FieldList *FLookup( TypeTable *type, char *name){
	FieldList *fields=NULL;
	fields=type->fields;
	while(fields!=NULL){
		if(!strcmp(name,fields->name))
			break;
		fields=fields->next;
	}
	return fields;
}

int getSize(TypeTable *type){
	int size=0;
	FieldList *f;
	if(!strcmp(type->name,"int") || !strcmp(type->name, "str"))
		return 1;
	
	f=type->fields;
	while(f!=NULL){
		size++;
		f=f->next;
	}
	return size;
}


void printTypeTable(){
	TypeTable *tmp=type_table;
	FieldList *ftmp;
	while(tmp!=NULL){
		printf("%s \t| ",tmp->name);
		ftmp=tmp->fields;
		while(ftmp!=NULL){
			printf("%d: %s %s, ",ftmp->fieldIndex, ftmp->type->name, ftmp->name);
			ftmp=ftmp->next;
		}
		printf("\n");
		tmp=tmp->next;
		
	}
	printf("\n");
}