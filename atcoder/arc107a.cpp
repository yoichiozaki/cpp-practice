#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    cout << (((A * (A + 1LL) / 2LL) % mod) * ((B * (B + 1LL) / 2LL) % mod)) % mod * ((C * (C + 1LL) / 2LL) % mod) % mod << endl;
    return 0;
}