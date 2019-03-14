struct Gsymbol *Ghead=NULL,*Gtail=NULL;
int SP=4096;
struct Gsymbol {
 char* name;
 int type;
 int size;
 int binding;
 struct Gsymbol *next;
 };
 struct Gsymbol* GLookup(char *name);
 void Install(char *name, int type, int size);
