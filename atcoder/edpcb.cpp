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

const long long INF = 1LL << 60;

int N;
long long h[110000];

long long dp[110000];

int main() {
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= N; i++) {
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