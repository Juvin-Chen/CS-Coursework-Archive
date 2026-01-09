#pragma once

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

class Point{
public:
    Point(int x0 = 0, int y0 = 0);
    ~Point();
    Point(Point &p0);
    int get_x() const;
    int get_y() const;
private:
    int x, y;

public:
    static void show_count();
    static const string doc;

private:
    static int count;
};

int Point::count=0;
const string Point::doc="a point class";

Point::Point(int x0, int y0) : x{x0}, y{y0} {++count;}
Point::~Point() {--count;}
Point::Point(Point &p0) : x{p0.x}, y{p0.y} {++count;}
inline int Point::get_x() const {return x;}
inline int Point::get_y() const {return y;}
void Point::show_count() {cout << "point object's count : " << count << endl;}