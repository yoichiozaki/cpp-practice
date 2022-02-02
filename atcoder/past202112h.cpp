#include <bits/stdc++.h>

using namespace std;

// dp[i][j]: S[0:i+1], T[0:j+1]に対する最長非共通部分列の長さ
// S[i+1]，T[j+1]が最長非共通部分列に含まれるのか否かで遷移できる状態が変わる

int main()
{
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i != N)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j != M)
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            if (i != N && j != M && S[i] != T[j])
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}