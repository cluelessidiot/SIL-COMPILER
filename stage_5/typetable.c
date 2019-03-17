#include<symboltable.h>

struct Typetable* TLookup(char* name)
{
   struct Typetable *temp;

    temp  = Thead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}
struct Typetable create()
{
      


}
void TInstall(char* name,int size,struct Fieldlist *fields)
{
    struct Typetable *temp;
    struct Fieldlist *ftemp;
    int counter=0;

    temp = (struct Typetable *) malloc(sizeof(struct Typetable));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> next = NULL;

    if(Thead == NULL)
    {
        Thead = temp;
        Ttail = temp;
    }
    else
    {
        Ttail -> next = temp;
        Ttail = Ttail -> next;
    }

    ftemp = fields;

    while(ftemp != NULL)
    {
    	if(ftemp -> type == TLookup("dummy"))
    	{
    		ftemp -> type = TLookup(name);
    	}

    	ftemp -> fieldIndex = counter++;
    	ftemp = ftemp -> next;

    }
    temp -> fields = fields;
    temp -> size = counter;
    Fhead = NULL;
    Ftail = NULL;
    return;
}


struct Fieldlist* FLookup(char* name,struct Fieldlist *list)
{
    struct Fieldlist *temp;
    temp  = list;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void FInstall(struct Typetable *type,char* name)
{
    struct Fieldlist *temp;
    struct Typetable *temp1;
    temp = (struct Fieldlist *) malloc(sizeof(struct Fieldlist));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
	temp -> type = type;
    temp -> next = NULL;

    if(Fhead == NULL)
    {
        Fhead = temp;
        Ftail = temp;
    }
    else
    {
        Ftail -> next = temp;
        Ftail = Ftail -> next;
    }
    return;
}

