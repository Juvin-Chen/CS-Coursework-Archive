#include<iostream>
#include<string>

#include"GradeCalc.hpp"

void test(){
    GradeCalc c1("OOP");
    std::cout<<"录入成绩：\n";
    c1.input(5);

    std::cout<<"输出成绩:\n";
    c1.output();
    
    std::cout<<"排序后成绩:\n";
    c1.sort();
    c1.output();
    
    std::cout<<"*************成绩统计信息*************\n";
    c1.info();

}
int main(){
    test();
}