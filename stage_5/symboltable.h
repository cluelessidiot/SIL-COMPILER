struct Gsymbol *Ghead=NULL,*Gtail=NULL;
struct Paramstruct *Phead=NULL,*Ptail=NULL;
int parambinding=-2;
struct Lsymbol *Lhead=NULL,*Ltail=NULL;
int funct_open=0;
int SP=4096;
int F_label=1;
//Global variable and Function
struct Gsymbol {
 char* name;
 int type;
 int size;
 int row;
 int column;
 int binding;
 struct Paramstruct *paramlist;
 int flabel;
 struct Gsymbol *next;
 };
struct Paramstruct {
	int type;
	char *name;
	int binding;
	struct param *next;
};
 struct Lsymbol {
	char *name;
	int type;
	int binding;
	struct Lsymbol *next;
};
struct Typetable
{
	char *name;					//type name
	int size;					//size of the type
	struct Fieldlist *fields;	//pointer to the head of fields list
	struct Typetable *next;		// pointer to the next type table entry
};
struct Fieldlist 
{
	char *name;				//name of the field
	int fieldIndex;			//the position of the field in the field list
	struct Typetable *type;	//pointer to type table entry of the field's type
	struct Fieldlist *next;	//pointer to the next field
};
 struct Gsymbol* GLookup(char *name);
 void Install(char *name, int type, int size,int row,int column,struct Paramstruct *ParamList,int flabel);
// struct Lsymbol *LLookup(char *name);
void PInstall(char* name,int type,int binding);
struct Paramstruct* PLookup(char* name,struct Paramstruct* Phead);
void check_param_eqvlnce(struct Paramstruct* Phead,struct Paramstruct* Gfunct);
void initialize_lsymbol_table();
int totalCount=0;
