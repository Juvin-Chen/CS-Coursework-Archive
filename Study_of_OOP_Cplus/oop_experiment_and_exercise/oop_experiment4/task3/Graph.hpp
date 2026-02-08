#pragma once

#include<string>
#include<vector>

enum class GraphType{circle,triangle,rectangle};

//Grape类定义
class Graph{
public:
    virtual void draw(){};
    virtual ~Graph()=default;
};

//Circle类
class Circle:public Graph{
public:
    void draw();
};

//Triangle类
class Triangle:public Graph{
public: 
    void draw();
};

//Rectangle类
class Rectangle:public Graph{
public:
    void draw();
};

//Canvas （画布）
class Canvas{
public:
    void add(const std::string &type);
    void paint() const;
    ~Canvas();
private:
    std::vector<Graph*> graphs;
};

//工具函数
GraphType str_to_GraphType(const std::string &s); //string->enum
Graph* make_graph(const std::string &type); //创建图形，返回堆对象指针


