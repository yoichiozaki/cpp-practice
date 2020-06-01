#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    if (n % 2 == 1)
    {
        int left = a[n / 2];
        int right = b[n / 2];
        ans = right - left + 1;
    }
    else
    {
        int left = a[n / 2 - 1] + a[n / 2];
        int right = b[n / 2 - 1] + b[n / 2];
        ans = right - left + 1;
    }
    cout << ans << endl;
    return 0;
}