#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, head, end;
    string s;

    cin >> n;

    for (int k = 0; k <= n; k++)
    {

        getline(cin, s);

        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == 'H' && s[i + 1] == 'o' && s[i + 2] == 's' && s[i + 3] == 'h' && s[i + 4] == 'i' && s[i + 5] == 'n' && s[i + 6] == 'o')
            {
                s[i] = 'H';
                s[i + 1] = 'o';
                s[i + 2] = 's';
                s[i + 3] = 'h';
                s[i + 4] = 'i';
                s[i + 5] = 'n';
                s[i + 6] = 'a';
            }
        }
        if (k != 0)
            cout << s << endl;
    }
    return 0;
}