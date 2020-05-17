#include <bits/stdc++.h>
using namespace std;

// 重み付き無向グラフを与えられて最小全域木を計算する => クラスカル法
// クラスカル法
// 1. V = {}, E = {}
// 2. Gから任意の頂点を1つ選んでVに加える
// 3. while Vがグラフの頂点集合と一致するまで
//      E += Vに含まれる頂点uとVに含まれない頂点vを結ぶ辺のうち，重さ最小の辺
//      V += v
// 4. (V, E)が最小全域木

class DisjointSet
{
private:
    vector<int> p;

public:
    DisjointSet(int size) : p(size, -1) {}
    bool unite_set(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (x > y)
                swap(x, y);
            p[x] += p[y];
            p[y] = x;
        }
        return x != y;
    }

private:
    int root(int x)
    {
        return p[x] < 0 ? x : p[x] = root(p[x]);
    }
};

struct corridor
{
    int u, v;
    int len;
    corridor(int u, int v, int len) : u(u), v(v), len(len) {}

    bool operator<(const corridor &rhs) const
    {
        if (len != rhs.len)
            return len < rhs.len;
        if (u != rhs.u)
            return u < rhs.u;
        return v < rhs.v;
    }
};

int main()
{
    int N, M;
    while (cin >> N)
    {
        if (N == 0)
            break;
        cin >> M;
        vector<corridor> cors;
        for (int i = 0; i < M; i++)
        {
            int u, v, len;
            char comma;
            cin >> u >> comma >> v >> comma >> len;
            cors.push_back(corridor(u, v, len));
        }
        sort(cors.begin(), cors.end());
        DisjointSet ds(N);
        int vcount = 0;
        int corlen = 0;
        for (auto iter = cors.begin(); vcount < N - 1; iter++)
        {
            if (ds.unite_set(iter->u, iter->v))
            {
                corlen += iter->len;
                vcount++;
            }
        }
        cout << corlen / 100 - vcount << endl;
    }

    return 0;
}