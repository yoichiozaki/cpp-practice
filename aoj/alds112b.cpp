#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int INF = 1 << 21;
const int WHITE = 0; // 「最小コストが未確定」の頂点
const int GRAY = 1; // 「最小コストが確定済み」の頂点の隣接頂点
const int BLACK = 2; // 「最小コストが確定済み」の頂点
// GRAY -> WHITEとはならない！

int n, G[MAX][MAX];

void dijkstra() {
    int minv;
    int dist[MAX], color[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        color[i] = WHITE;
    }

    dist[0] = 0;
    color[0] = GRAY;

    while (1) {
        minv = INF;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] < minv && color[i] != BLACK) {
                u = i;
                minv = dist[i];
            }
        }
        if (u == -1) break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && G[u][v] != INF) {
                if (dist[u] + G[u][v] < dist[v]) {
                    dist[v] = dist[u] + G[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = INF;
        }
    }
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}