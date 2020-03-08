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

int N;
long long W, weight[110], value[110];

long long dp[110][100100] = {0};

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= W; w++) {
            if (0 <= w - weight[i]) {
                chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i]);
            }
            chmax(dp[i+1][w], dp[i][w]);
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}