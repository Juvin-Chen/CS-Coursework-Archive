#include "CampusMap.hpp"
#include <stack> 

CampusMap::CampusMap() {
    numNodes = 0;
    numEdges = 0;
    // 初始化邻接矩阵
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            if (i == j) adjMatrix[i][j] = 0; // 自己到自己距离为0
            else adjMatrix[i][j] = INF;      // 默认不连通
        }
    }
}

// 模拟读取地图数据
void CampusMap::initDefaultMap() {
    //添加景点 (下标 0-5)
    addSpot("大门");
    addSpot("图书馆");
    addSpot("明德楼");
    addSpot("食堂");
    addSpot("宿舍");
    addSpot("体育馆");

    //添加路径 (起点ID, 终点ID, 距离)
    addPath(0, 1, 100); // 大门 - 图书馆 (100m)
    addPath(0, 2, 300); // 大门 - 教学楼
    addPath(1, 3, 200); // 图书馆 - 食堂
    addPath(1, 2, 80);  // 图书馆 - 教学楼 (近道)
    addPath(2, 4, 400); // 教学楼 - 宿舍
    addPath(3, 4, 100); // 食堂 - 宿舍
    addPath(3, 5, 150); // 食堂 - 体育馆
    addPath(4, 5, 250); // 宿舍 - 体育馆

    cout << "地图数据加载完毕！当前共有 " << numNodes << " 个景点。" << endl;
}

void CampusMap::addSpot(string name) {
    if (numNodes >= MAX_NODES) return;
    vertexes[numNodes].id = numNodes;
    vertexes[numNodes].name = name;
    numNodes++;
}

void CampusMap::addPath(int startId, int endId, int dist) {
    if (startId < 0 || startId >= numNodes || endId < 0 || endId >= numNodes) return;
    
    // 邻接矩阵赋值
    adjMatrix[startId][endId] = dist;
    adjMatrix[endId][startId] = dist; 
    numEdges++;
}

int CampusMap::getIndexByName(string name) {
    for (int i = 0; i < numNodes; i++) {
        if (vertexes[i].name == name) return i;
    }
    return -1; // 没找到
}

void CampusMap::showAllSpots() {
    cout << "\n---------------- [校园景点列表] ----------------" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << "[" << i << "] " << vertexes[i].name << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

//迪杰斯特拉 (Dijkstra) 算法实现
void CampusMap::findShortestPath(string startName, string endName) {
    int start = getIndexByName(startName);
    int end = getIndexByName(endName);

    //输入校验
    if (start == -1 || end == -1) {
        cout << ">>> 错误：输入的景点名称不存在，请检查后重试！" << endl;
        return;
    }

    //算法数据结构准备
    int dist[MAX_NODES];   
    int path[MAX_NODES];   
    bool visited[MAX_NODES]; 

    // 初始化
    for (int i = 0; i < numNodes; i++) {
        dist[i] = adjMatrix[start][i]; 
        visited[i] = false;            
        if (adjMatrix[start][i] < INF && i != start) 
            path[i] = start;         
        else 
            path[i] = -1;              
    }

    // 起点自己到自己距离为0，且标记为已访问
    dist[start] = 0;
    visited[start] = true;

    // 开始循环 (遍历 n-1 次)
    for (int i = 0; i < numNodes - 1; i++) {
        int minPrice = INF;
        int u = -1; 

        // 寻找未访问点中距离最小的
        for (int j = 0; j < numNodes; j++) {
            if (!visited[j] && dist[j] < minPrice) {
                minPrice = dist[j];
                u = j;
            }
        }

        // 如果找不到连通点了，说明剩下的都是孤岛，跳出
        if (u == -1) break; 
        
        visited[u] = true; // 标记 u 已确定最短路

        for (int v = 0; v < numNodes; v++) {
            // 如果 v 没被访问，且 u 到 v 有路
            if (!visited[v] && adjMatrix[u][v] < INF) {
                // 如果 (起点->u->v) 比 (起点->v) 更近
                if (dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v]; 
                    path[v] = u; 
                }
            }
        }
    }

    //输出结果
    if (dist[end] == INF) {
        cout << " 从 " << startName << " 到 " << endName << " 没有可行路线。" << endl;
    } else {
        cout << "\n规划成功！" << endl;
        cout << " 总距离: " << dist[end] << " 米" << endl;
        
        // 路径回溯 (从终点倒推回起点)
        cout << "推荐路线: ";
        stack<int> s;
        int curr = end;
        while (curr != start && curr != -1) {
            s.push(curr);
            curr = path[curr];
        }
        s.push(start); // 把起点也放进去

        // 打印栈
        while (!s.empty()) {
            cout << vertexes[s.top()].name;
            s.pop();
            if (!s.empty()) cout << " -> ";
        }
        cout << endl;
    }
}