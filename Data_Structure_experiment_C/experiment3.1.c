/*
编写程序，把十进制正整数转换为 n（n 可以为 2、8、16 等等）进制数输出。
注意：转换必须用书上 P48 页算法 3.1 实现，其他方法不给分；
基本操作的算法部分见书上 P46-P47 页。
*/

//c语言里面不支持引用，所以传递函数参数时需要用指针传递进去

#include<stdio.h>
#include<stdlib.h>

typedef int Status;

#define OVERFLOW -2 //通过宏定义给 “溢出错误” 定义一个标识性的返回值，用于明确表示内存分配溢出或数据结构操作溢出的错误状态。
#define OK 1
#define ERROR 0

//顺序栈的定义
#define MAXSIZE 100 //顺序栈存储空间的初始分配量
typedef struct {
    int *base;  //栈底
    int *top;  //栈顶
    int stacksize;  //栈可用的最大容量
}SqStack;

SqStack s;

//顺序栈的初始化
Status InitStack(SqStack *s){
    //构造一个空栈
    s->base=(int *)malloc(sizeof(int)*MAXSIZE); //为顺序栈分配了一个最大容量为MAXSIZE大小的数组空间
    if(!s->base) exit(OVERFLOW);
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return OK;
}

//入栈
Status Push(SqStack *s,int e){
    if(s->top-s->base==s->stacksize) return ERROR;
    *(s->top)=e;
    s->top++; //将栈顶指针移动到下一个位置
    return OK;
}

//出栈
Status Pop(SqStack *s,int *e){
    if(s->top==s->base) return ERROR;
    s->top--;  //将栈顶指针-1
    *e=*(s->top);
    return OK;
}


//取栈顶元素，将栈顶元素返回，而栈顶的指针保持不变
int GetTop(SqStack s){
    if(s.top!=s.base) return *(s.top-1);
}

//进制的转换
void Conversion(int num,int n){ //num:需要进行转换的数字，n代表转换成n进制
    InitStack(&s);
    while(num){
        Push(&s,num%n);
        num/=n;
    }
    const char *digit="0123456789ABCDEF";
    int e;
    while(Pop(&s, &e)){  //栈不为空的时候，将栈顶元素出栈
        printf("%c",digit[e]);
    }
    free(s.base);
}

void main(){
    int num,n;
    printf("请输入十进制数字: ");
    scanf("%d",&num);
    printf("请输入需要转换的进制: ");
    scanf("%d",&n);
    Conversion(num,n);
}