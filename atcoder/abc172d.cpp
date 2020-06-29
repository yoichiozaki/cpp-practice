#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long ans = 0LL;
    for (long long i = 1; i <= N; i++)
    {
        long long Y = N / i;
        ans += (Y * (Y + 1LL) * i) / 2LL;
    }
    cout << ans << endl;
    return 0;
}