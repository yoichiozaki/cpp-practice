#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;
    for (ll i = A; i <= min(B, A + K - 1LL); i++)
        cout << i << endl;
    for (ll i = max(B - K + 1LL, A + K); i <= B; i++)
        cout << i << endl;
    return 0;
}