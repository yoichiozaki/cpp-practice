#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, X;
    cin >> n >> X;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (X & (1 << i))
            ans += a;
    }
    cout << ans << endl;
    return 0;
}