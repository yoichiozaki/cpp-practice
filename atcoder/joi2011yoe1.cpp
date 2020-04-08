#include <bits/stdc++.h>
using namespace std;

using Field = vector<string>;
Field F;
int H, W, N;
const int dh[4] = {1, 0, -1, 0};
const int dw[4] = {0, 1, 0, -1};

int BFS(pair<int, int> from, pair<int, int> to) {
  vector<vector<int>> dist(H, vector<int>(W, 1e8));
  queue<pair<int, int>> q;

  dist[from.first][from.second] = 0;
  q.push(from);

  while (!q.empty()) {
    auto p = q.front(); q.pop();
    int h = p.first;
    int w = p.second;
    if (pair<int, int>(h, w) == to) {
      return dist[h][w];
    }
    for (int dir = 0; dir < 4; dir++) {
      int nh = h + dh[dir];
      int nw = w + dw[dir];
      if (nh < 0 || H <= nh || nw < 0 || W <= nw) continue;
      if (F[nh][nw] == 'X') continue;
      dist[nh][nw] = dist[h][w] + 1;
      q.push(pair<int, int>(nh, nw));
    }
  }
  return -1; // should not reach here
}

int main() {
  cin >> H >> W >> N;
  F.resize(H);
  vector<pair<int, int>> factories(N+1);
  for (int i = 0; i < H; i++) cin >> F[i];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (F[i][j] == 'S') F[i][j] = '0';
      if ('0' <= F[i][j] && F[i][j] <= '9') {
        int idx = F[i][j] - '0';
        factories[idx] = pair<int, int>(i, j);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += BFS(factories[i], factories[i+1]);
  }
  cout << ans << endl;
  return 0;
}