#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long ans = N + 1 - 2;
    for (long long a = 1; a * a <= N; a++)
    {
        if (N % a == 0)
        {
            long long b = N / a;
            ans = min(ans, a + b - 2);
        }
    }
    cout << ans << endl;
    return 0;
}