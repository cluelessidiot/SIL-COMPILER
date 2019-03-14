//#include "arith.h"
//extern int yyparse(void);
int var_array[26];
int regct=0;
int label_ct=0;
int *   p;//

//
//
int getAddr(struct tnode* t)
{  int q,r,s,x,y,z;
   int array_adjuster;
   int two_d_array_flag=0;
   int one_d_array_flag=0;
  // tnode_print(t);
   if(t->nodetype==POINTER)
   {
      q=getReg();
      r=t->Gentry->binding;
      fprintf(xsm_file,"MOV R%d, %d\n",q,r);
      fprintf(xsm_file,"MOV R%d, [R%d]\n",q,q);
      return q;
   }
  
   if(t->left!=NULL)//1d array....................
   {
     // q=getReg();
      s=codeGen(t->left);
      array_adjuster=t->Gentry->column;
      one_d_array_flag=1;
     
   }
   if(t->right!=NULL)
   {
     x=codeGen(t->right);
     two_d_array_flag=1;
   
   }
   if(two_d_array_flag==1)
   {
   		fprintf(xsm_file,"MUL R%d, %d\n",s,array_adjuster);
		fprintf(xsm_file,"ADD R%d, R%d\n",s,x);
		fprintf(xsm_file,"ADD R%d, %d\n",s,t->Gentry->binding);
		freeReg();  //only for right
		return s;
   
   
   }
   else if(one_d_array_flag==1)
   {
       	     
	     fprintf(xsm_file,"ADD R%d, %d\n",s,(t->Gentry)->binding);
	     return s;
   }
   else if(one_d_array_flag==0 && two_d_array_flag==0)
   { q=getReg();
   
     fprintf(xsm_file,"MOV R%d, %d\n",q,t->Gentry->binding);
     return q;
   }
} 		


//
struct label_node* head;
void typecheck(struct tnode *t)
{  
  switch(t->nodetype)
  {
   case NODE_EX:
    		if((t->left->type!=INTEGER) || (t->right->type!=INTEGER))
    			{
    			  yyerror("Type mismatch...Expected integer");
    			  exit(1);
    			  
    			}
    			break;
   case N_EQ:
   case N_NE:
   case N_GE:
   case N_GT:
   case N_LE:
   case N_LT:
    			
  		if((t->left->type!=INTEGER) || (t->right->type!=INTEGER))
    			{
    			  yyerror("Type mismatch...Expected integer for boolean operaion");
    			  exit(1);
    			  
    			}
    			break;
  case NODE_IF:
  case NODE_WHILE:
  		if(t->left->type!=BOOLE)
  		{
  		   yyerror("Type mismatch...Expected boolean type");
    			  exit(1);
  		} 
  		break;
  case NODE_REPEAT:
  case NODE_DOWHILE:
  		if(t->right->type!=BOOLE)
  		{
  		   yyerror("Type mismatch...Expected boolean type");
    			  exit(1);
  		} 
  		break;
  			 			
  case NODE_WRITE:
		if((t->left->type != INTEGER))
		{
		    yyerror("Invalid argument type to Write() function");
		        exit(1);
		}
			break; 
  case NODE_ASSGN:
  
  		if((t->left->type != INTEGER))
		{
		    yyerror("LHS of '=' operator expect integer type");
		    exit(1);  
		} 
 		if((t->right->type != INTEGER))
		{
		    yyerror("RHS of '=' operator expect integer type");
		    exit(1);  
		}
		break;
 case NODE_VAR:
 case POINTER:
 case AMPER:
            //tnode_print(t);
              {if(declrflag==0)
              {
              struct  Gsymbol *temp;
              printf(" inside typecheck var,ptr,amper %s\n",t->varname);
              temp=GLookup(t->varname);
            
              if(temp==NULL)
              {                 printf(" \nvarname %s\n",t->varname);
				yyerror("Undeclared Identifier");
				fprintf(stderr,"\t\t%s\n",t->varname);
				exit(1);
			}		 		
	     if( (t->left) && (t->left->val > temp->row)){
				yyerror("Array Out of bounds");
				fprintf(stderr,"\t\t%s\n",t->varname);
				exit(1);
			}
	    if( (t->right) && (t->right->val > temp->column)){
				yyerror("Array Out of bounds");
				fprintf(stderr,"\t\t%s\n",t->varname);
				exit(1);
			}
			t->type=temp->type;
			t->Gentry=temp;
			}
		
	else
	{  
	if((t->left && (t->left->nodetype != NODE_CONSTANT))|| (t->right && (t->right->nodetype != NODE_CONSTANT))){
					yyerror("Array size must be a constant");
					exit(1);
				}
	
	}
	break;				
  }



}}



reg_index codeGen( struct tnode *t) {
  int x,y,z;
  int l,m,n;
  int label1=0;
  int label2=0;
  int label3=0;
   //printf("inside code gen\n");
   //tnode_print(t);        //for checking correctness.....................................
 switch(t->nodetype){
 
          
	case NODE_READ:                //considering only one small letter var and assigning in top of stack..........
		x=getReg();
		int stackpos;
		stackpos=getAddr(t->left);             //4096+(*(t->left->varname))-'a';
		backup_stack(x,0);
		xos_call("Read",-1,stackpos,x);
		freeReg();
		restore_stack(x,x-1);
		return x;
		break;
	case AMPER:
	        x=getReg();
		fprintf(xsm_file,"MOV R%d, %d\n",x,t->Gentry->binding);
		return x;
		break;	        	
	case NODE_WRITE:
		//int stackpos=4096+(t->varname)-'a';
		x=getReg();
		//printf(" \n\nwirte %d\n\n",x);
		//x=5;
		l=codeGen(t->left);
		backup_stack(x,0);
		xos_call("Write",-2,l,x); //function to generate machine executable........................
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
	case POINTER:
		    //x=4096+*(t->varname)-'a';
		    x=getAddr(t);
		    //y=getReg();
		    fprintf(xsm_file,"MOV R%d, [R%d]\n",x,x);
		    return x;
		    break;
	case NODE_ASSGN:
	//printf("assgn inside\n");
	//printf("dfdfdfd %c",*(t->left->varname));
		    m=codeGen(t->right);
         	    x=getAddr(t->left);
         	    
		    fprintf(xsm_file,"MOV [R%d],R%d\n",x,m);
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
	case N_EQ:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"EQ R%d, R%d\n",l,m);
		freeReg();
		return l;
		break;
	case N_NE:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"NE R%d, R%d\n",l,m);
		freeReg();
		return l;
		break; 
	case N_GT:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"GT R%d, R%d\n",l,m);
		freeReg();
		return l;
		break; 
	case N_GE:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"GE R%d, R%d\n",l,m);
		freeReg();
		return l;
		break; 
	case N_LT:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"LT R%d, R%d\n",l,m);
		freeReg();
		return l;
		break; 
	case N_LE:
		l=codeGen(t->left);
		m=codeGen(t->right);
		fprintf(xsm_file,"LE R%d, R%d\n",l,m);
		freeReg();
		return l;
		break; 										     
	case NODE_IF:
		label1=getLabel();
		l=codeGen(t->left);
		fprintf(xsm_file,"JZ R%d, L%d\n",l,label1);
            	freeReg();
	        m=codeGen(t->mid); 
	        if(t->right!=NULL)
	        {
	         label2=getLabel();
	         fprintf(xsm_file,"JMP L%d\n",label2);
	        }    	  
 	         fprintf(xsm_file,"L%d:\n",label1);
 	        if(t->right!=NULL)
 	        {
 	        freeReg();
 	        m=codeGen(t->right);
 	        fprintf(xsm_file,"L%d:\n",label2);
 	        } 
 	        return m;
 	        break;
 	        
	case NODE_WHILE:
		 label1=getLabel();	        
		 label2=getLabel();
		 label_insert(&head,label2,label1);
		 fprintf(xsm_file,"L%d:\n",label1);
    	         l=codeGen(t->left);
    	         fprintf(xsm_file,"JZ R%d, L%d\n",l,label2);
    	         m=codeGen(t->right);
    	         freeReg();
    	         fprintf(xsm_file,"JMP L%d\n",label1);
    	         fprintf(xsm_file,"L%d:\n",label2);
		 label_pop(&head);
		 return l;
		 break;
		 
      case N_BRKP:
      		x=getReg();
        	fprintf(xsm_file,"BRKP\n");
        	return x;
        	break;
        	
      case N_BREAK:
      		x=getReg();
      		 z=label_pop(&head);
      		fprintf(xsm_file,"JMP L%d\n",z);
      		return x;
      		break;
      	
      case N_CONTINUE: 
      	        x=getReg();
      		int z=head->continue_label_val;
      		fprintf(xsm_file,"JMP L%d\n",z);
      		return x;  
      		break;
      		
      case NODE_DOWHILE:
    	        label1=getLabel();
    	       	label2=getLabel();
    	       	label3=getLabel();
    	        label_insert(&head,label3,label1);
    	        fprintf(xsm_file,"L%d:\n",label1);
    	        l=codeGen(t->left);
    	        freeReg();
    	        fprintf(xsm_file,"L%d:\n",label2);
    	        m=codeGen(t->right);
    	        fprintf(xsm_file,"JNZ R%d, L%d\n",m,label1);
    	        fprintf(xsm_file,"L%d:\n",label3);
    	       	label_pop(&head);
    	       	return m;
    	       	break;
    case NODE_REPEAT:
    	       	label1=getLabel();
    	       	label2=getLabel();
    	        label3=getLabel();
    	        label_insert(&head,label3,label1);
    	       	fprintf(xsm_file,"L%d:\n",label1);
    	        l=codeGen(t->left);
    	        freeReg();
    	       	fprintf(xsm_file,"L%d:\n",label2);
    	        m=codeGen(t->right);
    	       	fprintf(xsm_file,"JZ R%d, L%d\n",m,label1);
    	        fprintf(xsm_file,"L%d:\n",label3);
    	        label_pop(&head);
    	       	return m;
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
       case N_EQ:
		lval=evaluate(t->left);
	        rval=evaluate(t->right);
		return lval==rval;
		break;
		    
 	case N_NE:
		    lval=evaluate(t->left);
		    rval=evaluate(t->right);
		    return lval!=rval;
		    break;
	case N_LT:
		lval=evaluate(t->left);
		rval=evaluate(t->right);
		return lval<rval;
	        break;
		    
	case N_GT:
		lval=evaluate(t->left);
		rval=evaluate(t->right);
		    return lval>rval;
		    break;
		    
	case N_LE:
		lval=evaluate(t->left);
		rval=evaluate(t->right);
		    return lval<=rval;
		    break;
		    
	case N_GE:
	        lval=evaluate(t->left);
		rval=evaluate(t->right);
		    return lval>=rval;
		    break;
	case NODE_IF:
		    lval=evaluate(t->left);
		    if(lval){
		    	evaluate(t->mid);
		    }else{
		    	if(t->right){
		    	    rval=evaluate(t->right);
		    	}
		    }
		    return rval;
		    break;
		
		case NODE_WHILE:
		    while(lval=evaluate(t->left)){
		    	rval=evaluate(t->right);
		    }
		    return rval;
		    break;
       	     
       	     
       	     
    }


}

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *m,struct tnode *r){
    //creating tnode.....
  
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    //assigning val,type,nodetype
    temp->val=val;
    temp->type=type;
    temp->nodetype=nodetype;
    //temp->Gentry=GLookup(varname);
    //mallocing for varname
     //printf("%c",*varname);
   
     if(varname!=NULL && nodetype!=AMPER &&nodetype!=NODE_VAR && nodetype!=POINTER)
     {  
      temp->varname=(char*)malloc(sizeof(char));
      *(temp->varname)=varname;
   
 // strcpy(temp->varname,varname);      
     } 
    else if((varname!=NULL && nodetype==POINTER)||(varname!=NULL && nodetype==NODE_VAR) || (varname!=NULL && nodetype==AMPER))
    {        
          temp->varname=(char *)malloc((strlen(varname)+2)*sizeof(char));
	  strcpy(temp->varname,varname);
	//   Install(temp->varname,current_type,1); 
	 //struct Gsymbol *tmp= GLookup(varname);
	 //temp->Gentry=GLookup(varname);

	
    }
    else
    {
    temp->varname=NULL;
    }
    //assigning left and right nodes....
    temp->left = l;
    temp->right = r;
    temp->mid =m;
    tnode_print(temp);
    typecheck(temp);
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
   		  //  printf("%d",p);
		    fprintf(xsm_file,"PUSH R%d\n",p);
		    fprintf(xsm_file,"MOV R%d, %d\n",p,file_handler);
		    fprintf(xsm_file,"PUSH R%d\n",p);
          //  if(arg[0]=='R')
		//    fprintf(xsm_file,"MOV R%d, %d\n",p,var_pos);
		   if(arg[0]=='R')
                   fprintf(xsm_file,"PUSH R%d\n",var_pos);
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
//stack pushing file creation helper function........

void backup_stack(int p,int i)
{
  if(p==i)
     return ;
  fprintf(xsm_file,"PUSH R%d\n",i);
//  printf("i %d p %d\n",i,p);
  i++;
 backup_stack(p,i);   
}
void restore_stack(int p,int i)
{
  if(i<=0)
   return ;
     //printf("i %d p %d\n",i,p);
     i--;
  fprintf(xsm_file,"POP R%d\n",i);
  restore_stack(p,i);   
}
//getting label 
int getLabel()
{
return label_ct++;
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
fprintf(xsm_file, "MOV SP, %d\n",SP);
}
//answer printer to stack ..........
void answer_storer()
{
  fprintf(xsm_file, "MOV SP, %d\n",SP);
  fprintf(xsm_file, "PUSH R%d\n",regct);
  fprintf(xsm_file, "INT 10\n");
}
void stack_adjust()
{
    fprintf(xsm_file, "MOV SP,5020 \n");
}
//inserting label insert code
void label_insert(struct label_node **head,int break_val,int cont_val)
{
  struct label_node *temp;
  temp=(struct label_node*)malloc(sizeof(struct label_node));
  temp->break_label_val=break_val;
  temp->continue_label_val=cont_val;
  temp->next=*head;
  *head=temp;
}
int label_pop(struct label_node **head)
{
if(*head==NULL)
{
  return -1; 
}
else
{  int temp=(*head)->break_label_val;
   *head=(*head)->next;
   return temp;
}


}
//fumction to check AST.....................................
void tnode_print(struct tnode *t)
{  printf("\n[");
  printf("val %d\n",t->val);
   //printf("varname %s\n",t->varname);
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
    case 8:
    printf("N_GT\n");
    break;
    case 9:
    printf("N_GE\n");
    break;
    case 10:
    printf("N_GT\n");
    break;
    case 11:
    printf("N_GT\n");
    break;
    case 12:
    printf("N_GT\n");
    break;
    case 13:
    printf("N_GT\n");
    break;
    case 14:
    printf("NODE_IF\n");
    break;
    case 15:
    printf("NODE_WHILE\n");
    break;
    case 16:
    printf("NODE_DOWHILE\n");
    break;
    case 17:
    printf("NODE_REPEAT\n");
    break;
    case 18:
    printf("NODE_BREAK\n");
    break;
    case 19:
    printf("NODE_CONTINUE\n");
    break;
    case 20:
    printf("NODE_BRKP\n");
    break;
        case 21:
    printf("NODE_DECL_STMT\n");
    break;
        case 22:
    printf("POINTER\n");
    break;
        case 23:
    printf("AMPER\n");
    break;
  }
  
  if(t->varname!=NULL)
  printf("varname %s\n",t->varname);
 printf("]\n");
}
// 
void inorder(struct tnode *t)
{ printf("inside inorder");
if(t==NULL)
   return;
  inorder(t->left);
  tnode_print(t);
  inorder(t->right);

}
