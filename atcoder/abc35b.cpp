#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int T;
    cin >> T;
    int h = 0;
    int x = 0, y = 0;
    for (int i = 0; i < S.size(); i++)
        if (S[i] == '?')
            h++;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '?')
            continue;
        else
        {
            if (S[i] == 'L')
                x--;
            else if (S[i] == 'R')
                x++;
            else if (S[i] == 'U')
                y++;
            else
                y--;
        }
    }
    if (T == 1)
        cout << abs(x) + abs(y) + h << endl;
    else
        cout << max(int(S.size() % 2), abs(x) + abs(y) - h) << endl;
    return 0;
}