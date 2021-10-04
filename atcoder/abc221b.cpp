#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    if (S == T)
    {
        cout << "Yes" << endl;
        return 0;
    }

    for (int i = 1; i < S.size(); i++)
    {
        swap(S[i - 1], S[i]);
        if (S == T)
        {
            cout << "Yes" << endl;
            return 0;
        }
        swap(S[i - 1], S[i]);
    }
    cout << "No" << endl;
    return 0;
}