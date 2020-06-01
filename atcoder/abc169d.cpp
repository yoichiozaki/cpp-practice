#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve
{
    int n;
    vector<int> f, primes;
    Sieve(int n = 1) : n(n), f(n + 1)
    {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; i++)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i * i; j <= n; j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }
    bool isPrime(int x)
    {
        return f[x] == x;
    }
    vector<int> factorList(int x)
    {
        vector<int> res;
        while (x != 1)
        {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x)
    {
        vector<int> fl = factorList(x);
        if (fl.size() == 0)
            return {};
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for (int p : fl)
        {
            if (res.back().first == p)
            {
                res.back().second++;
            }
            else
            {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
    vector<long long> factorList(long long x)
    {
        vector<long long> res;
        for (int p : primes)
        {
            while (x % p == 0)
            {
                res.push_back(p);
                x /= p;
            }
        }
        if (x != 1)
            res.push_back(x);
        return res;
    }

    vector<pair<long long, int>> factor(long long x)
    {
        vector<long long> fl = factorList(x);
        if (fl.size() == 0)
            return {};
        vector<pair<long long, int>> res(1, make_pair(fl[0], 0));
        for (long long p : fl)
        {
            if (res.back().first == p)
            {
                res.back().second++;
            }
            else
            {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main()
{
    long long n;
    cin >> n;
    Sieve s(1000005);
    auto fs = s.factor(n);
    int ans = 0;
    for (auto p : fs)
    {
        int x = p.second;
        int b = 1;
        while (b <= x)
        {
            x -= b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}