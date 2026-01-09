#pragma

#include<iostream>

class Point{
public:
    Point(int x0=0,int y0=0):x{x0},y{y0}{};
    ~Point()=default;
    void show() const;
private:
    int x,y;
};

inline void Point::show() const{
    std::cout<<"("<<x<<","<<y<<")";
}