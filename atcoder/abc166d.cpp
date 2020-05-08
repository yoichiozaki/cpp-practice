#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    for (long long a = -1000; a < 1000; a++)
    {
        for (long long b = -1000; b < 1000; b++)
        {
            if (a * a * a * a * a - b * b * b * b * b == x)
            {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}