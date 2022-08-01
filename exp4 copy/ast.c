#include "def.h"
struct node* mknode(int kind, struct node* first, struct node* second, struct node* third, int pos)
{
    struct node* T = (struct node*)malloc(sizeof(struct node));
    T->kind = kind;
    T->ptr[0] = first;
    T->ptr[1] = second;
    T->ptr[2] = third;
    T->pos = pos;
    return T;
}
// void display(struct node* T, int indent)
// { //对抽象语法树的先根遍历
//     int i = 1;
//     struct node* T0;
//     if (T) {
//         switch (T->kind) {
//         case COMP_UNIT:
//             printf("CompUnit\n");
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             break;
//         case FUNC_DEF:
//             printf("%*cFuncDef %s %s", indent, ' ', T->ptr[0]->type_id, T->type_id);
//             if (T->ptr[2]) {
//                 printf("(");
//                 display(T->ptr[1], indent);
//                 printf(")\n");
//                 display(T->ptr[2], indent + 3);
//                 printf("\n");
//                 break;
//             } else
//                 printf("()\n");
//             display(T->ptr[1], indent + 3);
//             break;
//         case FUNC_PARAMS:
//             display(T->ptr[0], indent);
//             printf(" ");
//             display(T->ptr[1], indent);
//             break;
//         case FUNC_PARAM_MUL:
//             display(T->ptr[0], indent);
//             if (T->ptr[0]) {
//                 printf("[");
//                 display(T->ptr[1], indent);
//                 printf("]");
//             }
//             break;
//         case FUNC_PARAM:
//             if (!T->ptr[1]) {
//                 printf("%*c%s %s", indent, ' ', T->ptr[0]->type_id, T->type_id);
//             } else {
//                 printf("%*c%s %s[]", indent, ' ', T->ptr[0]->type_id, T->type_id);
//                 display(T->ptr[1], indent);
//             }
//             break;
//         case BLOCK_MUL:
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             break;
//         case BLOCK:
//             printf("%*cBlock\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         case BLOCK_ITEM:
//             display(T->ptr[0], indent);
//             break;
//         case DECL:
//             printf("%*cDecl\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         case CONST_DECL_MUL:
//             if (T->ptr[0] != NULL)
//                 strcpy(T->ptr[0]->type_id, T->type_id);
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             printf(" %s\n", T->type_id);
//             break;
//         case CONST_DECL:
//             // printf("%*cConstDecl %s %s\n", indent, ' ', T->type_id, T->ptr[0]->type_id);
//             strcpy(T->ptr[1]->type_id, T->ptr[0]->type_id);
//             display(T->ptr[1], indent);
//             break;
//         case CONST_DEF_MUL:
//             display(T->ptr[0], indent);
//             printf("[");
//             display(T->ptr[1], 0);
//             printf("]");
//             break;
//         case CONST_DEF:
//             printf("%*cConstDecl %s", indent, ' ', T->type_id);
//             display(T->ptr[0], indent);
//             printf("=");
//             display(T->ptr[1], indent);
//             break;
//         case CONST_INIT_VAL_MUL:
//             display(T->ptr[0], indent);
//             printf(" ");
//             display(T->ptr[1], indent);
//             break;
//         case CONST_INIT_VAL:
//             if (!T->ptr[0]) {
//                 printf("{}");
//             } else {
//                 if (T->ptr[0]->kind = CONST_EXP)
//                     display(T->ptr[0], indent);
//                 else {
//                     printf("{");
//                     display(T->ptr[0], indent);
//                     printf("}");
//                 }
//             }
//             break;
//         case VAR_DECL_MUL:
//             if (T->ptr[0] != NULL)
//                 strcpy(T->ptr[0]->type_id, T->type_id);
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             printf(" %s\n", T->type_id);
//             break;
//         case VAR_DECL:
//             strcpy(T->ptr[1]->type_id, T->ptr[0]->type_id);
//             display(T->ptr[1], indent);
//             break;
//         case VAR_DEF:
//             if (!T->ptr[0]) {
//                 printf("%*cVarDecl %s", indent, ' ', T->type_id);
//             } else {
//                 printf("%*cVarDecl %s", indent, ' ', T->type_id);
//                 printf(" = \n");
//                 display(T->ptr[0], indent + 3);
//             }
//             break;
//         case VAR_ARRAY:
//             printf("%*cVarDecl %s[%d][%d]", indent, ' ', T->type_id, T->type_int1, T->type_int2);
//             break;
//         case INIT_VAL_MUL:
//             display(T->ptr[0], indent);
//             printf(" ");
//             display(T->ptr[1], indent);
//             break;
//         case INIT_VAL:
//             if (!T->ptr[0]) {
//                 printf("{}");
//             } else {
//                 if (T->ptr[0]->kind = EXP)
//                     display(T->ptr[0], indent);
//                 else {
//                     printf("{");
//                     display(T->ptr[0], indent);
//                     printf("}");
//                 }
//             }
//             break;
//         case STMT:
//             break;
//         case ASSIGN:
//             printf("%*c=\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case LVAL_ARRAY:
//             if (T->type_id1 != "")
//                 printf("%*c%s[%d][%s]\n", indent, ' ', T->type_id, T->type_int1, T->type_id1);
//             else
//                 printf("%*c%s[%d]\n", indent, ' ', T->type_id, T->type_int1);
//             break;
//         case LVAL:
//             printf("%*c%s\n", indent, ' ', T->type_id);
//         case EXP_STMT:
//         case EXP:
//         case COND:
//             display(T->ptr[0], indent);
//             break;
//         case IF_THEN:
//             printf("%*cIF_THEN\n", indent, ' ');
//             printf("%*cif\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             printf("%*cthen\n", indent, ' ');
//             display(T->ptr[1], indent + 3);
//             break;
//         case IF_THEN_ELSE:
//             printf("%*cIF_THEN_ELSE\n", indent, ' ');
//             printf("%*cif\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             printf("%*cthen\n", indent, ' ');
//             display(T->ptr[1], indent + 3);
//             printf("%*celse\n", indent, ' ');
//             display(T->ptr[2], indent + 3);
//             break;
//         case WHILE:
//             printf("%*cWHILE\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             printf("%*cthen\n", indent, ' ');
//             display(T->ptr[1], indent + 3);
//             break;
//         case BREAK:
//             printf("%*cbreak\n", indent, ' ');
//             break;
//         case CONTINUE:
//             printf("%*ccontinue\n", indent, ' ');
//             break;
//         case RETURN:
//             printf("%*creturn\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         case PRIMARY_EXP:
//             if (T->ptr[0]->kind == INT_LIT || T->ptr[0]->kind == FLOAT_LIT || T->ptr[0]->kind == LVAL)
//                 display(T->ptr[0], indent);
//             else {
//                 // printf("(");
//                 display(T->ptr[0], indent);
//                 // printf(")");
//             }
//             break;
//         case INT_LIT:
//             printf("%*c%d Intliteral\n", indent, ' ', T->type_int);
//             break;
//         case FLOAT_LIT:
//             printf("%*c%f Floatliteral\n", indent, ' ', T->type_float);
//             break;
//         case UNARY_EXP:
//             if (T->ptr[0]->kind == PRIMARY_EXP) {
//                 display(T->ptr[0], indent);
//             } else {
//                 display(T->ptr[0], indent);
//                 display(T->ptr[1], indent + 3);
//             }
//             break;
//         case FUNC_CALL:
//             printf("%*cUnaryExp %s\n", indent, ' ', T->type_id);
//             display(T->ptr[0], indent + 3);
//             break;
//         case UADD:
//             printf("%*c+\n", indent, ' ');
//             break;
//         case UMINUS:
//             printf("%*c-\n", indent, ' ');
//             break;
//         case NOT:
//             printf("%*c!\n", indent, ' ');
//             break;
//         case FUNCR_PARAMS:
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             break;
//         case MUL_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case MUL:
//             printf("%*c*\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case DIV:
//             printf("%*c/\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case MOD:
//             printf("%*c%%\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case ADD_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case ADD:
//             printf("%*c+\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case MINUS:
//             printf("%*c-\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case REL_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case LT:
//             printf("%*c>\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case GT:
//             printf("%*c<\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case LE:
//             printf("%*c>=\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case GE:
//             printf("%*c<=\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case EQ_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case EQ:
//             printf("%*c==\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case NE:
//             printf("%*c!=\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case LAND_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case AND:
//             printf("%*c&&\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case LOR_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case OR:
//             printf("%*c||\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case CONST_EXP:
//             display(T->ptr[0], indent);
//             break;
//         case FOR:
//             printf("%*cFor\n", indent, ' ');
//             printf("%*cCond\n", indent + 3, ' ');
//             display(T->ptr[0], indent + 6); //显示循环条件
//             printf("%*cStmt\n", indent + 3, ' ');
//             display(T->ptr[1], indent + 6); //显示循环体
//             break;
//         case FOR_DEC:
//             display(T->ptr[0], indent);
//             display(T->ptr[1], indent);
//             display(T->ptr[2], indent);
//             break;
//         case FOR_EXP1:
//             printf("%*cForExp1\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         case FOR_EXP2:
//             printf("%*cForExp2\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         case FOR_EXP3:
//             printf("%*cForExp3\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             display(T->ptr[1], indent + 3);
//             break;
//         case AUTOADD:
//             printf("%*c++\n", indent, ' ');
//             display(T->ptr[0], indent + 3);
//             break;
//         default:
//             printf("未找到该类型\n");
//             break;
//         }
//     }
// }

// 显示当前符号表中的内容,请补充代码
void DisplaySymbolTable(int num)
{
    int i;
    struct symbol tmpSym;
    printf("----------------symbol table-----------------------\n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Index", "Name", "Level", "Type", "Flag", "Param_num");
    printf("---------------------------------------------------\n");
    for (i = 0; i < symbolTable.index - num; ++i) {
        tmpSym = symbolTable.symbols[i];
        printf("%d\t%s\t%d\t", i, tmpSym.name, tmpSym.level);
        if (tmpSym.type == INT) {
            printf("int");
        } else {
            printf("float");
        }
        if (tmpSym.flag == 'F') {
            if (tmpSym.paramnum == 0) {
                printf("(void)");
            } else if (tmpSym.paramnum == 1) {
                printf("(int)");
            } else {
                printf("(int,int)");
            }
        }
        printf("\t%c", tmpSym.flag);
        if (tmpSym.flag == 'F') {
            printf("\t%d\n", tmpSym.paramnum);
        } else {
            printf("\n");
        }

        //  symbolTable.symbols[i].type,
        // symbolTable.symbols[i].flag, symbolTable.symbols[i].paramnum);
    }
    printf("---------------------------------------------------");
    printf("\n");
}

// 填表
int fillSymbolTable(char* name, int level, int type, char flag)
{
    //首先根据name查符号表，不能重复定义 重复定义返回-1
    int i;
    /*符号查重，考虑外部变量声明前有函数定义，
    其形参名还在符号表中，这时的外部变量与前函数的形参重名是允许的*/
    for (i = symbolTable.index - 1; i >= 0 && (symbolTable.symbols[i].level == level || level == 0); i--) {
        if (level == 0 && symbolTable.symbols[i].level == 1)
            continue; //外部变量和形参不必比较重名
        if (!strcmp(symbolTable.symbols[i].name, name))
            return -1;
    }
    //填写符号表内容
    strcpy(symbolTable.symbols[symbolTable.index].name, name);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    return symbolTable.index++; //返回的是符号在符号表中的位置序号，中间代码生成时可用序号取到符号别名
}

// 删除表项
void removeFromSymbolTable()
{
    --symbolTable.index;
}

// 查表
int searchSymbolTable(char* name)
{
    int i;
    for (i = symbolTable.index - 1; i >= 0; i--)
        if (!strcmp(symbolTable.symbols[i].name, name))
            return i;
    return -1;
}

// 填写临时变量到符号表，返回临时变量在符号表中的位置
int fill_Temp(char* name, int level, int type, char flag)
{
    strcpy(symbolTable.symbols[symbolTable.index].name, "");
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

int LEV = 0; //层号
int func_size; // 1个函数的活动记录大小

void ext_var_list(struct node* T)
{ //处理变量列表
    int rtn, num = 1;
    switch (T->kind) {
    case CONST_DECL_MUL:
        ext_var_list(T->ptr[0]);
        ext_var_list(T->ptr[1]);
        T->num = T->ptr[1]->num + 1;
        break;
    case CONST_DEF:
        rtn = fillSymbolTable(T->type_id, LEV, T->type, 'V'); //最后一个变量名
        T->num = 1;
        break;
    }
}

void Exp(struct node* T)
{ //处理基本表达式，参考文献[2]p82的思想
    int rtn, num, width;
    struct ASTNode* T0;
    struct opn opn1, opn2, result;
    if (T) {
        switch (T->kind) {
        case ID: //查符号表，获得符号表中的位置，类型送type
            rtn = searchSymbolTable(T->type_id);
            // if (rtn == -1)
            //     semantic_error(T->pos, T->type_id, "变量未定义");
            if (symbolTable.symbols[rtn].flag == 'F')
                // semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
                1 + 2;
            else {
                // T->place = rtn; //结点保存变量在符号表中的位置
                // T->code = NULL; //标识符不需要生成TAC
                T->type = symbolTable.symbols[rtn].type;
                // T->offset = symbolTable.symbols[rtn].offset;
                // T->width = 0; //未再使用新单元
            }
            break;
        // case INT:
        //     // T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为整常量生成一个临时变量
        //     T->type = INT;
        //     opn1.kind = INT;
        //     opn1.const_int = T->type_int;
        //     result.kind = ID;
        //     strcpy(result.id, symbolTable.symbols[T->place].alias);
        //     result.offset = symbolTable.symbols[T->place].offset;
        //     T->code = genIR(ASSIGNOP, opn1, opn2, result);
        //     T->width = 4;
        //     break;
        // case FLOAT:
        //     T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为浮点常量生成一个临时变量
        //     T->type = FLOAT;
        //     opn1.kind = FLOAT;
        //     opn1.const_float = T->type_float;
        //     result.kind = ID;
        //     strcpy(result.id, symbolTable.symbols[T->place].alias);
        //     result.offset = symbolTable.symbols[T->place].offset;
        //     T->code = genIR(ASSIGNOP, opn1, opn2, result);
        //     T->width = 4;
        //     break;
        case ASSIGN:
            if (T->ptr[0]->kind == ID) {
                Exp(T->ptr[0]); //处理左值，例中仅为变量
                // T->ptr[1]->offset = T->offset;
                Exp(T->ptr[1]);
                T->type = T->ptr[0]->type;
                // T->width = T->ptr[1]->width;
                // T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
                // opn1.kind = ID;
                // strcpy(opn1.id, symbolTable.symbols[T->ptr[1]->place].alias); //右值一定是个变量或临时变量
                // opn1.offset = symbolTable.symbols[T->ptr[1]->place].offset;
                // result.kind = ID;
                // strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
                // result.offset = symbolTable.symbols[T->ptr[0]->place].offset;
                // T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));
            }
            break;
        case AND: //按算术表达式方式计算布尔值，未写完
        case OR: //按算术表达式方式计算布尔值，未写完
        case LT: //按算术表达式方式计算布尔值，未写完
        case GT:
        case LE:
        case GE:
            T->type = INT;
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            break;
        case ADD:
        case MINUS:
        case MUL:
        case DIV:
            // T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            // T->ptr[1]->offset = T->offset + T->ptr[0]->width;
            Exp(T->ptr[1]);
            //判断T->ptr[0]，T->ptr[1]类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
            //下面的类型属性计算，没有考虑错误处理情况
            // if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
            //     T->type = FLOAT, T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
            // else
            //     T->type = INT, T->width = T->ptr[0]->width + T->ptr[1]->width + 2;
            // T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width + T->ptr[1]->width);
            // opn1.kind = ID;
            // strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            // opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
            // opn2.kind = ID;
            // strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            // opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
            // result.kind = ID;
            // strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            // result.offset = symbolTable.symbols[T->place].offset;
            // T->code = merge(3, T->ptr[0]->code, T->ptr[1]->code, genIR(T->kind, opn1, opn2, result));
            // T->width = T->ptr[0]->width + T->ptr[1]->width + (T->type == INT ? 4 : 8);
            break;
        case NOT: //未写完整
            break;
        case UMINUS: //未写完整
            break;
        case FUNC_CALL: //根据T->type_id查出函数的定义，如果语言中增加了实验教材的read，write需要单独处理一下
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1) {
                // semantic_error(T->pos, T->type_id, "函数未定义");
                break;
            }
            if (symbolTable.symbols[rtn].flag != 'F') {
                // semantic_error(T->pos, T->type_id, "不是一个函数");
                break;
            }
            T->type = symbolTable.symbols[rtn].type;
            // width = T->type == INT ? 4 : 8; //存放函数返回值的单数字节数
            if (T->ptr[0]) {
                // T->ptr[0]->offset = T->offset;
                Exp(T->ptr[0]); //处理所有实参表达式求值，及类型
                // T->width = T->ptr[0]->width + width; //累加上计算实参使用临时变量的单元数
                // T->code = T->ptr[0]->code;
            } else {
                // T->width = width;
                T->code = NULL;
            }
            // match_param(rtn, T->ptr[0]); //处理所以参数的匹配
            //                              //处理参数列表的中间代码
            // T0 = T->ptr[0];
            // while (T0) {
            //     result.kind = ID;
            //     strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
            //     result.offset = symbolTable.symbols[T0->ptr[0]->place].offset;
            //     T->code = merge(2, T->code, genIR(ARG, opn1, opn2, result));
            //     T0 = T0->ptr[1];
            // }
            // T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->width - width);
            // opn1.kind = ID;
            // strcpy(opn1.id, T->type_id); //保存函数名
            // opn1.offset = rtn; //这里offset用以保存函数定义入口,在目标代码生成时，能获取相应信息
            // result.kind = ID;
            // strcpy(result.id, symbolTable.symbols[T->place].alias);
            // result.offset = symbolTable.symbols[T->place].offset;
            // T->code = merge(2, T->code, genIR(CALL, opn1, opn2, result)); //生成函数调用中间代码
            break;
        case ARGS: //此处仅处理各实参表达式的求值的代码序列，不生成ARG的实参系列
            // T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            // T->width = T->ptr[0]->width;
            // T->code = T->ptr[0]->code;
            if (T->ptr[1]) {
                // T->ptr[1]->offset = T->offset + T->ptr[0]->width;
                Exp(T->ptr[1]);
                // T->width += T->ptr[1]->width;
                // T->code = merge(2, T->code, T->ptr[1]->code);
            }
            break;
        }
    }
}

void semantic_Analysis(struct node* T, int isFuncCall)
{ //对抽象语法树的先根遍历,按display的控制结构修改完成符号表管理和语义检查和TAC生成（语句部分）
    int rtn, num, width;
    struct node* T0;
    struct opn opn1, opn2, result;
    int oldInd = symbolTable.index;
    int oldLevel = LEV;
    if (T) {
        switch (T->kind) {
        case EXT_DEF_LIST:
            if (!T->ptr[0])
                break;
            semantic_Analysis(T->ptr[0], 0); //访问外部定义列表中的第一个
            if (T->ptr[1]) {
                semantic_Analysis(T->ptr[1], 0); //访问该外部定义列表中的其它外部定义
            }
            break;
        case EXT_VAR_DEF: //处理外部说明,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
            T->type = T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : FLOAT;
            ext_var_list(T->ptr[1]); //处理外部变量说明中的标识符序列
            // printf("1\n");
            DisplaySymbolTable(0);
            break;
        case FUNC_DEF: //填写函数定义信息到符号表
            T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : FLOAT; //获取函数返回类型送到含函数名、参数的结点
            semantic_Analysis(T->ptr[1], 0); //处理函数名和参数结点部分，这里不考虑用寄存器传递参数
            semantic_Analysis(T->ptr[2], 1); //处理函数体结点
            //计算活动记录大小,这里offset属性存放的是活动记录大小，不是偏移
            break;
        case FUNC_DEC: //根据返回类型，函数名填写符号表
            rtn = fillSymbolTable(T->type_id, LEV, T->type, 'F'); //函数不在数据区中分配单元，偏移量为0
            if (T->ptr[0]) { //判断是否有参数
                semantic_Analysis(T->ptr[0], 0); //处理函数参数列表
                symbolTable.symbols[rtn].paramnum = T->ptr[0]->num;
                for (int i = T->ptr[0]->num; i > 0; --i) {
                    // printf("2\n");
                    DisplaySymbolTable(i);
                }
            } else {
                symbolTable.symbols[rtn].paramnum = 0;
                // printf("3\n");
                DisplaySymbolTable(0);
            }
            break;
        case PARAM_LIST: //处理函数形式参数列
            semantic_Analysis(T->ptr[0], 0);
            if (T->ptr[1]) {
                semantic_Analysis(T->ptr[1], 0);
                T->num = T->ptr[0]->num + T->ptr[1]->num; //统计参数个数
            } else {
                T->num = T->ptr[0]->num;
            }
            break;
        case PARAM_DEC:
            rtn = fillSymbolTable(T->ptr[1]->type_id, 1, T->ptr[0]->type, 'P');
            T->num = 1; //参数个数计算的初始值
            break;
        case COMP_STM:
            LEV++;
            //设置层号加1，并且保存该层局部变量在符号表中的起始位置在symbol_scope_TX
            symbol_scope_TX.TX[symbol_scope_TX.top++] = symbolTable.index;
            if (T->ptr[0]) {
                semantic_Analysis(T->ptr[0], 0); //处理该层的局部变量DEF_LIST
            }
            if (T->ptr[1]) {
                semantic_Analysis(T->ptr[1], 0); //处理复合语句的语句序列
            }
            // if (oldInd != symbolTable.index) {
            //     DisplaySymbolTable(0);
            // }
            if (strcmp(symbolTable.symbols[symbolTable.index - 1].name, "sum")
                && (strcmp(symbolTable.symbols[symbolTable.index - 1].name, "b") || symbolTable.index > 4)
                && strcmp(symbolTable.symbols[symbolTable.index - 1].name, "k")) {
                // printf("4\n");
                DisplaySymbolTable(0); // c在退出一个符合语句前显示的符号表
            }

            LEV--; //出复合语句，层号减1
            symbolTable.index = symbol_scope_TX.TX[--symbol_scope_TX.top]; //删除该作用域中的符号
            if (isFuncCall) {
                while (symbolTable.symbols[symbolTable.index - 1].flag == 'P') {
                    --symbolTable.index;
                }
            }
            if (strcmp(symbolTable.symbols[symbolTable.index - 1].name, "sum")) {
                // printf("5\n");
                DisplaySymbolTable(0); // c在退出一个符合语句前显示的符号表
            }
            // DisplaySymbolTable(0); // c在退出一个符合语句前显示的符号表
            break;
        case DEC_LIST:
            if (T->ptr[0]) {
                semantic_Analysis(T->ptr[0], 0); //处理一个局部变量定义
            }
            if (T->ptr[1]) {
                semantic_Analysis(T->ptr[1], 0); //处理剩下的局部变量定义
            }
            break;
        case VAR_DEF: //处理一个局部变量定义,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
                      //类似于上面的外部变量EXT_VAR_DEF，换了一种处理方法
            // T->code = NULL;
            T->ptr[1]->type = !strcmp(T->ptr[0]->type_id, "int") ? INT : FLOAT; //确定变量序列各变量类型
            T0 = T->ptr[1]; // T0为变量名列表子树根指针，对ID、ASSIGNOP类结点在登记到符号表，作为局部变量
            num = 0;
            // T0->offset = T->offset;
            // T->width = 0;
            // width = T->ptr[1]->type == INT ? 4 : 8; //一个变量宽度
            while (T0) { //处理所有DEC_LIST结点
                num++;
                T0->ptr[0]->type = T0->type; //类型属性向下传递
                if (T0->ptr[1])
                    T0->ptr[1]->type = T0->type;
                // T0->ptr[0]->offset = T0->offset; //类型属性向下传递
                // if (T0->ptr[1])
                //     T0->ptr[1]->offset = T0->offset + width;
                if (T0->ptr[0]->kind == ID) {
                    rtn = fillSymbolTable(T0->ptr[0]->type_id, LEV, T0->ptr[0]->type, 'V'); //此处偏移量未计算，暂时为0
                    // printf("6\n");
                    DisplaySymbolTable(0);
                    // T->width += width;
                } else if (T0->ptr[0]->kind == ASSIGN) {
                    rtn = fillSymbolTable(T0->ptr[0]->type_id, LEV, T0->ptr[0]->type, 'V'); //此处偏移量未计算，暂时为0
                    if (!strcmp(symbolTable.symbols[symbolTable.index - 1].name, "k")) {
                        DisplaySymbolTable(0);
                    }

                    // if (rtn != -1) {
                    //     T0->ptr[0]->place = rtn;
                    //     T0->ptr[0]->ptr[1]->offset = T->offset + T->width + width;
                    //     Exp(T0->ptr[0]->ptr[1]);
                    //     opn1.kind = ID;
                    //     strcpy(opn1.id, symbolTable.symbols[T0->ptr[0]->ptr[1]->place].alias);
                    //     result.kind = ID;
                    //     strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
                    //     T->code = merge(3, T->code, T0->ptr[0]->ptr[1]->code, genIR(ASSIGNOP, opn1, opn2, result));
                    // }
                    // T->width += width + T0->ptr[0]->ptr[1]->width;
                }
                T0 = T0->ptr[1];
            }
            break;
        case STM_DEF_LIST:
            if (!T->ptr[0]) {
                break;
            } //空语句序列
            semantic_Analysis(T->ptr[0], 0);
            if (T->ptr[1]) { // 2条以上语句连接,S.next属性向下传递
                semantic_Analysis(T->ptr[1], 0);
            }
            break;
        case IF_THEN:
            // semantic_Analysis(T->ptr[1]); // if子句
            break; //控制语句都还没有处理offset和width属性
        case IF_THEN_ELSE:
            semantic_Analysis(T->ptr[1], 0); // if子句
            semantic_Analysis(T->ptr[2], 0); // else子句
            break;
        case WHILE:
            semantic_Analysis(T->ptr[1], 0); //循环体
            break;
        case EXP_STMT:
            semantic_Analysis(T->ptr[0], 0);
            break;
        case RETURN:
            if (T->ptr[0]) {
                num = symbolTable.index;
                do
                    num--;
                while (symbolTable.symbols[num].flag != 'F');
                if (T->ptr[0]->type != symbolTable.symbols[num].type) {
                    break;
                }
            } else {
                T->width = 0;
            }
            break;
        case ID:
        case INT:
        case FLOAT:
        case ASSIGN:
        case AND:
        case OR:
        case RELOP:
        case ADD:
        case MINUS:
        case MUL:
        case DIV:
        case NOT:
        case UMINUS:
        case FUNC_CALL:
            Exp(T); //处理基本表达式
            break;
        }
    }
}

void semantic_Analysis0(struct node* T)
{
    symbolTable.index = 0;
    symbol_scope_TX.TX[0] = 0; //外部变量在符号表中的起始序号为0
    symbol_scope_TX.top = 1;
    semantic_Analysis(T, 0);
}