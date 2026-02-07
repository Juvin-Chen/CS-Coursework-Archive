#include "Manager.hpp"
#include <iostream>

using namespace std;

Manager::Manager() { InitList(employees); }

Manager::~Manager() { delete[] employees.elem; }

// 添加员工
void Manager::add_employee(const Employee &newe) {
    // 默认插入到末尾 (length + 1)
    if (ListInsert(employees, employees.length + 1, newe)) {
        cout << "添加成功！" << endl;
    } else {
        cout << "添加失败（表满）！" << endl;
    }
}

// 删除员工
void Manager::delete_employee(int id) {
    int index = -1;
    // 遍历查找 ID 对应的下标
    for (int i = 0; i < employees.length; i++) {
        if (employees.elem[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        ListDelete(employees, index + 1);
        cout << "删除成功！" << endl;
    } else {
        cout << "未找到 ID 为 " << id << " 的员工，删除失败。" << endl;
    }
}

// 查找员工 (实现漏掉的部分)
Employee *Manager::select_employee(Employee::KeyType type, const std::string &value) {
    for (int i = 0; i < employees.length; i++) {
        bool found = false;

        if (type == Employee::KeyType::ID) {
            if (to_string(employees.elem[i].id) == value)
                found = true;
        } else if (type == Employee::KeyType::NAME) {
            if (employees.elem[i].name == value)
                found = true;
        } else if (type == Employee::KeyType::ROLE) {
            if (employees.elem[i].role == value)
                found = true;
        }

        if (found) {
            return &employees.elem[i]; // 返回找到的员工对象的地址
        }
    }
    return nullptr;
}

// 更新员工
void Manager::update_employee(int id) {
    Employee *emp = select_employee(Employee::KeyType::ID, to_string(id));
    if (emp == nullptr) {
        cout << "未找到 ID 为 " << id << " 的员工，无法修改。" << endl;
        return;
    }

    cout << "请修改员工: " << emp->name << endl;
    cout << "请输入新职务: ";
    cin >> emp->role;
    cout << "请输入新电话: ";
    cin >> emp->phonenumber;
    cout << "请输入新住址: ";
    cin >> emp->address;
    // 暂时只修改这几个字段，其他字段根据需要继续添加输入...

    cout << "信息更新成功！" << endl;
}

// 显示所有员工
void Manager::show_all() {
    if (employees.length == 0) {
        cout << "当前暂无员工信息。" << endl;
        return;
    }

    cout << "ID\t姓名\t性别\t职务\t电话\t\t住址" << endl;
    for (int i = 0; i < employees.length; i++) {
        // 打印每个员工的信息，中间用制表符 \t 隔开
        cout << employees.elem[i].id << "\t" << employees.elem[i].name << "\t" << employees.elem[i].gender << "\t"
             << employees.elem[i].role << "\t" << employees.elem[i].phonenumber << "\t" << employees.elem[i].address
             << endl;
    }
}

// 快速排序相关实现

bool Manager::compare(const Employee &a, const Employee &b, Employee::KeyType type) {
    if (type == Employee::KeyType::ID)
        return a.id <= b.id;
    if (type == Employee::KeyType::NAME)
        return a.name <= b.name;
    if (type == Employee::KeyType::ROLE)
        return a.role <= b.role;
    return false; // 默认返回false
}

int Manager::partition(int low, int high, Employee::KeyType type) {
    Employee pivot = employees.elem[low]; // 取第一个元素做基准
    while (low < high) {
        // 从右往左找比基准小的
        while (low < high && !compare(employees.elem[high], pivot, type))
            high--;
        employees.elem[low] = employees.elem[high];

        // 从左往右找比基准大的
        while (low < high && compare(employees.elem[low], pivot, type))
            low++;
        employees.elem[high] = employees.elem[low];
    }
    employees.elem[low] = pivot;
    return low;
}

void Manager::quickSort(int low, int high, Employee::KeyType type) {
    if (low < high) {
        int pivot = partition(low, high, type);
        quickSort(low, pivot - 1, type);
        quickSort(pivot + 1, high, type);
    }
}

void Manager::sort_employee(Employee::KeyType type) {
    if (employees.length > 1) {
        quickSort(0, employees.length - 1, type);
        cout << "排序完成！" << endl;
    } else {
        cout << "数据不足，无需排序。" << endl;
    }
}