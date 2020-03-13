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
    int N; cin >> N;
    int h[N+10];
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    int dp[N+10];
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (2 < i) {
            chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
    }
    cout << dp[N] << endl;
    return 0;
}