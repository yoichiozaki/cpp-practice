#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    s.erase(unique(s.begin(), s.end()), s.end());
    if (s.size() != len)
        cout << "Bad" << endl;
    else
        cout << "Good" << endl;
    return 0;
}