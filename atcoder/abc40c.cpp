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
long long a[100010];
long long dp[100010];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (2 < i) {
            chmin(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
        }
        chmin(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
    }
    cout << dp[N] << endl;
    return 0;
}