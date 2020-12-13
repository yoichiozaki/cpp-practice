#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int ans = 0;
    for (auto c : S)
    {
        if (c == '1')
            ans++;
    }
    cout << ans << endl;
    return 0;
}