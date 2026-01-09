#include <iostream>
#include "Complex.hpp"
void test1() {
    using std::cout;
    using std::boolalpha;
    Complex<int> c1(2, -5), c2(c1);
    cout << "c1 = " << c1 << '\n';
    cout << "c2 = " << c2 << '\n';
    cout << "c1 + c2 = " << c1 + c2 << '\n';
    c1 += c2;
    cout << "c1 = " << c1 << '\n';
    cout << boolalpha << (c1 == c2) << '\n';
}
void test2() {
    using std::cin;
    using std::cout;
    Complex<double> c1, c2;
    cout << "Enter c1 and c2: ";
    cin >> c1 >> c2;
    cout << "c1 = " << c1 << '\n';
    cout << "c2 = " << c2 << '\n';
    const Complex<double> c3(c1);
    cout << "c3.real = " << c3.get_real() << '\n';
    cout << "c3.imag = " << c3.get_imag() << '\n';
}
int main() {
    std::cout << "自定义类模板Complex测试1: \n";
    test1();
    std::cout << "\n自定义类模板Complex测试2: \n";
    test2();
}
