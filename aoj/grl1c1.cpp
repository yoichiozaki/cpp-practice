#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const long long INF = 1LL << 32;

int n;
long long dp[MAX][MAX]; // dp[i][j]: 頂点i-頂点j間の最短経路コスト

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    int e, u, v, c;
    cin >> n >> e;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> c;
        dp[u][v] = c;
    }

    floyd();

    bool has_negative_cycle = false;

    for (int i = 0; i < n; i++) {
        if (dp[i][i] < 0) { // 自分自身に戻ってくる経路でコストが負になるものが存在
            has_negative_cycle = true;
        }
    }

    if (has_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                if (dp[i][j] == INF) cout << "INF";
                else cout << dp[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}