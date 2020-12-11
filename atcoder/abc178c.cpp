#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1000000007;

// x^y mod m
ll powermod(ll x, ll y)
{
    ll ret = 1LL;

    for (ll i = 0LL; i < y; i++)
    {
        ret = ret * x % mod;
    }

    return ret;
}

int main()
{
    ll N;
    cin >> N;
    ll ans = powermod(10LL, N) - powermod(9LL, N) - powermod(9LL, N) + powermod(8LL, N);
    ans %= mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}