#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double ret = 0.0;
    for (int i = 1; i <= a; i++)
    {
        double tmp = 1.0 / a;
        int now = i;
        while (now < b)
        {
            now *= 2.0;
            tmp /= 2.0;
        }
        ret += tmp;
    }
    cout << fixed << setprecision(12) << ret << endl;
    return 0;
}