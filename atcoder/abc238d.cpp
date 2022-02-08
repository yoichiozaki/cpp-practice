#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        long long a, s;
        cin >> a >> s;
        string ans = "No";
        if (2 * a <= s)
        {
            long long diff = s - 2 * a;
            if ((diff & a) == 0)
                ans = "Yes";
        }
        cout << ans << endl;
    }
}