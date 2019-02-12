#define reg_index int;
int getreg();
void freereg();
void header_printer();
void answer_storer();	
 FILE *xsm_file;
typedef struct tnode{
 int val; //value of for the expression tree
 char *op; //indicates the opertor branch
 struct tnode *left,*right; //left and right branches
 }tnode;
	
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
	
/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
/*To evaluate an expression tree*/
int evaluate(struct tnode *t);
reg_index codeGen( struct tnode *t);
