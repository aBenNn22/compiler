// %error-verbose
%define parse.error verbose
%locations
%{
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct node *,int);
int yylex();
char filename[32];
%}

%union {
	int    type_int;
	float  type_float;
	char   type_id[32];
	struct node *ptr;
}; 

//  %type 定义非终结符的语义值类型
%type <ptr> CompUnits CompUnit Decl ConstDecl BType ConstDef ConstInitVal VarDecl VarDef InitVal FuncDef FuncType FuncFParams FuncfFParam Block BlockItem Stmt
%type <ptr> Exp Cond LVal PrimaryExp Number UnaryExp UnaryOp FuncRParams MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp
%type <ptr> BlockMul ConstDeclMul ConstInitValMul VarDeclMul InitValMul AutoOp ForDec ForExp1 ForExp2 ForExp3

//% token 定义终结符的语义值类型
%token <type_id> INT FLOAT
%token VOID CONST RETURN IF ELSE FOR WHILE DO BREAK CONTINUE
%token LP RP LB RB LC RC
%token COMMA SEMICOLON QUESTION COLON MINUS NOT TILDE ASSIGN ADD MUL DIV MOD AND OR
// %token EQ NE LT LE GT GE
%token <type_id> ID EQ NE LT LE GT GE        //指定ID 的语义值是type_id，有词法分析得到的标识符字符串
%token <type_int> INT_LIT
%token <type_float> FLOAT_LIT
%token LEX_ERR

%left ASSIGN
%left OR
%left AND
%left EQ NE LT LE GT GE
%left PLUS MINUS
%left DIV MOD
%left AUTOADD AUTOMINUS
%right NOT UADD UMINUS
%left LB RB LP RP LC RC

// %left ASSIGNOP
// %left OR
// %left AND
// %left RELOP
// %left PLUS MINUS
// %left STAR DIV
// %right UMINUS NOT

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%%
CompUnits: CompUnit {display($1,0);}

CompUnit: Decl CompUnit {$$=mknode(COMP_UNIT,$1,$2,NULL,yylineno);}
        | FuncDef CompUnit {$$=mknode(COMP_UNIT,$1,$2,NULL,yylineno);}
        | Decl {$$=$1;}
        | FuncDef {$$=$1;}
        ;

FuncDef: BType ID LP RP Block {$$=mknode(FUNC_DEF,$1,$5,NULL,yylineno); strcpy($$->type_id,$2);}
        | BType ID LP FuncFParams RP Block {$$=mknode(FUNC_DEF,$1,$4,$6,yylineno); strcpy($$->type_id,$2);}
        | FuncType ID LP RP Block {$$=mknode(FUNC_DEF,$1,$5,NULL,yylineno); strcpy($$->type_id,$2);}
        | FuncType ID LP FuncFParams RP Block {$$=mknode(FUNC_DEF,$1,$4,$6,yylineno); strcpy($$->type_id,$2);}
        ;

FuncType: VOID {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"void");}
        // | INT {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"int");}
        // | FLOAT {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"float");}
        ;

FuncFParams: FuncfFParam {$$=mknode(FUNC_PARAMS,$1,NULL,NULL,yylineno);}
        | FuncfFParam COMMA FuncFParams {$$=mknode(FUNC_PARAMS,$1,$3,NULL,yylineno);}
        ;

FuncfFParamMul: {$$=NULL;}
        | FuncfFParamMul LB Exp RB {$$=mknode(FUNC_PARAM_MUL,$1,$3,NULL,yylineno);}
        ;

FuncfFParam: BType ID FuncfFParamMul {$$=mknode(FUNC_PARAM,$1,$3,NULL,yylineno); strcpy($$->type_id,$2);}
      //   | BType ID LB RB {$$=mknode(FUNC_PARAM,$1,NULL,NULL,yylineno); strcpy($$->type_id,$2);}
        ;

BlockMul: {$$=NULL;}
        | BlockMul BlockItem {$$=mknode(BLOCK_MUL,$1,$2,NULL,yylineno);}
        ;

Block: LC BlockMul RC {$$=mknode(BLOCK,$2,NULL,NULL,yylineno);}
        ;

BlockItem: Decl {$$=$1;}
        | Stmt {$$=$1;}
        ;

Decl: ConstDecl {$$=$1;} 
        | VarDecl {$$=$1;}
        ;

ConstDeclMul: ConstDef {$$=$1;}
        | ConstDef COMMA ConstDeclMul {$$=mknode(CONST_DECL_MUL,$1,$3,NULL,yylineno);}
        ;

ConstDecl: CONST BType ConstDeclMul SEMICOLON {$$=mknode(CONST_DECL,$2,$3,NULL,yylineno); strcpy($$->type_id,"const");}
        ;

BType: INT {$$=mknode(BTYPE,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"int");}
        | FLOAT {$$=mknode(BTYPE,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"float");}
        ;

ConstDefMul: {$$=NULL;}
        | LB ConstExp RB ConstDefMul {$$=mknode(CONST_DEF_MUL,$2,$4,NULL,yylineno);}
        ;

ConstDef: ID ASSIGN ConstInitVal {$$=mknode(CONST_DEF,$3,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        ;

ConstInitValMul: ConstInitVal {$$=$1;}
        | ConstInitVal COMMA ConstInitValMul {$$=mknode(CONST_INIT_VAL_MUL,$1,$3,NULL,yylineno);}
        ;

ConstInitVal: ConstExp {$$=$1;}
        | LC RC {$$=mknode(CONST_INIT_VAL,NULL,NULL,NULL,yylineno);}
        | LC ConstInitValMul RC {$$=mknode(CONST_INIT_VAL,$2,NULL,NULL,yylineno);}
        ;

VarDeclMul: VarDef {$$=$1;}
        | VarDef COMMA VarDeclMul {$$=mknode(VAR_DECL_MUL,$1,$3,NULL,yylineno);}
        ;

VarDecl: BType VarDeclMul SEMICOLON {$$=mknode(VAR_DECL,$1,$2,NULL,yylineno);}
        ;

VarDef: ID ConstDefMul  {$$=$1;}
        | ID ConstDefMul ASSIGN InitVal {$$=mknode(VAR_DEF,$3,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
      //   | ID LB INT_LIT RB LB INT_LIT RB{$$=mknode(VAR_ARRAY,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); 
      //                           $$->type_int1 = $3; $$->type_int2 = $6;}
        ;

InitValMul: InitVal {$$=$1;}
        | InitVal COMMA InitValMul {$$=mknode(INIT_VAL_MUL,$1,$3,NULL,yylineno);}
        ;

InitVal: Exp {$$=$1;}
        | LC RC {$$=mknode(INIT_VAL,NULL,NULL,NULL,yylineno);}
        | LC InitValMul RC {$$=mknode(INIT_VAL,$2,NULL,NULL,yylineno);}
        ;

Stmt: LVal ASSIGN Exp SEMICOLON {$$=mknode(ASSIGN,$1,$3,NULL,yylineno);}
        | SEMICOLON {$$=mknode(STMT,NULL,NULL,NULL,yylineno);}
        | Exp SEMICOLON {$$=mknode(EXP_STMT,$1,NULL,NULL,yylineno);}
        | Block {$$=$1;}
        | IF LP Cond RP Stmt %prec LOWER_THEN_ELSE{$$=mknode(IF_THEN,$3,$5,NULL,yylineno);}
        | IF LP Cond RP Stmt ELSE Stmt {$$=mknode(IF_THEN_ELSE,$3,$5,$7,yylineno);}
        | WHILE LP Cond RP Stmt {$$=mknode(WHILE,$3,$5,NULL,yylineno);}
        | BREAK SEMICOLON {$$=mknode(BREAK,NULL,NULL,NULL,yylineno);}
        | CONTINUE SEMICOLON {$$=mknode(CONTINUE,NULL,NULL,NULL,yylineno);}
        | RETURN Exp SEMICOLON {$$=mknode(RETURN,$2,NULL,NULL,yylineno);}
        | RETURN SEMICOLON {$$=mknode(RETURN,NULL,NULL,NULL,yylineno);}
        | FOR LP ForDec RP Block {$$=mknode(FOR,$3,$5,NULL,yylineno);}
        ;

ForDec: ForExp1  ForExp2 SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$1,$2,$4,yylineno);}
        | ForExp1  SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$1,$3,NULL,yylineno);}
        | ForExp1  ForExp2 SEMICOLON {$$=mknode(FOR_DEC,$1,$2,NULL,yylineno);}
        | ForExp1  SEMICOLON {$$=mknode(FOR_DEC,$1,NULL,NULL,yylineno);}
        | SEMICOLON ForExp2 SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$2,$4,NULL,yylineno);}
        | SEMICOLON ForExp2 SEMICOLON  {$$=mknode(FOR_DEC,$2,NULL,NULL,yylineno);}
        | SEMICOLON SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$3,NULL,NULL,yylineno);}     
        | SEMICOLON SEMICOLON {$$=mknode(FOR_DEC,NULL,NULL,NULL,yylineno);}
        ;

ForExp1:  VarDecl {$$=mknode(FOR_EXP1,$1,NULL,NULL,yylineno);}
        | VarDef SEMICOLON {$$=mknode(FOR_EXP1,$1,NULL,NULL,yylineno);}
        ;
ForExp2: Cond {$$=mknode(FOR_EXP2,$1,NULL,NULL,yylineno);}
        ;
ForExp3:  Exp COMMA ForExp3 {$$=mknode(FOR_EXP3,$1,$3,NULL,yylineno);}
        | Exp {$$=mknode(FOR_EXP3,$1,NULL,NULL,yylineno);}
        ;

Exp: AddExp {$$=$1;}
        ;

Cond: LOrExp {$$=$1;}
        ;

LVal: ID ConstDefMul {$$=mknode(LVAL,$2,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
      //   | ID LB INT_LIT RB LB ID RB {$$=mknode(LVAL_ARRAY,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);
      //                           strcpy($$->type_id1,$6); $$->type_int1 = $3;}
      //   | ID LB INT_LIT RB {$$=mknode(LVAL_ARRAY,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);
      //                           $$->type_int1 = $3;}
        ;

PrimaryExp: LP Exp RP {$$=mknode(PRIMARY_EXP,$2,NULL,NULL,yylineno);}
        | LVal {$$=$1;}
        | Number {$$=$1;}
        ;

Number: INT_LIT {$$=mknode(INT_LIT,NULL,NULL,NULL,yylineno); $$->type_int = $1;}
        | FLOAT_LIT {$$=mknode(FLOAT_LIT,NULL,NULL,NULL,yylineno); $$->type_float = $1;}
        ;

UnaryExp: PrimaryExp {$$=$1;}
        | ID LP RP {$$=mknode(FUNC_CALL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | ID LP FuncRParams RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | UnaryOp UnaryExp {$$=mknode(UNARY_EXP,$1,$2,NULL,yylineno);}
      //   | UnaryExp AutoOp {$$=mknode(UNARY_EXP,$1,$2,NULL,yylineno);}
        ;

// AutoOp: AUTOADD {$$=mknode(AUTOADD,NULL,NULL,NULL,yylineno);}
//         | AUTOMINUS {$$=mknode(AUTOMINUS,NULL,NULL,NULL,yylineno);}
//         ;

UnaryOp: ADD {$$=mknode(UADD,NULL,NULL,NULL,yylineno);}
        | MINUS {$$=mknode(UMINUS,NULL,NULL,NULL,yylineno);}
        | NOT {$$=mknode(NOT,NULL,NULL,NULL,yylineno);}
        ;

FuncRParams: Exp {$$=$1;}
        | Exp COMMA FuncRParams {$$=mknode(FUNC_PARAMS,$1,$3,NULL,yylineno);}
        ;

MulExp: UnaryExp {$$=$1;}
        | MulExp MUL UnaryExp {$$=mknode(MUL,$1,$3,NULL,yylineno);}
        | MulExp DIV UnaryExp {$$=mknode(DIV,$1,$3,NULL,yylineno);}
        | MulExp MOD UnaryExp {$$=mknode(MOD,$1,$3,NULL,yylineno);}
        ;

AddExp: MulExp {$$=$1;}
        | AddExp ADD MulExp {$$=mknode(ADD,$1,$3,NULL,yylineno);}
        | AddExp MINUS MulExp {$$=mknode(MINUS,$1,$3,NULL,yylineno);}
        ;

RelExp: AddExp {$$=$1;}
        | RelExp LT AddExp {$$=mknode(LT,$1,$3,NULL,yylineno);}
        | RelExp GT AddExp {$$=mknode(GT,$1,$3,NULL,yylineno);}
        | RelExp LE AddExp {$$=mknode(LE,$1,$3,NULL,yylineno);}
        | RelExp GE AddExp {$$=mknode(GE,$1,$3,NULL,yylineno);}
        ;

EqExp: RelExp {$$=$1;}
        | EqExp EQ RelExp {$$=mknode(EQ,$1,$3,NULL,yylineno);}
        | EqExp NE RelExp {$$=mknode(NE,$1,$3,NULL,yylineno);}
        ;

LAndExp: EqExp {$$=$1;}
        | LAndExp AND EqExp {$$=mknode(AND,$1,$3,NULL,yylineno);}
        ;

LOrExp: LAndExp {$$=$1;}
        | LOrExp OR LAndExp {$$=mknode(OR,$1,$3,NULL,yylineno);}
        ;

ConstExp: AddExp {$$=$1;}
        ;

        
%%

int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 0;
        strcpy(filename,strrchr(argv[1],'/')+1);
	yylineno=1;
	yyparse();
	return 0;
}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        fprintf(stderr,"%s:",filename);
        fprintf(stderr, "%d:%d: ", yylloc.first_line,yylloc.first_column);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, ".\n");
}	
