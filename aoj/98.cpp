#include <bits/stdc++.h>
using namespace std;

// (1, 1) - (x, y)の部分行列の総和を事前計算しておくことで任意の部分行列の総和をO(1)で計算できる

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> S(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a;
        }
    }
    int ans = -10010010;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                for (int l = 1; l <= j; l++)
                {
                    ans = max(ans, S[i][j] - S[i][l - 1] - S[k - 1][j] + S[k - 1][l - 1]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}