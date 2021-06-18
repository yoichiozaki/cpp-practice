#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    long long x, y;
    vector<pair<long long, long long>> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (k < a[i].first)
            break;
        k += a[i].second;
    }
    cout << k << endl;
    return 0;
}