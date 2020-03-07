#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> que;

    int count = 0;
    for (int s = 0; s < N; s++) {
        if (dist[s] != -1) continue;
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
        count += 1;
    }
    cout << count << endl;
    return 0;
}