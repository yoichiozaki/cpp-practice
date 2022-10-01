#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int target;
vector<int> path;

bool dfs(const Graph &G, int v, int parent) {
    path.push_back(parent);
    if (v == target) {
        return true;
    }
    bool found = false;
    for (auto neighbor: G[v]) {
        if (neighbor == parent) continue;
        found = found | dfs(G, neighbor, v);
    }
    if (!found) path.pop_back();
    return found;
}

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    X--, Y--;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    path.assign(0, 0);
    target = Y;
    dfs(G, X, -1);
    cout << X + 1 << " ";
    for (int i = 2; i < path.size(); i++) {
        cout << path[i] + 1 << " ";
    }
    cout << target + 1 << endl;
    return 0;
}