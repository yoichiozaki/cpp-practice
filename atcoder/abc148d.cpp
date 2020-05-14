#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int next = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (next == a[i])
            next++;
        else
            ans++;
    }
    if (ans == n)
        ans = -1;
    cout << ans << endl;
    return 0;
}