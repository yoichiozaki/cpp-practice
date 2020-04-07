#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;cin >> n;
  vector<ll> a(n), b(n);
  set<ll> ab;
  for (int i = 0; i < n; i++) {
    ll _a, _b;
    cin >> _a >> _b;
    ab.insert(_a); ab.insert(_b);
    a[i] = _a;
    b[i] = _b;
  }
  ll s, t;
  ll ans = 9223372036854775807;
  for (auto s : ab) {
    for (auto t : ab) {
      ll elapsed = 0;
      for (int k = 0; k < n; k++) {
        elapsed += abs(s - a[k]) + abs(a[k] - b[k]) + abs(t - b[k]);
      }
      ans = min(ans, elapsed);
    }
  }
  cout << ans << endl;
  return 0;
}