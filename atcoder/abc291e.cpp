#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> Graph(N);
    vector<int> indegree(N, 0);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        Graph[x].push_back(y);
        indegree[y]++;
    }
    vector<int> ans(N);
    queue<int> Q;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        if (Q.size() != 1) {
            cout << "No" << endl;
            return 0;
        }
        int node = Q.front(); Q.pop();
        ans[node] = cnt;
        cnt += 1;
        for (auto neighbor: Graph[node]) {
            indegree[neighbor] -= 1;
            if (indegree[neighbor] == 0) {
                Q.push(neighbor);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}