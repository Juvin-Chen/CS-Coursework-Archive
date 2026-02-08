#pragma once
#include <iostream>
class Point {
public:
    Point(int x0 = 0, int y0 = 0);
    ~Point();
    int get_x() const;
    int get_y() const;
    void show() const;
    void moveto(int new_x, int new_y);
private:
    int x, y;
};
Point::Point(int x0, int y0): x{x0}, y{y0} {}
Point::~Point() {}
inline int Point::get_x() const {return x;}
inline int Point::get_y() const {return y;}
inline void Point::show() const {std::cout << "(" << x << ", " << y << ")";}
void Point::moveto(int new_x, int new_y) { x = new_x; y = new_y; }