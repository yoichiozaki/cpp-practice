#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
            cnt++;
    }
    cout << cnt / 2 << endl;
    return 0;
}