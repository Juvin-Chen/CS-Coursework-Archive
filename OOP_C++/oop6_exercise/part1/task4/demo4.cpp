#include<iostream>
#include<string>

void test1(){
    const std::string s1{"OOP"}; //s1是const对象，值不可变
    const std::string *ptr;  //ptr是指针变量，指向const对象
    ptr=&s1;
    std::cout<<"s1="<<s1<<std::endl;
    std::cout<<"*ptr="<<*ptr<<std::endl;
    
    std::string s2{"CPLUS"};
    ptr=&s2;  //ptr指向非const对象，合法
    s2+="2049";
    std::cout<<"s2="<<s2<<std::endl;
    std::cout<<"*ptr="<<*ptr<<std::endl;
}

void test2(){
    std::string s1{"OOP"};
    std::string *const ptr=&s1;
    s1+="2025";
    *ptr+="#";
    std::cout<<"s1="<<s1<<std::endl;
    std::cout<<"*ptr="<<*ptr<<std::endl;
    //ptr=&s2; //error
}
int main(){
    std::cout<<"test1:指针变量指向const对象\n";
    test1();
    std::cout<<"\ntest2:指针变量本身是const\n";
    test2();
}

/*
test1中const std::string *ptr 中前面的 const，核心意义是 限制 “通过这个指针 ptr 不能修改它指向的 string 对象”——const 修饰的是 “指针指向的目标”，而非指针本身。
当 ptr 指向非 const 对象（如 s2）时：
s2 本身是普通 string（可修改，比如代码中 s2 += "2049" 是合法的）。
但 const 让 ptr 变成了 “只读指针”——通过 ptr 无法修改 s2。比如尝试写 *ptr += "#"，编译器会直接报错（因为 ptr 被 const 限制，不能通过它修改目标对象）。

test2 是 std::string *const ptr，const 在 * 后面，修饰的是 “指针本身”—— 意味着 ptr 一旦指向某个对象（比如 s1），就不能再指向其他对象（比如 ptr = &s2 会报错），但可以通过 ptr 修改指向的对象（比如 *ptr += "#" 是合法的）。
*/