#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll a, b, c, n;
    while (cin >> a >> b >> n)
    {
        a %= b;
        ll o = 0LL;
        for (int i = 0; i < n; i++)
        {
            a *= 10;
            o += a / b;
            a %= b;
            if (a == 0)
                break;
        }
        cout << o << endl;
    }
    return 0;
}