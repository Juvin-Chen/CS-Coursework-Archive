#include "CampusMap.hpp" 
#include <iostream>

int main() {
    CampusMap map;
    
    // 初始化数据
    map.initDefaultMap();

    while (true) {
        cout << "\n================ 校园导航系统 ================" << endl;
        cout << "1. 查看所有景点" << endl;
        cout << "2. 查询最短路径" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请选择: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            map.showAllSpots();
        }
        else if (choice == 2) {
            string start, end;
            map.showAllSpots(); // 先展示一下，方便用户看名字
            cout << "请输入起点名称: "; cin >> start;
            cout << "请输入终点名称: "; cin >> end;
            
            map.findShortestPath(start, end);
        }
        else if (choice == 0) {
            cout << "退出系统。" << endl;
            break;
        }
        else {
            cout << "输入无效！" << endl;
        }
    }
    return 0;
}