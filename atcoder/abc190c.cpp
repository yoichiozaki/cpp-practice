#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> conditions(M);
    for (int i = 0; i < M; i++)
    {
        cin >> conditions[i].first >> conditions[i].second;
    }

    int K;
    cin >> K;
    vector<pair<int, int>> choices(K);
    for (int i = 0; i < K; i++)
    {
        cin >> choices[i].first >> choices[i].second;
    }

    int ans = 0;
    for (int bits = 0; bits < 1 << K; bits++)
    {
        vector<bool> balls(N);
        for (int i = 0; i < K; i++)
        {
            int C = choices[i].first;
            int D = choices[i].second;
            balls[bits & 1 << i ? C : D] = true;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++)
        {
            int A = conditions[i].first;
            int B = conditions[i].second;
            if (balls[A] && balls[B])
                cnt++;
            if (ans < cnt)
                ans = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}