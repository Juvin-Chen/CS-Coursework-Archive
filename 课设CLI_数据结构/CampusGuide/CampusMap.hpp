#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_NODES 50
#define INF 999999

// 景点结构体
struct Spot {
    int id;      // 编号
    string name; // 名称
};

class CampusMap {
private:
    Spot vertexes[MAX_NODES];            // 顶点数组（存景点信息）
    int adjMatrix[MAX_NODES][MAX_NODES]; // 邻接矩阵（存边的权重/距离）
    int numNodes;
    int numEdges;

public:
    CampusMap();

    void initDefaultMap();

    // 根据名字找顶点的下标
    int getIndexByName(string name);

    // 添加景点
    void addSpot(string name);

    // 添加道路
    void addPath(int startId, int endId, int dist);

    // 显示所有景点
    void showAllSpots();

    // 核心算法：Dijkstra 计算最短路径
    void findShortestPath(string startName, string endName);
};