struct tnode* makeLeafNode(char *str){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->str = str;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}

void evaluate(struct tnode *t){
	if(t==NULL)
		return;
	if(t->op==NULL){
		printf("%s ",t->str);
	}
	else{
		printf("%s ",t->op);
		evaluate(t->left);
		evaluate(t->right);
	}
}
