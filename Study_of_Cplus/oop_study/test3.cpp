//多态

#include<iostream>
using namespace std;

class  Animal{
public:
    virtual void sound() const{
        cout<<"Animal makes a sound"<<endl;
    } 
    virtual ~Animal(){
        cout<<"Animal destroyed"<<endl;
    }
};

class Dog:public Animal{
public:
    //重写sound方法<<
    void sound() const override{
        cout<<"Dog barks."<<endl;
    }
    ~Dog(){
        cout<<"Dog destroyed"<<endl;
    }
};


// 派生类 Cat，继承自 Animal
class Cat : public Animal {
public:
    // 重写 sound 方法
    void sound() const override {
        cout << "Cat meows" << endl;
    }
   
    ~Cat() {
        cout << "Cat destroyed" << endl;
    }
};

int main(){
    Animal *animalPtr;
    //创建Dog对象，指向Animal指针
    animalPtr=new Dog();
    animalPtr->sound();
    delete animalPtr;

    animalPtr=new Cat();
    animalPtr->sound();
    delete animalPtr;
    return 0;
}