#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string t;
    char prev = s[0];
    int cnt = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        if (i == s.size())
        {
            t.push_back(prev);
            t += to_string(cnt);
        }
        else
        {
            if (prev == s[i])
            {
                cnt++;
            }
            else
            {
                t.push_back(prev);
                t += to_string(cnt);
                cnt = 1;
                prev = s[i];
            }
        }
    }
    cout << t << endl;
    return 0;
}