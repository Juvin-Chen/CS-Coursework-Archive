#pragma once
#include "Employee.hpp"

#define MAXSIZE 100
typedef Employee ElemType;

// 顺序表结构定义
struct SqList {
    ElemType *elem;
    int length;
};

bool InitList(SqList &L);
bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList &L, int i);
bool GetElem(const SqList &L, int i, ElemType &e);