#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    set<char> s;
    for (int i = 0; i < 3; i++)
        s.insert(S[i]);
    if (s.size() == 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}