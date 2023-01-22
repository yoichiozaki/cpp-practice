#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
vector<bool> has_visited;
stack<int> suspended;

void DFS(const Graph &G, int v) {
    has_visited[v] = true;
    suspended.push(v);
    while (!suspended.empty()) {
        int u = suspended.top(); suspended.pop();
        has_visited[u] = true;
        for (auto w: G[u]) {
            if (has_visited[w]) continue;
            else {
                has_visited[u] = true;
                suspended.push(w);
            }
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0;
    has_visited.assign(N, false);
    for (int v = 0; v < N; v++) {
        if (has_visited[v]) continue;
        DFS(G, v);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}