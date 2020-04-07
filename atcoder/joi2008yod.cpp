#include <bits/stdc++.h>
using namespace std;

int main() {
  int m; cin >> m;
  set<pair<int, int>> sign;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    sign.insert(pair<int, int>(x, y));
  }
  int n; cin >> n;
  set<pair<int, int>> night_sky;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    night_sky.insert(pair<int, int>(x, y));
  }

  for (auto star: night_sky) {
    pair<int, int> ss = *begin(sign);
    int dx = star.first - ss.first;
    int dy = star.second - ss.second;
    bool flag = true;
    for (auto sstar: sign) {
      int nx = sstar.first + dx;
      int ny = sstar.second + dy;
      if (!(night_sky.count(pair<int, int>(nx, ny)))) flag = false;
    }
    if (flag) {
      cout << dx << " " << dy << endl;
      return 0;
    }
  }
  return 0;
}