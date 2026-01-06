#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char TElemType; 

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//栈的定义 (用于非递归遍历) 
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
    BiTree *base; // 栈底指针 (存储的是树节点的指针)
    BiTree *top;  // 栈顶指针
    int stacksize;
} SqStack;

//栈的基本操作

//初始化栈
Status InitStack(SqStack *S) {
    S->base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//判空
Status StackEmpty(SqStack S) {
    if (S.top == S.base) return OK; // 这里的OK代表真，即为空
    return ERROR; // 不为空
}

// 进栈
Status Push(SqStack *S, BiTree e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (BiTree *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(BiTree));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}

// 出栈
Status Pop(SqStack *S, BiTree *e) {
    if (S->top == S->base) return ERROR;
    *e = *--S->top;
    return OK;
}

//算法6.4:先序创建二叉树,按先序输入，空节点用'#'代替
Status CreateBiTree(BiTree *T) {
    char ch;
    scanf("%c", &ch); // 读取一个字符

    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) exit(OVERFLOW);
        (*T)->data = ch;              // 生成根结点
        CreateBiTree(&(*T)->lchild);  // 构造左子树
        CreateBiTree(&(*T)->rchild);  // 构造右子树
    }
    return OK;
}

// 访问函数
Status Visit(TElemType e) {
    printf("%c ", e);
    return OK;
}

//算法6.2: 中序遍历 (非递归)
Status InOrderTraverse(BiTree T) {
    SqStack S;
    InitStack(&S); 
    BiTree p = T;
    
    //循环条件：p不为空或者栈不为空
    while (p || !StackEmpty(S)) {
        if (p) {
            // 根指针进栈，遍历左子树
            Push(&S, p);
            p = p->lchild;
        } else {
            // 根指针退栈，访问根节点，遍历右子树
            Pop(&S, &p);
            if (!Visit(p->data)) return ERROR;
            p = p->rchild;
        }
    }
    printf("\n");
    return OK;
}

int main() {
    BiTree T;
    //调用算法6.4建树
    CreateBiTree(&T);
    //调用算法6.2进行中序遍历
    printf("中序遍历(非递归)结果为: ");
    InOrderTraverse(T);
    printf("(正确结果应为: e b f a c h g)\n");
    return 0;
}