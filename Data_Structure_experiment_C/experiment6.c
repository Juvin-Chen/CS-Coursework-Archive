#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 // 最大顶点数

// --- 定义邻接表结构 ---

// 边节点 (Edge/Arc Node)
typedef struct ArcNode {
    int adjvex;              // 该边指向的顶点在数组中的下标
    struct ArcNode *nextarc; // 指向下一条边的指针
} ArcNode;

// 顶点节点 (Vertex Node)
typedef struct VNode {
    int data;                // 顶点信息 (这里存 1, 2, 3... 对应图中的编号)
    ArcNode *firstarc;       // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MAX_VERTEX_NUM];

// 图结构 (Graph)
typedef struct {
    AdjList vertices;        // 邻接表
    int vexnum, arcnum;      // 图的当前顶点数和边数
} ALGraph;

// --- 队列结构 (用于BFS) ---
typedef struct {
    int data[MAX_VERTEX_NUM];
    int front;
    int rear;
} Queue;

// 初始化队列
void InitQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

// 入队
void EnQueue(Queue *Q, int e) {
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front) return; // 队满
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
}

// 出队
int DeQueue(Queue *Q, int *e) {
    if (Q->front == Q->rear) return 0; // 队空
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return 1;
}

int QueueEmpty(Queue *Q) {
    return Q->front == Q->rear;
}

// --- 图的操作函数 ---

// 定位顶点在数组中的位置
int LocateVex(ALGraph *G, int v) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == v) return i;
    }
    return -1;
}

// 创建图 (按照实验要求构建邻接表)
void CreateGraph(ALGraph *G) {
    int i, v1, v2;
    
    printf("请输入顶点数和边数: ");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    printf("请输入 %d 个顶点的值: ", G->vexnum);
    for (i = 0; i < G->vexnum; i++) {
        scanf("%d", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL; // 初始化指针为空
    }

    printf("请输入 %d 条边:\n", G->arcnum);
    // 例如对于顶点1，先输入 1 2，再输入 1 4
    
    for (int k = 0; k < G->arcnum; k++) {
        scanf("%d %d", &v1, &v2);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        if (i == -1 || j == -1) {
            printf("顶点不存在，请重新输入\n");
            k--;
            continue;
        }

        // 创建新的边节点
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->nextarc = NULL;

        // 将新边插入到链表尾部 (为了保持遍历顺序与输入顺序一致: 字母序/数字序)
        // 如果插入头部，顺序会反过来。为了实验准确性，我们插入尾部。
        if (G->vertices[i].firstarc == NULL) {
            G->vertices[i].firstarc = p;
        } else {
            ArcNode *temp = G->vertices[i].firstarc;
            while (temp->nextarc != NULL) {
                temp = temp->nextarc;
            }
            temp->nextarc = p;
        }
    }
}

// 全局访问标记数组
bool visited[MAX_VERTEX_NUM];

// --- 深度优先遍历 (DFS) ---
void DFS(ALGraph *G, int vIndex) {
    visited[vIndex] = true;
    printf("%d ", G->vertices[vIndex].data); // 访问节点

    ArcNode *p = G->vertices[vIndex].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void DFSTraverse(ALGraph *G, int startVal) {
    int startIdx = LocateVex(G, startVal);
    if (startIdx == -1) {
        printf("起始点不存在!\n");
        return;
    }

    // 初始化访问数组
    for (int i = 0; i < G->vexnum; i++) visited[i] = false;

    printf("深度优先遍历 (DFS) 序列: ");
    DFS(G, startIdx); // 从指定点开始
    printf("\n");
}

// --- 广度优先遍历 (BFS) ---
void BFSTraverse(ALGraph *G, int startVal) {
    int startIdx = LocateVex(G, startVal);
    if (startIdx == -1) {
        printf("起始点不存在!\n");
        return;
    }

    for (int i = 0; i < G->vexnum; i++) visited[i] = false;

    Queue Q;
    InitQueue(&Q);

    printf("广度优先遍历 (BFS) 序列: ");
    
    visited[startIdx] = true;
    printf("%d ", G->vertices[startIdx].data);
    EnQueue(&Q, startIdx);

    while (!QueueEmpty(&Q)) {
        int u;
        DeQueue(&Q, &u);
        ArcNode *p = G->vertices[u].firstarc;
        while (p != NULL) {
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = true;
                printf("%d ", G->vertices[p->adjvex].data);
                EnQueue(&Q, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

// --- 主函数 ---
int main() {
    ALGraph G;
    printf("实验6: 图的遍历 (邻接表实现) \n");
    
    // 1. 建图
    CreateGraph(&G);

    // 2. 获取用户指定的起点
    int startNode;
    printf("\n请输入遍历起始点: ");
    scanf("%d", &startNode);

    // 3. 执行遍历
    printf("\n--- 运行结果 ---\n");
    DFSTraverse(&G, startNode);
    BFSTraverse(&G, startNode);

    return 0;
}