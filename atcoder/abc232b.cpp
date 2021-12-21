#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    if (S.size() == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    int prev = ((int)(S[0] - T[0]) + 26) % 26;
    for (int i = 1; i < S.size(); i++)
    {
        char s = S[i];
        char t = T[i];
        if (((int)(s - t) + 26) % 26 != prev)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}