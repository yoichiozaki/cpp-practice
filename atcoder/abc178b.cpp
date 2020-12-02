#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= 0 && b <= 0)
    {
        if (c <= 0 && d <= 0)
        {
            cout << a * c << endl;
            return 0;
        }
        else if (c <= 0 && 0 < d)
        {
            cout << a * c << endl;
            return 0;
        }
        else
        {
            cout << b * c << endl;
            return 0;
        }
    }
    else if (a <= 0 && 0 < b)
    {
        if (c <= 0 && d <= 0)
        {
            cout << a * c << endl;
            return 0;
        }
        else if (c <= 0 && 0 < d)
        {
            cout << max(a * c, b * d) << endl;
            return 0;
        }
        else
        {
            cout << b * d << endl;
            return 0;
        }
    }
    else if (0 <= a && 0 <= b)
    {
        if (c <= 0 && d <= 0)
        {
            cout << a * d << endl;
            return 0;
        }
        else if (c <= 0 && 0 < d)
        {
            cout << b * d << endl;
            return 0;
        }
        else
        {
            cout << b * d << endl;
            return 0;
        }
    }
    return 0;
}