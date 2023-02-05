#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> has_visited(N);
    int S = 0;
    for (int i = 0; i < N; i++) {
        if (!has_visited[i]) {
            S++;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (int v : G[u]) {
                    if (!has_visited[v]) {
                        has_visited[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
    }
    cout << M - N + S << endl;
    return 0;
}