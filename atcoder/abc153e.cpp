#include <bits/stdc++.h>
using namespace std;

// dp[i]: モンスターの体力をi減らすために消耗する魔力の最小値

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> dp(h + 1, 1001001001);
    dp[0] = 0; // モンスターの体力を0減らすために消耗する魔力の最小値は0
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b; // 魔力をb消耗してモンスターの体力をa減らせる
        for (int j = 0; j < h; j++)
        {
            int nj = min(j + a, h);
            dp[nj] = min(dp[nj], dp[j] + b);
        }
    }
    cout << dp[h] << endl;
    return 0;
}