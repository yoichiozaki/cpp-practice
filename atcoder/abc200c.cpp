#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> r(200, 0LL);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        r[a % 200]++;
    }
    long long ans = 0;
    for (int i = 0; i < 200; i++)
        ans += (r[i] * (r[i] - 1LL)) / 2LL;
    cout << ans << endl;
    return 0;
}