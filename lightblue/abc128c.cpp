#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> vec(M);
  for (int i = 0; i < M; i++) {
    int k; cin >> k;
    vec[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> vec[i][j];
      vec[i][j] -= 1;
    }
  }
  vector<int> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p[i];
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    bool ok = true;
    for (int j = 0; j < M; j++) {
      int c = 0; // 電球jにつながっていて，かつonになっているスイッチの個数
      for (auto id : vec[j]) {
        if ((bit >> id) & 1) {
          c++;
        }
      }
      c %= 2;
      if (c != p[j]) {
        ok = false;
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}