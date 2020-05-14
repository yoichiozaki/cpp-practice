#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int N, X;
    cin >> N >> X;
    vector<ll> x(N, 0);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    vector<ll> diff(N, 0);
    for (int i = 0; i < N; i++)
    {
        diff[i] = abs(X - x[i]);
    }
    ll ans = diff[0];
    for (int i = 0; i < N; i++)
    {
        ans = gcd(ans, diff[i]);
    }
    cout << ans << endl;
    return 0;
}