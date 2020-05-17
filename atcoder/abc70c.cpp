#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int N;
    cin >> N;
    ll ans = 1LL;

    for (int i = 0; i < N; i++)
    {
        ll T;
        cin >> T;
        ans = T / __gcd(ans, T) * ans;
    }
    cout << ans << endl;
    return 0;
}