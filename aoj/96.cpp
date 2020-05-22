#include <bits/stdc++.h>
using namespace std;

// ナイーブにするとだめなので半分全探索パターン

int main()
{
    int n;
    int a[2010];
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            a[i + j]++;
        }
    }
    while (cin >> n)
    {
        int ans = 0;
        for (int i = 0; i <= 2000; i++)
        {
            if (0 <= n - i && n - i <= 2000)
                ans += a[i] * a[n - i];
        }
        cout << ans << endl;
    }
    return 0;
}