#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}