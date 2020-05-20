#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a < b)
    {
        ans += c / a;
        ans += (c % a) / b;
    }
    else
    {
        ans += c / b;
        ans += (c % b) / a;
    }
    cout << ans << endl;
    return 0;
}