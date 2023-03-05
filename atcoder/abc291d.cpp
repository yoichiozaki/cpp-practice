#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

int main() {
    long long N; cin >> N;
    vector<pair<int, int>> cards(N);
    for (int i = 0; i < N; i++) {
        long long A, B; cin >> A >> B;
        cards[i] = make_pair(A, B);
    }
    vector<pair<long long, long long>> dp(N);
    for (int i = 0; i < N; i++) dp[i] = {0ll, 0ll};
    dp[0] = {1ll, 1ll};
    for (int i = 1; i < N; i++) {
        if (cards[i-1].first != cards[i].first) {
            dp[i].first = (dp[i].first % MOD + dp[i-1].first % MOD) % MOD;
        }
        if (cards[i-1].first != cards[i].second) {
            dp[i].second = (dp[i].second % MOD + dp[i-1].first % MOD) % MOD;
        }
        if (cards[i-1].second != cards[i].first) {
            dp[i].first = (dp[i].first % MOD + dp[i-1].second % MOD) % MOD;
        }
        if (cards[i-1].second != cards[i].second) {
            
            dp[i].second = (dp[i].second % MOD + dp[i-1].second % MOD) % MOD;
        }
        dp[i].first %= MOD;
        dp[i].second %= MOD;
    }
    cout << (dp[N - 1].first % MOD + dp[N - 1].second % MOD) % MOD;
    return 0;
}