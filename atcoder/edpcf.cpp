#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T; cin >> S >> T;
    S = ' ' + S;
    T = ' ' + T;
    int slen = S.length(), tlen = T.length();
    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1, 0));
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= tlen; j++) {
            if (S[i] == T[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int len = dp[slen][tlen];
    int i = slen, j = tlen;
    char ans[len];
    while (0 < len) {
        if (S[i] == T[j]) {
            ans[len - 1] = S[i];
            i--, j--;
            len--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}