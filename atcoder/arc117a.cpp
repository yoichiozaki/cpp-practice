#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;
    long long G[1 << 18];

    if (B <= A)
    {
        for (long long i = 0; i < A; i++)
            G[i] = i + 1;
        for (long long i = A; i < A + B - 1; i++)
            G[i] = -(i - A + 1);
        for (long long i = 0; i < A + B - 1; i++)
            G[A + B - 1] -= G[i];
    }
    else
    {
        for (long long i = 0; i < A - 1; i++)
            G[i] = i + 1;
        for (long long i = A; i < A + B; i++)
            G[i] = -(i - A + 1);
        for (long long i = 0; i < A + B; i++)
        {
            if (i != A - 1)
                G[A - i] -= G[i];
        }
    }

    for (long long i = 0; i < A + B; i++)
    {
        if (i != 0)
            cout << " ";
        cout << G[i];
    }
    cout << endl;
    return 0;
}