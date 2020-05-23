#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int f = a[i];
        while (!(f % 2 != 0 && f % 3 != 2))
            f--, ans++;
    }
    cout << ans << endl;
    return 0;
}