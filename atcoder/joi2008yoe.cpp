#include <bits/stdc++.h>
using namespace std;

int table[10][10000];

int main() {
  int row, col; cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> table[i][j];
    }
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << row); bit++) {
    int cnt = 0;
    for (int j = 0; j < col; j++) {
      int omote = 0, ura = 0, state;
      for (int r = 0; r < row; r++) {
        state = table[r][j];
        if ((bit >> r) & 1) {
          state = !state;
        }
        if (state) omote++;
        else ura++;
      }
      cnt += max(omote, ura);
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}