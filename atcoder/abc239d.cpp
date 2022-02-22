#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool is_prime[210];
    for (int i = 2; i <= 200; i++)
        is_prime[i] = 1;
    for (int p = 2; p * p <= 200; p++)
        if (is_prime[p])
            for (int i = p * p; i <= 200; i += p)
                is_prime[i] = false;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int x = a; x <= b; x++)
    {
        int flag = 1;
        for (int y = c; y <= d; y++)
            flag &= !is_prime[x + y];
        if (flag)
        {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}