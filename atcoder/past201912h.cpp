#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;

int main()
{
    int N;
    cin >> N;
    vector<int> C(N, 0);
    for (int i = 0; i < N; i++)
        cin >> C[i];
    int Q;
    cin >> Q;

    int sold_sofar[2] = {0, 0};
    int minimum[2] = {inf, inf};
    int cnt[2];
    cnt[1] = N / 2;
    cnt[0] = N - cnt[1];

    for (int i = 0; i < N; i++)
        minimum[i % 2] = min(minimum[i % 2], C[i]);

    long long ans = 0;
    for (int _ = 0; _ < Q; _++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, a;
            cin >> x >> a;
            x -= 1;
            if (a <= C[x] - sold_sofar[x % 2])
            {
                ans += a;
                C[x] -= a;
                minimum[x % 2] = min(minimum[x % 2], C[x]);
            }
        }
        else if (t == 2)
        {
            int a;
            cin >> a;
            if (a <= minimum[0] - sold_sofar[0])
            {
                ans += 1LL * a * cnt[0];
                sold_sofar[0] += a;
            }
        }
        else
        {
            int a;
            cin >> a;
            if (a <= minimum[0] - sold_sofar[0] && a <= minimum[1] - sold_sofar[1])
            {
                ans += 1LL * a * N;
                sold_sofar[0] += a;
                sold_sofar[1] += a;
            }
        }
    }

    cout << ans << endl;
    return 0;
}