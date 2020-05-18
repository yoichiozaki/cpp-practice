#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X;
    cin >> X;
    int t = 0;
    while (1)
    {
        t++;
        if (X <= t * (t + 1) / 2)
            break;
    }
    cout << t << endl;
    return 0;
}