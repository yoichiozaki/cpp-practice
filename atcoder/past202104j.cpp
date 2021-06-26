#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    double C;
    cin >> N >> C;
    vector<pair<int, int>> P(N);
    double p;
    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        P[i] = make_pair(X, Y);
        p += X;
    }
    p /= N;
    double ans = 0.0;
    for (int i = 0; i < N; i++)
    {
        ans += (P[i].first - p) * (P[i].first - p);
        ans += (P[i].second - C) * (P[i].second - C);
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}