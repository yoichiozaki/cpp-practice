#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1001001;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            ans = min(abs(i - j) + (n - (i * j)), ans);
        }
    }
    cout << ans << endl;
    return 0;
}