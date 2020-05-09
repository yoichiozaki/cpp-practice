#include <bits/stdc++.h>
using namespace std;

// 長方形の中心を通るか通らないか

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << fixed << setprecision(10) << double(a) * double(b) / 2.0 << " " << (x + x == a && y + y == b ? 1 : 0) << endl;
    return 0;
}