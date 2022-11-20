#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> parent(N, 0);
    vector<vector<int>> CC(N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        CC[parent[i]].push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            u--, v--;
            if (parent[u] != parent[v]) {
                if (CC[parent[u]].size() < CC[parent[v]].size()) {
                    swap(u, v);
                }
                int up = parent[u], vp = parent[v];
                for (int x: CC[vp]) {
                    CC[up].push_back(x);
                    parent[x] = up;
                }
                CC[vp].clear();
            }
        } else {
            int u; cin >> u;
            u--;
            auto& comp = CC[parent[u]];
            sort(comp.begin(), comp.end());
            for (int i = 0; i < comp.size(); i++) {
                cout << comp[i] + 1 << " \n"[i + 1 == comp.size()];
            }
        }
    }
    return 0;
}