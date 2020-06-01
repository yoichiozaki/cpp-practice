#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool flag = false;
    vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        if (x == 0)
            flag = true;
        a[i] = x;
    }
    if (flag)
    {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1LL;
    for (int i = 0; i < N; i++)
    {
        if (a[i] <= 1000000000000000000 / ans)
        {
            ans *= a[i];
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}