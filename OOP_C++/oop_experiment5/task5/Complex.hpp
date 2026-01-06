/*
问题场景描述
自定义简化版类模板 Complex , 实现类似C++标准库类模板 complex ，支持对类型的参数化。具体要求如下：
支持实例化类模板与各种构造
如 Complex<double> c1; Complex<double> c2(1.0, 2.0); Comlex<double>c3(c2);
提供接口 get_real() , get_imag() 返回实部和虚部
对类模板重载运算符，支持如下操作： c1 += c2 , c1 + c2 , c1 == c2 , cin >> c1 >> c2 , cout
<< c1 << c2
*/
#include<iostream>

template<typename T> class Complex;

template<typename T>
std::istream& operator>>(std::istream& in, Complex<T>& c);

template<typename T>
class Complex{
public:
    Complex()=default;
    Complex(T real_,T imag_):real{real_},imag{imag_}{}
    T get_real() const{ return real; }
    T get_imag() const{ return imag; }
    Complex& operator+=(const Complex<T>& c){
        this->real+=c.real;
        this->imag+=c.imag;
        return *this;
    }
    friend std::istream& operator>> <T>(std::istream& in,Complex<T> &c);
private:
    T real,imag;
};

template<typename T>
Complex<T> operator+(const Complex<T>& c1,const Complex<T>& c2){
    return Complex<T>(c1.get_real()+c2.get_real(),c1.get_imag()+c2.get_imag());
}

template<typename T>
bool operator==(const Complex<T>& c1,const Complex<T>& c2){
    if(c1.get_real()==c2.get_real()&&c1.get_imag()==c2.get_imag()) return true;
    return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& out,const Complex<T>& c){
    out << c.get_real();
    out << (c.get_imag() >= 0 ? "+" : "") << c.get_imag() << "i";
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in,Complex<T>& c){
    in>>c.real>>c.imag;
    return in;
} 
