struct Gsymbol* GLookup(char * name)
{
    struct Gsymbol *temp;
    
    temp  = Ghead;
    if(temp!=NULL)
   
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {  
    	temp = temp -> next;
    	//if(temp!=NULL)
    	//printf("inside Glook %s %s\n",temp->name,name);
    }
	return temp;
}

struct Lsymbol *LLookup(char *name)
{
    struct Lsymbol *temp;
    temp  = Lhead;
    while(temp != NULL && (strcmp(temp -> name,name)!= 0))
    {
    	temp = temp -> next;
    }
	return temp;
}

void LInstall(char *name,int type,int binding)
{
    struct Lsymbol *temp;
    temp = (struct Lsymbol *) malloc(sizeof(struct Lsymbol));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> next = NULL;
    totalCount++;
    temp -> binding = totalCount;
     if(binding<0)
          { temp -> binding =binding;
           totalCount--;  //parameter binded to address.....
          }

    if(Lhead != NULL)
    {
    	Ltail -> next = temp;
        Ltail = temp; 
    }
    else
    {
    	Lhead = temp;
    	Ltail = temp;
    }
    return;
}
void initialize_lsymbol_table()
{
   

}

struct Paramstruct* PLookup(char* name,struct Paramstruct* Phead)
{
   struct Paramstruct *temp;
    temp  = Phead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void PInstall(char* name,int type,int binding)
{
    struct Paramstruct *temp;
    temp = (struct Paramstruct *) malloc(sizeof(struct Paramstruct));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> next = NULL;

    if(Phead == NULL)
    {
        Phead = temp;
        Ptail = temp;
    }
    else
    {
        Ptail -> next = temp;
        Ptail = Ptail -> next;
    }
    return;
}
void check_param_eqvlnce(struct Paramstruct* Phead,struct Paramstruct* Gfunct)
{ if(Phead==NULL && Gfunct==NULL)
   return;
  while(strcmp(Phead->name,Gfunct->name)==0 && Phead->type==Gfunct->type)
  {   
     Phead=Phead->next;
     Gfunct=Gfunct->next;
   
     if(Phead==NULL && Gfunct==NULL)
     {
           return;
     }
     if(Phead==NULL)
     {
      printf("function declaration isnt complete\n");
      exit(1);
     }
     if(Gfunct==NULL)
     {
      printf("function declaration is exceeded\n");
      exit(1);
     }
  }
  if(strcmp(Phead->name,Gfunct->name)!=0)
  printf("error: %s used instead %s\n",Phead->name,Gfunct->name);
  if(Phead->type!=Gfunct->type)
  if(Phead->type==INTEGER)
  printf("error:  int type used for variable %s instead str ",Phead->name);
  else
  printf("error:  string type used for variable %s instead int ",Phead->name);
  exit(1);
}

int linect =0;	
//installing of symbol table...........
void Install(char *name, int type, int size,int row,int column,struct Paramstruct* ParamList,int flabel){

	struct Gsymbol *newnode;
	if(GLookup(name)!=NULL){
		fprintf(stderr,"error , %d : %s redefined\n",linect,name);
		exit(1);
	}
	if(type==NOTYPE){
		fprintf(stderr,"error , %d : Undefined type for %s \n",linect,name);
		exit(1);
	}
	newnode=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	newnode->next=NULL;
	newnode->name=(char*)malloc(sizeof(name));
	strcpy(newnode->name,name);
	newnode->type=type;
	newnode->size=size;
	newnode->row=row;
	newnode->column=column;
	
	if(ParamList==NULL)
	{
	newnode->binding=SP;
	SP=SP+size;
	newnode->paramlist=NULL;
	newnode->flabel=-1;
	}
	else
	{
	newnode->binding=0;
	newnode->paramlist=ParamList;
	newnode->flabel=F_label;
	
	F_label++;
	
	
	}
	if(Ghead==NULL)
	{
	 Ghead=Gtail=newnode;
	
	}
	else
	{
	Gtail->next=newnode;
	}
	Gtail=newnode;
	return;
}

void PrintSymbolTable()
{
struct Gsymbol *temp=Ghead;
if(temp==NULL)
   {
   printf("Symbol table is empty");
   return;
   }
else
 {   printf("varname	type	size	bind	row	column \n");
    while(temp!=NULL)
    { 
      printf("%s	%d	%d	%d	%d	%d\n",temp->name,temp->type,temp->size,temp->binding,temp->row,temp->column);
      if(temp->paramlist!=NULL)
          {  printf("Flabel of function is %d\n",temp->flabel);
            printf("parameter of function %s\n",temp->name);
            struct Paramstruct *tmp=temp->paramlist;
            printf("-----------Parametertable---------------\n");
            printf("name	type	  size	\n");
            while(tmp!=NULL)
            {
             printf("%s 	%d	 %d\n",tmp->name,tmp->type,tmp->binding);
             tmp=tmp->next;
            }
             printf("-----------end---------------\n");
          }
    temp=temp->next;
    }
 
 }

}
void print_local_table()
{
struct Lsymbol *tmp=Lhead;
            printf("-----------Local Symbol table---------------\n");
            printf("name	type	  size	\n");
            while(tmp!=NULL)
            {
             printf("%s 	%d	 %d\n",tmp->name,tmp->type,tmp->binding);
             tmp=tmp->next;
            }
             printf("-----------end---------------\n");

}
void function_call_verify(struct tnode* tno,struct Gsymbol* t)
{
	if(t==NULL){
		yyerror("Undeclared Function");
		exit(1);
	}
		while(tno!=NULL && t!=NULL){
		if(tno->type != t->type){
			yyerror("Argument type mismatch with definition");
			exit(1);
		}
		if(tno->nodetype==POINTER){
			if(!(tno->nodetype==AMPER)){ //&& !(tno->nodetype== NODE_VAR && tno->Gentry->pointer==1
				yyerror("Arguments type mismatch with definition pointer declaration");
				exit(1);
			}
		}
		tno=tno->mid;
		t=t->next;
	}

}

