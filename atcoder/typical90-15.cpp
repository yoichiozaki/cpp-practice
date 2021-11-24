#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;
long long fact[200009];    // fact[i] = i! mod m
long long factinv[200009]; // fact[i] = 1 / i! mod m

long long modpow(long long a, long long b)
{
    long long p = 1;
    long long q = a;
    for (int i = 0; i < 30; i++)
    {
        if ((b & (1LL << i)) != 0)
        {
            p *= q;
            p %= MOD;
        }
        q *= q;
        q %= MOD;
    }
    return p;
}

long long inv(long long x)
{
    return (1LL * modpow(x, MOD - 2)) % MOD;
}

long long nCr(long long n, long long r)
{
    if (n < r || r < 0)
        return 0;
    return (fact[n] * factinv[r] % MOD) * factinv[n - r] % MOD;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fact[i] = (1LL * i * fact[i - 1]) % MOD;
    for (int i = 0; i <= 200000; i++)
        factinv[i] = inv(fact[i]);

    long long N;
    cin >> N;
    for (long long K = 1; K <= N; K++)
    {
        long long ret = 0;
        for (long long i = 1; i <= N / K + 1; i++)
        {
            long long s1 = N - (K - 1) * (i - 1);
            long long s2 = i;
            ret += nCr(s1, s2);
            ret %= MOD;
        }
        cout << ret << endl;
    }

    return 0;
}