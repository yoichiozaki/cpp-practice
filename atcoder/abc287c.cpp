#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (M != N - 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (G[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    vector<bool> has_visited(N, false);
    queue<int> Q;
    has_visited[0] = true;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (!has_visited[v]) {
                has_visited[v] = true;
                Q.push(v);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (!has_visited[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}