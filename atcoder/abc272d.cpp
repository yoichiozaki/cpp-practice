#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<int> dist;
queue<int> suspended;

void BFS(const Graph &G, int v) {
    dist[v] = 0;
    suspended.push(v);
    while (!suspended.empty()) {
        int u = suspended.front(); suspended.pop();
        for (auto w: G[u]) {
            if (dist[w] != -1) continue;
            else {
                dist[w] = dist[u] + 1;
                suspended.push(w);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    Graph G(N * N);

    unordered_map<int, int> int_sqrt;
    for (int i = 0; i * i <= M; i++) {
        int_sqrt.insert({i * i, i});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int node = i * N + j;
            for (const auto& [m, _]: int_sqrt) {
                if (int_sqrt.find(M - m) != int_sqrt.end()) {
                    int nexti, nextj;
                    
                    nexti = i + int_sqrt[m];
                    nextj = j + int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }
                    
                    nexti = i - int_sqrt[m];
                    nextj = j + int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }

                    nexti = i + int_sqrt[m];
                    nextj = j - int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }

                    nexti = i - int_sqrt[m];
                    nextj = j - int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }
                }
            }
        }
    }

    dist.assign(N * N, -1);

    BFS(G, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cout << dist[i * N + j] << " ";
        }
        cout << dist[i * N + (N - 1)] << endl;
    }

    return 0;
}