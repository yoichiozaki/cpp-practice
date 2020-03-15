#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
using ll = long long;
int n, k;
ll T[MAX];

int check(ll P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        ll s = 0;
        while (s + T[i] <= P) {
            s += T[i];
            i++;
            if (i == n) return n;
        }
    }
    return i;
}

int solve() {
    ll left =0;
    ll right = 100000 * 10000;
    ll mid;
    while (1 < right - left) {
        mid = (left + right) / 2;
        int v = check(mid);
        if (n <= v) right = mid;
         else left = mid;
    }
    return right;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> T[i];
    ll ans = solve();
    cout << ans << endl;
    return 0;
}