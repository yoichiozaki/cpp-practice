#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if (i == 0)
        {
            if (!isupper(S[i]))
                S[i] = S[i] - 'a' + 'A';
        }
        else
        {
            if (isupper(S[i]))
                S[i] = S[i] - 'A' + 'a';
        }
    }
    cout << S << endl;
    return 0;
}