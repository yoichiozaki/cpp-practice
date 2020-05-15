#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cnt = 0;
    while (cin >> s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        if (s == t)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}