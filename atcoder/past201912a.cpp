#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int ans = 0;
    for (auto c : S)
    {
        if ('0' <= c && c <= '9')
        {
            ans = ans * 10 + c - '0';
        }
        else
        {
            cout << "error" << endl;
            return 0;
        }
    }
    cout << ans * 2 << endl;
    return 0;
}