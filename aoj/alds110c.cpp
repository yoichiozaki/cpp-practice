#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: X[1...i]とY[1...j]におけるLCSの長さ
//
// dp[i][j]
//    if (i == 0 || j == 0) => 0
//    if (0 < i && 0 < j && X[i] == Y[j]) => dp[i-1][j-1] + 1
//    if (0 < i && 0 < j && X[i] != Y[j]) => max(dp[i-1][j], dp[i][j-1])

const int N = 1000;

int lcs(string X, string Y) {
    int dp[N+1][N+1];
    int m = X.size();
    int n = Y.size();
    int max_length = 0;
    X = ' ' + X;
    Y = ' ' + Y;
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 1; j <= n; j++) dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            max_length = max(max_length, dp[i][j]);
        }
    }
    return max_length;
}

int main() {
    string x, y;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cout << lcs(x, y) << endl;
    }
    return 0;
}