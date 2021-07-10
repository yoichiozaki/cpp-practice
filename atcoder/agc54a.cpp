#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (S[0] != S[N - 1])
        cout << 1 << endl;
    else
    {
        bool ok = false;
        for (int i = 1; i < N - 1; i++)
        {
            if (S[0] != S[i] && S[i + 1] != S[N - 1])
            {
                ok = true;
            }
        }
        if (ok)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}