#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long l = 0;
    long long r = 2e9;
    while (1 < r - l)
    {
        long long mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 <= n + 1)
            l = mid;
        else
            r = mid;
    }
    cout << n - l + 1 << endl;
    return 0;
}