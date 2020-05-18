#include <bits/stdc++.h>
using namespace std;

int main()
{
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    double elapsed = 60.0 * H + M;
    double argH = 0.5 * elapsed;
    double argM = 6.0 * elapsed;
    double theta = abs(argH - argM);
    cout << fixed << setprecision(12) << sqrt(A * A + B * B - 2.0 * A * B * cos(M_PI * theta / 180.0)) << endl;
    return 0;
}