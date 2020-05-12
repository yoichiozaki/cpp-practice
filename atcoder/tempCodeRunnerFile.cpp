#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] <= now)
            now = h[i];
        else
        {
            ans += h[i] -= now;
            now = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
