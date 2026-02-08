/**
 * @file GCD_LCM.cpp
 * @brief 实现最大公约数(GCD)和最小公倍数(LCM)的计算
 * @details 核心算法：辗转相除法（欧几里得算法），相比辗转相减法效率更高
 *          数据类型选用long long，避免算法竞赛中常见的大数溢出问题
 */

#include <iostream>

using namespace std;

/**
 * GCD 最原始原理:用大的数不断减去小的数，把问题规模一步步缩小，直到两个数相等，这个相等的数就是最大公约数（GCD）。
 * 目标：找一把尺子 X，能同时量尽 48 和 18。 关键性质：如果 X 能整除 a 和 b，那么 X 一定能整除 a−b ，也就是 a%b。
 * 48 % 18 = 12 → 问题变为求 gcd (18, 12)。    |  18 % 12 = 6 → 问题变为求 gcd (12, 6)
 * 12 % 6 = 0 → 触发终止条件，返回当前的 b（6） |  结果：gcd (48, 18) = 6
 */

long long gcd_initial(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd_initial(b, a % b);
}

// 最精简的写法
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; } // 根据数学原理的公式计算
int main() {
    long long a, b; // 一般用long long 防止数据范围越界
    cin >> a >> b;
    cout << "gcd:" << gcd(a, b) << "\n" << "lcm:" << lcm(a, b) << endl;
    return 0;
}
