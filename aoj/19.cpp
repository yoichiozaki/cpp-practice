#include <bits/stdc++.h>
using namespace std;

long long factorial(long long x)
{
    if (x == 1)
    {
        return x;
    }
    else
    {
        return x * factorial(x - 1LL);
    }
}

int main()
{
    long long x;
    cin >> x;
    cout << factorial(x) << endl;
    return 0;
}