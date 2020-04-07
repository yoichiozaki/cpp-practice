#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<bool>> friends(n, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    friends[x][y] = friends[y][x] = true;
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if ((bit >> i) & 1) {
        for (int j = 0; j < i; j++) {
          if ((bit >> j) & 1) {
            if (!friends[i][j]) flag = false;
          }
        }
      }
    }
    if (flag) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << endl;
  return 0;
}