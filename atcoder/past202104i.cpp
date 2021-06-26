#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long H, W;
    cin >> H >> W;
    vector<vector<long long>> A(H);
    for (long long h = 0; h < H; h++)
    {
        vector<long long> row(W);
        for (long long w = 0; w < W; w++)
        {
            cin >> row[w];
        }
        A[h] = row;
    }
    long long K = H + W - 1;

    // dp[i][j][k] = 区画(i, j)までにk匹釣るときの美味しさの合計の最大値
    vector<vector<vector<long long>>> dp(H, vector<vector<long long>>(W, vector<long long>(K + 1)));

    for (long long h = 0; h < H; h++)
    {
        for (long long w = 0; w < W; w++)
        {
            if (h != 0)
            {
                for (long long k = 0; k <= K; k++)
                {
                    dp[h][w][k] = max(dp[h - 1][w][k], dp[h][w][k]);
                }
            }

            if (w != 0)
            {
                for (long long k = 0; k <= K; k++)
                {
                    dp[h][w][k] = max(dp[h][w][k], dp[h][w - 1][k]);
                }
            }

            for (long long k = K; k--;)
            {
                dp[h][w][k + 1] = max(dp[h][w][k + 1], dp[h][w][k] + A[h][w]);
            }
        }
    }

    for (long long k = 1; k <= K; k++)
        cout << dp.back().back()[k] << endl;
    return 0;
}