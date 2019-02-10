%{
      #include <stdio.h>
      #define YYSTYPE char
%}

%token CHARS NEWLINE
%token '+' '-'
%token '*' '/'
 
%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
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
  return 1;
}
