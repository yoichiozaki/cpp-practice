#include <bits/stdc++.h>
using namespace std;

int next_combination(int bit) {
  int x = bit & -bit;
  int y = bit + x;
  return (((bit & ~y) / x) >> 1) | y;
}

int main() {
  int n, k; cin >> n >> k;
  k--;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }
  n--;
  long long res = 1001001001001;
  int bit = (1 << k) - 1;
  for (; bit < (1 << n); bit = next_combination(bit)) {
    long long highest = a[0];
    long long tmp = 0;
    for (int i = 0; i < n; i++) {
      if ((bit >> i) & 1) {
        if (a[i+1] <= highest) {
          tmp += (highest - a[i+1] + 1);
          highest += 1;
        } else {
          highest = a[i+1];
        }
      } else {
        if (highest < a[i+1]) {
          highest = a[i+1];
        }
      }
    }
    res = min(res, tmp);
  }
  cout << res <<endl;
  return 0;
}