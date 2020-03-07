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

    bool is_bipartite = true;
    vector<int> dist(N, -1);
    queue<int> que;
    for (int s = 0; s < N; s++) {
        if (dist[s] != -1) continue; // 連結でないグラフも考慮している
        dist[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (auto w : G[v]) {
                if (dist[w] != -1) { // wは訪問済みなので整合性チェックをしてしまう
                    if (dist[v] == dist[w]) { // この条件は dist[v]%2 == dist[w]%2とも書ける
                        is_bipartite = false;
                    }
                } else { // wは未訪問
                    dist[w] = dist[v] + 1;
                    que.push(w);
                }
            }
        }
    }
    cout << (is_bipartite ? "Yes" : "No") << endl;
    return 0;
}

// 与えられたグラフが二部グラフであるならば，始点を黒色に塗ったとき，dist[v]%2 == 0ならばvは黒で，dist[v]%2 == 1ならばvは白となっていて，隣接頂点間で色が違うようになっていなければならない．vとその隣接頂点wに対してdist[v]とdist[w]の偶奇が異なっていることを確認すれば良い．更に考えると，dist[v]とdist[w]の差は1以下であるのでdist[v] != dist[w]とも言える