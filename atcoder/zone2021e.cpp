#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    deque<char> Q;
    bool is_reversed = false;
    for (char ch : S)
    {
        if (ch == 'R')
            is_reversed = !is_reversed;
        else if (is_reversed)
            Q.push_front(ch);
        else
            Q.push_back(ch);
    }

    if (is_reversed)
        reverse(Q.begin(), Q.end());

    string ans;
    for (char ch : Q)
    {
        if (ans.size() != 0 && ans.back() == ch)
            ans.pop_back();
        else
            ans.push_back(ch);
    }

    cout << ans << endl;
    return 0;
}