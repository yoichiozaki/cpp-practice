#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> prime_factorize(long long X)
{
    vector<pair<long long, long long>> ret;
    for (long long a = 2; a * a <= X; a++)
    {
        if (X % a != 0)
            continue;
        long long ex = 0;
        while (X % a == 0)
        {
            ex++;
            X /= a;
        }
        ret.push_back({a, ex});
    }
    if (X != 1)
        ret.push_back({X, 1});
    return ret;
}

int main()
{
    long long N, P;
    cin >> N >> P;
    const auto &f = prime_factorize(P);
    long long ans = 1;
    for (auto p : f)
    {
        for (long long i = 0; i < p.second / N; i++)
            ans *= p.first;
    }
    cout << ans << endl;
}