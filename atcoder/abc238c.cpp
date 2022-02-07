#include <bits/stdc++.h>

#define MOD 998244353
#define INV2 499122177

using namespace std;

long long calc(long long x)
{
    x %= MOD;
    long long ret = x;
    ret *= (x + 1);
    ret %= MOD;
    ret *= INV2;
    ret %= MOD;
    return ret;
}

int main()
{
    long long N;
    cin >> N;
    long long ans = 0;
    long long base = 10;
    for (int d = 1; d <= 18; d++)
    {
        long long left = base / 10;
        long long right = min(N, base - 1);
        if (left <= right)
        {
            ans += calc(right - left + 1);
            ans %= MOD;
        }
        base *= 10;
    }
    cout << ans << endl;
    return 0;
}