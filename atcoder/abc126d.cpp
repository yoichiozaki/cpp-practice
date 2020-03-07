#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) { }
};

using Graph = vector<vector<Edge>>;

vector<int> color; // color[i] = 1: 黒確定/ 0: 白確定/ -1:未訪問

// 条件を満たして色を塗れるならtrueを返す
bool dfs(const Graph &G, int v, int current_color = 0) {
    color[v] = current_color;
    for (auto edge : G[v]) {
        // 隣接頂点が未訪問のとき，隣接頂点に塗られている色が条件を満たすかを確認
        if (color[edge.to] != -1) {
            if ((color[edge.to] == current_color && edge.weight%2 == 1)
                || (color[edge.to] != current_color && edge.weight%2 == 0)) { // 重さが奇数なのに同じ色は条件を満たさない
                return false;
            } else {
                continue;
            }
        }
        // 辺の重さについて色を塗っていく
        if (edge.weight%2 == 0) {
            // 辺の重さが偶数なので同じ色を隣に塗る
            if (!dfs(G, edge.to, current_color)) {
                return false;
            }
        } else {
            // 辺の重さが奇数なので反対の色を塗る
            if (!dfs(G, edge.to, 1 - current_color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        u -= 1; v -= 1;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }

    color.assign(N, -1);
    for (int v = 0; v < N; v++) {
        if (color[v] != -1) { // vが訪問済みだったらスルー: 連結でないグラフを考慮
            continue;
        }
        if (dfs(G, v)) {
            break;
        }
    }
    for (int v = 0; v < N; v++) {
        cout << color[v] << endl;
    }
    return 0;
}