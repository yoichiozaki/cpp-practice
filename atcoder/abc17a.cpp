#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, e;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> s >> e;
        ans += s * e;
    }
    cout << ans / 10 << endl;
    return 0;
}