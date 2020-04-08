#include <bits/stdc++.h>
using namespace std;

const int odx[6] = {-1, -1,  0,  1,  1,  0};
const int ody[6] = { 0,  1,  1,  1,  0, -1};
const int edx[6] = {-1, -1,  0,  1,  1,  0};
const int edy[6] = {-1,  0,  1,  0, -1, -1};

int w, h;

int main() {
  cin >> w >> h;
  w += 2; h += 2;
  vector<vector<int>> a(h, vector<int>(w, -1));
  for (int i = 1; i < h-1; i++) {
    for (int j = 1; j < w-1; j++) {
      cin >> a[i][j];
    }
  }

  auto paint_BFS = [&](int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int x = p.first, y = p.second;
      for (int dir = 0; dir < 6; dir++) {
        int nx, ny;
        if (x%2 == 1) {
          nx = x + odx[dir]; ny = y + ody[dir];
        } else {
          nx = x + edx[dir]; ny = y + edy[dir];
        }

        if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if (a[nx][ny] == 1) continue;
        if (a[nx][ny] == -1) continue;
        a[nx][ny] = -1;
        q.push(make_pair(nx, ny));
      }
    }
  };

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == -1) paint_BFS(i, j);
    }
  }

  int ans = 0;
  {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int x = p.first, y = p.second;
      if (a[x][y] == 0) continue;
      for (int dir = 0; dir < 6; dir++) {
        int nx, ny;
        if (x%2 == 1) {
          nx = x + odx[dir]; ny = y + ody[dir];
        } else {
          nx = x + edx[dir]; ny = y + edy[dir];
        }

        if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if (a[nx][ny] == 0) continue;
        if (a[nx][ny] == 1) {
          ans++;
          continue;
        }
        q.push(make_pair(nx, ny));
      }
      a[x][y] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}