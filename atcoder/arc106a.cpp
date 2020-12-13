#include <bits/stdc++.h>
using namespace std;

long long lpow(long long x, long long y)
{
    long long ret = 1LL;
    while (0 < y)
    {
        if (y & 1LL)
            ret *= x;
        x *= x;
        y >>= 1LL;
    }
    return ret;
}

int main()
{
    long long N;
    cin >> N;
    for (long long a = 1; a <= 37LL; a++)
    {
        for (long long b = 1; b <= 25LL; b++)
        {
            if (N == lpow(3LL, a) + lpow(5LL, b))
            {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}