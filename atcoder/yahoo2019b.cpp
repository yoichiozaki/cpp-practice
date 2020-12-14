#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> cnt(4, 0);
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
    }
    if (cnt[0] == 3 || cnt[1] == 3 || cnt[2] == 3 || cnt[3] == 3)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}