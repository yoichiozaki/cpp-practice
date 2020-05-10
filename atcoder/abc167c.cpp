#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n, 0);
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bool impossible = false;
    for (int i = 0; i < m; i++)
    {
        ll gain = 0LL;
        for (int j = 0; j < n; j++)
        {
            gain += a[j][i];
        }

        if (gain < x)
        {
            impossible = true;
            break;
        }
    }
    if (impossible)
    {
        cout << -1 << endl;
        return 0;
    }

    ll cmin = 1001001001;
    for (long long bit = 0; bit < (1 << n); bit++)
    {
        ll tmpsum = 0;
        vector<ll> learned(m, 0LL);
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                tmpsum += c[i];
                for (int j = 0; j < m; j++)
                {
                    learned[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < m; i++)
        {
            if (learned[i] < x)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;
        cmin = min(cmin, tmpsum);
    }
    cout << cmin << endl;
    return 0;
}