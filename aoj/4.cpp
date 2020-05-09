#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c, d, e, f;
    cout << fixed << setprecision(3);
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        double k = 1.0 / (a * e - b * d);
        double x = k * (c * e - b * f);
        double y = k * (a * f - d * c);
        if (x == 0)
            x = 0;
        if (y == 0)
            y = 0;
        cout << x << " " << y << endl;
    }
    return 0;
}