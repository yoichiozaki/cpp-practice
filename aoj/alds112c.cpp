#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
const int INF = 1 << 20;
const int WHITE = 0; // 「最小コストが未確定」の頂点
const int GRAY = 1; // 「最小コストが確定済み」の頂点の隣接頂点
const int BLACK = 2; // 「最小コストが確定済み」の頂点
// GRAY -> WHITEとはならない！

int n;
vector<pair<int, int>> G[MAX];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    int color[MAX];
    int dist[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        color[i] = WHITE;
    }

    dist[0] = 0;
    color[0] = GRAY;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        pair<int, int> f = pq.top(); pq.pop();
        int u = f.second;
        color[u] = BLACK;

        if (dist[u]< f.first * (-1)) continue;

        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j].first;
            if (color[v] == BLACK) continue;
            if (dist[u] + G[u][j].second < dist[v]) {
                dist[v] = dist[u] + G[u][j].second;
                pq.push(make_pair(dist[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() {
    int k, u, v, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}