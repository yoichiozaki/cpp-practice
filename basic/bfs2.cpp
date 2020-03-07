#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(M, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto w : G[v]) {
            if (dist[w] != -1) continue;
            dist[w] = dist[v] + 1;
            que.push(w);
        }
    }

    for (int v = 0; v < N; v++) {
        cout << v << ": " << dist[v] << endl;
    }

    return 0;
}

// BFSは「辺の重さが均等なグラフにおける最短経路を求めるアルゴリズム」と捉えることもできる
// BFSの計算量: 各頂点は高々一度キューに突っ込まれ，各辺はたかだか一回だけ探索されるのでO(N+M)
// BFS vs DFS
// - DFSのほうが適切な場合: 解がスタートから遠いところにあることが探索前に分かっていて，幅優先探索によって虱潰しに探索することが現実的でない場合でもDFSであれば適切な枝刈りや探索順序の工夫によって解が現実的な時間内に求まることもある．グラフの頂点の順序に意味がある場合はDFSによって実装するほうが自然．帰りがけ時に小ノードの結果をまとめるような処理がほしいときは再帰関数を用いたDFSの実装のほうが簡単
// - BFSのほうが適切な場合: BFSは最短経路を求めるアルゴリズムとしても用いることができる．探索空間は大きいけど解がスタート地点から十分に近いところにあるときはBFSでも解を発見できることがある