#include <bits/stdc++.h>
using namespace std;

int main() {
    long long dp[35];
    for (int i = 0; i < 35; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < 35; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int days = 0;
        if (dp[n]%10 != 0) {
            days = dp[n-1]/10 + 1;
        } else {
            days = dp[n-1]/10;
        }
        int years = 0;
        if (days%365 != 0) {
            years = days/365 + 1;
        } else {
            years = days/365;
        }
        cout << years << endl;
    }
    return 0;
}