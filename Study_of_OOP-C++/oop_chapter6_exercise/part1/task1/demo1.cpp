#include"Point.hpp"
#include<iostream>
const int N=2;
 
//test1:对象数组的含义
void test1(){
    Point x[N]; //默认构造函数会被调用，为对象数组的每个元素分配资源
    std::cout<<x[0].get_x()<<","<<x[0].get_y()<<std::endl;
}

//test2:用已经存在的对象初始化对象数组
void test2(){
    Point p1(1,1),p2(3,5);
    Point x[N]={p1,p2}; //复制构造函数会被调用
    for(auto i=0;i<N;i++){
        std::cout<<x[i].get_x()<<","<<x[i].get_y()<<std::endl;
    }
}

//test3:用临时对象初始化对象数组
void test3(){
    Point x[N]={Point(),Point(5,5)};
    for(auto i=0;i<N;i++){
        std::cout<<x[i].get_x()<<","<<x[i].get_y()<<std::endl;
    }
}

//对象数组作为函数参数
void output(const Point x[],int n){
    for(auto i=0;i<n;i++)
        std::cout<<x[i].get_x()<<","<<x[i].get_y()<<std::endl;
}
void test4(){
    Point p1(1,1),p2(3,5);
    Point x[N]={p1,p2};
    output(x,N);
}

void test5(){
    Point p1(1,1),p2(3,5);
    const Point x[N]={p1,p2};
    output(x,N);
}

int main(){
    test3();
}

//笔记小记
/*
test1:
Point x[N]; //默认构造函数会被调用，为对象数组的每个元素分配资源
std::cout<<x[0].get_x()<<","<<x[0].get_y()<<std::endl;
直接刚开始定义一个数组的同时，初始化两个变量0，0
constructor called.
constructor called.
0,0
destructor called.
destructor called.

test2:
Point p1(1,1),p2(3,5);
Point x[N]={p1,p2}; //复制构造函数会被调用
for(auto i=0;i<N;i++){
    std::cout<<x[i].get_x()<<","<<x[i].get_y()<<std::endl;
}
先通过构造函数构造两个对象，接下来进行数组初始化的时候将两个对象复制进去。总共是有4个对象的，之后再调用析构函数
constructor called.
constructor called.
copy constructor called.
copy constructor called.
1,1
3,5
destructor called.
destructor called.
destructor called.
destructor called.

test3:
Point x[N]={Point(),Point(5,5)};
for(auto i=0;i<N;i++){
    std::cout<<x[i].get_x()<<","<<x[i].get_y()<<std::endl;
}
constructor called.
constructor called.
0,0
5,5
destructor called.
destructor called.

test4 and test5:
void test4(){
    Point p1(1,1),p2(3,5);
    Point x[N]={p1,p2};
    output(x,N);
}

void test5(){
    Point p1(1,1),p2(3,5);
    const Point x[N]={p1,p2};
    output(x,N);
}
constructor called.
constructor called.
copy constructor called.
copy constructor called.
1,1
3,5
destructor called.
destructor called.
destructor called.
destructor called.
*/