#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N;
    double D, H, ans = 0;
    cin >> N >> D >> H;
    while (N--)
    {
        double d, h;
        cin >> d >> h;
        if (ans < (h - d * (H - h) / (D - d)))
        {
            ans = (h - d * (H - h) / (D - d));
        }
    }
    cout << ans << endl;
    return 0;
}