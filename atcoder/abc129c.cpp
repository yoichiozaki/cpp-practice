#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int N, M; cin >> N >> M;
    long long broken[100010];
    for (int i = 0; i <= 100010; i++) {
        broken[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        broken[a]++;
    }
    long long dp[100010];
    for (int i = 0; i < 100010; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    if (broken[1]) {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }
    for (int i = 2; i <= N; i++) {
        if (broken[i]) {
            dp[i] = 0;
        } else {
            if (broken[i-2] == 0 && broken[i-1] == 0) {
                dp[i] += (dp[i-2] + dp[i-1]);
            } else if (broken[i-2] == 0 && broken[i-1] == 1) {
                dp[i] += dp[i-2];
            } else if (broken[i-2] == 1 && broken[i-1] == 0) {
                dp[i] += dp[i-1];
            } else if (broken[i-2] == 1 && broken[i-1] == 1) {
                dp[i] = 0;
            }
            dp[i] %= MOD;
        }
    }
    cout << dp[N] << endl;
    return 0;
}