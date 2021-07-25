#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;

    string T = "chokudai";
    long long MOD = 1000000007;

    // dp[i][j] := Sのi文字目まで使用してchokudaiのj文字目まで選択する方法
    vector<vector<long long>> dp(200000, vector<long long>(10, 0LL));

    for (int i = 0; i <= (int)S.length(); i++)
    {
        dp[i][0] = 1LL;
    }

    // for (int j = 1; j <= (int)T.length(); j++)
    // {
    //     dp[0][j] = 0LL;
    // }

    for (int i = 1; i <= (int)S.length(); i++)
    {
        for (int j = 1; j <= (int)T.length(); j++)
        {
            if (S[i - 1] == T[j - 1])
            {
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD) % MOD;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }

    cout << dp[(int)S.length()][(int)T.length()] << endl;
    return 0;
}