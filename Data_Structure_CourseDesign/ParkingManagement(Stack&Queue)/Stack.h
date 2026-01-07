#pragma once

//ADT

typedef int Status;
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define MAXSIZE 2 //配合题目中给的测试数据

//顺序栈的定义
typedef struct{
    int *base;
    int *top;
    int stacksize;
}Stack;

Status InitStack(Stack *s);
Status Push(Stack *s,int e);
Status Pop(Stack *s,int *e);
int GetTop(Stack *s);
