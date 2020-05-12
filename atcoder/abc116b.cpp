#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s;
    cin >> s;
    set<long long> st;
    long long a = s;
    int cnt = 1;
    while (st.count(a) == 0)
    {
        st.insert(a);
        cnt++;
        if (a % 2 == 0)
            a /= 2;
        else
            a = 3 * a + 1;
    }
    cout << cnt << endl;
    return 0;
}