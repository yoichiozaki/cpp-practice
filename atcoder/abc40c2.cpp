#include <bits/stdc++.h>
using namespace std;

// 配るDP

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

using ll = long long;
const ll INF = 1LL << 60;

int N;
ll a[100010];
ll dp[100010];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;
    for (int i = 1; i <= N; i++) {
        chmin(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
        chmin(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
    }
    cout << dp[N] << endl;
    return 0;
}