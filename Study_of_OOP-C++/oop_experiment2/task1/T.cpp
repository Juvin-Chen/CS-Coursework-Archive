#include"T.h"
#include<iostream>
#include<string>

//类T实现

//static成员数据类外初始化，不需要加static
const std::string T::doc{"a simple class sample"};
const int T::max_cnt=999;
int T::cnt=0;

int T::get_cnt(){
    return cnt;
}

T::T(int x,int y):m1(x),m2(y){
    cnt++;
    std::cout<<"T constructor called.\n";
}

T::T(const T &t):m1(t.m1),m2(t.m2){
    cnt++;
    std::cout<<"T copy constructor called.\n";
}

T::T(T &&t):m1(t.m1),m2(t.m2){
    cnt++;
    std::cout<<"T move constructor called.\n";
}

T::~T(){
    cnt--;
    std::cout<<"T destructor called.\n";
}

void T::adjust(int ratio){
    m1*=ratio;
    m2*=ratio;
} 

void T::display() const{
    std::cout<<"("<<m1<<","<<m2<<")";
}


//普通函数实现
void func(){
    T t5(42);
    t5.m2=2049;
    std::cout<<"t5=";
    t5.display();
    std::cout<<"\n";
}






