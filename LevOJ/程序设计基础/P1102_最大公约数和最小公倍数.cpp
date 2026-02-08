#include <iostream>

using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n" << lcm(a, b) << endl;
    return 0;
}
