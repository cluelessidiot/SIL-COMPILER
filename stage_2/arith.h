//defining constants
#define NODE_EX 1
#define NODE_ASSGN 2
#define NODE_CONN 3
#define NODE_CONSTANT 4
#define NODE_READ 5
#define NODE_VAR 6
#define NODE_WRITE 7
#define reg_index int;
FILE *yyin;
struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r);
void inorder(struct tnode *t);
void tnode_print(struct tnode *t);
int getReg();
void freeReg();
void header_printer();
void answer_storer();	
 FILE *xsm_file;
typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;
	
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
	
/*Make a tnode with opertor, left and right branches set*/
//ruct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
/*To evaluate an expression tree*/
int evaluate(struct tnode *t);
reg_index codeGen( struct tnode *t);

void xos_call(char *arg,int file_handler,int var_pos,int p );
void backup_stack(int p,int i);
void answer_storer();

