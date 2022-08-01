/*定义部分，包含c语言的一些宏定义，如文件包含、宏名定义，以及一些变量和类型的定义和声明*/
%{
#include "sysy.tab.h"
#include "string.h"
#include "def.h"
#include "stdio.h"
#define SHOW 0
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
typedef union {
	int type_int;
	float type_float;
	char type_char[3];
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE YYLVAL

%}
%option yylineno
%x COMMENT
/*正则式宏名的定义*/


ID   [A-Za-z][A-Za-z0-9]*  
INT  ([0-9]+)|(0[xX][0-9a-fA-F]+)|(0[0-7]+)
FLOAT  ([0-9]*\.[0-9]+)|([0-9]+\.)

/*规则部分 正则表达式    动作*/
%%

{INT}        { printf("(%s, INT)\n", yytext);yylval.type_int=strtol(yytext,NULL,0);  return INT;}
{FLOAT}  	 { printf("(%s, FLOAT)\n", yytext);yylval.type_float=atof(yytext); return FLOAT;}


"int"        { printf("(%s, TYPR-INT)\n", yytext);strcpy(yylval.type_id,  yytext);return TYPE;}
"float"      { printf("(%s, TYPE-FLOAT)\n", yytext);strcpy(yylval.type_id,  yytext);return TYPE;}

"return"     { printf("(%s, RETURN)\n", yytext);return RETURN;}
"if"         { printf("(%s, RETURN)\n", yytext);return IF;}
"else"       { printf("(%s, ELSE)\n", yytext);return ELSE;}
"while"      { printf("(%s, WHILE)\n", yytext);return WHILE;}
"for" 		 { printf("(%s, FOR)\n", yytext);return FOR;}
"break"		 { printf("(%s, BREAK)\n", yytext);return BREAK;}
"continue"	 { printf("(%s, CONTINUE)\n", yytext);return CONTINUE;}

{ID}       { printf("(%s, ID)\n", yytext);strcpy(yylval.type_id,  yytext); return ID;/*由于关键字的形式也符合标识符的规则，所以把关键字的处理全部放在标识符的前面，优先识别*/}
";"			{ printf("(%s, SEMI)\n", yytext);return SEMI;}
","			{ printf("(%s, COMMA)\n", yytext);return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" { printf("(%s, RELOP)\n", yytext);strcpy(yylval.type_id, yytext);return RELOP;}
"="			{ printf("(%s, ASSIGNOP)\n", yytext);return ASSIGNOP;}
"+"			{ printf("(%s, PLUS)\n", yytext);return PLUS;}
"-"			{ printf("(%s, MINUS)\n", yytext);return MINUS;}
"*"			{ printf("(%s, STAR)\n", yytext);return STAR;}
"/"			{ printf("(%s, DIV)\n", yytext);return DIV;}
"%"			{ printf("(%s, MOD)\n", yytext);return MOD;}

"++" 		{ printf("(%s, AUTOADD)\n", yytext);return AUTOADD;}
"--" 		{ printf("(%s, AUTOSUB)\n", yytext);return AUTOSUB;}
"+=" 		{ printf("(%s, COMADD)\n", yytext);return COMADD;}
"-=" 		{ printf("(%s, COMSUB)\n", yytext);return COMSUB;}
"*="     	{ printf("(%s, COMSUB)\n", yytext);return COMSTAR;}
"/="     	{ printf("(%s, COMDIV)\n", yytext);return COMDIV;}
"%="     	{ printf("(%s, COMMOD)\n", yytext);return COMMOD;}

"&&"        { printf("(%s, AND)\n", yytext);return AND;}
"||"        { printf("(%s, OR)\n", yytext);return OR;}
"!"			{ printf("(%s, NOT)\n", yytext);return NOT;}
"("			{ printf("(%s, LP)\n", yytext);return LP;}
")"			{ printf("(%s, RP)\n", yytext);return RP;}
"[" 		{ printf("(%s, LB)\n", yytext);return LB;}
"]" 		{ printf("(%s, RB)\n", yytext);return RB;}
"{"			{ printf("(%s, LC)\n", yytext);return LC;}
"}"			{ printf("(%s, RC)\n", yytext);return RC;}

[\n]           { printf("(\\n, line feed)\n");yycolumn=1;}   
[ \r\t]          {}  

"//"[^\n]*		 { printf("(%s, line comment)\n", yytext);}     /*跳过单行注释*/
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN INITIAL;}
<COMMENT>([^*]|\n)+|.     /*跳过多行注释*/
<COMMENT><<EOF>> {printf("%s：%d: Unterminated comment\n",yytext,yylineno);return 0;}
.			{printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}


%%

/* 和bison联用时，不需要这部分
void main()
{
yylex();
return 0;
}

*/
int yywrap()
{
return 1;
}