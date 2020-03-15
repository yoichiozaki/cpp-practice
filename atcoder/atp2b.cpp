#include <bits/stdc++.h>
using namespace std;

long long pow_mod(long long n, long long p, long long m) {
    long long r = 1;
    for (; 0 < p; p >>= 1) {
        if (p & 1) {
            r = (r * n)% m;
        }
        n = (n * n) % m;
    }
    return r;
}

int main() {
    long long N, P, M; cin >> N >> M >> P;
    cout << pow_mod(N, P, M) << endl;
    return 0;
}