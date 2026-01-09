#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include"Button.hpp"

//窗口类
class Window{
public:
    Window(const std::string &title);
    void display() const;
    void close();
    void add_button(const std::string &label);
    void click_button(const std::string &label);
private:
    bool has_button(const std::string &label) const;

private:
    std::string title;
    std::vector<Button> buttons;
};

Window::Window(const std::string &title):title{title}{ buttons.push_back(Button("close")); }

inline void Window::display() const{
    std::string s(40,'*');
    std::cout<<s<<std::endl;
    std::cout<<"window:"<<title<<std::endl;
    int cnt=0;
    for(const auto &button:buttons){
        std::cout<<++cnt<<"."<<button.get_label()<<std::endl;
    }
    std::cout<<s<<std::endl;
}

inline void Window::close() {
    std::cout<<"close window "<<title<<std::endl;
    click_button("close");
}

inline bool Window::has_button(const std::string &label) const {
    for(const auto &button: buttons)
        if(button.get_label() == label)
            return true;
    return false;
}

inline void Window::add_button(const std::string &label) {
    if(has_button(label))
        std::cout << "button " << label << " already exists!\n";
    else buttons.push_back(Button(label));
}

inline void Window::click_button(const std::string &label) {
    for(auto &button:buttons)
        if(button.get_label() == label) {
            button.click();
        return;
    }
    std::cout << "no button: " << label << std::endl;
}
