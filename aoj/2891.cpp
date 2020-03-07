#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

// seen[v]: 行きがけ時に頂点vを訪問済みかを記録
// finished[v]: 帰りがけ時に頂点vを訪問済みかを記録
vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1;
stack<int> history; // 訪問履歴を積むスタック

// v: 訪問中の頂点
// p: vの親
void dfs(const Graph &G, int v, int p) {
    seen[v] = true; // 行きがけ時に頂点vを訪問したのでマーク
    history.push(v);
    for (auto w : G[v]) {
        if (w == p) continue; // 隣接頂点が親なのでスルー
        if (finished[w]) continue; // 帰りがけの訪問も済んでいる頂点はスルー

        // 隣接頂点wについて行きがけ時に訪問済みだけど，帰りがけ時に訪問済みでないことが判明したのでwはサイクルの始点であり終点として記録
        if (seen[w] && !finished[w]) {
            pos = w;
            return;
        }

        dfs(G, w, v);

        if (pos != -1) {
            return; // pos != -1なのでサイクルが見つかっている
        }
    }

    history.pop();
    finished[v] = true;
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    finished.assign(N, false);

    dfs(G, 0, -1);

    set<int> cycle;
    while (!history.empty()) {
        int t = history.top();
        cycle.insert(t);
        history.pop();
        if (t == pos) break;
    }

    int Q; cin >> Q;
    for (int _ = 0; _ < Q; _++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (cycle.count(a) && cycle.count(b)) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}