#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n)
{
    if (n <= 1)
        return false;
    for (long long p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
            return false;
    }
    return true;
}

int main()
{
    long long X;
    cin >> X;
    long long res = X;
    while (!is_prime(res))
        res++;
    cout << res << endl;
    return 0;
}