#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    ll now = 0;
    vector<pair<ll, ll>> p(N);
    for (ll i = 0; i < N; i++)
    {
        ll A, B;
        cin >> A >> B;
        p[i] = make_pair(A, B);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < N; i++)
    {
        now += p[i].second;
        ans += p[i].first * p[i].second;
        if (M < now)
        {
            ans -= (now - M) * p[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}