#include "Car.h"
#include "Queue.h"
#include "Stack.h"
#include <cstdlib>
#include <iostream>
#include <unordered_map> //无序关联式容器，底层用哈希表实现
#include <vector>
using namespace std;

unordered_map<int, int> park_map; // 用来存储每个车辆对应的停车位置

int main() {
    char c;   // 操作指令
    int a;    // 车牌号
    int b;    // 到达/离开时间
    int type; // 车辆类型

    Stack s1, s2;
    InitStack(&s1); // s1用于表示停车场
    InitStack(&s2); // 辅助栈
    Queue q;
    InitQueue(&q);
    int queue_num = 0; // 用于计算队列个数

    cout << "==================== 停车管理系统 ====================\n";
    cout << "输入格式: A [车牌] [时间] [车辆类型]  /  D [车牌] [时间] \n";

    while (1) {
        car car_one;
        cin >> c >> a >> b;
        car_one.num = a;
        if (c == 'A') {
            cin >> type;
            car_one.type = (CarType)type;
            if (s1.top - s1.base != s1.stacksize) {
                car_one.arrive_time = b;
                park_map[a] = s1.top - s1.base + 1;
                Push(&s1, car_one);
                cout << "车辆到达，停车场未满，车辆停在停车场从北往南第" << park_map[a] << "个位置\n";
            } else {
                EnQueue(&q, car_one);
                queue_num++;
                cout << "车辆到达，停车场已满，车辆停在便道上第" << queue_num << "个位置\n";
            }
        } else if (c == 'D') {
            int count = s1.top - s1.base - park_map[a];
            car e;
            while (count--) {
                Pop(&s1, &e);
                Push(&s2, e);
            }
            Pop(&s1, &e);
            cout << "车辆离开，车辆在停车场的停车时长为" << b - e.arrive_time << "min\n";
            cout << "需要缴纳的停车费为" << e.type * (b - e.arrive_time) << "元" << "\n";
            while (s2.top != s2.base) {
                Pop(&s2, &e);
                park_map[e.num]--;
                Push(&s1, e);
            }
            // 将便道上的队头车辆入栈
            if (q.rear != q.front) {
                DeQueue(&q, &e);
                queue_num--;
                e.arrive_time = b;
                park_map[e.num] = s1.stacksize;
                Push(&s1, e);
            }
        } else {
            cout << "输入操作指令'E'，停车场管理程序退出！\n";
            break;
        }
    }
    return 0;
}