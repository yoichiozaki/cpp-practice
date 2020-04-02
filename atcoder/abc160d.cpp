#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main() {
    int n, x, y; cin >> n >> x >> y;
    x--; y--;
    vector<int> ans(n, 0);
    for (int sv = 0; sv < n; sv++) {
        vector<int> dist(n, INF);
        queue<int> q;
        auto push = [&](int v, int d) {
            if (dist[v] != INF) return;
            dist[v] = d;
            q.push(v);
        };
        push(sv, 0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int d = dist[v];
            if (0 <= v - 1) push(v - 1, d + 1);
            if (v + 1 < n) push(v + 1, d + 1);
            if (v == x) push(y, d + 1);
            if (v == y) push(x, d + 1);
        }
        for (int i = 0; i < n; i++) {
            ans[dist[i]]++;
        }
    }
    for (int i = 0; i < n; i++) ans[i] /= 2;
    for (int i = 1; i <= n-1; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}