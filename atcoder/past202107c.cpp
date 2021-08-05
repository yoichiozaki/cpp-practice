#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    long long L, R;
    cin >> S;
    cin >> L >> R;

    if (S == "0")
    {
        if (L == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return 0;
    }

    if (S[0] == '0' || 11 <= S.size())
    {
        cout << "No" << endl;
        return 0;
    }

    long long N = stol(S);
    if (L <= N && N <= R)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}