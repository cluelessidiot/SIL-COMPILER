%{
	#include<stdio.h>
	char *file1;
	
	int flag=1;
%}

%%

[0-9]+ {	printf("number"); }


%%

/*int yywrap()
{       //   printf("here in yy wrap");
  	FILE *newfile_pointer;
  	char *file2="input_file_2.l";
  	newfile_pointer = fopen("input_file_2.l","r");
  	if(flag)
  	{       printf("changing to stdin");
  		file1=file2;  
  		yyin = stdin;
    		flag=0;
    		return 0;
  	}
  	else
  		return 1;
}*/

int main()
{
	file1="input_file.l";
         
  	//yyin = fopen("input_file.l","r");
  	yylex();
  	return 1;
}
