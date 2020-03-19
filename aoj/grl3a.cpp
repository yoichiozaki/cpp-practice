#include <bits/stdc++.h>
using namespace std;

// DFS木において．頂点uが結節点 <=> 頂点uとその子孫-uの親より上の先祖間に枝が生えていない

#define MAX 100000

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev) {
    prenum[current] = lowest[current] = timer;
    timer++;

    visited[current] = true;

    int next;

    for (int i = 0; i < G[current].size(); i++) {
        next = G[current][i];
        if (!visited[next]) {
            parent[next] = current;
            dfs(next, current);
            lowest[current] = min(lowest[current], lowest[next]);
        } else if (next != prev) { // backedgeあり
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void articulation_points() {
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    timer = 1;
    dfs(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < N; i++) {
        int p = parent[i];
        if (p == 0) np++;
        else if (prenum[p] <= lowest[i]) ap.insert(p);
    }
    if (1 < np) ap.insert(0); // DFS木の根を親とする頂点が2個以上あるので根は結節点
    for (auto iter = ap.begin(); iter != ap.end(); iter++) {
        cout << *iter << endl;
    }
}

int main() {
    int m;
    cin >> N >> m;
    for (int i = 0; i < m; i++) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    articulation_points();
    return 0;
}