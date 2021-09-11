#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long L;
    int Q;
    cin >> L >> Q;
    set<long long> st;
    st.insert(0);
    st.insert(L);
    for (int _ = 0; _ < Q; _++)
    {
        int c;
        long long x;
        cin >> c >> x;
        if (c == 1)
        {
            st.insert(x);
        }
        else
        {
            auto it = st.lower_bound(x);
            cout << *it - *prev(it) << endl;
        }
    }
    return 0;
}