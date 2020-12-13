#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int y_ = min(y, x + x);
    a *= 2;
    b = 2 * b + 1;
    int d = abs(a - b);
    cout << d / 2 * y_ + d % 2 * x << endl;
    return 0;
}