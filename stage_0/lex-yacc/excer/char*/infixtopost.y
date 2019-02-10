%{
      #include <stdio.h>
      
      int yylex();
   char* joiner(char,char*,char*);
%}
%union{
	char *str;
	//char str;
}
%type <str> CHARS  expr '+' '-'
%token CHARS NEWLINE 
%token '+' '-'
%token '*' '/'
 
%%
start : expr NEWLINE  {  
                        printf("\nComplete%s\n",$1);
                        exit(1);
                      }
  ;

expr:  expr '+' expr { $$=joiner('+',$1,$3);printf("plus %s\n",$$);}
  |expr '-' expr     {$$=joiner('-',$1,$3);printf("minus %s\n",$$);}
  |expr '*' expr     {$$=joiner('*',$1,$3);printf("mul %s\n",$$);}
  |expr '/' expr     {$$=joiner('/',$1,$3);printf("div %s\n",$$);}
  | '(' expr ')'     {$$=$2;}
  | CHARS         {$$=$1;}//printf(" %s ",$1);}
  ;

%%

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
  yyparse();
  return 1;
}
char* joiner(char op,char *a,char *b)
{
    char *x;
    x=(char*)malloc(sizeof(char));
    *x=op;
    //printf("%s\n",strcat(x,strcat(a,b)));
  return strcat(x,strcat(a,b));
}

