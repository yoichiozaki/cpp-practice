#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    vector<bool> dp(101010, false);
    int X;
    cin >> X;
    dp[0] = true;
    for (int x = 0; x < X; x++)
    {
        if (dp[x])
        {
            for (int d = 100; d < 106; d++)
            {
                dp[x + d] = true;
            }
        }
    }
    if (dp[X])
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}