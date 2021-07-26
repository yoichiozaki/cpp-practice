#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long x = 2 * b - a - c;
    long long k = (0 <= x ? 0 : (1 - x) / 2);
    long long ans = x + 3 * k;
    cout << ans << endl;
    return 0;
}