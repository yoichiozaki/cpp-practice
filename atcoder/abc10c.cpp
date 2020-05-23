#include <bits/stdc++.h>
using namespace std;

int main()
{
    double txa, tya, txb, tyb, T, V;
    cin >> txa >> tya >> txb >> tyb >> T >> V;
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        double d1 = sqrt((x - txa) * (x - txa) + (y - tya) * (y - tya));
        double d2 = sqrt((x - txb) * (x - txb) + (y - tyb) * (y - tyb));
        if (d1 + d2 <= T * V)
            flag = true;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}