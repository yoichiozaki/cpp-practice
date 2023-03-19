#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<double> prob(N + 1);
    for (int i = 1; i <= N; i++) cin >> prob[i];

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][0] = dp[i-1][0] * (1.0 - prob[i]);
            } else {
                dp[i][j] = dp[i-1][j-1] * prob[i] + dp[i-1][j] * (1.0 - prob[i]);
            }
        }
    }
    double ans = 0.0;
    for (int i = (N + 1) / 2; i <= N; i++) ans += dp[N][i];
    cout << setprecision(12) << ans << endl;
    return 0;
}