%{
      #include <stdio.h>
      #define YYSTYPE char
      int ct;
%}

%token CHARS NEWLINE
%token '+' '-'
%token '*' '/'
 
%%

start : brac NEWLINE  {
                        printf("\n%dComplete\n",ct);
                        exit(1);
                      }
  ;
brac:	'('brac')'  {ct++;}
	|'('')'brac {ct++;}
	|brac'('')' {ct++;}
        |'('')'     {ct++;}
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
  printf("%d",ct);
  return 1;
}
