#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    long long ans = 0;
    if (k <= a)
    {
        cout << k << endl;
        return 0;
    }
    else
    {
        k -= a;
        ans += a;
        if (k <= b)
        {
            cout << ans << endl;
            return 0;
        }
        else
        {
            ans -= (k - b);
            cout << ans << endl;
        }
    }
    return 0;
}