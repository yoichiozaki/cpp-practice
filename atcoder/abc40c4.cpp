#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> a(N + 1, 0LL);
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    vector<long long> dp(N + 1, 1001001001);
    dp[1] = 0LL;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        if (3 <= i)
            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[N] << endl;
    return 0;
}