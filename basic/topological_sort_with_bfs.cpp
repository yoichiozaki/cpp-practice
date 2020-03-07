#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    vector<int> out_degree(N, 0);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        G[b].push_back(a); // 逆向きで辺を張る
        out_degree[a]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (out_degree[i] == 0) {
            que.push(i); // シンクたちをqueに突っ込む
        }
    }

    vector<int> order;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        order.push_back(v);
        for (auto w : G[v]) {
            out_degree[w]--;
            if (out_degree[w] == 0) {
                que.push(w);
            }
        }
    }
    reverse(order.begin(), order.end());
    for (auto v : order) {
        cout << v << endl;
    }

    return 0;
}

// 外向きの辺が生えていない頂点とその頂点めがけた辺をグラフから削除することを頂点がなくなるまで繰り返す