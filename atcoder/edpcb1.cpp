#include <bits/stdc++.h>
using namespace std;

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

const int INF = 1 << 30;

int main() {
    int N, K; cin >> N >> K;
    int h[N+110];
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    int dp[N+110];
    for (int i = 0; i < N+110; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            chmin(dp[i+k], dp[i] + abs(h[i] - h[i+k]));
        }
    }

    cout << dp[N] << endl;
    return 0;
}