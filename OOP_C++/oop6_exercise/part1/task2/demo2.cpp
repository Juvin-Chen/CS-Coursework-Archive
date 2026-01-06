#include"Point.hpp"
#include<array>
#include<iostream>

const int N=2;

void test(){
    std::array<Point,N> x{Point(0,0),Point(3,5)}; //使用标准库array，创建Point数组对象
    for(auto i=0;i<N;i++){
        std::cout<<x.at(i).get_x()<<","<<x.at(i).get_y()<<"\n";
    }
    for(const auto &i:x)
        std::cout<<i.get_x()<<","<<i.get_y()<<"\n";
}

int main(){
    test();
}