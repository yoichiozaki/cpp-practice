#include <bits/stdc++.h>
using namespace std;

// REF: https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396

// Union-Find木とは
// - グループ分けを木構造で管理するデータ構造
// - 同じグループに所属していることを，同じ木に属しているとして表現する
// - 要素xと要素yが同一グループに属するかを高速に判定することができる

struct UnionFind {
    vector<int> parent; // parent[i] = iの親

    UnionFind(int size) : parent(size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int root(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        int xroot = root(x);
        int yroot = root(y);
        if (xroot == yroot) return;
        parent[xroot] = yroot; // xの根をyの根に付ける
    }

    bool same(int x, int y) {
        int xroot = root(x);
        int yroot = root(y);
        return xroot == yroot;
    }
};

int main() {
    return 0;
}