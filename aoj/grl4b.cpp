#include <bits/stdc++.h>
using namespace std;

// BFSによるトポロジカルソート

const int MAX = 100000;
const int INF = 1 << 29;

vector<int> G[MAX]; // グラフの隣接リスト表現
list<int> out; // トポロジカルソートされた結果を格納
bool V[MAX]; // V[i]: 頂点iがソート済みならtrue
int N; // グラフの頂点数
int indegree[MAX]; // indegree[i]: 頂点iに向かって生える辺の本数

// 頂点sからのBFS
void BFS(int s) {
    queue<int> q;
    q.push(s);
    V[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        out.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indegree[v]--; // 辺(u, v)を削除
            if (indegree[v] == 0 && !V[v]) {
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void topological_sort() {
    for (int i = 0; i < N; i++) {
        indegree[i] = 0;
    }

    for (int u = 0; u < N; u++) {
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indegree[v]++;
        }
    }

    for (int u = 0; u < N; u++) {
        if (indegree[u] == 0 && !V[u]) {
            BFS(u);
        }
    }

    for (auto iter = out.begin(); iter != out.end(); iter++) {
        cout << *iter << endl;
    }
}

int main() {
    int s, t, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) V[i] = false;
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }
    topological_sort();
    return 0;
}