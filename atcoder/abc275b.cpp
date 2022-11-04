#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    long long A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    long long X = (((A % MOD) * (B % MOD) % MOD) * (C % MOD)) % MOD;
    long long Y = (((D % MOD) * (E % MOD) % MOD) * (F % MOD)) % MOD;
    cout << (X + MOD - Y) % MOD << endl;
    return 0;
}