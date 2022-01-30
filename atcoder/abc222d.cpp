#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    for (long long i = 0; i < N; i++)
        cin >> B[i];

    long long MAX = 3000;
    vector<vector<long long>> dp(vector<vector<long long>>(N + 1, vector<long long>(MAX + 1, 0LL)));
    dp[0][0] = 1;
    for (long long i = 0; i < N + 1; i++)
    {
        for (long long j = 0; j < MAX; j++)
        {
            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= 998244353;
        }
        if (i != N)
        {
            for (long long j = A[i]; j <= B[i]; j++)
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= 998244353;
            }
        }
    }
    cout << dp[N][MAX] << endl;
    return 0;
}