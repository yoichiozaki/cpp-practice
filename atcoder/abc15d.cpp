#include <bits/stdc++.h>
using namespace std;

int main() {
    int W; cin >> W;
    int N, K; cin >> N >> K;
    int A[N], B[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // dp[i][j][k]: k番目までの画像を使って，幅合計i・使用枚数jのときの重要度の合計の最大値

    int dp[W+1][K+1][N+1];
    memset(dp, 0, sizeof(dp));

    // 0番目までの画像を使って，幅合計0・使用枚数0のときの重要度の合計の最大値は0
    dp[0][0][0] = 0;

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= N; k++) {
                if (0 <= i - A[k-1]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-A[k-1]][j-1][k-1] + B[k-1]);
                }
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
            }
        }
    }

    cout << dp[W][K][N] << endl;
    return 0;
}