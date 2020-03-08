#include <bits/stdc++.h>
using namespace std;

// メモ化再帰

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

ll rec(int i) {
    if (i == 1) {
        return 0;
    }
    ll res = INF;
    chmin(res, rec(i-1) + abs(a[i] - a[i-1]));
    if (2 < i) {
        chmin(res, rec(i-2) + abs(a[i] - a[i-2]));
    }
    return dp[i] = res; // メモ
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }

    cout << rec(N) << endl;
    return 0;
}