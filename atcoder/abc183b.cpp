#include <bits/stdc++.h>
using namespace std;

int main()
{
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    cout << fixed << setprecision(15);
    cout << (sx * gy + gx * sy) / (gy + sy) << endl;
    return 0;
}