#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (S.substr(i, 4) == "ZONe")
            ans++;
    }
    cout << ans << endl;
    return 0;
}