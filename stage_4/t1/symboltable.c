struct Gsymbol* GLookup(char * name)
{
    struct Gsymbol *temp;
    
    temp  = Ghead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {  //printf("%s",temp->name);
    	temp = temp -> next;
    }
	return temp;
}
int linect =0;	
//installing of symbol table...........
void Install(char *name, int type, int size){
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
	newnode->binding=SP+size;
	SP=SP+size;
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
 {   printf("varname	type	size	bind\n");
    while(temp!=NULL)
    { 
      printf("%s	%d	%d	%d\n",temp->name,temp->type,temp->size,temp->binding);
    temp=temp->next;
    }
 
 }

}

