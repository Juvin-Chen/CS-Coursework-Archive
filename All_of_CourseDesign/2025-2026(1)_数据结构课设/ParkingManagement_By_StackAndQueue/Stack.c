#include "Stack.h"
#include <stdlib.h>

// 顺序栈的初始化
Status InitStack(Stack *s) {
    s->base = (car *)malloc(sizeof(car) * MAXSIZE);
    if (!s->base)
        exit(OVERFLOW);
    s->top = s->base;
    s->stacksize = MAXSIZE;
    return OK;
}

// 入栈
Status Push(Stack *s, car e) {
    if (s->top - s->base == s->stacksize)
        return ERROR;
    *(s->top) = e;
    s->top++;
    return OK;
}

// 出栈
Status Pop(Stack *s, car *e) {
    if (s->top == s->base)
        return ERROR;
    s->top--;
    *e = *(s->top);
    return OK;
}
