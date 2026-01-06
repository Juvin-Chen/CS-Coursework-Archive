#include"Point.hpp"
#include<iostream>
#include<string>
#include<vector>
void output1(const std::vector<std::string> &v){
    for(auto &i:v){
        std::cout<<i<<" ";
    }
}

void output2(const std::vector<Point> &v){
    for(auto &i:v){
        i.show();
        std::cout<<" ";
    }
}

void test1(){
    std::vector<std::string> v1{"c plus plus", "java", "rust", "python"};
    std::vector<std::string> v2{v1}; // 复制构造新对象v2
    // 更新v2
    for(auto &i: v2)
        i.at(0) -= 32;  //大小写转换

    std::cout << "v1: "; output1(v1); std::cout<<'\n';
    std::cout << "v2: "; output1(v2);
}
void test2(){
    std::vector<Point> x{Point(), Point(3, 4), Point(-1, -1)};
    std::vector<Point> y{x}; // 复制构造新对象y
    // 更新对象y
    for(auto &i: y)
        i.moveto(i.get_x()+1, i.get_y()+1);
    y.push_back(Point(42, 42));
    std::cout << "x: "; output2(x);
    std::cout << "\n y: "; output2(y);   
}
int main(){
    std::cout << "测试1: 组合使用std::vector和std::string\n";
    test1();
    std::cout << "\n\n测试2: 组合使用std::vector和自定义类Point\n";
    test2();
}