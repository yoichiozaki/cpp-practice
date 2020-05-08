#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

using Graph = vector<vector<Edge>>;

int n;
vector<int> depth;

void DFS(const Graph &G, int v, int parent, int d)
{
    depth[v] = d;
    for (auto u : G[v])
    {
        if (u.to == parent)
            continue;
        DFS(G, u.to, v, d + u.weight);
    }
}

int main()
{
    scanf("%d", &n);
    Graph G(n);
    depth.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int s, t, w;
        scanf("%d %d %d", &s, &t, &w);
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    for (int root = 0; root < n; root++)
    {
        for (int i = 0; i < n; i++)
            depth[i] = 0;
        DFS(G, root, -1, 0);
        printf("%d\n", *max_element(depth.begin(), depth.end()));
    }
    return 0;
}