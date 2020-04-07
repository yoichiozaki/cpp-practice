#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long bi = b[i];
    auto aiter = lower_bound(a.begin(), a.end(), bi);
    auto citer = upper_bound(c.begin(), c.end(), bi);
    ans += distance(a.begin(), aiter) * distance(citer, c.end());
  }
  cout << ans << endl;
  return 0;
}