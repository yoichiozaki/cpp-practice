#include <bits/stdc++.h>

using namespace std;

int main()
{
    // i = 0, 1, ..., N
    // j = 0, 1, ..., X
    // k = 0, 1, ..., Y
    // dp[i][j][k]: 1, 2, ..., i番目の弁当を使ってたこ焼きj個以上たい焼きk個以上を用意するのに必要な弁当の個数の最小値
    //   - i = 0
    //       - dp[0][0][0] = 0, それ以外は状態としてありえない
    //   - i = 1, 2, ..., N
    //       - dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
    //       - dp[i + 1][min(Ai + j, X)][min(Bi + k, Y)] = min(dp[i + 1][min(Ai + j, X)][min(Bi + k, Y)], dp[i][j][k] + 1);

    const int INF = INT_MAX / 2;
    int N;
    cin >> N;
    int X, Y;
    cin >> X >> Y;
    vector<pair<int, int>> bento(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        bento[i] = make_pair(a, b);
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(X + 1, vector<int>(Y + 1, INF)));

    dp[0][0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= X; j++)
        {
            for (int k = 0; k <= Y; k++)
            {
                if (dp[i][j][k] < INF)
                {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                    dp[i + 1][min(bento[i].first + j, X)][min(bento[i].second + k, Y)] = min(dp[i + 1][min(bento[i].first + j, X)][min(bento[i].second + k, Y)], dp[i][j][k] + 1);
                }
            }
        }
    }

    if (dp[N][X][Y] == INF)
        cout << -1 << endl;
    else
        cout << dp[N][X][Y] << endl;
    return 0;
}