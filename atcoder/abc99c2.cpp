#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;
const int INF = 1001001001;

int dp[MAX_N];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < MAX_N; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j *= 6)
            dp[i] = min(dp[i], dp[i - j] + 1);
        for (int j = 1; j <= i; j *= 9)
            dp[i] = min(dp[i], dp[i - j] + 1);
    }
    cout << dp[N] << endl;
    return 0;
}