#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k]: 0以上i以下の数字から異なるj個の数字を取り出してその合計がkとなる組み合わせの総数

long long dp[101][10][1001];

long long dfs(long long i, long long j, long long k)
{
    if (j < 0LL || k < 0LL)
        return 0LL;
    if (i < 0LL)
    {
        if (!j && !k)
            return 1LL;
        else
            return 0LL;
    }
    if (~dp[i][j][k])
        return dp[i][j][k];

    long long ret = dfs(i - 1LL, j, k) + dfs(i - 1LL, j - 1LL, k - i);
    return dp[i][j][k] = ret;
}

int main()
{
    fill_n(**dp, 101LL * 10LL * 1001LL, -1LL);
    long long n, s;
    while (cin >> n >> s, n || s)
        cout << dfs(100LL, n, s) << endl;
    return 0;
}