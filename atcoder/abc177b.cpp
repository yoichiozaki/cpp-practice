#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int ans = T.length();

    for (int start = 0; start <= S.length() - T.length(); start++)
    {
        int diff = 0;
        for (int i = 0; i < T.length(); i++)
        {
            if (T[i] != S[start + i])
                diff++;
        }
        ans = min(ans, diff);
    }

    cout << ans << endl;
    return 0;
}