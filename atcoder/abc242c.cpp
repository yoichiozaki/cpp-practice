#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int DP[1048576][10] = {0};

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= 9; i++)
        DP[1][i] = 1;
    for (int d = 2; d <= N; d++)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = max(1, i - 1); j <= min(9, i + 1); j++)
            {
                DP[d][j] += DP[d - 1][i];
                DP[d][j] %= MOD;
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= 9; i++)
    {
        ret += DP[N][i];
        ret %= MOD;
    }
    cout << ret << endl;
    return 0;
}