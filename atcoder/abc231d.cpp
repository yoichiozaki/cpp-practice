#include <bits/stdc++.h>

using namespace std;

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
    vector<int> D(N);
    UnionFind uf(N);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;
        if (uf.same(A, B))
        {
            cout << "No" << endl;
            return 0;
        }
        uf.unite(A, B);
        D[A] += 1;
        D[B] += 1;
    }
    for (int i = 0; i < N; i++)
        if (D[i] > 2)
        {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
    return 0;
}