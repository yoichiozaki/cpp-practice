#include <bits/stdc++.h>
using namespace std;

// クラスカル法
// 1. 辺を重みの昇順にソート
// 2. MSTを構成する辺の集合Kを空集合にリセット
// 3. 辺を1つずつ取り出しながら|K|が|V|-1になるまでKに加えることで閉路が発生しないような辺をKに加える
// 「閉路を作らないように」というところでUnion-find木が使える

#define MAX 10000
#define INF (1 << 29)

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

class Edge {
public:
    int source, target, cost;
    Edge(int source = 0, int target = 0, int cost = 0): source(source), target(target), cost(cost) {}
    bool operator < (const Edge &e) const {
        return cost < e.cost;
    }
    // void print() {
    //     cout << "[" << source << "]--" << cost << "-->[" << target << "]" << endl;
    // }
};

// vector<Edge> MST(0);

int kruskal(int N, vector<Edge> edges) {
    int total_cost = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds = DisjointSet(N+1);
    for (int i = 0; i < N; i++) {
        ds.make_set(i);
    }
    int source, target;
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (!ds.same(e.source, e.target)) {
            // MST.push_back(e);
            total_cost += e.cost;
            ds.unite(e.source, e.target);
        }
    }
    return total_cost;
}

int main() {
    int N, M, cost;
    int source, target;
    cin >> N >> M;
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        cin >> source >> target >> cost;
        edges.push_back(Edge(source, target, cost));
    }
    cout << kruskal(N, edges) << endl;
    // for (auto iter = MST.begin(); iter != MST.end(); iter++) {
    //     (*iter).print();
    // }
    return 0;
}