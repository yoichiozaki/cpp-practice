#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<double, double>> ranges(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        double l, r;
        cin >> l >> r;
        t -= 1;
        if (t & 1)
            r -= 0.5;
        if (t & 2)
            l += 0.5;
        ranges[i] = make_pair(l, r);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            ans += (max(ranges[i].first, ranges[j].first) <= min(ranges[i].second, ranges[j].second));
        }
    }
    cout << ans << endl;
    return 0;
}