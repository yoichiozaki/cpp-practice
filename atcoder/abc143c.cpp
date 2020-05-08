#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            s[i] = '*';
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '*')
            ans++;
    }
    cout << ans << endl;
    return 0;
}