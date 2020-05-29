#include <iostream>
#include <vector>
using namespace std;

// DPテーブル
const int MAX_N = 15;
const int MAX_W = 110000;
int dp[MAX_N][MAX_W]; // 12 種類だが余裕をもつ

int main()
{
    int W;
    cin >> W;

    // 品物を列挙 (価値はすべて 1)
    vector<int> weight;
    for (int i = 1; i <= W; i *= 6)
        weight.push_back(i);
    for (int i = 9; i <= W; i *= 9)
        weight.push_back(i); // 1 が重複しないように (しても問題はない)
    int n = (int)weight.size();

    // DP初期条件: dp[i][0] = 0
    for (int i = 0; i < MAX_N; ++i)
        for (int w = 0; w < MAX_W; ++w)
            dp[i][w] = 1 << 29; // INF
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    // DPループ
    for (int i = 0; i < n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            dp[i + 1][w] = min(dp[i + 1][w], dp[i][w]);
            if (w >= weight[i])
                dp[i + 1][w] = min(dp[i + 1][w], dp[i + 1][w - weight[i]] + 1);
        }
    }

    cout << dp[n][W] << endl;
}