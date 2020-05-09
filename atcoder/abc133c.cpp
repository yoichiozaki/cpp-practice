#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long L, R;
    cin >> L >> R;
    if (2019 <= R - L)
    {
        cout << 0 << endl;
    }
    else
    {
        long long ans = 2019;
        for (long long i = L; i <= R; i++)
        {
            for (long long j = i + 1; j <= R; j++)
            {
                ans = min(ans, (i * j) % 2019LL);
            }
        }
        cout << ans << endl;
    }
    return 0;
}