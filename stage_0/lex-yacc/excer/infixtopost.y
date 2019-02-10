%{
      #include <stdio.h>
      #define YYSTYPE int
      #define YYSTYPE_IS_DECLARED 1
      int yylex();

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

expr:  expr '+' expr        {printf("+ %s %s ",$1,$3);}
  |expr '-' expr     {printf("- %s %s ",$1,$3);}
  |expr '*' expr     {printf("* %s %s ",$1,$3);}
  |expr '/' expr     {printf("/ %s %s ",$1,$3);}
  | '(' expr ')'
  | CHARS         {}
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
