#include <bits/stdc++.h>
using namespace std;

int main()
{
    const double PI = acos(-1.0);
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;
    auto f = [&](double t) {
        if (tan(t) <= b / a)
            return a * b - a * (a * tan(t)) / 2;
        else
            return b * (b / tan(t)) / 2;
    };
    double left = 0, right = PI / 2;
    for (int iter = 0; iter < 100; ++iter)
    {
        double theta = (left + right) / 2;
        if (f(theta) >= x)
            left = theta;
        else
            right = theta;
    }
    cout << fixed << setprecision(10) << left * 180 / PI << endl;
}