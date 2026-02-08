/**
 * @file 素数.cpp
 * @brief 算法竞赛中素数相关核心功能实现
 * @details 算法竞赛场景下，素数相关需求主要分为两类，本文件聚焦这两类需求的高效实现：
 *          1. 单个数的素性判断（试除法）
 *          2. 区间内素数筛选（打表）与预处理（埃氏筛/线性筛（欧拉筛））
 */

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// 如果是判断一个单独的数字 n 是否为素数，最通用的高效率做法是试除法，但只需要试除到 sqrt{n} 即可。
// 试除法
bool isPrime(long long n) {
    if (n <= 1)
        return false; // 1不是素数
    if (n == 2 || n == 3)
        return true;
    // 优化：排除偶数和 3 的倍数，步长可以为 6
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
}

/*
试除法算法解析（优化方案）：
大于 3 的素数，一定不会是 2 或 3 的倍数。
我们可以把所有大于 3 的自然数，用 6k + r 的形式表示（k 是正整数，r 取值为 0,1,2,3,4,5）：
6k → 能被 6 整除，不是素数
6k+1 → 可能是素数（比如 7, 13, 19…）
6k+2 → 能被 2 整除（=2*(3k+1)），不是素数
6k+3 → 能被 3 整除（=3*(2k+1)），不是素数
6k+4 → 能被 2 整除（=2*(3k+2)），不是素数
6k+5 → 等价于 6(k+1)-1，也可能是素数（比如 5, 11, 17…）
所以结论是：大于 3 的素数，必然出现在 6k-1 或 6k+1 的位置上（也就是 6 的倍数的两侧）。

回到代码里的 i += 6
代码已经提前排除了 ≤3 的数，也排除了 2 和 3 的倍数，剩下要检查的数，只可能是 6k-1 或 6k+1 的形式。
循环里只需要检查 n 是否能被 i 或 i+2 整除，就能覆盖所有可能的因子，不用再检查中间的数（因为中间的数都是 2 或 3
的倍数，已经被提前排除了）。
*/

/*
批量生成素数表（素数筛法），“求 1 到 N 之间有多少个素数”或者“需要频繁查询某个数是不是素数”。
这时候如果对每个数都调用上面的isPrime，总复杂度会高达O（N*sqrt(N)），这通常会超时(TLE)。
*/

// 1.埃式筛：这是最直观的筛法，但在竞赛中通常不是最优解，因为它会重复标记（例如 12 会被 2 和 3 同时标记）。

// 2.欧拉筛 / 线性筛 (Euler's Sieve / Linear Sieve) —— 强烈推荐，时间复杂度： O(N) （线性）

const int MAXN = 1e7 + 5;
int primes[MAXN];
bool is_composite[MAXN]; // 合数
int cnt = 0;

void eulerSeive(int n) {
    // 也可以用 vector<bool>，但 bool 数组通常稍快一点
    memset(is_composite, 0, sizeof(is_composite));

    is_composite[0] = is_composite[1] = true;

    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;
            // i 里面已经包含某个小素数，要保证是被「最小质因数」筛掉的
            if (i % primes[j] == 0) // 保证不重复筛，如果没有这一行，它就退化成了埃氏筛。
                break;
        }
    }
}

int main() {
    // 加速 C++ IO ，可选
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cout << "请输入筛选范围：";
    cin >> n;

    eulerSeive(n);

    cout << "1 到 " << n << " 共有 " << cnt << " 个素数。" << endl;
    cout << "开始打印素数表:\n ";
    for (int i = 0; i < cnt; i++)
        cout << primes[i] << " ";
    cout << endl;
}

/*
欧拉筛算法解析：
任何一个合数（比如12,30,45），都可以拆成一堆质数相乘（这叫质因数分解）。在这一堆质数里，数值最小的那个，就是“最小质因数”。
欧拉筛的核心铁律：任何一个合数，只能由它的「最小质因数」乘以「最大因数」来筛掉。
*/