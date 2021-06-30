#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "same" << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        if (tolower(s[i]) != tolower(t[i]))
        {
            cout << "different" << endl;
            return 0;
        }
    }

    cout << "case-insensitive" << endl;
    return 0;
}