#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    vector<int> parents;
    UnionFind() {}
    UnionFind(int size) : parents(size, -1) {}
    int find(int x)
    {
        if (parents[x] < 0)
            return x;
        return parents[x] = find(parents[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (parents[x] > parents[y])
            swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        return true;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    int size(int x)
    {
        return -parents[find(x)];
    }
};

struct Edge
{
    long long u;
    long long v;
    long long cost;
};
bool comp_edge(const Edge &lhs, const Edge &rhs)
{
    return lhs.cost < rhs.cost;
}

struct Kruskal
{
    UnionFind tree;
    long long sum;
    vector<Edge> graph;
    int V;
    Kruskal(const vector<Edge> &graph_, int V_) : graph(graph_), V(V_)
    {
        init();
    }
    void init()
    {
        sort(graph.begin(), graph.end(), comp_edge);
        tree = UnionFind(V);
        sum = 0;
        for (auto edge : graph)
        {
            if (!tree.unite(edge.u, edge.v) && edge.cost >= 0)
                sum += edge.cost;
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> graph(E);
    for (int i = 0; i < E; i++)
    {
        long long u, v, cost;
        cin >> u >> v >> cost;
        u -= 1;
        v -= 1;
        Edge e = {u, v, cost};
        graph[i] = e;
    }
    Kruskal krs(graph, V);
    cout << krs.sum << endl;
    return 0;
}