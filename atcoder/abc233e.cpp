#include <bits/stdc++.h>

using namespace std;

int main()
{
    string X;
    cin >> X;
    int s = 0;
    int c = 0;
    for (auto &ch : X)
        s += (ch - '0');
    string ans = "";
    for (int i = X.size() - 1;; i--)
    {
        c += s;
        ans.push_back('0' + (c % 10));
        c /= 10;
        if (0 <= i)
            s -= (X[i] - '0');
        if (i <= 0 && c == 0)
            break;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}