#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 20;

int main()
{
    int W;
    int C = 0;
    while (cin >> W)
    {
        if (W == 0)
            break;

        C++;
        int N;
        cin >> N;
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; i++)
        {
            int v, w;
            char comma;
            cin >> v >> comma >> w;
            items[i] = make_pair(v, w);
        }

        // dp[i][j]: 0-(i-1)番目までの商品から重さがjを超えないように選ぶときの価値の最大値
        int dp[1005][1005] = {{}};

        // dpテーブルの初期化
        fill(dp[0], dp[1004], -INF);

        dp[0][0] = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (dp[i][j] == -INF)
                    continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + items[i].second <= W)
                    dp[i + 1][j + items[i].second] = max(dp[i + 1][j], dp[i][j] + items[i].first);
            }
        }

        pair<int, int> ans = make_pair(0, 0);

        for (int i = 0; i <= W; i++)
        {
            if (ans.first < dp[N][i])
            {
                ans.first = dp[N][i];
                ans.second = i;
            }
        }
        cout << "Case " << C << ":" << endl;
        cout << ans.first << endl;
        cout << ans.second << endl;
    }
    return 0;
}