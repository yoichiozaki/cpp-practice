#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (x < y)
        swap(x, y);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    cout << a * b / g << endl;
    return 0;
}