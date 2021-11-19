#include <bits/stdc++.h>

using namespace std;

string S;
long long mod = 1000000007;
long long dp[100009][8]; // dp[i][j] = Sのi文字目までで"atcoder"のj文字目まで実現する場合の数

int main()
{
    int N;
    cin >> N;
    cin >> S;

    dp[0][0] = 1;
    for (int i = 0; i < (int)S.size(); i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (S[i] == 'a' && j == 0)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 't' && j == 1)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'c' && j == 2)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'o' && j == 3)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'd' && j == 4)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'e' && j == 5)
                dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'r' && j == 6)
                dp[i + 1][j + 1] += dp[i][j];
        }
        for (int j = 0; j <= 7; j++)
            dp[i + 1][j] %= mod;
    }

    cout << dp[S.size()][7] << endl;

    return 0;
}