#include"Stack.h"
#include<stdlib.h>

//顺序栈的初始化
Status InitStack(Stack *s){
    s->base=(int*)malloc(sizeof(int)*MAXSIZE);
    if(!s->base) exit(OVERFLOW);
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return OK;
}

//入栈
Status Push(Stack *s,int e){
    if(s->top-s->base==s->stacksize) return ERROR;
    *(s->top)=e;
    s->top++;
    return OK;
}

//出栈
Status Pop(Stack *s,int *e){
    if(s->top==s->base) return ERROR;
    s->top--;
    *e=*(s->top);
    return OK;
}

//获取栈顶元素
int GetTop(Stack *s){
    if(s->top!=s->base) return *(s->top-1);
}
