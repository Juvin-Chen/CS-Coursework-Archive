#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 13  // 哈希表长度

// 1. 构造结构体
typedef struct Elem {
    int key;            // 元素的值
    int compareTimes;   // 查找到该元素需要比较的次数
    int flag;           // 用来标识该位置是否已经存有数据 (0:空, 1:有数据)
} Elem;

typedef struct HashList {
    Elem *base;
    int length;
} HashList;

// 2. 建立哈希表
void CreateHashList(HashList &HL) {
    int data[] = {23, 5, 17, 12, 26, 31, 13, 4, 6};
    int n = sizeof(data) / sizeof(data[0]);
    
    HL.length = MAXSIZE;
    HL.base = (Elem *)malloc(HL.length * sizeof(Elem));
    
    // 初始化表
    for (int i = 0; i < HL.length; i++) {
        HL.base[i].flag = 0;
        HL.base[i].key = 0;
        HL.base[i].compareTimes = 0;
    }

    // 插入数据
    for (int i = 0; i < n; i++) {
        int key = data[i];
        int hashAddr = key % 13; // 哈希函数 H(key) = key MOD 13
        int count = 1;           // 比较次数记录

        // 线性探测处理冲突
        while (HL.base[hashAddr].flag == 1) {
            hashAddr = (hashAddr + 1) % HL.length;
            count++;
        }
        
        // 存入哈希表
        HL.base[hashAddr].key = key;
        HL.base[hashAddr].compareTimes = count;
        HL.base[hashAddr].flag = 1;
    }
    printf("哈希表创建成功！\n");
}

// 3. 显示哈希表
void PrintHashList(HashList HL) {
    printf("\n当前哈希表内容：\n");
    printf("地址\t关键字\t比较次数\n");
    for (int i = 0; i < HL.length; i++) {
        if (HL.base[i].flag == 1) {
            printf("%d\t%d\t%d\n", i, HL.base[i].key, HL.base[i].compareTimes);
        }
    }
}

// 4. 查找
void IndexHashList(HashList HL) {
    int key;
    printf("\n请输入需要查找的关键字: ");
    scanf("%d", &key);

    int hashAddr = key % 13;
    int startAddr = hashAddr; // 记录起始位置防止死循环
    int count = 0;

    while (HL.base[hashAddr].flag != 0) {
        count++;
        if (HL.base[hashAddr].key == key) {
            printf("查找成功！关键字 %d 在哈希表中的地址为: %d，比较次数: %d\n", key, hashAddr, count);
            return;
        }
        hashAddr = (hashAddr + 1) % HL.length;
        if (hashAddr == startAddr) break; // 找了一圈没找到
    }
    printf("查找失败！该值在哈希表中不存在。\n");
}

// 5. 计算平均查找长度 ASL
void CalcuASL(HashList HL) {
    float totalCompare = 0;
    int count = 0;
    for (int i = 0; i < HL.length; i++) {
        if (HL.base[i].flag == 1) {
            totalCompare += HL.base[i].compareTimes;
            count++;
        }
    }
    if (count == 0) printf("表中无数据。\n");
    else printf("\n该表的平均查找长度 ASL = %.2f\n", totalCompare / count);
}

// 6. 主函数
int main() {
    HashList H;
    int choice;
    
    // 自动初始化创建
    CreateHashList(H);

    while (1) {
        printf("\n========================\n");
        printf("1. 显示哈希表\n");
        printf("2. 查找\n");
        printf("3. 退出\n");
        printf("========================\n");
        printf("SELECT: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                PrintHashList(H);
                CalcuASL(H);
                break;
            case 2:
                IndexHashList(H);
                break;
            case 3:
                printf("退出程序。\n");
                free(H.base);
                return 0;
            default:
                printf("输入有误，请重新选择。\n");
        }
    }
    return 0;
}