#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int N, M, s, t; cin >> N >> M >> s >> t;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    vector<int> dist(N, -1); // 全頂点を未訪問として初期化
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto w : G[v]) {
            if (dist[w] != -1) continue;
            dist[w] = dist[v] + 1;
            que.push(w);
        }
    }

    if (dist[t] != -1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}