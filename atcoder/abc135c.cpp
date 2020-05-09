#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans;
    vector<long long> a(n + 1), b(n);
    for (int i = 0; i < n + 1; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        long long c = min(a[i], b[i]);
        b[i] -= c;
        a[i] -= c;
        ans += c;
        c = min(a[i + 1], b[i]);
        b[i] -= c;
        a[i + 1] -= c;
        ans += c;
    }
    cout << ans << endl;
    return 0;
}