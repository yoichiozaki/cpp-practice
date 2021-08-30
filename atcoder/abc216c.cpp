#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    string ans = "";
    while (0 < N)
    {
        if (N % 2 == 1)
            ans += 'A', N -= 1;
        else
            ans += 'B', N /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}