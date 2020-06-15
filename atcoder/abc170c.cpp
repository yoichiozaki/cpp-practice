#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;
    vector<int> d(102, 0);
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        d[p] = 1;
    }
    pair<int, int> ans(99999, -1);
    for (int i = 0; i <= 101; i++)
    {
        if (d[i] == 1)
            continue;
        int diff = abs(X - i);
        ans = min(ans, pair<int, int>(diff, i));
    }
    cout << ans.second << endl;
    return 0;
}