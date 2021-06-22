#include <bits/stdc++.h>

using namespace std;

bool is_ok(long long x, long long n)
{
    return n <= x * (x + 1) / 2;
}

int main()
{
    long long n;
    cin >> n;
    long long ng = 0;
    long long ok = 3000000000;
    while (1 < ok - ng)
    {
        long long mid = (ok + ng) / 2;
        if (is_ok(mid, n))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}