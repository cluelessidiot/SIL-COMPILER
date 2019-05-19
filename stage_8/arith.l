%{

#include<stdio.h>
#include<stdlib.h>
#include"data.h"
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
[&]		{return ADDRTK;}
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
begin 	{return BEGINTK;}
end 	{return END;}
read 	{return READ;}
write 	{return WRITE;}
breakpoint {return BRKPTK;}
break 	{return BREAKTK;}
continue {return CONTINUETK;}
repeat 	{return REPEAT;}
until 	{return UNTIL;}
decl 	{declflag=1; return DECL;}
enddecl	{declflag=0; return ENDDECL;}
main	{return MAINTK;}
AND		{return ANDTK;}
OR 		{return ORTK;}
NOT 	{return NOTTK;}
tuple 	{return TUPLE;}
type 	{return TYPETK;}
endtype	{return ENDTYPE;}
NULL 	{return NULLTK;}
null 	{return NULLTK;}
alloc 	{return ALLOC;}
free 	{return FREE;}
initialize {return INITIALIZE;}
return	{return RETURN;}
self	{return SELF;}
class	{return CLASS;}
endclass {return ENDCLASS;}
new		{return NEW;}
delete	{return DELETE;}
extends {return EXTENDS;}
[{}()]	{return *yytext;}
,	{return *yytext;}
[\[\]]	{return *yytext;}
[a-zA-Z][a-zA-Z0-9_]* {yylval=createTree(0,NULL,yytext,VAR,NULL,NULL,NULL); return ID;}
\"[a-zA-Z0-9 #-~!]*\" {yylval=createTree(0,TLookup("str"),yytext,CONS,NULL,NULL,NULL); return TXT;}
. 	{yyerror("Unknown Character"); fprintf(stderr,"\t\t%s\n",yytext); }

%%
