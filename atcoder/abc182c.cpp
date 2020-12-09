#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<int> amari(3, 0);
    while (N)
    {
        amari[N % 10LL % 3LL]++;
        N /= 10LL;
    }

    int digit = amari[0] + amari[1] + amari[2];
    int cnt = (amari[1] + 2 * amari[2]) % 3;

    if (cnt == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (cnt == 1)
    {
        if (amari[1] != 0)
        {
            if (digit == 1)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cout << 1 << endl;
                return 0;
            }
        }
        else
        {
            if (digit == 2)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    else
    {
        if (amari[2] != 0)
        {
            if (digit == 1)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cout << 1 << endl;
                return 0;
            }
        }
        else
        {
            if (digit == 2)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    return 0;
}