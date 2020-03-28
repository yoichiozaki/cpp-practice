#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// x^n % M
ull power(ull x, ull n, ull M) {
    ull res = 1;
    if (0 < n) {
        res = power(x, n/2, M);
        if (n%2 == 0) res = (res * res) % M;
        else res = (((res * res) % M) * x) % M;
    }
    return res;
}

int main() {
    ull m, n; cin >> m >> n;
    cout << power(m, n, 1000000007) << endl;
    return 0;
}