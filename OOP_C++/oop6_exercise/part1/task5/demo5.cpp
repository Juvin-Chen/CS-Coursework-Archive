#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<numeric>

template<typename T>
void output(const T &t){
    if(t.empty()){
        std::cout<<"\n";
        return ;
    }
    auto iter=t.begin();  //迭代器的使用
    std::cout<<*iter++;
    for(;iter!=t.end();++iter){
        std::cout<<","<<*iter;
    }
    std::cout<<"\n";
}

void test1(){
    std::array<int,5> x1{1,9,0,2,3};
    std::cout<<"x1:"; output(x1);
    
    std::array<int,5> x2;
    x2.fill(42); //用42填x2对象内数据项
    x1.swap(x2); //交换x1,x2对象
    std::cout<<"x1:"; output(x1);
    std::cout<<"x2:"; output(x2);
    x1={};  //用空列表填充，元素值置0
    std::cout<<"x1:"; output(x1);
}

void test2(){
    std::vector<int> x1; // 对象创建方式1
    std::cout << "x1: "; output(x1);

    std::vector<int> x2(5); // 对象创建方式2
    std::cout << "x2: "; output(x2);
    
    std::vector<int> x3{42, 33}; // 对象创建方式3
    x3.push_back(55);
    x3.resize(5,-1); //扩容到5个元素
    std::cout<<x3.size()<<std::endl;
    std::cout<<"x3:"; output(x3);
    int sum=accumulate(x3.begin(),x3.end(),0);
    std::cout<<"sum(x3):"<<sum<<std::endl;
    x3.clear();
    std::cout<<"x3.size()="<<x3.size()<<", x3.capacity()="<<x3.capacity()<<std::endl;
}

void test3(){
    std::string s1{"OOP"};
    s1+="2049";

    std::string s2=s1.substr(0,3);
    int pos1=s1.find_first_not_of('o');
    int pos2=s1.find_first_of('o');
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "pos1 = " << pos1 << std::endl;
    std::cout << "pos2 = " << pos2 << std::endl;
}

int main(){
    std::cout<<"test1:array\n";
    test1();

    std::cout<<"\ntest2:vector\n";
    test2();

    std::cout<<"\ntest3:string\n";
    test3();
}
