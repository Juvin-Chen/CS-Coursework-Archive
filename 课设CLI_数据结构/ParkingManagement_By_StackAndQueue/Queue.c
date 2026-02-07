#include "Queue.h"
#include <stdlib.h>

// 链队的初始化
Status InitQueue(Queue *q) {
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    q->front->next = NULL;
    return OK;
}

// 入队
Status EnQueue(Queue *q, car e) {
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return OK;
}

// 出队
Status DeQueue(Queue *q, car *e) {
    if (q->front == q->rear)
        return ERROR;
    QNode *p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;
    free(p);
    return OK;
}
