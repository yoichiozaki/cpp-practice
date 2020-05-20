#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    set<char> st;
    for (auto c : S)
    {
        st.insert(c);
    }
    if (st.size() == 1)
        cout << "SAME" << endl;
    else
        cout << "DIFFERENT" << endl;
    return 0;
}