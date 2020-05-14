#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    if (S[0] != 'A')
    {
        cout << "WA" << endl;
        return 0;
    }
    else
        S[0] = 'a';
    if (count(S.begin() + 2, S.end() - 1, 'C') != 1)
    {
        cout << "WA" << endl;
        return 0;
    }
    else
    {
        S[S.find("C")] = 'c';
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (!('a' <= S[i] && S[i] <= 'z'))
        {
            cout << "WA" << endl;
            return 0;
        }
    }
    cout << "AC" << endl;
    return 0;
}