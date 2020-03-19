#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1 << 21;

int n, G[N][N];
int dist[N];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 0) continue;
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << ((dist[i] == INF ? -1 : dist[i])) << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v; v--;
            G[u][v] = 1;
        }
    }
    BFS(0);
    return 0;
}