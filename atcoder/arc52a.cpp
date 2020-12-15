#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    string ans = "";
    for (auto c : S)
    {
        if ('0' <= c && c <= '9')
            ans += c;
    }
    cout << ans << endl;
    return 0;
}