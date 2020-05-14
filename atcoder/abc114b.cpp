#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 1 << 20;
    int n = s.size();
    for (int i = 0; i <= n - 3; i++)
    {
        int x = 0;
        int base = 1;
        for (int j = 2; - 1 < j; j--)
        {
            x += base * (s[i + j] - '0');
            base *= 10;
        }
        ans = min(ans, abs(x - 753));
    }
    cout << ans << endl;
    return 0;
}