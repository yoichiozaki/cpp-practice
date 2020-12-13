#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    else
        return gcd(b, (a % b));
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    long long N;
    cin >> N;
    vector<long long> v(N, 0LL);
    for (long long i = 0LL; i < N; i++)
        v[i] = i + 1LL;
    long long ret = accumulate(v.begin() + 1LL, v.end(), 1LL, [](long long a, long long b) { return lcm(a, b); });
    cout << ret + 1LL << endl;
    return 0;
}