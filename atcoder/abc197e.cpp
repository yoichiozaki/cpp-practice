#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> X(N); // X[color] = [x0, x1, ...]
    for (int i = 0; i < N; i++)
    {
        int x, c;
        cin >> x >> c;
        X[c - 1].push_back(x);
    }

    // dp[i][j]: 色iのぼーるについて，回収前左端にいる（j = 0）もしくは右端にいる（j = 1）とき，
    // 全てのボールを回収し終わるまでに必要な最小の時間
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));

    int end_at_left = 0;
    int end_at_right = 0;

    // 色iごとに計算
    for (int i = 0; i < N; i++)
    {
        // 色iは置いてないので即座に次の状態へ遷移
        if (X[i].empty())
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            continue;
        }
        sort(X[i].begin(), X[i].end());
        int left = X[i].front(); // 色iのボールのうち左端の座標
        int right = X[i].back(); // 色iのボールのうち右端の座標

        // 色i+1のボールの回収を左端で終わるシナリオ
        dp[i + 1][0] = min(
            // 色iのボールの回収を左端で終わって，色i+1のボールの最右端まで移動し，回収しながら左端で終わる
            dp[i][0] + abs(right - end_at_left) + abs(left - right),
            // 色iのボールの回収を右端で終わって，色i+1のボールの最右端まで移動し，回収しながら左端で終わる
            dp[i][1] + abs(right - end_at_right) + abs(left - right));

        // 色i+1のボールの回収を右端で終わるシナリオ
        dp[i + 1][1] = min(
            // 色iのボールの回収を左端で終わって，色i+1のボールの最左端まで移動し，回収しながら右端で終わる
            dp[i][0] + abs(left - end_at_left) + abs(right - left),
            // 色iのボールの回収を右端で終わって，色i+1のボールの最左端まで移動し，回収しながら右端で終わる
            dp[i][1] + abs(left - end_at_right) + abs(right - left));

        end_at_left = left;
        end_at_right = right;
    }

    // 左端で回収し終わってから原点に戻るシナリオと右端で終わってから原点に戻るシナリオを比較
    cout << min(dp[N][0] + abs(end_at_left), dp[N][1] + abs(end_at_right)) << endl;
    return 0;
}