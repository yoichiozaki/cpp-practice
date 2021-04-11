#include <bits/stdc++.h>
using namespace std;

int main()
{
    double R, X, Y;
    cin >> R >> X >> Y;
    double d = sqrt(X * X + Y * Y);
    if (d == R)
    {
        cout << 1 << endl;
    }
    else if (d <= R + R)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << ceil(d / R) << endl;
    }
    return 0;
}