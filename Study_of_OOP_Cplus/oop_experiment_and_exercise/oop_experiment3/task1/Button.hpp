#pragma once

#include<iostream>
#include<string>

class Button{
public:
    Button(const std::string &label_);
    const std::string& get_label() const;
    void click();
private:
    std::string label;
};

Button::Button(const std::string &label):label{label}{}

inline const std::string& Button::get_label() const { return label; }

inline void Button::click(){ std::cout<<"Button "<<label<<"clicked\n"; }

