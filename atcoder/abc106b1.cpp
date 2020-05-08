#include <bits/stdc++.h>
using namespace std;

int divisor(int n)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ret++;
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1 && divisor(i) == 8)
            ans++;
    }
    cout << ans << endl;
    return 0;
}