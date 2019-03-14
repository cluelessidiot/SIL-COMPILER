struct Gsymbol *Ghead=NULL,*Gtail=NULL;
int SP=4096;
typedef struct Gsymbol {
 char* name;
 int type;
 int row;
 int column;
 int size;
 int binding;
 struct Gsymbol *next;
 }Gsymbol;
 struct Gsymbol* GLookup(char *name);
 void Install(char *name, int type, int size,int rows,int column);


