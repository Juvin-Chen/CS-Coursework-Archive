#pragma once
#include"Car.h"


#define MAXSIZE 2 //配合题目中给的测试数据

//顺序栈的定义,ADT
typedef struct{
    car *base;
    car *top;
    int stacksize;
}Stack;

Status InitStack(Stack *s);
Status Push(Stack *s,car e);
Status Pop(Stack *s,car *e);

