#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 働ける日数に上限がないので来た仕事をできるだけ多く処理すればよいので
    // 締切の早いものからこなしていく
    int N;
    cin >> N;
    vector<tuple<long long, long long, long long>> tasks;
    for (int i = 1; i <= N; i++)
    {
        long long d, c, s;
        cin >> d >> c >> s;
        tasks.push_back(make_tuple(d, c, s));
    }
    sort(tasks.begin(), tasks.end());

    vector<long long> D(N + 1), C(N + 1), S(N + 1);
    for (int i = 1; i <= N; i++)
    {
        D[i] = get<0>(tasks[i - 1]);
        C[i] = get<1>(tasks[i - 1]);
        S[i] = get<2>(tasks[i - 1]);
    }

    vector<vector<long long>> dp(5001, vector<long long>(5001, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 5000; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + C[i + 1] <= D[i + 1])
                dp[i + 1][j + C[i + 1]] = max(dp[i + 1][j + C[i + 1]], dp[i][j] + S[i + 1]);
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 5000; i++)
        ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}