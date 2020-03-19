#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet() {}

    DisjointSet(int size) {
        rank.resize(size, 0);
        parent.resize(size, 0);
        for (int i = 0; i < size; i++) {
            make_set(i);
        }
    }

    void make_set(int x) {
        parent[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y) {
        return find_set(x) == find_set(y);
    }

    void unite(int x, int y) {
        link(find_set(x), find_set(y));
    }

    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int find_set(int x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }

};

int main() {
    int n, a, b, q;
    int t;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    for (int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        if (t == 0) ds.unite(a, b);
        else if (t == 1) {
            if (ds.same(a, b)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}