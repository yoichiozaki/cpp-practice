#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<bool> has_visited;
void DFS(const Graph &G, int v, int depth)
{
    if (2 < depth)
        return;
    has_visited[v] = true;

    for (auto w : G[v])
    {
        if (has_visited[w])
            continue;
        DFS(G, w, depth + 1);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    has_visited.assign(N, false);
    DFS(G, 0, 0);
    if (has_visited[N - 1])
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}