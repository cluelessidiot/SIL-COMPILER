%{

#include<stdio.h>
#include<stdlib.h>
#include"arith.h"
#define YYSTYPE tnode*
#include "y.tab.h"

extern int yyerror(char const *);
extern int line, declflag;
extern struct TypeTable *TLookup(char *);
extern struct tnode* createTree(int val, TypeTable *type, char *c,int nodetype, struct tnode *l, struct tnode *m, struct tnode *r);

%}

%option noyywrap

%%

[0-9]+ 	{yylval=createTree(atoi(yytext),TLookup("int"),NULL,CONS,NULL,NULL,NULL); return NUM;}
[+] 	{return PLUS;}
[-] 	{return MINUS;}
"/" 	{return DIV;}
"%" 	{return MOD;}
[*] 	{return MUL;}
"<" 	{return LT;}
">" 	{return GT;}
"<=" 	{return LE;}
">=" 	{return GE;}
"==" 	{return EQ;}
"!=" 	{return NE;}
[=] 	{return ASSIGN;}
[&]		{return AMPERCANT;}
[ \t] 	{}
[\n] 	{line++;}
[();] 	{return *yytext;}
"."		{return *yytext;}
if 	{return IF;}
then 	{return THEN;}
else 	{return ELSE;}
endif 	{return ENDIF;}
while 	{return WHILE;}
do 	{return DO;}
endwhile {return ENDWHILE;}
begin 	{return PBEGIN;}
end 	{return PEND;}
read 	{return READ;}
write 	{return WRITE;}
breakpoint {return BRKP_L;}
break 	{return BREAK_L;}
continue {return CONTINUE_L;}
repeat 	{return REPEAT;}
until 	{return UNTIL;}
decl 	{declflag=1; return DECL;}
enddecl	{declflag=0; return ENDDECL;}
main	{return MTOKEN;}
AND	{return AND_;}
OR 	{return OR_;}
NOT 	{return NOT_;}
tuple 	{return TUPLE;}
type 	{return TYPE_ST;}
endtype	{return ENDTYPE;}
NULL 	{return NULLTK;}
alloc 	{return ALLOC;}
free 	{return FREE;}
initialize {return INITIALIZE;}
return	{return RETURN;}
[{}()]	{return *yytext;}
,	{return *yytext;}
[\[\]]	{return *yytext;}
[a-zA-Z][a-zA-Z0-9]* {yylval=createTree(0,NULL,yytext,VAR,NULL,NULL,NULL); return ID;}
\"[a-zA-Z0-9]*\" {yylval=createTree(0,TLookup("str"),yytext,CONS,NULL,NULL,NULL); return STRNG;}
. 	{yyerror("Unknown Character"); fprintf(stderr,"\t\t%s\n",yytext); }

%%
