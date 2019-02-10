%{

/* 
* this sample demonstrates (very) simple recognition:
* a verb/not a verb.
*/
%}
%%
[\t q]+  /* ignore whitespace */ ;
aathil.ta { printf("%s:password match\n", yytext); }
[a-zA-Z]+ { printf("%s: is not a macth\n", yytext); }
.|\n  { ECHO; /* normal default anyway */ }
%%

main()
{
yylex() ;
}
