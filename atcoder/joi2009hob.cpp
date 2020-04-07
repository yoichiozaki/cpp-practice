#include <bits/stdc++.h>
using namespace std;

int main() {
  long long d;
  int n, m;
  cin >> d >> n >> m;
  vector<int> pizza_stores(n+1);
  for (int i = 1; i < n; i++) cin >> pizza_stores[i];
  pizza_stores[0] = 0;
  pizza_stores[n] = d;
  sort(pizza_stores.begin(), pizza_stores.end());
  vector<int> houses(m);
  for (int i = 0; i < m; i++) cin >> houses[i];
  long long  ans = 0;
  for (int i = 0; i < m; i++) {
    auto iter = lower_bound(pizza_stores.begin(), pizza_stores.end(), houses[i]);
    ans += min(abs(*iter - houses[i]), abs(*(iter - 1) - houses[i]));
  }
  cout << ans << endl;
  return 0;
}