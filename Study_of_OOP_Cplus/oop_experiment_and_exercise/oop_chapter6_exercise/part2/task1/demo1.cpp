#include"Point.hpp"

void test1(){
    Point a(3,4);
    a.show();
    std::cout<<"\n";

    Point *ptr;
    ptr=&a;
    ptr->show();
}

void test2(){
    Point *ptr=new Point(3,4);
    ptr->show();
    delete ptr;
}

int main(){
    std::cout<<"test1:"<<std::endl; test1();
    std::cout<<"\ntest2:"<<std::endl; test2();
}