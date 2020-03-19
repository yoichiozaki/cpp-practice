#include <bits/stdc++.h>
using namespace std;

// 木の直径: 最遠頂点間距離
// 木の直径の求め方
// 1. 適当な頂点sから最も遠い頂点xを求める
// 2. 頂点xから最も遠い頂点yを求める
// 3. 頂点xと頂点y間の距離が木の直径

#define MAX 100000
#define INF (1 << 30)

class Edge {
public:
    int t, w;
    Edge() {}
    Edge(int t, int w): t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, dist[MAX];

bool visited[MAX];
int cnt;

// 頂点sを始点とするBFS
void bfs(int s) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    int u;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            if (dist[e.t] == INF) {
                dist[e.t] = dist[u] + e.w;
                q.push(e.t);
            }
        }
    }
}


void solve() {
    bfs(0);
    int maxv = 0;
    int tgt = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) continue;
        if (maxv < dist[i]) {
            maxv = dist[i];
            tgt = i;
        }
    }
    bfs(tgt);
    maxv = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) continue;
        maxv = max(maxv, dist[i]);
    }
    cout << maxv << endl;
}

int main() {
    int s, t, w;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }
    solve();
    return 0;
}