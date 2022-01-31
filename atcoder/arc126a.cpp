#include <bits/stdc++.h>

using namespace std;

long long solve(long long n2, long long n3, long long n4)
{
    long long N1 = n2;
    long long N2 = n4;
    long long N3 = n3 / 2;
    long long ans = 0;

    long long a, b, c;
    long long k;

    // (0, 1, 1): 1x0 + 2x1 + 3x1
    a = 0, b = 1, c = 1;
    k = N1 + N2 + N3;
    if (a > 0)
        k = min(k, N1 / a);
    if (b > 0)
        k = min(k, N2 / b);
    if (c > 0)
        k = min(k, N3 / c);
    ans += k;
    N1 -= a * k;
    N2 -= b * k;
    N3 -= c * k;

    // (2, 0, 1): 1x2 + 2x0 + 3x1
    a = 2, b = 0, c = 1;
    k = N1 + N2 + N3;
    if (a > 0)
        k = min(k, N1 / a);
    if (b > 0)
        k = min(k, N2 / b);
    if (c > 0)
        k = min(k, N3 / c);
    ans += k;
    N1 -= a * k;
    N2 -= b * k;
    N3 -= c * k;

    // (1, 2, 0): 1x1 + 2x2 + 3x0
    a = 1, b = 2, c = 0;
    k = N1 + N2 + N3;
    if (a > 0)
        k = min(k, N1 / a);
    if (b > 0)
        k = min(k, N2 / b);
    if (c > 0)
        k = min(k, N3 / c);
    ans += k;
    N1 -= a * k;
    N2 -= b * k;
    N3 -= c * k;

    // (3, 1, 0): 1x3 + 2x1 + 3x0
    a = 3, b = 1, c = 0;
    k = N1 + N2 + N3;
    if (a > 0)
        k = min(k, N1 / a);
    if (b > 0)
        k = min(k, N2 / b);
    if (c > 0)
        k = min(k, N3 / c);
    ans += k;
    N1 -= a * k;
    N2 -= b * k;
    N3 -= c * k;

    // (5, 0, 0): 1x5 + 2x0 + 3x0
    a = 5, b = 0, c = 0;
    k = N1 + N2 + N3;
    if (a > 0)
        k = min(k, N1 / a);
    if (b > 0)
        k = min(k, N2 / b);
    if (c > 0)
        k = min(k, N3 / c);
    ans += k;
    N1 -= a * k;
    N2 -= b * k;
    N3 -= c * k;

    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        long long N2, N3, N4;
        cin >> N2 >> N3 >> N4;
        cout << solve(N2, N3, N4) << endl;
    }
    return 0;
}