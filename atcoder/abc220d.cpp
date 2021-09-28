#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 配るDP
    // i = 1, 2, 3, ...
    // j = 0, 1, 2, ..., 9
    // dp[i][j]: A[i]まで処理したときに左端要素がjとなる操作手順の総数
    // dp[i+1][(j + A[i+1]) % 10] += dp[i][j]
    // dp[i+1][(j * A[i+1]) % 10] += dp[i][j]

    long long MOD = 998244353;
    long long N;
    cin >> N;
    vector<long long> A(N + 1);
    for (long long i = 0; i < N; i++)
        cin >> A[i + 1];
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));
    for (long long j = 0; j < 10; j++)
    {
        if (j == A[1])
            dp[1][j] = 1; // A[1]まで処理したときに左端要素がA[1]となる操作手順の総数は「なにもしない」の1通り
        else
            dp[1][j] = 0;
    }
    for (long long i = 1; i <= N - 1; i++)
    {
        for (long long j = 0; j <= 9; j++)
        {

            dp[i + 1][(j + A[i + 1]) % 10] = ((dp[i + 1][(j + A[i + 1]) % 10]) % MOD + (dp[i][j] % MOD)) % MOD;
            // dp[i + 1][(j * A[i + 1]) % 10] = ((dp[i + 1][(j * A[i + 1]) % 10]) % MOD + (dp[i][j] % MOD)) % MOD;
            dp[i + 1][(j * (A[i + 1] % 10)) % 10] = ((dp[i + 1][(j * (A[i + 1] % 10)) % 10]) % MOD + (dp[i][j] % MOD)) % MOD;
        }
    }
    for (long long K = 0; K <= 9; K++)
        cout << dp[N][K] << endl;
    return 0;
}