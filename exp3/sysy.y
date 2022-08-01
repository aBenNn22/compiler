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

CompUnit: CompUnit Decl {$$=mknode(COMP_UNIT,$1,$2,NULL,NULL,yylineno);}
        | CompUnit FuncDef {$$=mknode(COMP_UNIT,$1,$2,NULL,NULL,yylineno);}
        | Decl {$$=mknode(COMP_UNIT,NULL,$1,NULL,NULL,yylineno);}
        | FuncDef {$$=mknode(COMP_UNIT,NULL,$1,NULL,NULL,yylineno);}
        ;

FuncDef: BType ID LP RP Block {$$=mknode(FUNC_DEF,$1,$5,NULL,NULL,yylineno); strcpy($$->type_id,$2);}
        | BType ID LP FuncFParams RP Block {$$=mknode(FUNC_DEF,$1,$4,$6,NULL,yylineno); strcpy($$->type_id,$2);}
        | FuncType ID LP RP Block {$$=mknode(FUNC_DEF,$1,$5,NULL,NULL,yylineno); strcpy($$->type_id,$2);}
        | FuncType ID LP FuncFParams RP Block {$$=mknode(FUNC_DEF,$1,$4,$6,NULL,yylineno); strcpy($$->type_id,$2);}
        ;

FuncType: VOID {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"void");}
        // | INT {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"int");}
        // | FLOAT {$$=mknode(FUNC_TYPE,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"float");}
        ;

FuncFParams: FuncfFParam {$$=mknode(FUNC_PARAMS,NULL,$1,NULL,NULL,yylineno);}
        | FuncFParams COMMA FuncfFParam {$$=mknode(FUNC_PARAMS,$1,$3,NULL,NULL,yylineno);}
        ;

// FuncfFParamMul: {$$=NULL;}
//         | FuncfFParamMul LB Exp RB {$$=mknode(FUNC_PARAM_MUL,$1,$3,NULL,NULL,yylineno);}
//         ;

FuncfFParam: BType ID {$$=mknode(FUNC_PARAM,$1,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$2);}
        | BType ID LB RB {$$=mknode(FUNC_PARAM,$1,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$2);}
        ;

BlockMul: {$$=NULL;}
        | BlockMul BlockItem {$$=mknode(BLOCK_MUL,$1,$2,NULL,NULL,yylineno);}
        ;

Block: LC BlockMul RC {$$=mknode(BLOCK,$2,NULL,NULL,NULL,yylineno);}
        ;

BlockItem: Decl {$$=mknode(BLOCK_ITEM,$1,NULL,NULL,NULL,yylineno);}
        | Stmt {$$=mknode(BLOCK_ITEM,$1,NULL,NULL,NULL,yylineno);}
        ;

Decl: ConstDecl {$$=mknode(DECL,$1,NULL,NULL,NULL,yylineno);} 
        | VarDecl {$$=mknode(DECL,$1,NULL,NULL,NULL,yylineno);}
        ;

ConstDeclMul: ConstDef {$$=mknode(CONST_DECL_MUL,NULL,$1,NULL,NULL,yylineno);}
        | ConstDeclMul COMMA ConstDef {$$=mknode(CONST_DECL_MUL,$1,$3,NULL,NULL,yylineno);}
        ;

ConstDecl: CONST BType ConstDeclMul SEMICOLON {$$=mknode(CONST_DECL,$2,$3,NULL,NULL,yylineno); strcpy($$->type_id,"const");}
        ;

BType: INT {$$=mknode(BTYPE,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"int");}
        | FLOAT {$$=mknode(BTYPE,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"float");}
        ;

// ConstDefMul: {$$=NULL;}
//         | ConstDefMul LB ConstExp RB {$$=mknode(CONST_DEF_MUL,$1,$3,NULL,NULL,yylineno);}
//         ;

ConstDef: ID ASSIGN ConstInitVal {$$=mknode(CONST_DEF,$3,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        ;

ConstInitValMul: ConstInitVal {$$=mknode(CONST_INIT_VAL_MUL,NULL,$1,NULL,NULL,yylineno);}
        | ConstInitValMul COMMA ConstInitVal {$$=mknode(CONST_INIT_VAL_MUL,$1,$3,NULL,NULL,yylineno);}
        ;

ConstInitVal: ConstExp {$$=mknode(CONST_INIT_VAL,$1,NULL,NULL,NULL,yylineno);}
        | LC RC {$$=mknode(CONST_INIT_VAL,NULL,NULL,NULL,NULL,yylineno);}
        | LC ConstInitValMul RC {$$=mknode(CONST_INIT_VAL,$2,NULL,NULL,NULL,yylineno);}
        ;

VarDeclMul: VarDef {$$=mknode(VAR_DECL_MUL,NULL,$1,NULL,NULL,yylineno);}
        | VarDeclMul COMMA VarDef {$$=mknode(VAR_DECL_MUL,$1,$3,NULL,NULL,yylineno);}
        ;

VarDecl: BType VarDeclMul SEMICOLON {$$=mknode(VAR_DECL,$1,$2,NULL,NULL,yylineno);}
        ;

VarDef: ID  {$$=mknode(VAR_DEF,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | ID ASSIGN InitVal {$$=mknode(VAR_DEF,$3,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | ID LB INT_LIT RB LB INT_LIT RB{$$=mknode(VAR_ARRAY,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); 
                                $$->type_int1 = $3; $$->type_int2 = $6;}
        ;

InitValMul: InitVal {$$=mknode(INIT_VAL_MUL,NULL,$1,NULL,NULL,yylineno);}
        | InitValMul COMMA InitVal {$$=mknode(INIT_VAL_MUL,$1,$3,NULL,NULL,yylineno);}
        ;

InitVal: Exp {$$=mknode(INIT_VAL,$1,NULL,NULL,NULL,yylineno);}
        | LC RC {$$=mknode(INIT_VAL,NULL,NULL,NULL,NULL,yylineno);}
        | LC InitValMul RC {$$=mknode(INIT_VAL,$2,NULL,NULL,NULL,yylineno);}
        ;

Stmt: LVal ASSIGN Exp SEMICOLON {$$=mknode(ASSIGN,$1,$3,NULL,NULL,yylineno);}
        | SEMICOLON {$$=mknode(STMT,NULL,NULL,NULL,NULL,yylineno);}
        | Exp SEMICOLON {$$=mknode(EXP_STMT,$1,NULL,NULL,NULL,yylineno);}
        | Block {$$=$1;}
        | IF LP Cond RP Stmt %prec LOWER_THEN_ELSE{$$=mknode(IF_THEN,$3,$5,NULL,NULL,yylineno);}
        | IF LP Cond RP Stmt ELSE Stmt {$$=mknode(IF_THEN_ELSE,$3,$5,$7,NULL,yylineno);}
        | WHILE LP Cond RP Stmt {$$=mknode(WHILE,$3,$5,NULL,NULL,yylineno);}
        | BREAK SEMICOLON {$$=mknode(BREAK,NULL,NULL,NULL,NULL,yylineno);}
        | CONTINUE SEMICOLON {$$=mknode(CONTINUE,NULL,NULL,NULL,NULL,yylineno);}
        | RETURN Exp SEMICOLON {$$=mknode(RETURN,$2,NULL,NULL,NULL,yylineno);}
        | RETURN SEMICOLON {$$=mknode(RETURN,NULL,NULL,NULL,NULL,yylineno);}
        | FOR LP ForDec RP Block {$$=mknode(FOR,$3,$5,NULL,NULL,yylineno);}
        ;

ForDec: ForExp1  ForExp2 SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$1,$2,$4,NULL,yylineno);}
        | ForExp1  SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$1,$3,NULL,NULL,yylineno);}
        | ForExp1  ForExp2 SEMICOLON {$$=mknode(FOR_DEC,$1,$2,NULL,NULL,yylineno);}
        | ForExp1  SEMICOLON {$$=mknode(FOR_DEC,$1,NULL,NULL,NULL,yylineno);}
        | SEMICOLON ForExp2 SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$2,$4,NULL,NULL,yylineno);}
        | SEMICOLON ForExp2 SEMICOLON  {$$=mknode(FOR_DEC,$2,NULL,NULL,NULL,yylineno);}
        | SEMICOLON SEMICOLON ForExp3 {$$=mknode(FOR_DEC,$3,NULL,NULL,NULL,yylineno);}     
        | SEMICOLON SEMICOLON {$$=mknode(FOR_DEC,NULL,NULL,NULL,NULL,yylineno);}
        ;

ForExp1:  VarDecl {$$=mknode(FOR_EXP1,$1,NULL,NULL,NULL,yylineno);}
        | VarDef SEMICOLON {$$=mknode(FOR_EXP1,$1,NULL,NULL,NULL,yylineno);}
        ;
ForExp2: Cond {$$=mknode(FOR_EXP2,$1,NULL,NULL,NULL,yylineno);}
        ;
ForExp3:  Exp COMMA ForExp3 {$$=mknode(FOR_EXP3,$1,$3,NULL,NULL,yylineno);}
        | Exp {$$=mknode(FOR_EXP3,$1,NULL,NULL,NULL,yylineno);}
        ;

Exp: AddExp {$$=mknode(EXP,$1,NULL,NULL,NULL,yylineno);}
        ;

Cond: LOrExp {$$=mknode(COND,$1,NULL,NULL,NULL,yylineno);}
        ;

LVal: ID {$$=mknode(LVAL,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | ID LB INT_LIT RB LB ID RB {$$=mknode(LVAL_ARRAY,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);
                                strcpy($$->type_id1,$6); $$->type_int1 = $3;}
        | ID LB INT_LIT RB {$$=mknode(LVAL_ARRAY,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);
                                $$->type_int1 = $3;}
        ;

PrimaryExp: LP Exp RP {$$=mknode(PRIMARY_EXP,$2,NULL,NULL,NULL,yylineno);}
        | LVal {$$=mknode(PRIMARY_EXP,$1,NULL,NULL,NULL,yylineno);}
        | Number {$$=mknode(PRIMARY_EXP,$1,NULL,NULL,NULL,yylineno);}
        ;

Number: INT_LIT {$$=mknode(INT_LIT,NULL,NULL,NULL,NULL,yylineno); $$->type_int = $1;}
        | FLOAT_LIT {$$=mknode(FLOAT_LIT,NULL,NULL,NULL,NULL,yylineno); $$->type_float = $1;}
        ;

UnaryExp: PrimaryExp {$$=mknode(UNARY_EXP,$1,NULL,NULL,NULL,yylineno);}
        | ID LP RP {$$=mknode(FUNC_CALL,NULL,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        | ID LP FuncRParams RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
        // | UnaryOp UnaryExp {$$=mknode(UNARY_EXP,$1,$2,NULL,NULL,yylineno);}
        // | AutoOp UnaryExp {$$=mknode(UNARY_EXP,$1,$2,NULL,NULL,yylineno);}
        | UnaryExp AutoOp {$$=mknode(UNARY_EXP,$1,$2,NULL,NULL,yylineno);}
        ;

AutoOp: AUTOADD {$$=mknode(AUTOADD,NULL,NULL,NULL,NULL,yylineno);}
        | AUTOMINUS {$$=mknode(AUTOMINUS,NULL,NULL,NULL,NULL,yylineno);}
        ;

UnaryOp: ADD {$$=mknode(UADD,NULL,NULL,NULL,NULL,yylineno);}
        | MINUS {$$=mknode(UMINUS,NULL,NULL,NULL,NULL,yylineno);}
        | NOT {$$=mknode(NOT,NULL,NULL,NULL,NULL,yylineno);}
        ;

FuncRParams: Exp {$$=mknode(FUNCR_PARAMS,NULL,$1,NULL,NULL,yylineno);}
        | FuncRParams COMMA Exp {$$=mknode(FUNC_PARAMS,$1,$3,NULL,NULL,yylineno);}
        ;

MulExp: UnaryExp {$$=mknode(MUL_EXP,$1,NULL,NULL,NULL,yylineno);}
        | MulExp MUL UnaryExp {$$=mknode(MUL,$1,$3,NULL,NULL,yylineno);}
        | MulExp DIV UnaryExp {$$=mknode(DIV,$1,$3,NULL,NULL,yylineno);}
        | MulExp MOD UnaryExp {$$=mknode(MOD,$1,$3,NULL,NULL,yylineno);}
        ;

AddExp: MulExp {$$=mknode(ADD_EXP,$1,NULL,NULL,NULL,yylineno);}
        | AddExp ADD MulExp {$$=mknode(ADD,$1,$3,NULL,NULL,yylineno);}
        | AddExp MINUS MulExp {$$=mknode(MINUS,$1,$3,NULL,NULL,yylineno);}
        ;

RelExp: AddExp {$$=mknode(REL_EXP,$1,NULL,NULL,NULL,yylineno);}
        | RelExp LT AddExp {$$=mknode(LT,$1,$3,NULL,NULL,yylineno);}
        | RelExp GT AddExp {$$=mknode(GT,$1,$3,NULL,NULL,yylineno);}
        | RelExp LE AddExp {$$=mknode(LE,$1,$3,NULL,NULL,yylineno);}
        | RelExp GE AddExp {$$=mknode(GE,$1,$3,NULL,NULL,yylineno);}
        ;

EqExp: RelExp {$$=mknode(EQ_EXP,$1,NULL,NULL,NULL,yylineno);}
        | EqExp EQ RelExp {$$=mknode(EQ,$1,$3,NULL,NULL,yylineno);}
        | EqExp NE RelExp {$$=mknode(NE,$1,$3,NULL,NULL,yylineno);}
        ;

LAndExp: EqExp {$$=mknode(LAND_EXP,$1,NULL,NULL,NULL,yylineno);}
        | LAndExp AND EqExp {$$=mknode(AND,$1,$3,NULL,NULL,yylineno);}
        ;

LOrExp: LAndExp {$$=mknode(LOR_EXP,$1,NULL,NULL,NULL,yylineno);}
        | LOrExp OR LAndExp {$$=mknode(OR,$1,$3,NULL,NULL,yylineno);}
        ;

ConstExp: AddExp {$$=mknode(CONST_EXP,$1,NULL,NULL,NULL,yylineno);}
        ;

// program: ExtDefList    { display($1,0); semantic_Analysis0($1);}     /*显示语法树,语义分析*/
//          ; 
// ExtDefList: {$$=NULL;}
//           | ExtDef ExtDefList {$$=mknode(EXT_DEF_LIST,$1,$2,NULL,yylineno);}   //每一个EXTDEFLIST的结点，其第1棵子树对应一个外部变量声明或函数
//           ;  
// ExtDef:   Specifier ExtDecList SEMI   {$$=mknode(EXT_VAR_DEF,$1,$2,NULL,yylineno);}   //该结点对应一个外部变量声明
//          |Specifier FuncDec CompSt    {$$=mknode(FUNC_DEF,$1,$2,$3,yylineno);}         //该结点对应一个函数定义
//          | error SEMI   {$$=NULL; }
//          ;
// Specifier:  TYPE    {$$=mknode(TYPE,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=!strcmp($1,"int")?INT:FLOAT;}   
//            ;      
// ExtDecList:  VarDec      {$$=$1;}       /*每一个EXT_DECLIST的结点，其第一棵子树对应一个变量名(ID类型的结点),第二棵子树对应剩下的外部变量名*/
//            | VarDec COMMA ExtDecList {$$=mknode(EXT_DEC_LIST,$1,$3,NULL,yylineno);}
//            ;  
// VarDec:  ID          {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}   //ID结点，标识符符号串存放结点的type_id
//          ;
// FuncDec: ID LP VarList RP   {$$=mknode(FUNC_DEC,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id
// 		|ID LP  RP   {$$=mknode(FUNC_DEC,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id

//         ;  
// VarList: ParamDec  {$$=mknode(PARAM_LIST,$1,NULL,NULL,yylineno);}
//         | ParamDec COMMA  VarList  {$$=mknode(PARAM_LIST,$1,$3,NULL,yylineno);}
//         ;
// ParamDec: Specifier VarDec         {$$=mknode(PARAM_DEC,$1,$2,NULL,yylineno);}
//          ;

// CompSt: LC DefList StmList RC    {$$=mknode(COMP_STM,$2,$3,NULL,yylineno);}
//        ;
// StmList: {$$=NULL; }  
//         | Stmt StmList  {$$=mknode(STM_LIST,$1,$2,NULL,yylineno);}
//         ;
// Stmt:   Exp SEMI    {$$=mknode(EXP_STMT,$1,NULL,NULL,yylineno);}
//       | CompSt      {$$=$1;}      //复合语句结点直接最为语句结点，不再生成新的结点
//       | RETURN Exp SEMI   {$$=mknode(RETURN,$2,NULL,NULL,yylineno);}
//       | IF LP Exp RP Stmt %prec LOWER_THEN_ELSE   {$$=mknode(IF_THEN,$3,$5,NULL,yylineno);}
//       | IF LP Exp RP Stmt ELSE Stmt   {$$=mknode(IF_THEN_ELSE,$3,$5,$7,yylineno);}
//       | WHILE LP Exp RP Stmt {$$=mknode(WHILE,$3,$5,NULL,yylineno);}
//       ;
  
// DefList: {$$=NULL; }
//         | Def DefList {$$=mknode(DEF_LIST,$1,$2,NULL,yylineno);}
//         ;
// Def:    Specifier DecList SEMI {$$=mknode(VAR_DEF,$1,$2,NULL,yylineno);}
//         ;
// DecList: Dec  {$$=mknode(DEC_LIST,$1,NULL,NULL,yylineno);}
//        | Dec COMMA DecList  {$$=mknode(DEC_LIST,$1,$3,NULL,yylineno);}
// 	   ;
// Dec:     VarDec  {$$=$1;}
//        | VarDec ASSIGNOP Exp  {$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}
//        ;
// Exp:    Exp ASSIGNOP Exp {$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}//$$结点type_id空置未用，正好存放运算符
//       | Exp AND Exp   {$$=mknode(AND,$1,$3,NULL,yylineno);strcpy($$->type_id,"AND");}
//       | Exp OR Exp    {$$=mknode(OR,$1,$3,NULL,yylineno);strcpy($$->type_id,"OR");}
//       | Exp RELOP Exp {$$=mknode(RELOP,$1,$3,NULL,yylineno);strcpy($$->type_id,$2);}  //词法分析关系运算符号自身值保存在$2中
//       | Exp PLUS Exp  {$$=mknode(PLUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"PLUS");}
//       | Exp MINUS Exp {$$=mknode(MINUS,$1,$3,NULL,yylineno);strcpy($$->type_id,"MINUS");}
//       | Exp STAR Exp  {$$=mknode(STAR,$1,$3,NULL,yylineno);strcpy($$->type_id,"STAR");}
//       | Exp DIV Exp   {$$=mknode(DIV,$1,$3,NULL,yylineno);strcpy($$->type_id,"DIV");}
//       | LP Exp RP     {$$=$2;}
//       | MINUS Exp %prec UMINUS   {$$=mknode(UMINUS,$2,NULL,NULL,yylineno);strcpy($$->type_id,"UMINUS");}
//       | NOT Exp       {$$=mknode(NOT,$2,NULL,NULL,yylineno);strcpy($$->type_id,"NOT");}
//       | ID LP Args RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,yylineno);strcpy($$->type_id,$1);}
//       | ID LP RP      {$$=mknode(FUNC_CALL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}
//       | ID            {$$=mknode(ID,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}
//       | INT           {$$=mknode(INT,NULL,NULL,NULL,yylineno);$$->type_int=$1;$$->type=INT;}
//       | FLOAT         {$$=mknode(FLOAT,NULL,NULL,NULL,yylineno);$$->type_float=$1;$$->type=FLOAT;}
//       ;
// Args:    Exp COMMA Args    {$$=mknode(ARGS,$1,$3,NULL,yylineno);}
//        | Exp               {$$=mknode(ARGS,$1,NULL,NULL,yylineno);}
//        ;
        
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
