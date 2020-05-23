#include <bits/stdc++.h>
using namespace std;

bool atcoder(char c)
{
    if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r')
        return true;
    else
        return false;
}

int main()
{
    string S, T;
    cin >> S >> T;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != T[i])
        {
            if (S[i] != '@' && T[i] != '@')
            {
                cout << "You will lose" << endl;
                return 0;
            }
            else
            {
                if (S[i] == '@' && atcoder(T[i]) || atcoder(S[i]) && T[i] == '@')
                    continue;
                else
                {
                    cout << "You will lose" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "You can win" << endl;
    return 0;
}