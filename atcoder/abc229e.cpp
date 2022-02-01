#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    vector<long long> parents;
    UnionFind(long long N) : parents(N)
    {
        for (long long i = 0; i < N; i++)
            parents[i] = i;
    }
    long long root(long long x)
    {
        if (parents[x] == x)
            return x;
        return parents[x] = root(parents[x]);
    }
    void unite(long long x, long long y)
    {
        long long rx = root(x);
        long long ry = root(y);
        if (rx == ry)
            return;
        parents[rx] = ry;
    }
    bool same(long long x, long long y)
    {
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
};

int main()
{
    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> G(N);
    for (long long i = 0; i < M; i++)
    {
        long long a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }
    UnionFind uf(N);
    vector<long long> ans = {0};
    long long cc = 0;
    for (long long i = N - 1; 1 <= i; i--)
    {
        cc++;
        for (auto j : G[i])
        {
            if (!uf.same(i, j))
            {
                uf.unite(i, j);
                cc--;
            }
        }
        ans.push_back(cc);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << endl;
    return 0;
}