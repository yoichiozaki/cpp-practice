#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
long long dp[MAX + 1][MAX + 1];

string find_kth_string(int A, int B, long long K)
{
    if (A == 0)
        return string(B, 'b');
    if (B == 0)
        return string(A, 'a');
    if (K <= dp[A - 1][B])
        return string("a") + find_kth_string(A - 1, B, K);
    else
        return string("b") + find_kth_string(A, B - 1, K - dp[A - 1][B]);
}

int main()
{
    int A, B;
    cin >> A >> B;
    long long K;
    cin >> K;
    dp[0][0] = 1;
    for (int i = 0; i <= A; ++i)
    {
        for (int j = 0; j <= B; ++j)
        {
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << find_kth_string(A, B, K) << endl;
    return 0;
}