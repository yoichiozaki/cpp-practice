#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int score[N+1];
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
        sum += score[i];
    }
    bool dp[N+1][sum+1]; // dp[i][j] := 1-i問目までで合計j点にできるか否か．dp[0]の行は「どの問題も使わず」という意味として捉える
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // どの問題も使わずに合計0点にできる

    // dp[i+1][j]: 1-(i+1)問目までで合計j点にできるか否か
    // - 1-i問目までで合計j点にできているなら，1-(i+1)問目までで合計j点にできる
    // - 1-i問目までで合計j-score[i+1]点にできるなら，1-(i+1)問目までで合計j点にできる

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < score[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-score[i]];
            }
        }
    }

    int count = 0;
    for (int i = 0; i <= sum; i++) {
        if (dp[N][i]) count++;
    }
    cout << count << endl;
    return 0;
}