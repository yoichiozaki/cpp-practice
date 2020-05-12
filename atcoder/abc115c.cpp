#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 1001001001LL;
    for (int i = 0; i < N - K + 1; i++)
    {
        ans = min(h[i + K - 1] - h[i], ans);
    }
    cout << ans << endl;
    return 0;
}