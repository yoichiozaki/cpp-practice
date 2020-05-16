#include <bits/stdc++.h>
using namespace std;

long long dp[90];

int main()
{
    dp[0] = 2;
    dp[1] = 1;
    for (int i = 2; i < 90; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int N;
    cin >> N;
    cout << dp[N] << endl;
    return 0;
}