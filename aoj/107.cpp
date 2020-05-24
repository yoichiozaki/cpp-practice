#include <bits/stdc++.h>
using namespace std;

int main()
{
    double d, w, h;
    while (cin >> d >> w >> h, d || w || h)
    {
        double dist1 = (sqrt(d * d + w * w)) / 2.0;
        double dist2 = (sqrt(w * w + h * h)) / 2.0;
        double dist3 = (sqrt(d * d + h * h)) / 2.0;
        double min_dist = min(dist1, min(dist2, dist3));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            double r;
            cin >> r;
            if (min_dist < r)
                cout << "OK" << endl;
            else
                cout << "NA" << endl;
        }
    }

    return 0;
}