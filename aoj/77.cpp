#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        string ret = "";
        for (int i = 0; i < s.size();)
        {
            if (s[i] == '@')
            {
                int rep = s[i + 1] - '0';
                char c = s[i + 2];
                for (int j = 0; j < rep; j++)
                    ret += c;
                i += 3;
            }
            else
                ret += s[i], i++;
        }
        cout << ret << endl;
    }
    return 0;
}