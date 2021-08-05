#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    vector<vector<vector<long double>>> dp(N, vector<vector<long double>>(sum + 1, vector<long double>(sum + 1, 1000000)));

    dp[0][0][0] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            for (int k = 0; k < sum + 1; k++)
            {
                if (dp[i][j][k] == 1000000)
                {
                    continue;
                }
                for (int l = 0; l + j <= sum; l++)
                {
                    dp[i + 1][j + l][l] = min(dp[i + 1][j + l][l], sqrt(1 + (k - l) * (k - l)) + dp[i][j][k]);
                }
            }
        }
    }
    cout << setprecision(18) << dp[N - 1][sum][0] << endl;
    return 0;
}