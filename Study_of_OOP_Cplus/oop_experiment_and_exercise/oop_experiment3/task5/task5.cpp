#include "contactBook.hpp"

void test() {
    ContactBook contactbook;

    std::cout << "1. add contacts\n";
    contactbook.add("Bob", "18199357253");
    contactbook.add("Alice", "17300886371");
    contactbook.add("Linda", "18184538072");
    contactbook.add("Alice", "17300886371");

    std::cout << "\n2. display contacts\n";
    std::cout << "There are " << contactbook.size() << " contacts.\n";
    contactbook.display();

    std::cout << "\n3. find contacts\n";
    contactbook.find("Bob");
    contactbook.find("David");

    std::cout << "\n4. remove contact\n";
    contactbook.remove("Bob");
    contactbook.remove("David");
}

int main() {
    test();
}