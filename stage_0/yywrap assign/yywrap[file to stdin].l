%{
	#include<stdio.h>
	char *file1;
%}

%%

[0-9]+ 	printf("number");

%%

int yywrap()
{
  	FILE *newfile_pointer;
  	//newfile_pointer = fopen("input_file_2.l","r");
  	if(1)
  	{
  	
  		yyin = stdin;
    		return 0;
  	}
  	
}

int main()
{
	file1="input_file.l";
  	yyin = fopen("input_file.l","r");
  	yylex();
  	return 1;
}
