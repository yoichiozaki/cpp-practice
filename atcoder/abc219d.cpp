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
    //       - dp[i][min(j + Ai, X)][min(k + Bi, Y)] <- min(dp[i][min(j + Ai, X)][min(k + Bi, Y)], dp[i - 1][j][k] + 1)
    //       - dp[i][j][k] <- min(dp[i][j][k], dp[i - 1][j][k])

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

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= X; j++)
        {
            for (int k = 0; k <= Y; k++)
            {
                dp[i][min(j + bento[i].first, X)][min(k + bento[i].second, Y)] = min(dp[i][min(j + bento[i].first, X)][min(k + bento[i].second, Y)], dp[i - 1][j][k] + 1);
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }

    if (dp[N][X][Y] == INF)
        cout << -1 << endl;
    else
        cout << dp[N][X][Y] << endl;
    return 0;
}