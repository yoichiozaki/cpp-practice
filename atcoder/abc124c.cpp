#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char head = s[0];
    int cnt = 0;
    if (head == '0')
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!((i % 2 == 0 && s[i] == '0') || (i % 2 == 1 && s[i] == '1')))
                cnt++;
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!((i % 2 == 0 && s[i] == '1') || (i % 2 == 1 && s[i] == '0')))
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}