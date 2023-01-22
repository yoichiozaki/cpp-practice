#include <bits/stdc++.h>

using namespace std;

using Graph = unordered_map<string, vector<string>>;
unordered_map<string, bool> has_visited;
unordered_map<string, bool> memo;

bool DFS(Graph &G, string v) {
    memo[v] = true;
    if (has_visited[v]) return true;
    bool has_loop = false;
    has_visited[v] = true;
    for (auto u : G[v]) {
        if (DFS(G, u)) has_loop = true;
    }
    has_visited[v] = false;
    return has_loop;
}

int main() {
    int N; cin >> N;
    Graph G;
    for (int i = 0; i < N; i++) {
        string S, T; cin >> S >> T;
        if (!G.count(S)) G[S] = {T};
        else G[S].push_back(T);
    }

    for (const auto kv : G) {
        if (memo[kv.first]) continue;
        if (DFS(G, kv.first)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}