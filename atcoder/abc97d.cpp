#include <bits/stdc++.h>
using namespace std;

// 互いに交換し合える数字たちを1つのグループにまとめる
// そのグループ内に存在する数字たちの中に，数列のi番目にある数字と数字iが同居していれば，必ず数字iは数列のi番目に到達することができる
// 数字をまとめる・同一グループ判定する => union-find tree

struct UnionFind {
    vector<int> parents;

    UnionFind(int size) : parents(size) {
        for (int i = 0; i < size; i++) parents[i] = i;
    }

    int root(int x) {
        if (parents[x] == x) {
            return x;
        }
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

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    UnionFind tree(N);

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        tree.unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (tree.same(i, P[i]-1)) { // 数列のi番目の数字と数字iが可換なグループにいるなら必ず数列のi番目に数字iを置くことができる
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}