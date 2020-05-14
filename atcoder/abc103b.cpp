#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    s += s;
    if (s.find(t) != -1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}