#include <bits/stdc++.h>
using namespace std;

// DFSによるトポロジカルソート

const int MAX = 100000;

vector<int> G[MAX]; // グラフの隣接リスト表現
list<int> out; // トポロジカルソートされた結果を格納
bool V[MAX]; // V[i]: 頂点iがソート済みならtrue
int N; // グラフの頂点数

// 頂点uからのDFS
void DFS(int u) {
    V[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!V[v]) {
            DFS(v);
        }
    }
    out.push_front(u);
}

int main() {
    int s, t, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) V[i] = false;
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    for (int i = 0; i < N; i++) {
        if (!V[i]) {
            DFS(i);
        }
    }

    for (auto iter = out.begin(); iter != out.end(); iter++) {
        cout << (*iter) << endl;
    }
    return 0;
}