#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A, R, N;
    cin >> A >> R >> N;
    if (R == 1)
    {
        cout << A << endl;
        return 0;
    }
    else
    {
        if (31 <= N)
        {
            cout << "large" << endl;
            return 0;
        }
    }

    for (long long _ = 0; _ < N - 1; _++)
    {
        A *= R;
        if (1000000000 < A)
        {
            cout << "large" << endl;
            return 0;
        }
    }
    if (A <= 1000000000)
        cout << A << endl;
    else
        cout << "large" << endl;
    return 0;
}