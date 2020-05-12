#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        if (2 <= st.size())
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            if (!((a == '1' && b == '0') || (a == '0' && b == '1')))
            {
                st.push(b);
                st.push(a);
            }
        }
    }
    cout << s.size() - st.size() << endl;
    return 0;
}