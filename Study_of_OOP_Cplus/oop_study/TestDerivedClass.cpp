//类的继承

#include<iostream>
//基类Shape
class Shape{
public:
    void setWidth(int w){
        width=w;
    }
    void setHeight(int h){
        height=h;
    }
protected:
    int width,height;
};

//基类PaintCost
class PaintCost{
public:
    int getCost(int area){
        return area*70;
    }
};

//派生类
class Rectangle:public Shape,public PaintCost{
public:
    int getarea(){
        return width*height;
    }
};

int main(void){
    Rectangle r;
    r.setWidth(5);
    r.setHeight(7);
    int area=r.getarea();
    //输出对象的面积
    std::cout<<"S:"<<area<<std::endl;
    //输出总花费
    std::cout<<r.getCost(area)<<std::endl;
    std::cout<<"做阐释";
    return 0;
}
