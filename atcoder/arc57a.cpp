#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, K;
    cin >> A >> K;
    if (K == 0)
    {
        cout << 2000000000000LL - A << endl;
        return 0;
    }
    int ans = 1;
    while (A + 1 + K * A < 2000000000000LL)
    {
        A += 1 + K * A;
        ans++;
    }
    cout << ans << endl;
    return 0;
}