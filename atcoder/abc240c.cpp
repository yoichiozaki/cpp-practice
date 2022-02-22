#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];
    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= X; j++)
        {
            if (dp[i][j])
            {
                if (j + A[i] <= X)
                {
                    dp[i + 1][j + A[i]] = true;
                }
                if (j + B[i] <= X)
                {
                    dp[i + 1][j + B[i]] = true;
                }
            }
        }
    }
    if (dp[N][X])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}