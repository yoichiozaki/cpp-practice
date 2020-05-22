#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int ans = -1;
    for (int x = 0; x <= A; x++)
    {
        ans = max(ans, x * (A - x));
    }
    cout << ans << endl;
    return 0;
}