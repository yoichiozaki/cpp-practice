#include <bits/stdc++.h>

using namespace std;

// 区間DP
// dp[left][right] := 区間[left, right]の人が全員抜けるのにかかる最小コスト

int main()
{
    int N;
    cin >> N;
    int A[1 << 18];
    for (int i = 1; i <= 2 * N; i++)
    {
        cin >> A[i];
    }

    int dp[500][500];
    for (int i = 1; i <= 2 * N; i++)
    {
        for (int j = 1; j <= 2 * N; j++)
        {
            dp[i][j] = (1 << 29);
            if (i < 2 * N)
                dp[i][i + 1] = abs(A[i] - A[i + 1]);
        }
    }

    for (int i = 3; i <= 2 * N; i += 2)
    {
        for (int j = 1; j <= 2 * N - i; j++)
        {
            int left = j;
            int right = j + i;
            for (int k = left; k <= right - 1; k++)
                dp[left][right] = min(dp[left][right], dp[left][k] + dp[k + 1][right]);
            dp[left][right] = min(dp[left][right], dp[left + 1][right - 1] + abs(A[left] - A[right]));
        }
    }

    cout << dp[1][2 * N] << endl;
    return 0;
}