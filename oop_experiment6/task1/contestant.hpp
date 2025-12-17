#pragma once

#include<iomanip>
#include<iostream>
#include<string>

struct Contestant{
    //学号/姓名/专业
    long id;
    std::string name; 
    std::string major; 
    int solved;   //解题数
    int penalty;  //总罚时
};

//重载<<,要求：姓名/专业里不含空白符
inline std::ostream& operator<<(std::ostream &out,const Contestant& c){
    out<<std::left;
    out<<std::setw(15)<<c.id
       <<std::setw(15)<<c.name
       <<std::setw(20)<<c.major
       <<std::setw(10)<<c.solved
       <<std::setw(10)<<c.penalty;
    return out;
}

//重载>>，这个函数就是输入Contestant对象
inline std::istream& operator>>(std::istream& in,Contestant& c){
    in>>c.id>>c.name>>c.major>>c.solved>>c.penalty;
    return in;
}
