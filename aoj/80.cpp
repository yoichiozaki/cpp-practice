#include <bits/stdc++.h>
using namespace std;

int main()
{
    double q;
    while (cin >> q)
    {
        if (q == -1.0)
            break;
        double x = q / 2.0;
        while (0.00001 * q <= abs(x * x * x - q))
        {
            x = x - (x * x * x - q) / (3.0 * x * x);
        }
        cout << fixed << setprecision(12) << x << endl;
    }
    return 0;
}