#pragma once
#include "Manager.hpp"

class Menu {
public:
    void run(); // 启动函数

private:
    Manager mgr; // Menu持有一个Manager对象

    void handleAdd();
    void handleDelete();
    void handleUpdate();
    void handleSearch();
    void handleSort();
};