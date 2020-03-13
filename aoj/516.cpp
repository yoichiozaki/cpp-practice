#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, K;
    while (cin >> N >> K) {
        if (N == 0) break;

        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<long long> s(N+1, 0);
        for (int i = 0; i < N; i++) s[i+1] = s[i] + a[i];

        long long ans = -INF;
        for (int i = 0; i <= N-K; i++) {
            long long val = s[i+K] - s[i];
            if (ans < val) ans = val;
        }
        cout << ans << endl;
    }
    return 0;
}