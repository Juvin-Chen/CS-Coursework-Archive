#include <memory>
#include <iostream>
#include <vector>
#include "publisher.hpp"
void test1(){
    std::vector<Publisher *> v;
    v.push_back(new Book("Harry Potter", "J.K. Rowling"));
    v.push_back(new Film("The Godfather", "Francis Ford Coppola"));
    v.push_back(new Music("Blowing in the wind", "Bob Dylan"));
    for(Publisher *ptr: v) {
        ptr->publish();
        ptr->use();
        std::cout << '\n';
        delete ptr;
    }
}
void test2() {
    std::vector<std::unique_ptr<Publisher>> v;
    v.push_back(std::make_unique<Book>("Harry Potter", "J.K. Rowling"));
    v.push_back(std::make_unique<Film>("The Godfather", "Francis Ford Coppola"));
    v.push_back(std::make_unique<Music>("Blowing in the wind", "Bob Dylan"));
    for(const auto &ptr:v){
        ptr->publish();
        ptr->use();
        std::cout<<'\n';
    }
}
void test3() {
    Book book("A Philosophy of Software Design", "John Ousterhout");
    book.publish();
    book.use();
}
int main() {
    std::cout << "运行时多态：纯虚函数、抽象类\n";
    std::cout << "\n测试1: 使用原始指针\n";
    test1();
    std::cout << "\n测试2: 使用智能指针\n";
    test2();
    std::cout << "\n测试3: 直接使用类\n";
    test3();
}