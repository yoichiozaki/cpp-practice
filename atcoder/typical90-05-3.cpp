#include <bits/stdc++.h>

using namespace std;

long long modpow(long long a, long long b, long long m)
{
    long long p = 1, q = a;
    for (int i = 0; i < 63; i++)
    {
        if ((b & (1LL << i)) != 0)
        {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

const long long MOD = 1000000007;

long long N, B, K;
long long C[11];

long long power10[64];
long long dp[64][1009];
long long ans[64][1009];

int main()
{
    cin >> N >> B >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> C[i];
    }

    for (int i = 0; i <= 62; i++)
    {
        power10[i] = modpow(10LL, (1LL << i), B);
    }

    for (int i = 1; i <= K; i++)
    {
        dp[0][C[i] % B] += 1;
    }

    for (int i = 0; i < 62; i++)
    {
        for (int j = 0; j < B; j++)
        {
            for (int k = 0; k < B; k++)
            {
                dp[i + 1][(j * power10[i] + k) % B] += dp[i][j] * dp[i][k];
                dp[i + 1][(j * power10[i] + k) % B] %= MOD;
            }
        }
    }

    ans[0][0] = 1;
    for (int i = 0; i < 62; i++)
    {
        if ((N & (1LL << i)) != 0LL)
        {
            for (int j = 0; j < B; j++)
            {
                for (int k = 0; k < B; k++)
                {
                    ans[i + 1][(j * power10[i] + k) % B] += ans[i][j] * dp[i][k];
                    ans[i + 1][(j * power10[i] + k) % B] %= MOD;
                }
            }
        }
        else
        {
            for (int j = 0; j < B; j++)
            {
                ans[i + 1][j] = ans[i][j];
            }
        }
    }

    cout << ans[62][0] << endl;
    return 0;
}