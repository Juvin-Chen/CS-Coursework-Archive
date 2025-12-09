/*
假设循环队列的最大长度为 7，现在依次将以下数据入队列： {7， 5， 3， 9， 2， 4}；接着进行 3 次出队列的操作，再将 15、 18 这两个数据入队列，
最后从队头到队尾依次输出队列中的元素。
*/

/*
1. 循环队列的基本概念
什么是循环队列？
循环队列是一种特殊的线性数据结构，它使用固定大小的数组，通过模运算实现队列首尾相接的循环使用，有效解决了普通队列"假溢出"的问题。

2.循环队列的特点
固定大小：预先分配固定容量的数组
循环利用：当指针到达数组末尾时，回到数组开头
两个指针：front（队首）和 rear（队尾）
空和满的判断：需要特殊处理来区分队列空和队列满的状态
*/

#include<stdio.h>
#include<stdlib.h>

typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 7

 
//顺序队列
typedef struct{
    int *base;  //存储空间的基地址
    int front;  //头指针
    int rear;  //尾指针
}SqQueue;

//循环队列的初始化
Status InitQueue(SqQueue *q){
    q->base=(int *)malloc(sizeof(int)*MAXSIZE);
    if(!q->base) exit(OVERFLOW);  //分配失败
    q->front=q->rear=0;
    return OK;
}

//求队列长度
int QueueLength(SqQueue q){
    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

//入队，在队尾插入一个新的元素
Status EnQueue(SqQueue *q,int e){
    //若尾指针在循环意义上+1等于头指针，队满（因为有一个位置是不放元素的）
    if((q->rear+1)%MAXSIZE==q->front) return ERROR;
    q->base[q->rear]=e; //新元素插入队尾
    q->rear=(q->rear+1)%MAXSIZE;
    return OK;
}

//出队
Status DeQueue(SqQueue *q,int *e){
    if(q->front==q->rear) return ERROR;  //队空
    *e=q->base[q->front];  //返回队头元素的值，队头指针不变
    q->front=(q->front+1)%MAXSIZE;
    return OK;
}

//取队头元素
int GetHead(SqQueue q){
    if(q.front!=q.rear) return q.base[q.front]; 
    return -1;
}

void test(){
    SqQueue q;
    InitQueue(&q);
    int e;
    printf("先初始化队列： ");
    for(int i=0;i<6;i++){
        scanf("%d",&e);
        EnQueue(&q,e);
    }
    printf("进行三次出队操作\n");
    int i,k=3;
    while(k--) DeQueue(&q,&i);
    printf("再进行两个元素的入队: ");
    k=2;
    while(k--){
        scanf("%d",&e);
        EnQueue(&q,e);
    }
    printf("打印最终队列中的元素：");
    while(DeQueue(&q,&i)) printf("%d ",i);
}

int main(){
    test();
}
