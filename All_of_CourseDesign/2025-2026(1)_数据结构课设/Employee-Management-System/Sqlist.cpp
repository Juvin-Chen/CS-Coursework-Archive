#include "Sqlist.hpp"
#include <iostream>

// 初始化顺序表
bool InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) {
        std::cerr << "内存分配失败" << std::endl;
        return false;
    }
    L.length = 0;
    return true;
}

// 插入元素
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MAXSIZE)
        return false;

    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
}

// 删除元素
bool ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length)
        return false;

    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return true;
}

// 根据下标获取元素
bool GetElem(const SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.elem[i - 1];
    return true;
}