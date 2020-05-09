#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    long long ans = b - b / c - b / d + b / (c * d / gcd(c, d));
    ans -= a - a / c - a / d + a / (c * d / gcd(c, d));
    cout << ans << endl;
}