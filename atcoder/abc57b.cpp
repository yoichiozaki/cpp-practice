#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pos(N);
    vector<pair<ll, ll>> checks(M);
    for (int i = 0; i < N; i++)
        cin >> pos[i].first >> pos[i].second;
    for (int i = 0; i < M; i++)
        cin >> checks[i].first >> checks[i].second;
    vector<int> ans(N);
    for (int i = 0; i < N; i++)
    {
        ll tmp = 1001001001LL;
        for (int j = 0; j < M; j++)
        {
            ll n = abs(pos[i].first - checks[j].first) + abs(pos[i].second - checks[j].second);
            if (n < tmp)
            {
                tmp = n;
                ans[i] = j;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] + 1 << endl;
    return 0;
}