#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, D;
    cin >> M >> D;
    int ans = 0;
    if (D < 10)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 10; j <= D; j++)
        {
            if ((j / 10) >= 2 && (j % 10) >= 2 && i == (j / 10) * (j % 10))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}