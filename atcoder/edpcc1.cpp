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
long long play[100010][3]; // play[i][j] = i日目の遊びjで得られる幸福度

long long dp[100010][3];

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> play[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmax(dp[i+1][k], dp[i][j] + play[i][k]);
            }
        }
    }

    long long res = 0;
    for (int j = 0; j < 3; j++) {
        chmax(res, dp[N][j]);
    }
    cout << res << endl;
    return 0;
}