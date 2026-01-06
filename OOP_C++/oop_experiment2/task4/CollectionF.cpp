#pragma
#include"Fraction.h"
#include"CollectionF.h"
#include<iostream>
#include<cmath>
//最大公约数
int gcd(int a,int b){
    a=abs(a); b=abs(b);
    return (b==0)?a:gcd(b,a%b);
}
//化简 
Fraction CollectionF::fun(Fraction f){
    if (f.down == 0) return Fraction(0, 0); // 分母为0，返回特殊值
    int gcdnum = gcd(f.up, f.down);
    int new_up = f.up / gcdnum;
    int new_down = f.down / gcdnum;
    // 规范化符号：将负号转移到分子，保证分母始终为正
    if (new_down < 0) {
        new_up = -new_up;
        new_down = -new_down;
    }
    return Fraction(new_up, new_down);
    
}

void CollectionF::output(Fraction f){
    Fraction f0 = fun(f); // 先进行化简
    if(f0.down==0){std::cout<<"分母不能为0"; return;}
    if(f0.up==0){std::cout << 0; return;}
    if(f0.down == 1){std::cout << f0.up; return;}
    if ((f0.up > 0 && f0.down > 0) || (f0.up < 0 && f0.down < 0)) {
        //正分数
        std::cout<<abs(f0.up)<<"/"<<abs(f0.down);
    }else{
        //负分数
        std::cout<<"-"<<abs(f0.up)<<"/"<<abs(f0.down);
    }
}

Fraction CollectionF::add(const Fraction &f1,const Fraction &f2){
    int newup=f1.up*f2.down+f2.up*f1.down,newdown=f1.down*f2.down;
    int gcdnum=gcd(newup,newdown);
    return Fraction(newup/gcdnum,newdown/gcdnum);
}

Fraction CollectionF::sub(const Fraction &f1,const Fraction &f2){
   Fraction f0(-f2);
   return add(f1,f0);
}

Fraction CollectionF::mul(const Fraction &f1,const Fraction &f2){
    int newup=f1.up*f2.up,newdown=f1.down*f2.down;
    int gcdnum=gcd(newup,newdown);
    return Fraction(newup/gcdnum,newdown/gcdnum);
}

Fraction CollectionF::div(const Fraction &f1,const Fraction &f2){
    if(f2.down==0) return Fraction(0,0);
    Fraction f0(f2.down,f2.up);
    return mul(f1,f0);
}