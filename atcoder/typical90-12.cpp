#include <bits/stdc++.h>

using namespace std;

// 盤面の位置を頂点としてUnionFind木で管理

struct UnionFind
{
    vector<int> parents;
    void init(int size)
    {
        parents.resize(size, -1);
    }
    int root(int node)
    {
        if (parents[node] == -1)
            return node;
        parents[node] = root(parents[node]);
        return parents[node];
    }
    void unite(int u, int v)
    {
        u = root(u);
        v = root(v);
        if (u == v)
            return;
        parents[u] = v;
    }
    bool same(int u, int v)
    {
        if (root(u) == root(v))
            return true;
        return false;
    }
};

int H, W, Q;
UnionFind T;
bool board[2010][2010];

void Q1(int h, int w)
{
    int dh[4] = {-1, 0, 1, 0};
    int dw[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (!board[nh][nw])
            continue;
        T.unite((h - 1) * W + (w - 1), (nh - 1) * W + (nw - 1));
    }
    board[h][w] = true;
}

bool Q2(int h1, int w1, int h2, int w2)
{
    if (!board[h1][w1] || !board[h2][w2])
        return false;
    if (T.same((h1 - 1) * W + (w1 - 1), (h2 - 1) * W + (w2 - 1)))
        return true;
    return false;
}

int main()
{
    cin >> H >> W >> Q;
    T.init(H * W);
    for (int i = 0; i < Q; i++)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            int h, w;
            cin >> h >> w;
            Q1(h, w);
        }
        else
        {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            if (Q2(h1, w1, h2, w2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}