#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double d1 = 0, d2 = 0, d3 = -1;
    for (int i = 0; i < N; i++)
    {
        double x;
        cin >> x;
        d1 += abs(x);
        d2 += x * x;
        d3 = max(d3, abs(x));
    }
    cout << fixed << setprecision(15)
         << d1 << endl
         << sqrt(d2) << endl
         << d3 << endl;
    return 0;
}