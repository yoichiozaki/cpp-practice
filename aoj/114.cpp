#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// シミュレーションするとTLE
// 各座標軸に対して独立に考えて最小公倍数

ll gcd(ll x, ll y)
{
    if (x < y)
        swap(x, y);
    ll z = x % y;
    while (z)
    {
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}
ll lcm(ll x, ll y)
{
    ll g = gcd(x, y);
    return x / g * y;
}
ll lcm(ll x, ll y, ll z)
{
    ll l1 = lcm(x, y), l2 = lcm(x, z);
    return lcm(l1, l2);
}
int main()
{
    ll a[3], m[3];
    while (cin >> a[0] >> m[0] >> a[1] >> m[1] >> a[2] >> m[2],
           a[0] || m[0] || a[1] || m[1] || a[2] || m[2])
    {
        ll c[3] = {};
        ll x[3];
        for (ll i = 0; i < 3; i++)
        {
            c[i] = 1;
            x[i] = a[i] % m[i];
            while (x[i] != 1)
            {
                x[i] = (a[i] * x[i]) % m[i];
                c[i]++;
            }
        }
        cout << lcm(c[0], c[1], c[2]) << endl;
    }
    return 0;
}