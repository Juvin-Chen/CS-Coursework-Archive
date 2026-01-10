#pragma once
#include "Sqlist.hpp"
#include <string>

class Manager {
public:
    Manager();  
    ~Manager(); 

    void sort_employee(Employee::KeyType type);
    Employee* select_employee(Employee::KeyType type, const std::string& value);
    void update_employee(int id);
    void add_employee(const Employee& newe);
    void delete_employee(int id);
    void show_all();

private:
    SqList employees;
    
private:
    bool compare(const Employee& a, const Employee& b, Employee::KeyType type);
    int partition(int low, int high, Employee::KeyType type);
    void quickSort(int low, int high, Employee::KeyType type);
};