#include <bits/stdc++.h>
using namespace std;

// 正負をひっくり返して最短経路問題に帰着させる

struct Edge {
    int from;
    int to;
    long long weight;
    Edge(int f, int t, long long w) : from(f), to(t), weight(w) { }
};

using Graph = vector<Edge>;

const long long INF = 1LL << 60;

int main() {
    int N, M; cin >> N >> M;
    Graph G;
    for (int i = 0; i < M; i++) {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        from--; to--;
        G.push_back(Edge(from, to, -1 * weight));
    }
    long long dist[N];
    fill(dist, dist+N, INF);
    dist[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            struct Edge e = G[j];
            if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                if (i == N-1) {
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 * dist[N-1] << endl;

    return 0;
}
