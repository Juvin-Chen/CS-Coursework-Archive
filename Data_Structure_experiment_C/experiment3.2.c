/*
利用栈的基本操作对给定的字符串判断其是否是回文，若是则输出“Right”，否则输出“Wrong”。例如：“ijklmnGnmlkji”是回文。
*/

#include<stdio.h>
#include<stdlib.h>

typedef int Status; //返回状态

#define OVERFLOW -2 //通过宏定义给 “溢出错误” 定义一个标识性的返回值，用于明确表示内存分配溢出或数据结构操作溢出的错误状态。
#define OK 1
#define ERROR 0

//顺序栈的定义
#define MAXSIZE 100 //顺序栈存储空间的初始分配量
typedef struct {
    char *base;  //栈底
    char *top;  //栈顶
    int stacksize;  //栈可用的最大容量
}SqStack;

SqStack s;

//顺序栈的初始化
Status InitStack(SqStack *s){
    //构造一个空栈
    s->base=(char *)malloc(sizeof(int)*MAXSIZE); //为顺序栈分配了一个最大容量为MAXSIZE大小的数组空间
    if(!s->base) exit(OVERFLOW);
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return OK;
}

//入栈
Status Push(SqStack *s,char e){
    if(s->top-s->base==s->stacksize) return ERROR;
    *(s->top)=e;
    s->top++; //将栈顶指针移动到下一个位置
    return OK;
}

//出栈
Status Pop(SqStack *s,char *e){
    if(s->top==s->base) return ERROR;
    s->top--;  //将栈顶指针-1
    *e=*(s->top);
    return OK;
}

//取栈顶元素，将栈顶元素返回，而栈顶的指针保持不变
char GetTop(SqStack s){
    if(s.top!=s.base) return *(s.top-1);
}

void main(){
    char str[100];
    scanf("%s",str); //scanf输入之后会自动在字符串末尾加上'\0'
    SqStack s;
    InitStack(&s);
    for(int i=0;str[i]!='\0';i++)
        Push(&s,str[i]);
    char c;
    int i=0;
    while (Pop(&s,&c))
    {
        if(c!=str[i]){
            printf("Wrong");
            return;
        }
        i++;
    }
    printf("Right");
    free(s.base);
}