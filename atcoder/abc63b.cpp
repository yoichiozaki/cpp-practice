#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> st;
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    if (s.size() != st.size())
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    return 0;
}