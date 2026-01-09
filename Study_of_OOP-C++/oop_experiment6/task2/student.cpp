#include<iostream>
#include<string>
#include<iomanip>
#include"student.hpp"

const std::string& Student::get_major() const{
    return major;
}

int Student::get_grade() const{
    return grade;
}

std::ostream& operator<<(std::ostream& os,const Student& s){
    os<<std::left;
    os<<std::setw(10)<<s.id
      <<std::setw(10)<<s.name
      <<std::setw(10)<<s.major
      <<std::setw(10)<<s.grade;
    return os;
}
std::istream& operator>>(std::istream& is,Student& s){
    is>>s.id>>s.name>>s.major>>s.grade;
    return is;
}