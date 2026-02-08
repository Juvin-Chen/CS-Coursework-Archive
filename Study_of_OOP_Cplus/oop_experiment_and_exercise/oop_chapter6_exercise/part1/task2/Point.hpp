#pragma once

#include<iostream>

class Point{
public:
    Point(int x0=0,int y0=0);
    Point(const Point &p);
    Point(Point &&p0);
    ~Point();

    int get_x() const;
    int get_y() const;

private:
    int x,y;
};

Point::Point(int x0,int y0):x(x0),y(y0){
    std::cout<<"constructor called.\n";
}

Point::Point(const Point &p0):x{p0.x},y{p0.y}{
    std::cout<<"copy constructor called.\n";
}

Point::Point(Point &&p0):x{p0.x},y{p0.y}{
    std::cout<<"move constructor called.\n";
}

Point::~Point(){
    std::cout<<"destructor called.\n";
}

inline int Point::get_x() const{
    return x;
}
inline int Point::get_y() const{
    return y;
}
