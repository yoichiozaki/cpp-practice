#include <bits/stdc++.h>

using namespace std;

int main()
{
    long double T;
    cin >> T;
    long double L, X, Y;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    cout << setprecision(12) << endl;
    for (int i = 0; i < Q; i++)
    {
        long double E;
        cin >> E;
        long double cx = 0;
        long double cy = -(L / 2.0) * sin(E / T * 2 * M_PI);
        long double cz = (L / 2.0) - (L / 2.0) * cos(E / T * 2.0 * M_PI);
        long double d1 = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));
        long double d2 = cz;
        cout << atan2(d2, d1) * 180.0 / M_PI << endl;
    }
    return 0;
}