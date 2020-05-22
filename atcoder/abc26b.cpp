#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double ans = 0.0;
    vector<double> r(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> r[i];
    sort(r.begin(), r.end());
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
            ans -= M_PI * r[i] * r[i];
        else
            ans += M_PI * r[i] * r[i];
    }
    cout << fixed << setprecision(12) << abs(ans) << endl;
    return 0;
}
