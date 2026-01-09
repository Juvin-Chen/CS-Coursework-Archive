#pragma once

#include <iostream>

class vectorInt{
public:
    vectorInt();
    vectorInt(int n);
    vectorInt(int n,int value);
    vectorInt(const vectorInt& vi); //深拷贝
    ~vectorInt();

    int size() const;
    int& at(int index);
    const int& at(int index) const;
    vectorInt& assign(const vectorInt& vi);
    

    int *begin();
    int *end();
    const int *begin() const;
    const int *end() const;
private:
    int n; //当前数据项的个数
    int *ptr; //数据区
};

vectorInt::vectorInt():n{0},ptr(nullptr){}
vectorInt::vectorInt(int n):n{n},ptr{new int[n]}{}

vectorInt::vectorInt(int n,int value):n{n},ptr{new int[n]}{
    for(int i=0;i<n;i++) ptr[i]=value;
}

vectorInt::vectorInt(const vectorInt& vi):n{vi.n},ptr{new int[n]}{
    for(int i=0;i<n;i++) ptr[i]=vi.ptr[i];
}

vectorInt::~vectorInt(){
    delete[] ptr;
}
int vectorInt::size() const{ return n; }

const int& vectorInt::at(int index)  const{
    if(index<0||index>=n){
        std::cerr<<"IndexError:index out of range\n";
        std::exit(1);
    }
    return ptr[index];
}

int& vectorInt::at(int index){
    if(index<0||index>=n){
        std::cerr<<"IndexError:index out of range\n";
        std::exit(1);
    }
    return ptr[index];
}

//深拷贝
vectorInt& vectorInt::assign(const vectorInt& vi){
    if (this==&vi) return *this;
    int *ptr_tmp;
    ptr_tmp=new int[vi.n];
    for(int i=0;i<vi.n;i++)
        ptr_tmp[i]=vi.ptr[i];
    delete[] ptr;  //将原来自己分配的数组资源释放掉
    n=vi.n;
    ptr=ptr_tmp;
    return *this;
}

int *vectorInt::begin(){ return ptr; }
int *vectorInt::end(){ return ptr+n; }
const int *vectorInt::begin() const{ return ptr; }
const int *vectorInt::end() const{ return ptr+n; }





