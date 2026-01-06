#include"Complex.h"
#include<iostream>
#include<iomanip>
#include<complex>

void test_Complex();
void test_std_complex();

int main(){
    std::cout<<"测试1：自定义Complex类\n";
    test_Complex();
    
    std::cout<<"测试2：std::complex\n";
    test_std_complex();
}

void test_Complex() {
    using std::cout;
    using std::endl;
    using std::boolalpha;
    cout << "类成员测试: " << endl;
    cout << Complex::doc << endl << endl;
    cout << "Complex对象测试: " << endl;
    Complex c1;
    Complex c2(3, -4);
    Complex c3(c2);
    Complex c4 = c2;
    const Complex c5(3.5);
    cout << "c1 = "; output(c1); cout << endl;
    cout << "c2 = "; output(c2); cout << endl;
    cout << "c3 = "; output(c3); cout << endl;
    cout << "c4 = "; output(c4); cout << endl;
    cout << "c5.real = " << c5.get_real()<< ", c5.imag = " << c5.get_imag() << endl << endl;
    cout << "复数运算测试: " << endl;
    cout << "abs(c2) = " << abs(c2) << endl;
    c1.add(c2);
    cout << "c1 += c2, c1 = "; output(c1); cout << endl;
    cout << boolalpha;
    cout << "c1 == c2 : " << is_equal(c1, c2) << endl;
    cout << "c1 != c2 : " << is_not_equal(c1, c2) << endl;
    c4 = add(c2, c3);
    cout << "c4 = c2 + c3, c4 = "; output(c4); cout << endl;
}

void test_std_complex() {
    using std::cout;
    using std::endl;
    using std::boolalpha;
    cout << "std::complex<double>对象测试: " << endl;
    std::complex<double> c1;
    std::complex<double> c2(3, -4);
    std::complex<double> c3(c2);
    std::complex<double> c4 = c2;
    const std::complex<double> c5(3.5);
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5.real = " << c5.real()<< ", c5.imag = " << c5.imag() << endl << endl;
    cout << "复数运算测试: " << endl;
    cout << "abs(c2) = " << abs(c2) << endl;
    c1 += c2;
    cout << "c1 += c2, c1 = " << c1 << endl;
    cout << boolalpha;
    cout << "c1 == c2 : " << (c1 == c2)<< endl;
    cout << "c1 != c2 : " << (c1 != c2) << endl;
    c4 = c2 + c3;
    cout << "c4 = c2 + c3, c4 = " << c4 << endl;
}

