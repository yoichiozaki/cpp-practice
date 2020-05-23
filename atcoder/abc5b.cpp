#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 999;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}