//#include "arith.h"
//extern int yyparse(void);
int var_array[26];
int regct=0;

reg_index codeGen( struct tnode *t) {
  int x,y,z;
  int l,m,n;
   //printf("inside code gen\n");
   //tnode_print(t);        //for checking correctness.....................................
 switch(t->nodetype){
 
          
	case NODE_READ:                //considering only one small letter var and assigning in top of stack..........
		x=getReg();
		int stackpos;
		stackpos=4096+(*(t->left->varname))-'a';
		backup_stack(x,0);
		xos_call("Read",-1,stackpos,x);
		restore_stack(x,x-1);
		return x;
		break;
	case NODE_WRITE:
		//int stackpos=4096+(t->varname)-'a';
		x=getReg();
		l=codeGen(t->left);
		backup_stack(x,0);
		xos_call("Write",-2,l,x);
		restore_stack(x,x-1);
		freeReg();
		return x;
		break;
	case NODE_CONSTANT:
		x=getReg();
                fprintf(xsm_file,"MOV R%d, %d\n",x,t->val);
		return x;
		break;	
	case NODE_CONN:
		if(t->left)
		    {
		    l= codeGen(t->left);
		    freeReg();
		    
		    }	  	
		if(t->right)
		    {	
		    l= codeGen(t->right);
		    freeReg();		    
		    }
		    return l;
		    break;
	case NODE_VAR:
	
		    x=4096+*(t->varname)-'a';
		    y=getReg();
		    fprintf(xsm_file,"MOV R%d, [%d]\n",y,x);
		    return y;
		    break;
	case NODE_ASSGN:
	//printf("assgn inside\n");
	//printf("dfdfdfd %c",*(t->left->varname));
		    m=codeGen(t->right);
	            x=4096+*((t->left)->varname)-'a';
		    fprintf(xsm_file,"MOV [%d],R%d\n",x,m);
		    return m;
		    break;	     	    	  		  
	case NODE_EX:
	     l=codeGen(t->left);
	     m=codeGen(t->right);
	     switch(*(t->varname)){
	     
	     	case '+':
	     	     fprintf(xsm_file,"ADD R%d, R%d\n",l,m);
     	  	     freeReg();
     		     break;
     	  	case '-':	     
	             fprintf(xsm_file,"SUB R%d, R%d\n",l,m);
     	             freeReg();
     	             break;
     	  	case '*':
     	  	     fprintf(xsm_file,"MUL R%d, R%d\n",l,m);
     	             freeReg();
     	             break;
     	  	case '/':
     	  	     fprintf(xsm_file,"DIV R%d, R%d\n",l,m);
     	  	     freeReg();
     	  	     break;
	     }
	     return l;
	     break;	  
 }

}
//evaluate function......................................
int evaluate(struct tnode* t)
{   int lval,rval;
    int varct;
    switch((t->nodetype))
    {
    	case NODE_CONN:
    	       if(t->left!=NULL)
    	         {
    	         lval= evaluate(t->left);
    	      //   return lval;
    	         }
    	       if(t->right!=NULL)
    	          {
    	          rval=evaluate(t->right);
    	          return rval;
    	          }  
    		break;
    	case NODE_VAR:
    		varct=*(t->varname)-'a';
    		return var_array[varct];
    		break;
    	case NODE_ASSGN:
    		varct=*(t->left->varname)-'a';
    		rval=evaluate(t->right);
    		var_array[varct]=rval;
    		return rval;
    		break;			
    	case NODE_CONSTANT:
    	       return t->val;
    	       break;	
        case NODE_EX:
             switch(*(t->varname)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
       case NODE_READ:
       	     varct=*(t->left->varname)-'a';
       	     scanf("%d",&var_array[varct]);
       	     return var_array[varct];
       	     break;
       case NODE_WRITE: 	     	 	       
    	   //  varct=*(t->varname)-'a';
    	     rval=evaluate(t->left);
       	     printf("%d\n",rval);
       	     return rval;
       	     break;
    }


}
//fumction to check AST.....................................
void tnode_print(struct tnode *t)
{  printf("\n[");
  printf("val %d\n",t->val);
  printf("type %d\n",t->type);
  printf("nodetype %d\n",t->nodetype);
  switch(t->nodetype){
  case 1:
    printf("EXPR\n");
    break;
    case 2:
    printf("ASSGN\n");
    break;
    case 3:
    printf("CONN\n");
    break;
    case 4:
    printf("CONSTANT\n");
    break;
    case 5:
    printf("READ\n");
    break;
    case 6:
    printf("VAR\n");
    break;
    case 7:
    printf("WRITE\n");
    break;
   
  }
  
  if(t->varname!=NULL)
  printf("varname %c\n",*(t->varname));
 printf("]\n");
}
// 
void inorder(struct tnode *t)
{ //printf("inside inorder");
if(t==NULL)
   return;
  inorder(t->left);
  tnode_print(t);
  inorder(t->right);

}
struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r){
    //creating tnode.....
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    //assigning val,type,nodetype
    temp->val=val;
    temp->type=type;
    temp->nodetype=nodetype;
    //mallocing for varname
    if(varname!=NULL)
    {
    temp->varname=(char*)malloc(sizeof(char));
    *(temp->varname)=varname;
    }
    else
    {
    temp->varname=NULL;
    }
    //assigning left and right nodes....
    temp->left = l;
    temp->right = r;
    return temp;
}


/*int evaluate(struct tnode *t){
    if(t->varname == NULL){
      //  printf("%d\n",t->val);
        return t->val;
    }
    else{
        switch(*(t->varname)){
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
}*/
// library call function........
void xos_call(char *arg,int file_handler,int var_pos,int p )
{
   		    fprintf(xsm_file,"MOV R%d, \"%s\"\n",p,arg);
		    fprintf(xsm_file,"PUSH R%d\n",p);
		    fprintf(xsm_file,"MOV R%d, %d\n",p,file_handler);
		    fprintf(xsm_file,"PUSH R%d\n",p);
            if(arg[0]=='R')
		    fprintf(xsm_file,"MOV R%d, %d\n",p,var_pos);
	     if(arg[0]=='R')
                   fprintf(xsm_file,"PUSH R%d\n",p);
		  else
                  fprintf(xsm_file,"PUSH R%d\n",var_pos);
                    fprintf(xsm_file,"PUSH R0\n");
		    fprintf(xsm_file,"PUSH R0\n");
		    fprintf(xsm_file,"CALL 0\n");
		    fprintf(xsm_file,"POP R%d\n",p);
		    fprintf(xsm_file,"POP R0\n");
		    fprintf(xsm_file,"POP R0\n");
		    fprintf(xsm_file,"POP R0\n");
		    fprintf(xsm_file,"POP R0\n");
}
//وَالطَّيِّبٰتُ لِلطَّيِّبِيۡنَ وَالطَّيِّبُوۡنَ لِلطَّيِّبٰتِ
//stack pushing file creation helper function........
void backup_stack(int p,int i)
{
  if(p==i)
     return ;
  fprintf(xsm_file,"PUSH R%d\n",i);
  backup_stack(p,i++);   
}
void restore_stack(int p,int i)
{
  if(i<0)
   return ;
  fprintf(xsm_file,"POP R%d\n",i);
  backup_stack(p,i--);   
}
//getting free registers and allocating.....
int getReg()
{ if(regct<20)
  return regct++;
  else
  {
  printf("Out of Registers..\n"); 
  exit(1);
  }
}
void freeReg()
{if(regct>0)
return regct--;
}
//printing header file......
void header_printer()
{
fprintf(xsm_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n ",0,2056,0,0,0,0,0,0); 
fprintf(xsm_file, "BRKP\n");
fprintf(xsm_file, "MOV SP, 4121\n");
}
//answer printer to stack ..........
void answer_storer()
{
  fprintf(xsm_file, "MOV SP, 4095\n");
  fprintf(xsm_file, "PUSH R%d\n",regct);
 fprintf(xsm_file, "INT 10\n");  

}
void stack_adjust()
{
    fprintf(xsm_file, "MOV SP,5020 \n");
}
