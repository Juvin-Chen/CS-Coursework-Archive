#include "Menu.hpp"
#include <iostream>

using namespace std;

//启动系统主循环
void Menu::run() {

    mgr.add_employee(Employee(1003, "Alice", "Female", "Manager", "13800138000", "Beijing"));
    mgr.add_employee(Employee(1001, "John",  "Male",   "Coder",   "13900000000", "Shanghai"));
    mgr.add_employee(Employee(1002, "Lisi",  "Female", "HR",      "13612345678", "Guangzhou"));
    mgr.add_employee(Employee(1005, "Alex",  "Male",   "Cleaner", "13311112222", "Shenzhen"));

    cout << " [main指令] 4条测试数据已加载" << endl;

    while (true) {
        cout << "\n========================================" << endl;
        cout << "       员工管理系统 (CLI版)             " << endl;
        cout << "========================================" << endl;
        cout << "   1. 添加员工 (Insert)" << endl;
        cout << "   2. 删除员工 (Delete)" << endl;
        cout << "   3. 修改员工 (Update)" << endl;
        cout << "   4. 查找员工 (Search)" << endl;
        cout << "   5. 员工排序 (Sort)" << endl;
        cout << "   6. 显示所有 (Show All)" << endl;
        cout << "   0. 退出系统 (Exit)" << endl;
        cout << "========================================" << endl;
        cout << "请输入操作编号: ";

        int choice;
        cin>>choice; 
        if (choice < 0 || choice > 6) {
            cout << ">>> 输入数字不对！请输入 0 到 6 之间的数字。" << endl;
            continue; 
        }

        switch (choice) {
        case 1: 
            handleAdd(); 
            break;
        case 2: 
            handleDelete(); 
            break;
        case 3: 
            handleUpdate(); 
            break;
        case 4: 
            handleSearch(); 
            break;
        case 5: 
            handleSort(); 
            break;
        case 6: 
            mgr.show_all(); 
            break;
        case 0: 
            cout << "系统已退出！" << endl; 
            return;
        default: 
            cout << "输入无效，请重新选择！" << endl; 
            break;
        }
    }
}

//处理添加员工
void Menu::handleAdd() {
    Employee e;
    cout << "\n[新增员工]" << endl;
    cin >> e;
    //调用 Manager 的添加功能
    mgr.add_employee(e);
}

//处理删除员工
void Menu::handleDelete() {
    int id;
    cout << "请输入要删除的员工ID: ";
    cin >> id;
    mgr.delete_employee(id);
}

//处理修改员工
void Menu::handleUpdate() {
    int id;
    cout << "\n--- [修改信息] ---" << endl;
    cout << "请输入要修改信息的员工ID: ";
    cin >> id;
    mgr.update_employee(id);
}

//处理查找员工
void Menu::handleSearch() {
    cout << "\n--- [查询员工] ---" << endl;
    cout << "请选择查询方式:" << endl;
    cout << "1. 按 ID 查询" << endl;
    cout << "2. 按 姓名 查询" << endl;
    cout << "请选择: ";

    int choice;
    cin >> choice;
    Employee::KeyType type;
    string value;

    if (choice == 1) {
        type = Employee::KeyType::ID;
        cout << "请输入目标ID: ";
        cin >> value;
    } else if (choice == 2) {
        type = Employee::KeyType::NAME;
        cout << "请输入目标姓名: ";
        cin >> value;
    }

    // 调用 Manager 查找，接收返回的指针
    Employee* result = mgr.select_employee(type, value);

    if (result != nullptr) {
        cout << "\n 查询成功！员工信息如下：" << endl;
        cout << "------------------------------------------------" << endl;
        cout << *result << endl;
        cout << "------------------------------------------------" << endl;
    } else {
        cout << "\n>>> 查无此人！请检查输入条件。" << endl;
    }
}

//处理排序
void Menu::handleSort() {
    cout << "\n[员工排序]" << endl;
    cout << "请选择排序依据:" << endl;
    cout << "1. 按 ID 升序" << endl;
    cout << "2. 按 姓名 字典序" << endl;
    cout << "3. 按 职务 字典序" << endl;
    cout << "请选择: ";

    int choice;
    cin >> choice;

    Employee::KeyType type;
    switch (choice) {
        case 1: type = Employee::KeyType::ID; break;
        case 2: type = Employee::KeyType::NAME; break;
        case 3: type = Employee::KeyType::ROLE; break;
        default: 
            cout << " 无效选择，默认按 ID 排序。" << endl;
            type = Employee::KeyType::ID;
            break;
    }

    mgr.sort_employee(type);
    
    //排序后自动显示一下结果
    cout << "排序完成，列表如下：" << endl;
    mgr.show_all();
}