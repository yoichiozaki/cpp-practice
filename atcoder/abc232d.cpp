#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> field(N);
    for (int i = 0; i < N; i++)
        cin >> field[i];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = N - 1; 0 <= i; i--)
    {
        for (int j = M - 1; 0 <= j; j--)
        {
            if (field[i][j] == '#')
                continue;
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + 1;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}