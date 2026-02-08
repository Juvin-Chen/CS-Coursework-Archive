// 使用指针变量间接访问类的静态成员（公有）
#include<iostream>
#include"Point.hpp"

void test1(){
    Point begin(4,5),end(4,10);
    std::cout<<Point::doc<<'\n';
    Point::show_count();
}

void test2(){
    Point begin(4,5),end(4,10);
    const std::string *ptr;
    ptr=&Point::doc;  //ptr指向static成员数据doc
    std::cout<<*ptr<<'\n';
    void (*pf)();
    pf=Point::show_count;  //pf指向static成员函数show_count
    (*pf)();

}

int main(){
    std::cout<<"直接访问: 类名::static成员名 (公有static成员)\n";
    test1();
    std::cout<<"\n间接访问: \n";
    test2();
}