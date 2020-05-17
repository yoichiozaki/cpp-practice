#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x, h;
    cout << fixed << setprecision(12);
    while (cin >> x >> h)
    {
        if (x == 0 && h == 0)
            break;
        cout << x * x + sqrt(x * x * x * x + 4 * h * h * x * x) << endl;
    }
    return 0;
}