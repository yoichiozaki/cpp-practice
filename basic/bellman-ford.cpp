#include <bits/stdc++.h>
using namespace std;

// ベルマン・フォード法
// - 重み付きグラフの単一始点経路問題に対して，おもに負のコストの辺があるときに使用されるアルゴリズム
//
// - すべての辺を一つの配列にまとめておく
// - 最短距離が更新されなくなるまで以下を繰り返す
//     - 辺を1つづつ走査して，「その辺の始点へのコスト+辺のコスト」が「終点へのコスト」より小さければ，終点へのコストを更新する
// - 負の辺があればこのアルゴリズムは停止する
// - 任意の頂点への最短経路は，同じ頂点を二度と通らないので，Vをグラフの総頂点数とすれば高々V-1本
// - よって辺の走査を最大V-1回すれば最短距離が求まる
// - V回目の更新が発生すれば，始点から到達できる位置に必ず負の閉路が存在することになる
// - 計算量はO(VE)

int INF = 1 << 30;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) { }
};

int main() {
    // V: 頂点数, E: 辺数
    int V, E; cin >> V >> E;

    // S: 始点, G:終点
    int S, G; cin >> S >> G;

    int dist[E]; // dist[i]: 始点Sから頂点iに行くときの最小コスト

    vector<Edge> edges; // 辺の情報を配列にまとめる
    for (int i = 0; i < E; i++) {
        int f, t, w; cin >> f >> t >> w;
        edges.push_back(Edge(f, t, w));
    }

    // 初期化
    fill(dist, dist+V, INF);
    dist[S] = 0;

    for (int i = 0; i < V; i++) {

        // 辺について走査
        for (int j = 0; j < (int)edges.size(); j++) {
            struct Edge e = edges[j];

            if (dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                if (i == V-1) {
                    cout << "found negative loop" << endl; // 頂点数と同じ回数ループすると負の閉路が存在することになる
                    break;
                }
            }
        }
    }

    cout << dist[G] << endl;

    return 0;
}