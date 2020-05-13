#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "100";
    char x, comma, y;
    while (cin >> x >> comma >> y)
    {
        swap(s[x - 'A'], s[y - 'A']);
    }
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == '1')
            cout << char('A' + i) << endl;
    }
    return 0;
}