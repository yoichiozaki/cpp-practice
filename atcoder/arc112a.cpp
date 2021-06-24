#include <bits/stdc++.h>

using namespace std;

long long calc_sum(long long a, long long b)
{
    return (a + b) * (b - a + 1) / 2;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        long long L, R;
        cin >> L >> R;
        if (R - L < L)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << calc_sum(1, R - 2 * L + 1) << endl;
        }
    }
    return 0;
}