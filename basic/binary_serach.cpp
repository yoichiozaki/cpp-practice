#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll N, L, R; cin >> N >> L >> R;
    ll a[1000009];
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int left = lower_bound(a+1, a+N+1, L - a[i]) - a;
        int right = lower_bound(a+1, a+1+N, (R + 1LL) - a[i]) - a;
        ans += 1LL * (right - left);
    }
    cout << ans << endl;
    return 0;
}