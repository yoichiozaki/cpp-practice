#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: タイル(i, j)から左上方向に広げられる正方形の最大の辺の長さ
// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

#define MAX 1400

int dp[MAX][MAX], G[MAX][MAX];

int solution(int H, int W) {
    int maxWidth = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }
    for (int i = 1; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }
    return maxWidth * maxWidth;
}

int main() {
    int H, W; cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }
    cout << solution(H, W) << endl;
    return 0;
}