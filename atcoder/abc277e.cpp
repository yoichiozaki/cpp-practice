#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Edge;
const int INF = 1e9;

int N, M, K;
vector<Edge> G[400005];
int dist[400005];

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int u, v, a; cin >> u >> v >> a;
        if (a == 1) {
            G[u].push_back(Edge(v, 1)), G[v].push_back(Edge(u, 1));
        } else {
            G[u + N].push_back(Edge(v + N, 1)), G[v + N].push_back(Edge(u + N, 1));
        }
    }
    for (int i = 1; i <= K; i++) {
        int s; cin >> s;
        G[s].push_back(Edge(s + N, 0));
        G[s + N].push_back(Edge(s, 0));
    }

    // Dijkstra
    deque<int> Q;
    for (int i = 1; i <= 2 * N; i++) {
        dist[i] = INF;
    } 
    Q.push_back(1);
    dist[1] = 0;

    while (!Q.empty()) {
        int node = Q.front(); Q.pop_front();
        for (int i = 0; i < G[node].size(); i++) {
            int neighbor = G[node][i].first;
            int cost = G[node][i].second;
            if (dist[node] + cost < dist[neighbor]) {
                dist[neighbor] = dist[node] + cost;
                if (cost == 0) {
                    Q.push_front(neighbor);
                } else {
                    Q.push_back(neighbor);
                }
            }
        }
    }

    int ans = min(dist[N], dist[2 * N]);
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}