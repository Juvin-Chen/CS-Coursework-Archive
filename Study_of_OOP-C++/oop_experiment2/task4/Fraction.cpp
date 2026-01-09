#pragma

#include"Fraction.h"
#include"CollectionF.h"
#include<string>
#include<iostream>

int Fraction::get_up() const{ 
    return CollectionF::fun(*this).up;
}
int Fraction::get_down() const{
    return CollectionF::fun(*this).down;
}
Fraction::Fraction(int up,int down):up(up),down(down){}
Fraction Fraction::operator-() const{
    return Fraction(-this->up,this->down);
}
Fraction Fraction::negative() const{
    return -(*this);
}



