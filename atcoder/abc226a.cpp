#include <bits/stdc++.h>

using namespace std;

int main()
{
    string X;
    cin >> X;
    int a;
    int ans = 0;
    int n = X.size();
    for (int i = 0; i < n - 4; i++)
    {
        a = (int)(X[i] - '0');
        ans = 10 * ans + a;
    }
    if (X[n - 3] >= '5')
        ans++;
    cout << ans << endl;
    return 0;
}