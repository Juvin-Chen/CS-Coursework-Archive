#include"vectorInt.hpp"
#include<iostream>

void test1();
void test2();
void output1(const vectorInt &vi);
void output2(const vectorInt &vi);
int main() {
    std::cout << "测试1: \n";
    test1();
    std::cout << "\n测试2: \n";
    test2();
   
}
void test1() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    vectorInt x1(n);
    for(auto i = 0; i < n; ++i)
        x1.at(i) = (i+1)*10;
    std::cout << "x1: "; output1(x1);
    vectorInt x2(n, 42);
    vectorInt x3(x2);
    x2.at(0) = -1;
    std::cout << "x2: "; output1(x2);
    std::cout << "x3: "; output1(x3);
}
void test2() {
    const vectorInt x(5, 42);
    vectorInt y;
    y.assign(x);
    std::cout << "x: "; output2(x);
    std::cout << "y: "; output2(y);
}



// 使用xx.at()+循环输出vectorInt对象数据项
void output1(const vectorInt &vi) {
    if(vi.size() == 0) {
        std::cout << '\n';
        return;
    }
    std::cout << vi.at(0);
    for(auto i = 1; i < vi.size(); ++i)
        std::cout << ", " << vi.at(i);
    std::cout << '\n';
}
// 使用迭代器+循环输出vectorInt对象数据项
void output2(const vectorInt &vi) {
    if(vi.size() == 0) {
        std::cout << '\n';
        return;
    }
    auto it = vi.begin();
    std::cout << *it;
    for(it = vi.begin()+1; it != vi.end(); ++it)
        std::cout << ", " << *it;
    std::cout << '\n';
}