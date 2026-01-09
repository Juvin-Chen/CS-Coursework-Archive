#pragma

#include<string>

class Complex{
//类属性
public:
    static const std::string doc;

//对象属性
private:
    double real,imag;

public:
    Complex(double x=0,double y=0);
    Complex(const Complex &c)=default;
    Complex(Complex &&c)=default;
    Complex& operator=(const Complex&) = default;
    Complex& operator=(Complex&&) = default;
    
    double get_real() const;
    double get_imag() const;
    void add(const Complex &c);

//友元函数
    friend void output(const Complex &c);
    friend double abs(const Complex &c);
    friend Complex add(const Complex &c1,const Complex &c2);
    friend bool is_equal(const Complex &c1,const Complex &c2);
    friend bool is_not_equal(const Complex &c1,const Complex &c2);
};

inline const std::string Complex::doc="a simplified complex class";