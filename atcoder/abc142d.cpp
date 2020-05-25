#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// AとBの正の公約数からいくつか選んだときに得られる集合について，
// その集合に含まれる合成数をその数の素因数の一つに置き換えて得られる集合も
// またAとBの正の公約数からいくつか選んだときに得られる集合となるので，
// 最大サイズを考えるに当たっては，1と素数のみからなる集合を考えれば良い

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

vector<pair<ll, int>> factorize(ll n)
{
    vector<pair<ll, int>> res;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i)
            continue;
        res.emplace_back(i, 0);
        while (n % i == 0)
        {
            n /= i;
            res.back().second++;
        }
    }
    if (n != 1)
        res.emplace_back(n, 1);
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    auto f = factorize(g);
    int ans = f.size() + 1;
    cout << ans << endl;
    return 0;
}
