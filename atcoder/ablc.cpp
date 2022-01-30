#include <bits/stdc++.h>

using namespace std;

// 無向グラフなので連結成分を数えて全部が連結するように橋をかければいい

struct UnionFind
{
    vector<int> par;

    UnionFind(int N) : par(N)
    {
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf = UnionFind(N);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A--, B--;
        uf.unite(A, B);
    }
    set<int> s;
    for (int i = 0; i < N; i++)
        s.insert(uf.root(i));
    cout << s.size() - 1 << endl;
    return 0;
}