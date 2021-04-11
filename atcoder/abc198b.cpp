#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 10; i++)
    {
        string t = string(i, '0') + s;
        string rev_t = t;
        reverse(rev_t.begin(), rev_t.end());
        if (t == rev_t)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}