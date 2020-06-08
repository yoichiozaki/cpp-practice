#include <bits/stdc++.h>
using namespace std;

// dpする
// dp[i]: 座標iに接地した状態で到達したときにかかる時間の最小値

const int INF = 1001001001;

int main()
{
    int N, L;
    cin >> N >> L;
    set<int> st;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    int T1, T2, T3;
    cin >> T1 >> T2 >> T3;
    T1 *= 10, T2 *= 10, T3 *= 10;
    vector<int> dp(L + 100, INF);
    dp[0] = 0;
    for (int i = 0; i < L + 50; i++)
    {
        if (st.count(i) == 0)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + T1);
            dp[i + 2] = min(dp[i + 2], dp[i] + T1 + T2);
            dp[i + 4] = min(dp[i + 4], dp[i] + T1 + 3 * T2);
        }
        else
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + T1 + T3);
            dp[i + 2] = min(dp[i + 2], dp[i] + T1 + T2 + T3);
            dp[i + 4] = min(dp[i + 4], dp[i] + T1 + 3 * T2 + T3);
        }
    }
    cout << dp[L] / 10 << endl;
    return 0;
}