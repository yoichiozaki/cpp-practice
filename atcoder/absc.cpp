#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == '1')
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}