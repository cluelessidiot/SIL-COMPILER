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
brac:	'('brac expr brac')'  {ct++;}
	|'('brac')'  {ct++;}
	|'('expr')'brac {ct++;}
	|'('')'brac {ct++;}
	|brac'('')' {ct++;}
	|brac'('expr')' {ct++;}
        |'('')'      {ct++;}
        |    {}
	;

expr:  expr '+' expr        {printf("+ ");}
  |expr '-' expr     {printf("- ");}
  |expr '*' expr     {printf("* ");}
  |expr '/' expr     {printf("/ ");}
  | '(' expr ')'
  | CHARS         {printf("%c ",$1);}
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
