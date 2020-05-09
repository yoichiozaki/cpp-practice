#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<float> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    float ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans == 0)
            ans += v[i];
        else
            ans = (ans + v[i]) / 2.0;
    }
    cout << ans << endl;

    return 0;
}