#include<iostream>
#include"Point.hpp"

void test1(){
    Point a(3,4);
    a.moveto(0,0);
    a.x=42;
    a.show();
}

void test2(){
    Point a(3,4);
    void (Point::*pf1)(int ,int);
    pf1=&Point::moveto;
    (a.*pf1)(0,0);

    int Point::*pdata;
    pdata=&Point::x;
    a.*pdata=42;

    void (Point::*pf2)() const;  //这种类型的定义括号不要忘记去加
    pf2=&Point::show;
    (a.*pf2)();
    
}

int main(){
    std::cout << "直接访问: 对象名.成员名 (公有成员)\n";
    test1();
    std::cout << "\n间接访问: 指向对象成员的指针\n";
    test2();
}
