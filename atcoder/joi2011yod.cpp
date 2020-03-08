#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; n--;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int sum; cin >> sum;
    long long dp[110][30];
    memset(dp, 0, sizeof(dp));

    // dp[i][j]: 左からi個の穴に+/-を入れてa_0~a_iまでの部分和をjにする方法の総数
    // dp[i+1][j]: 左からi+1個の穴に+/-を入れてa_0~a_iまでの部分和をjにする方法の総数
    //     = dp[i][j-a_(i+1)] + dp[i][j+a_(i+1)]
    // dp[0][a_0]: 左から0個の穴に+/-を入れて部分和をa_0にする方法は1通り
    // dp[0][a_0以外]: 左から0個の穴に+/-を入れて部分和をa_0にする方法は0通り

    dp[0][nums[0]] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (0 <= j + nums[i+1] && j + nums[i+1] <= 20) {
                dp[i+1][j] += dp[i][j+nums[i+1]];
            }
            if (0 <= j - nums[i+1] && j - nums[i+1] <= 20) {
                dp[i+1][j] += dp[i][j-nums[i+1]];
            }
        }
    }

    cout << dp[n-1][sum] << endl;
    return 0;
}