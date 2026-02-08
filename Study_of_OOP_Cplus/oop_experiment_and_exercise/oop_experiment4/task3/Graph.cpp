#include<algorithm>
#include<cctype>
#include<iostream>
#include<string>

#include"Graph.hpp"

void Circle::draw(){ std::cout<<"draw a circle...\n"; }

void Triangle::draw(){ std::cout<<"draw a triangle...\n"; }

void Rectangle::draw(){ std::cout<<"draw a rectangle...\n"; }

void Canvas::add(const std::string &type){
    Graph* g=make_graph(type);
    if(g)
        graphs.push_back(g);
}

void Canvas::paint() const{
    for(Graph *g:graphs)
        g->draw();
}

Canvas::~Canvas(){
    for(Graph* g:graphs)
        delete g;
}

//工具函数实现，字符串->枚举转换
GraphType str_to_GraphType(const std::string &s){
    std::string t=s;
    std::transform(s.begin(),s.end(),t.begin(),[](unsigned char c){ return std::tolower(c); });
    if(t=="circle") return GraphType::circle;
    if(t=="triangle") return GraphType::triangle;
    if(t=="rectangle") return GraphType::rectangle;
    return GraphType::circle;  //缺省返回
}

//创建图形，返回堆对象指针
Graph* make_graph(const std::string& type){
    switch(str_to_GraphType(type)){
        case GraphType::circle: return new Circle;
        case GraphType::triangle: return new Triangle;
        case GraphType::rectangle: return new Rectangle;
        default: return nullptr;
    }
}
