#include <bits/stdc++.h>
using namespace std;

// dp[i][j]: (i, j)を右下隅とする正方形の最大サイズ

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<string> field(n);
        for (int i = 0; i < n; i++)
            field[i];
        int dp[n][n], ans = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = field[0][i] == '*' ? 0 : 1;
            dp[i][0] = field[i][0] == '*' ? 0 : 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (field[i][j] == '*')
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}