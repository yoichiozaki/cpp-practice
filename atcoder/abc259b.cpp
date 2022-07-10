#include <bits/stdc++.h>

using namespace std;

int main() {
    double a,b,d;
    cin >> a >> b >> d;
    double r = hypot(a, b);
    double theta = atan2(b, a);
    theta += d * acos(-1.0) / 180.0;
    double x = cos(theta) * r;
    double y = sin(theta) * r;
    cout << setprecision(10) << x << ' ' << y << endl;
    return 0;
}