
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x, y;
    complex<double> a, b;

    cin >> n;
    cin >> x >> y;
    a = {x, y};
    cin >> x >> y;
    b = {x, y};

    auto m = (a + b) / 2.0;

    auto res = m + (a - m) * polar(1.0, M_PI * 2.0 / n);

    cout << setprecision(9) << res.real() << " " << res.imag() << endl;
}
