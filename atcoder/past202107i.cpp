#include <bits/stdc++.h>

using namespace std;

int main()
{
    // こめかみが原点
    int N;
    cin >> N;
    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long double dx = (x1 + x2) / 2.0;
    long double dy = (y1 + y2) / 2.0;
    x2 -= dx;
    y2 -= dy;
    long double E = sqrt(x2 * x2 + y2 * y2);
    long double cos = x2 / E;
    long double sin = -y2 / E;
    cout << setprecision(12);
    for (int i = 0; i < N; i++)
    {
        long double x, y;
        cin >> x >> y;
        x -= dx;
        y -= dy;
        cout << x * cos - y * sin << " " << x * sin + y * cos << endl;
    }
    return 0;
}