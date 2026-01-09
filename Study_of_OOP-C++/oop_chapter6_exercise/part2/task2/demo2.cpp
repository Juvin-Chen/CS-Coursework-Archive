#include"Point.hpp"
#include<iostream>
void test(){
    Point a(3,4);
    std::cout<<"&a="<<&a<<'\n';
    a.show();
    std::cout<<'\n';
    
    const Point b(5,5);
    std::cout<<"&b="<<&b<<'\n';
    b.show();
}
int main(){
    test();
}