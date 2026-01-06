#include "Fraction.h"
#include"CollectionF.h"
#include <iostream>
void test1();
void test2();
int main() {
    std::cout << "测试1: Fraction类基础功能测试\n";
    test1();
    std::cout << "\n测试2: 分母为0测试: \n";
    test2();
}
void test1() {
    using std::cout;
    using std::endl;
    cout << "Fraction类测试: " << endl;
    cout << Fraction::doc << endl << endl;
    Fraction f1(5);
    Fraction f2(3, -4), f3(-18, 12);
    Fraction f4(f3);
    cout << "f1 = "; CollectionF::output(f1); cout << endl;
    cout << "f2 = "; CollectionF::output(f2);  cout << endl;
    cout << "f3 = "; CollectionF::output(f3); cout << endl;
    cout << "f4 = "; CollectionF::output(f3); cout << endl;
    const Fraction f5(f4.negative());
    cout << "f5 = "; CollectionF::output(f5); cout << endl;
    cout << "f5.get_up() = " << f5.get_up()
    << ", f5.get_down() = " << f5.get_down() << endl;
    cout << "f1 + f2 = "; CollectionF::output(CollectionF::add(f1, f2)); cout << endl;
    cout << "f1 - f2 = "; CollectionF::output(CollectionF::sub(f1, f2)); cout << endl;
    cout << "f1 * f2 = "; CollectionF::output(CollectionF::mul(f1, f2)); cout << endl;
    cout << "f1 / f2 = "; CollectionF::output(CollectionF::div(f1, f2)); cout << endl;
    cout << "f4 + f5 = "; CollectionF::output(CollectionF::add(f4, f5)); cout << endl;
}
void test2() {
    using std::cout;
    using std::endl;
    Fraction f6(42, 55), f7(0, 3);
    cout << "f6 = "; CollectionF::output(f6); cout << endl;
    cout << "f7 = "; CollectionF::output(f7); cout << endl;
    cout << "f6 / f7 = "; CollectionF::output(CollectionF::div(f6, f7)); cout << endl;
}