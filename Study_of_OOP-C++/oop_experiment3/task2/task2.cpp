#include<iostream>
#include<vector>

void test1();
void test2();
void output1(const std::vector<int> &v);
void output2(const std::vector<int> &v);
void output3(const std::vector<std::vector<int>> &v);

int main(){
    std::cout<<"深复制验证1: 标准库vector<int>\n";
    test1();
    std::cout<<"\n深复制验证2: 标准库vector<int>嵌套使用\n";
    test2();
}

void test1(){
    std::vector<int> v1(5,42);
    const std::vector<int> v2(v1);

    std::cout << "**********拷贝构造后**********\n";
    std::cout << "v1: "; output1(v1);
    std::cout << "v2: "; output1(v2);

    v1.at(0)=-1;
    std::cout<<"**********修改v1[0]后**********\n";
    std::cout<<"v1:"; output1(v1);
    std::cout<<"v2:"; output1(v2);
}

void test2(){
    std::vector<std::vector<int>> v1{{1,2,3},{4,5,6,7}};
    const std::vector<std::vector<int>> v2(v1);
    std::cout << "**********拷贝构造后**********\n";
    std::cout << "v1: "; output3(v1);
    std::cout << "v2: "; output3(v2);

    v1.at(0).push_back(-1);
    std::cout << "**********修改v1[0]后**********\n";
    std::cout << "v1: \n"; output3(v1);
    std::cout << "v2: \n"; output3(v2);
}

//at
void output1(const std::vector<int> &v){
    if(v.size()==0){
        std::cout<<'\n';
        return;
    }
    std::cout<<v.at(0);  //test1中只修改了v1
    for(auto i=1;i<v.size();i++){
        std::cout<<","<<v.at(i);
    }
    std::cout<<"\n";
}
//iterator
void output2(const std::vector<int> &v){
    if(v.size()==0){
        std::cout<<'\n';
        return;
    }
    auto it=v.begin();
    std::cout<<*it;
    for(it=v.begin()+1;it!=v.end();++it)
        std::cout<<","<<*it;
    std::cout<<'\n';
}

//print vector<vector<int>>数据项 
void output3(const std::vector<std::vector<int>> &v){
    if(v.size() == 0) {
        std::cout << '\n';
        return;
    }
    for(auto &i: v)
        output2(i);
}

