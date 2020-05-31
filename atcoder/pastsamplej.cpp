#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), bit(M);
    for (int i = 0; i < M; i++)
    {
        int b;
        cin >> a[i] >> b;
        for (int j = 0; j < b; j++)
        {
            int c;
            cin >> c;
            bit[i] |= 1 << (c - 1);
        }
    }

    // dp[ビット列] = そのビット列に相当する宝物群を得るときの最小コスト
    vector<int> dp(1 << N, INF);
    dp[0] = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        if (dp[i] == INF)
            continue;
        for (int j = 0; j < M; j++)
        {
            dp[i | bit[j]] = min(dp[i | bit[j]], dp[i] + a[j]);
        }
    }

    int res = dp[(1 << N) - 1]; // dp[111...111];

    if (res == INF)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}
