#include <bits/stdc++.h>
using namespace std;

long long f(long long x)
{
    return x * x;
}

int main()
{
    long long d;
    while (cin >> d)
    {
        long long rep = 600 / d;
        long long area = 0;
        for (long long i = 1; i < rep; i++)
        {
            area += d * f(i * d);
        }
        cout << area << endl;
    }
    return 0;
}