//definitions for tnode.type
#define INTEGER 1
#define STRING 2
#define BOOL 3
#define NOTYPE 4
#define INTEGER_PTR 5
#define STRING_PTR 6

//definitions for tnode.nodetype
#define VAR 1
#define CONS 2
#define OP 3
#define ASS 4
#define WRITEOP 5
#define READOP 6
#define CONN 7
#define PLUSOP 8
#define MINUSOP 9
#define DIVOP 10
#define MULOP 11
#define LTOP 12
#define LEOP 13
#define GTOP 14
#define GEOP 15
#define EQOP 16
#define NEOP 17
#define IFSTMT 18
#define WHILESTMT 19
#define BREAK 20
#define CONTINUE 21
#define BRKP 22
#define DOWHILESTMT 23
#define UNTILSTMT 24
#define DECLSTMT 25
#define ADDR 26
#define POINTER 27
#define TYPE 28
#define FUNCTION 29
#define RET 30
#define AND 31
#define OR 32
#define NOT 33
#define TUPLEFIELD 34
#define FIELD 35
#define ALLOCNODE 36
#define FREENODE 37
#define INITNODE 38
#define NULLNODE 39
#define MODOP 40
#define NEWNODE 41
#define CLASSNODE 42
#define FIELDFUNCTION 43

//macros used in codegen for loop type
#define NOLOOP 0
#define WHILELOOP 1
#define DOWHILELOOP 2
#define UNTILLOOP 3

#define reg_index int


typedef struct TypeTable {
	char *name;
	int size;
	struct FieldList *fields;
	struct TypeTable *next;
} TypeTable;


struct param_struct {
	//int type;
	TypeTable *type;
	char *name;
	int pointer;
	int binding;
	struct param *next;
} ;

#define TupleList struct param_struct

typedef struct FieldList {
	char *name;
	int fieldIndex;
	struct TypeTable *type;
		struct ClassTable *ctype;
	struct FieldList *next;
} FieldList;


typedef struct tnode{
	int val;
	//int type;
	TypeTable *type;
		struct ClassTable *ctype;
	char *varname;
	int nodetype;
	struct Gsymbol *Gentry;
	struct tnode *left, *middle, *right, *tuplefield, *field;
}tnode;

typedef struct Gsymbol {
	char *name;
	//int type;
	TypeTable *type;
	struct ClassTable *ctype;
	int size;
	int binding;
	int pointer;
	TupleList *tuplelist; //same as param
	char *tuplename;
	struct Gsymbol *next;
	int rows, cols;
	struct param_struct *paramlist;
	int flabel;
	
} Gsymbol;
typedef struct Lsymbol {
	char *name;
	//int type;
	TypeTable *type;
	int size;
	int binding;
	int pointer;
	TupleList *tuplelist;
	char *tuplename;
	struct Lsymbol *next;
} Lsymbol;
 struct  ClassTable {
	char *name;
	struct FieldList *memberfield;
	struct MemberFuncList *vfuncptr;
	 struct ClassTable *parent;
	int class_index;
	int fieldcount;
	int methodcount;
	 struct ClassTable *next;
} ;
typedef struct MemberFuncList {
	char *name;
	struct TypeTable *type;
	struct param *paramlist;
	int funcposition;
	int flabel;
	struct MemberFuncList *next;
} MemberFuncList;

