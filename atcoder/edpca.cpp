#include <bits/stdc++.h>
using namespace std;

// DP実装の順序
// 1. DP配列全体を「DPの種類に応じた初期値」で初期化
// 2. 初期条件を入力
// 3. ループを回す
// 4. テーブルから解を得て出力

template<class T> inline bool chmin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;

int N;
long long h[100010];

long long dp[100010];

int main() {
    // 入力受け取り
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    // dpテーブル初期化
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }

    // 初期条件
    dp[1] = 0;

    // ループを回す
    for (int i = 2; i <= N; i++) {
        if (2 < i) {
            chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));

        // 冗長に書くと以下
        // if (i == 2) {
        //     chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        // } else {
        //     chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        //     chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        // }
    }

    // 結果を出力
    cout << dp[N] << endl;

    return 0;
}