#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string t;
    cin >> t;
    string ans = "";
    for (auto ch : t)
    {
        if (ch == '1')
        {
            ans += s1;
        }
        else if (ch == '2')
        {
            ans += s2;
        }
        else
        {
            ans += s3;
        }
    }
    cout << ans << endl;
    return 0;
}