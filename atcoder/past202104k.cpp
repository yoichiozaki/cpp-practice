#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3fffffff;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(100, -INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int P, U;
        cin >> P >> U;
        U += P / 100 * 20 - P;
        P %= 100;
        auto dp2 = dp;
        for (int i = P; i < 100; i++)
        {
            dp[i] = max(dp[i], dp2[i - P] + U);
        }
        for (int i = 0; i < P; i++)
        {
            dp[i] = max(dp[i], dp2[i - P + 100] + U + 20);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}