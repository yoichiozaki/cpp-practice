#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] != s[i + 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}