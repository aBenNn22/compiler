#include "def.h"
struct node* mknode(int kind, struct node* first, struct node* second, struct node* third, struct node* fourth, int pos)
{
    struct node* T = (struct node*)malloc(sizeof(struct node));
    T->kind = kind;
    T->ptr[0] = first;
    T->ptr[1] = second;
    T->ptr[2] = third;
    T->ptr[3] = fourth;
    T->pos = pos;
    return T;
}
void display(struct node* T, int indent)
{ //对抽象语法树的先根遍历
    int i = 1;
    struct node* T0;
    if (T) {
        switch (T->kind) {
        case COMP_UNIT:
            display(T->ptr[0], indent);
            printf("CompUnit\n");
            display(T->ptr[1], indent);
            break;
        case FUNC_DEF:
            printf("%*cFuncDef %s %s", indent, ' ', T->ptr[0]->type_id, T->type_id);
            if (T->ptr[2]) {
                printf("(");
                display(T->ptr[1], indent);
                printf(")\n");
                display(T->ptr[2], indent + 3);
                printf("\n");
                break;
            } else
                printf("()\n");
            display(T->ptr[1], indent + 3);
            break;
        case FUNC_PARAMS:
            display(T->ptr[0], indent);
            printf(" ");
            display(T->ptr[1], indent);
            break;
        case FUNC_PARAM_MUL:
            display(T->ptr[0], indent);
            if (T->ptr[0]) {
                printf("[");
                display(T->ptr[1], indent);
                printf("]");
            }
            break;
        case FUNC_PARAM:
            if (!T->ptr[1]) {
                printf("%*c%s %s", indent, ' ', T->ptr[0]->type_id, T->type_id);
            } else {
                printf("%*c%s %s[]", indent, ' ', T->ptr[0]->type_id, T->type_id);
                display(T->ptr[1], indent);
            }
            break;
        case BLOCK_MUL:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case BLOCK:
            printf("%*cBlock\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case BLOCK_ITEM:
            display(T->ptr[0], indent);
            break;
        case DECL:
            printf("%*cDecl\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case CONST_DECL_MUL:
            if (T->ptr[0] != NULL)
                strcpy(T->ptr[0]->type_id, T->type_id);
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            printf(" %s\n", T->type_id);
            break;
        case CONST_DECL:
            // printf("%*cConstDecl %s %s\n", indent, ' ', T->type_id, T->ptr[0]->type_id);
            strcpy(T->ptr[1]->type_id, T->ptr[0]->type_id);
            display(T->ptr[1], indent);
            break;
        case CONST_DEF_MUL:
            display(T->ptr[0], indent);
            printf("[");
            display(T->ptr[1], 0);
            printf("]");
            break;
        case CONST_DEF:
            printf("%*cConstDecl %s", indent, ' ', T->type_id);
            display(T->ptr[0], indent);
            printf("=");
            display(T->ptr[1], indent);
            break;
        case CONST_INIT_VAL_MUL:
            display(T->ptr[0], indent);
            printf(" ");
            display(T->ptr[1], indent);
            break;
        case CONST_INIT_VAL:
            if (!T->ptr[0]) {
                printf("{}");
            } else {
                if (T->ptr[0]->kind = CONST_EXP)
                    display(T->ptr[0], indent);
                else {
                    printf("{");
                    display(T->ptr[0], indent);
                    printf("}");
                }
            }
            break;
        case VAR_DECL_MUL:
            if (T->ptr[0] != NULL)
                strcpy(T->ptr[0]->type_id, T->type_id);
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            printf(" %s\n", T->type_id);
            break;
        case VAR_DECL:
            strcpy(T->ptr[1]->type_id, T->ptr[0]->type_id);
            display(T->ptr[1], indent);
            break;
        case VAR_DEF:
            if (!T->ptr[0]) {
                printf("%*cVarDecl %s", indent, ' ', T->type_id);
            } else {
                printf("%*cVarDecl %s", indent, ' ', T->type_id);
                printf(" = \n");
                display(T->ptr[0], indent + 3);
            }
            break;
        case VAR_ARRAY:
            printf("%*cVarDecl %s[%d][%d]", indent, ' ', T->type_id, T->type_int1, T->type_int2);
            break;
        case INIT_VAL_MUL:
            display(T->ptr[0], indent);
            printf(" ");
            display(T->ptr[1], indent);
            break;
        case INIT_VAL:
            if (!T->ptr[0]) {
                printf("{}");
            } else {
                if (T->ptr[0]->kind = EXP)
                    display(T->ptr[0], indent);
                else {
                    printf("{");
                    display(T->ptr[0], indent);
                    printf("}");
                }
            }
            break;
        case STMT:
            break;
        case ASSIGN:
            printf("%*c=\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case LVAL_ARRAY:
            if (T->type_id1 != "")
                printf("%*c%s[%d][%s]\n", indent, ' ', T->type_id, T->type_int1, T->type_id1);
            else
                printf("%*c%s[%d]\n", indent, ' ', T->type_id, T->type_int1);
            break;
        case LVAL:
            printf("%*c%s\n", indent, ' ', T->type_id);
        case EXP_STMT:
        case EXP:
        case COND:
            display(T->ptr[0], indent);
            break;
        case IF_THEN:
            printf("%*cIF_THEN\n", indent, ' ');
            printf("%*cif\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            printf("%*cthen\n", indent, ' ');
            display(T->ptr[1], indent + 3);
            break;
        case IF_THEN_ELSE:
            printf("%*cIF_THEN_ELSE\n", indent, ' ');
            printf("%*cif\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            printf("%*cthen\n", indent, ' ');
            display(T->ptr[1], indent + 3);
            printf("%*celse\n", indent, ' ');
            display(T->ptr[2], indent + 3);
            break;
        case WHILE:
            printf("%*cWHILE\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            printf("%*cthen\n", indent, ' ');
            display(T->ptr[1], indent + 3);
            break;
        case BREAK:
            printf("%*cbreak\n", indent, ' ');
            break;
        case CONTINUE:
            printf("%*ccontinue\n", indent, ' ');
            break;
        case RETURN:
            printf("%*creturn\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case PRIMARY_EXP:
            if (T->ptr[0]->kind == INT_LIT || T->ptr[0]->kind == FLOAT_LIT || T->ptr[0]->kind == LVAL)
                display(T->ptr[0], indent);
            else {
                // printf("(");
                display(T->ptr[0], indent);
                // printf(")");
            }
            break;
        case INT_LIT:
            printf("%*c%d Intliteral\n", indent, ' ', T->type_int);
            break;
        case FLOAT_LIT:
            printf("%*c%f Floatliteral\n", indent, ' ', T->type_float);
            break;
        case UNARY_EXP:
            if (T->ptr[0]->kind == PRIMARY_EXP) {
                display(T->ptr[0], indent);
            } else {
                display(T->ptr[0], indent);
                display(T->ptr[1], indent + 3);
            }
            break;
        case FUNC_CALL:
            printf("%*cUnaryExp %s\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            break;
        case UADD:
            printf("%*c+\n", indent, ' ');
            break;
        case UMINUS:
            printf("%*c-\n", indent, ' ');
            break;
        case NOT:
            printf("%*c!\n", indent, ' ');
            break;
        case FUNCR_PARAMS:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            break;
        case MUL_EXP:
            display(T->ptr[0], indent);
            break;
        case MUL:
            printf("%*c*\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case DIV:
            printf("%*c/\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case MOD:
            printf("%*c%%\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case ADD_EXP:
            display(T->ptr[0], indent);
            break;
        case ADD:
            printf("%*c+\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case MINUS:
            printf("%*c-\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case REL_EXP:
            display(T->ptr[0], indent);
            break;
        case LT:
            printf("%*c>\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case GT:
            printf("%*c<\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case LE:
            printf("%*c>=\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case GE:
            printf("%*c<=\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case EQ_EXP:
            display(T->ptr[0], indent);
            break;
        case EQ:
            printf("%*c==\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case NE:
            printf("%*c!=\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case LAND_EXP:
            display(T->ptr[0], indent);
            break;
        case AND:
            printf("%*c&&\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case LOR_EXP:
            display(T->ptr[0], indent);
            break;
        case OR:
            printf("%*c||\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case CONST_EXP:
            display(T->ptr[0], indent);
            break;
        case FOR:
            printf("%*cFor\n", indent, ' ');
            printf("%*cCond\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6); //显示循环条件
            printf("%*cStmt\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示循环体
            break;
        case FOR_DEC:
            display(T->ptr[0], indent);
            display(T->ptr[1], indent);
            display(T->ptr[2], indent);
            break;
        case FOR_EXP1:
            printf("%*cForExp1\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case FOR_EXP2:
            printf("%*cForExp2\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case FOR_EXP3:
            printf("%*cForExp3\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case AUTOADD:
            printf("%*c++\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        default:
            printf("未找到该类型\n");
            break;
        }
    }
}