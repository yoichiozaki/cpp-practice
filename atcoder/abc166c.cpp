#include <bits/stdc++.h>
using namespace std;

// 隣接する頂点から最も標高の高いものを記録しておく

#define N 100010

int main()
{
    int n, m, h[N], view[N];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        view[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        view[a] = max(view[a], h[b]);
        view[b] = max(view[b], h[a]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (view[i] < h[i] ? 1 : 0);
    }
    cout << ans << endl;
    return 0;
}