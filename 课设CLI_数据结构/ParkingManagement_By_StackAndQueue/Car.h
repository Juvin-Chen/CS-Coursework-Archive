#pragma once

typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

enum CarType { Small = 1, Large = 2 };

typedef struct car {
    int num;         // 车牌号
    int arrive_time; // 到达时间
    CarType type;
} car;
