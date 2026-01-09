#include<iostream>

//类A定义
class A{
public:
    A(int x0,int y0);
    void display() const;
private:
    int x,y;
};

A::A(int x0,int y0):x{x0},y{y0}{}

void A::display() const{
    std::cout<<x<<","<<y<<"\n";
}

class B{
public:
    B(double x0,double y0);
    void display() const;
private: 
    double x,y;
};

B::B(double x0,double y0):x{x0},y{y0}{}

void B::display() const{
    std::cout << x << ", " << y << '\n';
}

void test(){
    std::cout << "测试类A: " << '\n';
    A a(3, 4);
    a.display();
    std::cout << "\n测试类B: " << '\n';
    B b(3.2, 5.6);
    b.display();
}
int main(){
    test();
}

