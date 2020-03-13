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

int main() {
    int N; cin >> N;
    long long W; cin >> W;
    long long weight[110], value[110];
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }
    long long dp[110][100100] = {0};
    for (int i = 0; i < N; i++) {
        for (int sumw = 0; sumw <= W; sumw++) {
            if (0 <= sumw - weight[i]) {
                chmax(dp[i+1][sumw], dp[i][sumw-weight[i]] + value[i]);
            }
            chmax(dp[i+1][sumw], dp[i][sumw]);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}