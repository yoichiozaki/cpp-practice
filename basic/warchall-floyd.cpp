#include <bits/stdc++.h>
using namespace std;

// 全頂点対最短経路問題
// - ワーシャルフロイド法：計算量O(V^3)なのであまり使われない
// - 全頂点に対してそれぞれを始点としたダイクストラ法をやればいい：計算量O(VE log V)
// - 木上での全頂点対最短経路問題：Lowest Common Ancestorアルゴリズムで解ける．事前計算量O(V)，クエリごとO(log V)

// ワーシャルフロイド法
// - 実装が簡単
// - 動的計画法を使っている

const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j]= INF;
        }
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k]);
            }
        }
    }

    cout << "0からの最短距離" << endl;
    for (int i = 0; i < n; i++) {
        if (dp[0][i] < INF) {
            cout << dp[0][i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
    cout << "1からの最短距離" << endl;
    for (int i = 0; i < n; i++) {
        if (dp[1][i] < INF) {
            cout << dp[1][i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
    return 0;
}