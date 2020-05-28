#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m, n)
    {
        vector<string> field(n);
        for (int i = 0; i < n; i++)
            cin >> field[i];

        vector<vector<int>> dp(n + 10, vector<int>(m + 10, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; 0 <= j; j--)
            {
                if (field[i][j] == '.')
                {
                    chmax(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int h = 0;
                int minw = dp[i][j];
                for (int k = i; k <= n; k++)
                {
                    h++;
                    chmin(minw, dp[k][j]);
                    chmax(res, h * minw);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}