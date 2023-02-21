#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, D, K; cin >> N >> D >> K;
        K--;
        int A = N / gcd(N, D);
        cout << (long long) D * K % N + K / A << endl;
    }
    return 0;
}