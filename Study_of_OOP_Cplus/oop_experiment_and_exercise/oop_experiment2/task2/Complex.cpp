#include"Complex.h"
#include<iostream>
#include<cmath>

Complex::Complex(double x,double y):real(x),imag(y){}

double Complex::get_real() const{ return real;}

double Complex::get_imag() const { return imag;}

void Complex::add(const Complex &c){
    real+=c.real;
    imag+=c.imag;
}

void output(const Complex &c){
    if(c.imag<0){
        std::cout<<c.real<<c.imag<<"i";
        return;
    }
    std::cout<<c.real<<"+"<<c.imag<<"i";
}

double abs(const Complex &c){
    return sqrt(c.real*c.real+c.imag*c.imag);
}

Complex add(const Complex &c1,const Complex &c2){
    return Complex(c1.real+c2.real,c2.imag+c1.imag);
}

bool is_equal(const Complex &c1,const Complex &c2){
    if(c1.real==c2.real&&c1.imag==c2.imag) return true;
    return false;
}

bool is_not_equal(const Complex &c1,const Complex &c2){
    return is_equal(c1,c2)?false:true;
}






