#include <bits/stdc++.h>

using namespace std;

long long f(int k)
{
    long long ret = 1;
    for (int i = 1; i <= 30; i++)
    {
        ret *= 3;
        if (i == k)
        {
            ret += 1;
        }
    }
    return ret;
}

int main()
{
    long long N;
    cin >> N;
    for (int k = 1; k <= 30; k++)
    {
        long long val = f(k);
        if (val == N)
        {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}