#include<iostream>
#include<string>

//定义类模板
template<typename T>
class X{
public:
    X(T x0,T y0);
    void display();
private:
    T x,y;
};

template<typename T>
X<T>::X(T x0,T y0):x{x0},y{y0}{}

template<typename T>
void X<T>::display(){
    std::cout<<x<<","<<y<<'\n';
}

void test(){
    std::cout<<"测试1：用int实例化类模板X"<<'\n';
    X<int> x1(3,4);
    x1.display();

    std::cout << "\n测试2: 用double实例化类模板X" << '\n';
    X<double> x2(3.2, 5.6);
    x2.display();

    std::cout << "\n测试3: 用string实例化类模板X" << '\n';
    X<std::string> x3("hello", "oop");
    x3.display();
}

int main(){
    test();
}