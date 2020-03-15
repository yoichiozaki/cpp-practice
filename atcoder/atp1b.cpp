#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind(int size) : parent(size) {
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind tree(N);

    for (int i = 0; i < Q; i++) {
        int p, x, y; cin >> p >> x >> y;

        if (p == 0) {
            tree.unite(x, y);
        } else {
            if (tree.same(x, y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}