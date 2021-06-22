#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<int> a(n);
    for (auto &ele : a)
    {
        cin >> ele;
    }
    long long ans = n * (n - 1) / 2;

    sort(a.begin(), a.end());
    a.push_back(-1);
    long long cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            ans -= (cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
        else
        {
            cnt += 1;
        }
    }
    cout << ans << endl;
    return 0;
}