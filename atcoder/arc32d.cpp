#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parents;

    UnionFind(int size) : parents(size) {
        for (int i = 0; i < size; i++) parents[i] = i;
    }

    int root(int x) {
        if (parents[x] == x) return x;
        return parents[x] = root(parents[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parents[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M; cin >> N >> M;

    UnionFind tree(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree.unite(a, b);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!tree.same(0, i)) {
            tree.unite(0, i);
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}