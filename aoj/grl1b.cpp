#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) { }
};

const int INF = 10000000;

int main() {
    int V, E, r; cin >> V >> E >> r;
    vector<Edge> edges;
    int dist[V];
    fill(dist, dist+V, INF);
    dist[r] = 0;
    for (int i = 0; i < E; i++) {
        int f, t, w; cin >> f >> t >> w;
        edges.push_back(Edge(f, t, w));
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            struct Edge e = edges[j];
            if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                if (i == V-1) {
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
    return 0;
}