#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    for (int i = 0; i < N; i++)
        cin >> t[i];
    ll ans = 0LL;
    for (int i = 0; i < N - 1; i++)
    {
        ans += min(T, t[i + 1] - t[i]);
    }
    cout << ans + T << endl;
    return 0;
}