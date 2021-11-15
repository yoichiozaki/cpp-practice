#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 桁DP
    // dp[上から数えた決定済み桁数][Bで割ったあまり] = 個数
    // for c in C:
    //     dp[i + 1][(10 * j + c) % B] += dp[i][j]

    long long MOD = 1000000007;
    long long N, B, K;
    cin >> N >> B >> K;
    vector<long long> C(K);
    for (int i = 0; i < K; i++)
        cin >> C[i];

    vector<vector<long long>> dp(N + 5, vector<long long>(B + 5, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < B; j++)
        {
            for (auto c : C)
            {
                int next_remain = (j * 10 + c) % B;
                dp[i + 1][next_remain] += dp[i][j];
                dp[i + 1][next_remain] %= MOD;
            }
        }
    }

    cout << dp[N][0] << endl;

    return 0;
}