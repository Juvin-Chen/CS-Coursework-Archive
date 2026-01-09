#include <iostream>
#include <memory>
#include <vector>
#include "pet.hpp"
void test1() {
    std::vector<MachinePet *> pets;
    pets.push_back(new PetCat("miku"));
    pets.push_back(new PetDog("da huang"));
    for(MachinePet *ptr: pets) {
        std::cout << ptr->get_nickname() << " says " << ptr->talk() << '\n';
        delete ptr; // 须手动释放资源
    }
}
void test2() {
    std::vector<std::unique_ptr<MachinePet>> pets;
    pets.push_back(std::make_unique<PetCat>("miku"));
    pets.push_back(std::make_unique<PetDog>("da huang"));
    for(auto const &ptr: pets)
    std::cout << ptr->get_nickname() << " says " << ptr->talk() << '\n';
}
void test3() {
    // MachinePet pet("little cutie"); // 编译报错：无法定义抽象类对象
    const PetCat cat("miku");
    std::cout << cat.get_nickname() << " says " << cat.talk() << '\n';
    const PetDog dog("da huang");
    std::cout << dog.get_nickname() << " says " << dog.talk() << '\n';
}
int main() {
    std::cout << "测试1: 使用原始指针\n";
    test1();
    std::cout << "\n测试2: 使用智能指针\n";
    test2();
    std::cout << "\n测试3: 直接使用类\n";
    test3();
}