#pragma once
#include"Car.h"

//队列的链式存储结构
typedef struct QNode{
    car data;
    struct QNode *next;
}QNode;

//带有头结点
typedef struct{
    QNode* front;  //队头指针
    QNode* rear;  //队尾指针
}Queue;

Status InitQueue(Queue *q);
Status EnQueue(Queue *q,car e);
Status DeQueue(Queue *q,car* e);