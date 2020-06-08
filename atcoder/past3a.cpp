#include <bits/stdc++.h>
using namespace std;

string str_tolower(string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "same" << endl;
        return 0;
    }
    string ls = str_tolower(s);
    string lt = str_tolower(t);
    if (ls == lt)
    {
        cout << "case-insensitive" << endl;
        return 0;
    }
    cout << "different" << endl;
    return 0;
}