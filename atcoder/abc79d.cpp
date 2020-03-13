#include <bits/stdc++.h>
using namespace std;

int dp[10][10];

void warshall() {
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    int H, W; cin >> H >> W;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> dp[i][j];
        }
    }
    warshall();
    int ans = 0;
    for (int i = 0; i < H*W; i++) {
        int x; cin >> x;
        if (x == -1) {
            continue;
        } else {
            ans += dp[x][1];
        }
    }
    cout << ans << endl;
    return 0;
}