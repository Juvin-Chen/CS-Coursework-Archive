#pragma

#include<iostream>

class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){}
    ~Point() = default;
    void show() const { std::cout<<"("<<x<<","<<y<<")"; }
    void moveto(int new_x, int new_y){ x=new_x; y=new_y;}
    int x,y;
};