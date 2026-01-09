#include<iostream>

//向操作系统申请/释放一个T类型对象的空间
//new T
//delete T

void test1(){
    using std::cout;
    using std::endl;
    int *ptr1=nullptr;
    ptr1=new int;  //只分配空间，不初始化
    *ptr1=42;
    cout<<*ptr1<<endl;
    delete ptr1;

    ptr1=new int(77); //分配空间并初始化
    cout<<*ptr1<<endl;
    delete ptr1;

    ptr1=new int();  //分配空间，值初始化为0
    cout<<*ptr1<<endl;
    delete ptr1;
}

//向操作系统申请/释放一组连续空间，存放n个T类型对象
//new T[n]
//delete[] T
void test2(){
    using std::cout;
    using std::endl;
    const int N=5;
    int *ptr2=nullptr;
    ptr2=new int[N];  //分配一组内存空间不初始化
    for(auto i=0;i<N;i++){
        cout<<ptr2[i]<<" ";
    }
    cout<<endl; 
    delete[] ptr2;

    ptr2=new int[N]();  //初始化为0
    for(int i=0;i<N;i++){
        cout<<ptr2[i]<<" ";
    }
    cout<<endl;
    delete[] ptr2;
}

//向操作系统申请/释放一组连续的内存空间，存放N个T类型的对象
//new T[n1][n2];
//delete[] T
void test3(){
    using std::cout;
    using std::endl;
    const int N1=2,N2=5;
    int (*ptr3)[N2]; //指向一维数组的首地址的指针
    ptr3=new int[N1][N2]; //二维数组的首地址就是一维数组指针，分配一组连续内存空间，返回指向一维数组的指针
    for(int i=0;i<N1;i++){
        for(int j=0;j<N2;j++){
            cout<<ptr3[i][j]<<" "; //未初始化，内容不确定 
        }
    }
    cout<<"\n";
    delete[] ptr3;
}
int main(){
    std::cout<<"test1:"<<"\n";
    test1();
    std::cout<<"test2:"<<"\n";
    test2();
    std::cout<<"test3:"<<"\n";
    test3();
}