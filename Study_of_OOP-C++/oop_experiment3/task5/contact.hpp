#pragma once

#include<iostream>
#include<string>

//联系人
class Contact{
public:
    Contact(const std::string &name_,const std::string &phone);
    const std::string &get_name() const;
    const std::string &get_phone() const;
    void display() const;

private:
    std::string name;
    std::string phone;
};

Contact::Contact(const std::string &name_,const std::string &phone_):name{name_},phone{phone_} {}

const std::string &Contact::get_name() const{
    return name;
}

const std::string&Contact::get_phone() const{
    return phone;
}

void Contact::display() const{
    std::cout<<name<<","<<phone;
}