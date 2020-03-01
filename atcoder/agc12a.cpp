#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> a(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0LL;
    for (int i = 0; i < 2*N; i++) {
        if (i%2 == 1) {
            ans += a.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}