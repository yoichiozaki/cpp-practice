#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int y = s[s.size() - 1] - '0';
    string x = s.substr(0, s.size() - 2);
    if (y <= 2)
        x += '-';
    else if (7 <= y)
        x += '+';
    cout << x << endl;
    return 0;
}