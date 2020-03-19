#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: (M_i)(M_i+1)...(M_j-1)(M_j)を最適な順序で計算したときのスカラー乗算の回数の最小値

const int N = 100;

int main() {
    int n, deg[N+1], dp[N+1][N+1];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i-1] >> deg[i];
    }

    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int left = 1; left <= n-len+1; left++){
            int right = left + len - 1;
            dp[left][right] = (1 << 21);
            for (int mid = left; mid <= right; mid++) {
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid+1][right] + deg[left-1]*deg[mid]*deg[right]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}