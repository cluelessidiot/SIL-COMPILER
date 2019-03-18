%{
#include<stdio.h>
#include<stdlib.h>
//program to scan  xsm file  and change corresponding label to address...............

int lineno=1,scan=0,l[100],f[100],n,addr;
FILE *out;
%}
label [LF][0-9]+
jmp "JMP"[ ]+
call "CALL"[ ]+
jz "JZ"[ ]+"R"[0-9]+[ ]*","[ ]*
jnz "JNZ"[ ]+"R"[0-9]+[ ]*","[ ]*
%%
  //first scan store the value in an array[]....and again traverse 
{label}":\n" {	if(scan==0)
			{
			printf("\nline dcdv %d\n",lineno);
		        yyless(yyleng-2);
			n=atoi(yytext+1);
			printf(" reduced%d ",n);
			printf("L%d",n);
			if(yytext[0]=='L')
			        {
				l[n]=2056+(lineno-9)*2;
				printf("l[n]%d  %d\n",n,l[n]);
				}
			else if(yytext[0]=='F')
				{
				f[n]=2056+(lineno-9)*2;
				printf("f[n]%d  %d\n",n,f[n]);
				}
			}
		
	    }

":\n" {;}

({jmp}|{call}|{jz}|{jnz}) {if(scan==1) fprintf(out,"%s",yytext);}

{label} { if(scan==1) {
	  	n=atoi(yytext+1);
	  	if(yytext[0]=='L')
			addr=l[n];
		  else if(yytext[0]=='F')
			addr=f[n];
		  fprintf(out,"%d",addr);
		  printf("\n%c %d %d\n",yytext[0],n,addr);
	  }
	  
	}

[\n] {	if(scan==0) {lineno++;}
	else if(scan==1){
		fprintf(out,"%s",yytext);
		
	     }
     }

. {if(scan==1){
	
	fprintf(out,"%s",yytext);
    }
  }

%%

int yywrap(){
	int i;
	//
	if(scan==0){
		//fseek(yyin,0,0); 
		rewind(yyin);
		scan=1;
		return 0;
	}
	else
		return 1;
}
int main(int argc, char *argv[]){
	
	if(argc!=3){
		fprintf(stderr,"Invalid input files count to label translator\n");
		exit(1);
	}
	yyin=fopen(argv[1],"r");
	out=fopen(argv[2],"w+");
	yylex();
	return 0;
	}
