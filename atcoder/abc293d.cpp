#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    vector<int> degree(N, 0);
    for (int i = 0; i < M; i++) {
        int A, C; char B, D;
        cin >> A >> B >> C >> D;
        A--, C--;
        G[A].push_back(C);
        G[C].push_back(A);
        degree[A]++, degree[C]++;
    }
    int X = 0, Y = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        else {
            queue<int> Q;
            visited[i] = true;
            Q.push(i);
            bool is_cycle = true;
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                if (degree[v] != 2) is_cycle = false;
                for (int neigh : G[v]) {
                    if (visited[neigh]) continue;
                    else {
                        Q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }
            if (is_cycle) X++;
            else Y++;
        }
    }
    cout << X << " " << Y << endl;
    return 0;
}