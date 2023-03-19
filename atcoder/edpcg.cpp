#include <bits/stdc++.h>

using namespace std;

int pathlen[100010] = {};
int visited[100010] = {};
vector<vector<int>> G;

int rec(int node) {
    if (visited[node]) return pathlen[node];

    visited[node] = 1;
    int len = 0;
    for (auto neighbor : G[node]) {
        len = max(len, rec(neighbor) + 1);
    }
    pathlen[node] = len;
    return len;
}

int main() {
    int N, M; cin >> N >> M;
    G = vector<vector<int>>(N + 1);
    for (int i = 1; i <= M; i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
    }
    int ans = 0;
    for (int node = 1; node <= N; node++) {
        ans = max(ans, rec(node));
    }
    cout << ans << endl;
    return 0;
}