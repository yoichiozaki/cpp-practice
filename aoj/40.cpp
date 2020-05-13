#include <bits/stdc++.h>
using namespace std;

string decrypt(string s)
{
    string res = s;
    for (int i = 1; i < 26; i++)
    {
        if (i % 2 == 0 || i % 13 == 0)
            continue;
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] == ' ')
                    continue;
                res[k] = (((s[k] - 'a') * i + j) % 26) + 'a';
            }

            if (res.find("this") != -1 || res.find("that") != -1)
            {
                return res;
            }
        }
    }
    return "";
}

int main()
{
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        cout << decrypt(s) << endl;
    }
    return 0;
}