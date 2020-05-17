#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            cin >> a[0];
        else
        {
            long long b;
            cin >> b;
            a[i] += b + a[i - 1];
        }
    }
    long long ans = 2000000000;
    for (int i = 0; i < N - 1; i++)
    {
        ans = min(ans, abs(2LL * a[i] - a[N - 1]));
    }
    cout << ans << endl;
    return 0;
}