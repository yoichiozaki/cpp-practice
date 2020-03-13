#include <bits/stdc++.h>
using namespace std;

vector<int> to[2505];
vector<int> ot[2505];
bool reachable_from_1[2505];
bool reachable_to_N[2505];
bool ok[2505];

const int INF = 1001001001;

void dfs(int v) {
    if (reachable_from_1[v]) return;
    reachable_from_1[v] = true;
    for (int u : to[v]) {
        dfs(u);
    }
}

void sfd(int v) {
    if (reachable_to_N[v]) return;
    reachable_to_N[v] = true;
    for (int u : ot[v]) {
        sfd(u);
    }
}

int main() {
    int n, m, p; cin >> n >> m >> p;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c -= p; c = -c;
        edges.emplace_back(a, b, c);
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    dfs(0);
    sfd(n-1);
    for (int i = 0; i < n; i++) {
        ok[i] = reachable_from_1[i] & reachable_to_N[i];
    }
    { // bellman-ford法
        vector<int> dist(n, INF);
        dist[0] = 0;
        bool update = true;
        int step = 0;
        while (update) {
            update = false;
            for (int i = 0; i < m; i++) {
                int a, b, c;
                tie(a, b, c) = edges[i];
                if (!ok[a]) continue;
                if (!ok[b]) continue;
                int newD = dist[a] + c;
                if (newD < dist[b]) {
                    dist[b] = newD;
                    update = true;
                }
            }
            step++;
            if (n < step) {
                cout << -1 << endl;
                return 0;
            }
        }
        int ans = -dist[n-1];
        ans = max(0, ans);
        cout << ans << endl;
    }
    return 0;
}