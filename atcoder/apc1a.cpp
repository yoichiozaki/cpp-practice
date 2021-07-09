#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    if (x % y == 0)
        cout << -1 << endl;
    else
        cout << x * (y - 1) << endl;
    return 0;
}