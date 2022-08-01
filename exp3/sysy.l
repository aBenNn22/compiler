%option noyywrap
%{
#include "sysy.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	int type_float;
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno

ID ([A-Za-z_][_A-Za-z0-9]*)
COMMENT1 ("//"[^\n]*)
commentbegin "/*"
commentelement .|\n
commentend "*/"
%x COMMENT
spaces ([ \t\r\n]+)
OCTINT 0[0-7]+
DECINT -?[0-9]+
HEXINT 0[Xx][0-9a-fA-F]+
INTERR 0[0-7]*[89]+[0-7]*
FLOAT {DECINT}\.[0-9]+[fF]?
SCIENCE (([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)|(-?[0-9]+))[Ee]-?[0-9]+[fF]?
SOMEERR [0-9]+[a-zA-Z]+[0-9]*

%%
{spaces} { yycolumn = 1; }
{INTERR} { return LEX_ERR;}
{OCTINT} {yylval.type_int = atoi(yytext); return INT_LIT;}
{DECINT} {yylval.type_int = atoi(yytext); return INT_LIT;}
{HEXINT} {yylval.type_int = atoi(yytext); return INT_LIT;}
{FLOAT} {yylval.type_float = atof(yytext); return FLOAT_LIT;}
{SCIENCE} {yylval.type_float = atof(yytext); return FLOAT_LIT;}
{SOMEERR} {strcpy(yylval.type_id, yytext); return LEX_ERR;}
"int" {strcpy(yylval.type_id, yytext); return INT;}
"float" {strcpy(yylval.type_id, yytext); return FLOAT;}
"void" { return VOID;}
"const" { return CONST;}
"return" { return RETURN;}
"for" {return FOR;}
"if" { return IF;}
"else" { return ELSE;}
"for" { return FOR;}
"while" { return WHILE;}
"do" { return DO;}
"break" { return BREAK;}
"continue" { return CONTINUE;}
{ID} {strcpy(yylval.type_id, yytext); return ID;}
"(" { return LP;}
")" { return RP;}
"[" { return LB;}
"]" { return RB;}
"{" { return LC;}
"}" { return RC;}
"," { return COMMA;}
";" { return SEMICOLON;}
"?" {  return QUESTION;}
":" { return COLON;}
"!" { return NOT;}
"=" { return ASSIGN;}
"-" { return MINUS;}
"+" { return ADD;}
"*" { return MUL;}
"/" { return DIV;}
"%" { return MOD;}
"&&" { return AND;}
"||" { return OR;}
"==" {strcpy(yylval.type_id, yytext); return EQ;}
"!=" {strcpy(yylval.type_id, yytext); return NE;}
"<" {strcpy(yylval.type_id, yytext); return LT;}
"<=" {strcpy(yylval.type_id, yytext); return LE;}
">" {strcpy(yylval.type_id, yytext); return GT;}
">=" {strcpy(yylval.type_id, yytext); return GE;}
"++" {return AUTOADD;}
"--" {return AUTOMINUS;}
{COMMENT1} {/* skip COMMENT1 */;}
{commentbegin} {BEGIN COMMENT;}
<COMMENT>{commentelement} {}
<COMMENT>{commentend} {BEGIN INITIAL;}
<<EOF>> {return 0;}


%%



