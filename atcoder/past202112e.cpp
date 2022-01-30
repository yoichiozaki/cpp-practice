#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char a[200010];
    int hand[10];
    for (int i = 0; i < 10; i++)
    {
        if ((1 <= i) && (i <= 5))
            hand[i] = 1;
        else
            hand[i] = 0;
    }
    int ans = 500;
    cin >> a;
    n = strlen(a);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
            ans += 301;
        else if (hand[(a[i - 1] - '0')] == hand[(a[i] - '0')])
            ans += 210;
        else
            ans += 100;
    }
    cout << ans << endl;

    return 0;
}