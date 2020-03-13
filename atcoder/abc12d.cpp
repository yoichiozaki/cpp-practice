#include <bits/stdc++.h>
using namespace std;

int MAX_DIST = 1e9;
vector<vector<int>> dp(0, vector<int>(0, MAX_DIST));

void warshall() {
    int v = dp[0].size();
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    dp = vector<vector<int>>(n, vector<int>(n, MAX_DIST));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    warshall();
    int ret = MAX_DIST;
    for (int i = 0; i < n; i++) {
        ret = min(ret, *max_element(dp[i].begin(), dp[i].end()));
    }
    cout << ret << endl;
    return 0;
}