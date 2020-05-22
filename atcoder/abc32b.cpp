#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    if (s.size() < k)
    {
        cout << 0 << endl;
        return 0;
    }
    set<string> st;
    for (int i = 0; i < s.size() - k + 1; i++)
    {
        st.insert(s.substr(i, k));
    }
    cout << st.size() << endl;
}