%option noyywrap
%option yylineno

%{
#include <stdio.h>

enum Token {
    INT=258, FLOAT, VOID, CONST, RETURN, IF, ELSE, FOR, WHILE, DO, BREAK, CONTINUE,
    LP, RP, LB, RB, LC, RC, COMMA, SEMICOLON, QUESTION, COLON,
    MINUS, NOT, TILDE, ASSIGN, ADD, MUL, DIV, MOD, AND, OR,
    EQ, NE, LT, LE, GT, GE,
    ID, INT_LIT, FLOAT_LIT,
    LEX_ERR
};
%}
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
{spaces} { /* ignore all spaces */}
{INTERR} {printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
{OCTINT} {printf("%s : INT_LIT\n", yytext); return INT_LIT;}
{DECINT} {printf("%s : INT_LIT\n", yytext); return INT_LIT;}
{HEXINT} {printf("%s : INT_LIT\n", yytext); return INT_LIT;}
{FLOAT} {printf("%s : FLOAT_LIT\n", yytext); return FLOAT_LIT;}
{SCIENCE} {printf("%s : FLOAT_LIT\n", yytext); return FLOAT_LIT;}
{SOMEERR} {printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
"int" {printf("%s : INT\n", yytext); return INT;}
"float" {printf("%s : FLOAT\n", yytext); return FLOAT;}
"void" {printf("%s : VOID\n", yytext); return VOID;}
"const" {printf("%s : CONST\n", yytext); return CONST;}
"return" {printf("%s : RETURN\n", yytext); return RETURN;}
"if" {printf("%s : IF\n", yytext); return IF;}
"else" {printf("%s : ELSE\n", yytext); return ELSE;}
"for" {printf("%s : FOR\n", yytext); return FOR;}
"while" {printf("%s : WHILE\n", yytext); return WHILE;}
"do" {printf("%s : DO\n", yytext); return DO;}
"break" {printf("%s : BREAK\n", yytext); return BREAK;}
"continue" {printf("%s : CONTINUE\n", yytext); return CONTINUE;}
{ID} {printf("%s : ID\n", yytext); return ID;}
"(" {printf("%s : LP\n", yytext); return LP;}
")" {printf("%s : RP\n", yytext); return RP;}
"[" {printf("%s : LB\n", yytext); return LB;}
"]" {printf("%s : RB\n", yytext); return RB;}
"{" {printf("%s : LC\n", yytext); return LC;}
"}" {printf("%s : RC\n", yytext); return RC;}
"," {printf("%s : COMMA\n", yytext); return COMMA;}
";" {printf("%s : SEMICOLON\n", yytext); return SEMICOLON;}
"?" {printf("%s : QUESTION\n", yytext);  return QUESTION;}
":" {printf("%s : COLON\n", yytext); return COLON;}
"!" {printf("%s : NOT\n", yytext); return NOT;}
"=" {printf("%s : ASSIGN\n", yytext); return ASSIGN;}
"-" {printf("%s : MINUS\n", yytext); return MINUS;}
"+" {printf("%s : ADD\n", yytext); return ADD;}
"*" {printf("%s : MUL\n", yytext); return MUL;}
"/" {printf("%s : DIV\n", yytext); return DIV;}
"%" {printf("%s : MOD\n", yytext); return MOD;}
"&&" {printf("%s : AND\n", yytext); return AND;}
"||" {printf("%s : OR\n", yytext); return OR;}
"==" {printf("%s : EQ\n", yytext); return EQ;}
"!=" {printf("%s : NE\n", yytext); return NE;}
"<" {printf("%s : LT\n", yytext); return LT;}
"<=" {printf("%s : LE\n", yytext); return LE;}
">" {printf("%s : GT\n", yytext); return GT;}
">=" {printf("%s : GE\n", yytext); return GE;}
{COMMENT1} {/* skip COMMENT1 */;}
{commentbegin} {BEGIN COMMENT;}
<COMMENT>{commentelement} {}
<COMMENT>{commentend} {BEGIN INITIAL;}
<<EOF>> {return 0;}



%%


int main(int argc, char** argv) {
    if(argc > 1) {
        if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]); 
            return  1; 
        }
        int token;
        while((token = yylex()) != 0);
        fclose(yyin);
    } else printf("No source file given!\n"); 

    return 0; 
}

