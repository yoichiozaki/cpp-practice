#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e+18;

int main() {
    long long N, M; cin >> N >> M;
    long long ans = INF;
    for (long long i = 1; i <= N; i++) {
        long long X = (M + i - 1) / i;
        if (X <= N) ans = min(ans, i * X);
        if (i > X) break;
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}