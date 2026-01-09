#include"T.h"
#include<iostream>

void test_T();

int main(){
    std::cout<<"test class T: \n";
    test_T();
    std::cout<<"\ntest friend func: \n";
    func();
}

void test_T(){
    using std::cout;
    using std::endl;
    cout<<"T info:"<<T::doc<<endl;
    cout<<"T objects' max count :"<<T::max_cnt<<endl;
    cout<<"T objects' current count :"<<T::get_cnt()<<endl<<endl;

    T t1;
    cout<<"t1="; t1.display(); cout<<endl;
    
    T t2(3,4);
    cout<<"t2="; t2.display(); cout<<endl;
    
    T t3(t2);
    t3.adjust(2);
    cout<<"t3="; t3.display(); cout<<endl;

    T t4(std::move(t2));
    cout<<"t4="; t4.display(); cout<<endl;

    cout<<"test: T objects'current count: "<<T::get_cnt()<<endl;
}