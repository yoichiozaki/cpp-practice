#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N; // サイクルを1つ含むグラフなので辺数もN
  Graph G(N);
  vector<int> degree(N, 0);
  for (int i = 0; i < N; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    degree[u]++; degree[v]++;
  }

  queue<int> q;
  for (int i = 0; i < N; i++) if (degree[i] == 1) q.push(i);

  vector<bool> has_enqueued(N, false); // has_enqueued[i]: 頂点iがキューに入ったことがあるか
  while (!q.empty()) {
    int v = q.front(); q.pop();
    has_enqueued[v] = true;
    for (auto w: G[v]) {
      degree[w]--;
      if (degree[w] == 1) q.push(w);
    }
  }

  int Q; cin >> Q;
  for (int _ = 0; _ < Q; _++) {
    int a, b; cin >> a >> b; a--; b--;
    if (!has_enqueued[a] && !has_enqueued[b]) cout << 2 << endl;
    else cout << 1 << endl;
  }
}