#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    set<char> s;
    s.insert(S[0]);
    s.insert(S[1]);
    s.insert(S[2]);
    if (s.size() == 3)
        cout << 6 << endl;
    else if (s.size() == 2)
        cout << 3 << endl;
    else
        cout << 1 << endl;
    return 0;
}