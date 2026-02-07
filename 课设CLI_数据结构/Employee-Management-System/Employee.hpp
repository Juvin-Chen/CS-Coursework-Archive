#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    /* 定义一个枚举类 (enum class)，用来表示字段类型,既可以用于【查找】，也可以用于【排序】*/
    enum class KeyType {
        ID,
        NAME,
        ROLE,
    };

    /*员工的基本信息：编号、姓名、性别、出生年月、学历、职务、电话、住址*/
    int id;
    string name;
    string gender; // male/female
    string birthdate;
    string education;
    string role;
    string phonenumber;
    string address;

    Employee() : id(0) {}
    Employee(int id, string name, string gender, string role, string phone, string address, string birth = "未知",
             string edu = "未知")
        : id(id), name(name), gender(gender), role(role), phonenumber(phone), address(address), birthdate(birth),
          education(edu) {}

    // 重载输出运算符
    friend ostream &operator<<(ostream &os, const Employee &emp) {
        os << "ID: " << emp.id << endl;
        os << "姓名: " << emp.name << endl;
        os << "性别: " << emp.gender << endl;
        os << "出生年月: " << emp.birthdate << endl;
        os << "学历: " << emp.education << endl;
        os << "职务: " << emp.role << endl;
        os << "电话: " << emp.phonenumber << endl;
        os << "住址: " << emp.address;
        return os;
    }

    // 重载输入运算符
    friend istream &operator>>(istream &is, Employee &emp) {
        cout << "请输入ID (数字): ";
        is >> emp.id;
        cout << "请输入姓名: ";
        is >> emp.name;
        cout << "请输入性别: ";
        is >> emp.gender;
        cout << "请输入出生年月: ";
        is >> emp.birthdate;
        cout << "请输入学历: ";
        is >> emp.education;
        cout << "请输入职务: ";
        is >> emp.role;
        cout << "请输入电话: ";
        is >> emp.phonenumber;
        cout << "请输入住址: ";
        is >> emp.address;
        return is;
    }
};
