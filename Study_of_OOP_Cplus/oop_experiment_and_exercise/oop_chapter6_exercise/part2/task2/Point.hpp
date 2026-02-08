#pragma once

#include<iostream>
#include<typeinfo>

class Point{
public:
    Point(int x0=0,int y0=0):x(x0),y(y0){};
    ~Point()=default;
    int get_x() const{ return x; }
    int get_y() const{ return y; }
    void show() const{ 
        std::cout<<"this="<<this<<"\n";
        std::cout<<"this type:"<<typeid(this).name()<<"\n";
        std::cout<<"this type:"<<typeid(*this).name()<<"\n";
        std::cout<<"void show() const is called."<<'\n';
        std::cout<<"("<<x<<","<<y<<")"<<'\n';
    }
    void show(){
        std::cout<<"this="<<this<<'\n';
        std::cout<<"this type:"<<typeid(this).name()<<"\n";
        std::cout<<"void show() is called."<<'\n';
        std::cout<<"("<<x<<","<<y<<")"<<'\n';
    }
private:
    int x,y;
};