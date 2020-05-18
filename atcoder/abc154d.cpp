#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<double> p(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];
    vector<double> E(N);
    double ans = 0.0;
    for (int i = 0; i < N; i++)
    {
        E[i] = (p[i] + 1.0) / 2.0;
        if (i < K)
            ans += E[i];
    }
    double e = ans;
    for (int i = 0; i < N - K; i++)
    {
        e = e + E[i + K] - E[i];
        ans = max(ans, e);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}