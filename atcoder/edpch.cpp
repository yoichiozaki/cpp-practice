#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
    int H, W; cin >> H >> W;
    vector<string> field(H);
    for (int i = 0; i < H; i++) cin >> field[i];
    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!(i == 0 && j == 0)) {
                if (field[i][j] == '#') dp[i][j] = 0;
                else {
                    if (i - 1 < 0) {
                        dp[i][j] = (dp[i][j - 1]) % MOD;
                    } else if (j - 1 < 0) {
                        dp[i][j] = (dp[i - 1][j]) % MOD;
                    } else {
                        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                    }
                }
            }
        }
    }
    cout << dp[H - 1][W - 1] << endl;
    return 0;
}