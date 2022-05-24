#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int cost;
    int index;
};

vector<int> dijkstra(int start, vector<vector<Edge>> &G) {
    vector<long long> dist(G.size(), 1LL << 60);
    vector<int> prev_nodes(G.size());
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        long long d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (dist[v] != d) continue;
        for (auto[neighbor, cost, index]: G[v]) {
            if (dist[neighbor] > dist[v] + cost) {
                dist[neighbor] = dist[v] + cost;
                pq.push(make_pair(dist[neighbor], neighbor));
                prev_nodes[neighbor] = index;
            }
        }
    }
    
    return prev_nodes;
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c;
        u -= 1;
        v -= 1;
        G[u].push_back({v, c, i});
        G[v].push_back({u, c, i});
    }
    vector<int> prev_nodes = dijkstra(0, G);
    for (int i = 1; i < N; i++) {
        cout << prev_nodes[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}