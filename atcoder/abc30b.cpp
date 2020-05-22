#include <bits/stdc++.h>
using namespace std;

int main()
{
    double N, M;
    cin >> N >> M;
    double X = N;
    if (N >= 12)
    {
        X = N - 12;
    }
    double Y = X * 30 + M / 2;
    double Z = M * 6;
    cout << fixed << setprecision(10) << min(360 - (max(Z, Y) - min(Z, Y)), max(Z, Y) - min(Z, Y)) << endl;
}
