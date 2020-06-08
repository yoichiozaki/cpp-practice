#include <bits/stdc++.h>
using namespace std;

long long rpower(long long x, long long n)
{
    if (n == 0)
        return 1LL;
    long long ret = rpower(x, n / 2);
    ret *= ret;
    if (n % 2 == 1)
        ret *= x;
    return ret;
}

int main()
{
    long long A, R, N;
    cin >> A >> R >> N;
    if (log(1000000000) < log(A) + (N - 1) * log(R))
    {
        cout << "large" << endl;
        return 0;
    }
    long long ans = A * rpower(R, N - 1);
    cout << ans << endl;
    return 0;
}