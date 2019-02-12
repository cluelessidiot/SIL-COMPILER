   
     int regct=0;
int getreg()
{ 
  return regct++;
  
}
void freereg()
{
return regct--;
}
void header_printer()
{

 fprintf(xsm_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n ",0,2056,0,0,0,0,0,0); 
fprintf(xsm_file, "BRKP\n");

}
reg_index codeGen( struct tnode *t) {
  
   if(t->left==NULL || t->right == NULL)
        							// printf("\nLEAF%d",t->val);
    
      {
       int p = getreg();
       //printf("MOV R%d, %d\n",p,t->val);

	fprintf(xsm_file,"MOV R%d, %d\n",p,t->val);
	return p;
  }
        							
    else 
    {  //printf("\nfkg");
      int j,k;
         j=codeGen(t->left);
         k=codeGen(t->right);
       //  printf("jk %d %d",j,k);
     if(*(t->op)=='+')    
     {
    
     fprintf(xsm_file,"ADD R%d, R%d\n",j,k);
     	  freereg();
     	  return j;
    }
        if(*(t->op)=='-')    
     {
    
     fprintf(xsm_file,"SUB R%d, R%d\n",j,k);
     	  freereg();
     	  return j;
    } 	
      
          if(*(t->op)=='*')    
     {
    
     fprintf(xsm_file,"MUL R%d, R%d\n",j,k);
     	  freereg();
     	  return j;
    } 	
      
          if(*(t->op)=='/')    
     {
      
     fprintf(xsm_file,"DIV R%d, R%d\n",j,k);
     	  freereg();
     	  return j;
    } 	
       	
      
    }     



}
struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op=NULL;
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;
    if(temp->left==NULL)
       
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
}int evaluate(struct tnode *t){
    if(t->op == NULL){
      //  printf("%d\n",t->val);
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}
