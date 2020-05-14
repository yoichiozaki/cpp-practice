#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int ans = 0;
        int f = 5;
        while (f <= n)
        {
            ans += n / f;
            f *= 5;
        }
        cout << ans << endl;
    }
    return 0;
}