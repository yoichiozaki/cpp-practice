#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 三辺の長さの最大公約数が立方体の一辺の長さ
    long long A, B, C;
    cin >> A >> B >> C;
    long long R = __gcd(A, __gcd(B, C));
    cout << (A / R - 1LL) + (B / R - 1LL) + (C / R - 1LL) << endl;
    return 0;
}