#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        while (s.find("the") == -1 && s.find("this") == -1 && s.find("that") == -1) // ths/this/thatが見つからないうちは回る
        {
            for (int i = 0; i < s.size(); i++)
            {
                if ('a' <= s[i] && s[i] < 'z')
                    s[i]++;
                else if (s[i] == 'z')
                    s[i] = 'a';
            }
        }
        cout << s << endl;
    }
    return 0;
}