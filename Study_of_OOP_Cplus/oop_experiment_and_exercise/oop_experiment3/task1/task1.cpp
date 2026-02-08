#include "window.hpp"
#include <iostream>
void test(){
    Window w("Demo");
    w.add_button("add");
    w.add_button("remove");
    w.add_button("modify");
    w.add_button("add");
    w.display();
    w.close();
}
int main() {
    std::cout << "用组合类模拟简单GUI:\n";
    test();
}