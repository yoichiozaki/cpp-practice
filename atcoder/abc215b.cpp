#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long X = 1;
    for (long long i = 0; i <= 60; i++)
    {
        if (N < X)
        {
            cout << i - 1 << endl;
            break;
        }
        X *= 2LL;
    }
    return 0;
}