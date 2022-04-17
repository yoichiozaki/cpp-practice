#include <bits/stdc++.h>

#define MOD 998244353
using namespace std;

int main() {
    long long N, M, K; cin >> N >> M >> K;
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0LL));
    dp[0][0] = 1LL;
    for (long long n = 0; n < N; n++) {
        for (long long k = 0; k < K; k++) {
            for (long long m = 1; m <= M; m++) {
                if (k + m <= K) {
                    dp[n + 1][k + m] = ((dp[n + 1][k + m] % MOD) + (dp[n][k] % MOD)) % MOD;
                }
            }
        }
    }
    long long ans = 0LL;
    for (long long k = 1; k <= K; k++) {
        ans = ((ans % MOD) + (dp.back()[k] % MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}