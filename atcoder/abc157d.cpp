#include <bits/stdc++.h>
using namespace std;

// 人を頂点とし，友達関係を辺とするグラフにおいて，連結成分のサイズから友達||ブロック関係を除く

struct UnionFind
{
    vector<int> d;
    UnionFind(int n) : d(n, -1) {}
    int root(int x)
    {
        if (d[x] < 0)
            return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (d[x] > d[y])
            swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -d[root(x)]; }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    UnionFind graph(N);
    vector<int> friendship(N, 0);
    vector<vector<int>> block(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        friendship[a]++;
        friendship[b]++;
        graph.unite(a, b);
    }
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        block[a].push_back(b);
        block[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        int ans = graph.size(i) - friendship[i] - 1;
        for (int u : block[i])
        {
            if (graph.same(i, u))
                ans--;
        }
        printf("%d%c", ans, i == N - 1 ? '\n' : ' ');
    }
    return 0;
}