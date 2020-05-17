#include <bits/stdc++.h>
using namespace std;

int ans[11][330], n, a, c;
bool b[10];
void dfs(int d, int x)
{
    if (d == n)
        ans[n][x]++;
    else
    {
        for (int i = 0; i < 10; i++)
            if (!b[i])
            {
                b[i] = 1;
                dfs(d + 1, x + (d + 1) * i);
                b[i] = 0;
            }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        n = i + 1, dfs(0, 0);
    while (cin >> a >> c)
        if (c < 331)
            cout << ans[a][c] << endl;
        else
            cout << 0 << endl;
    return 0;
}