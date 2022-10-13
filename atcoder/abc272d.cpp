#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<int> dist;
queue<int> suspended;

void BFS(const Graph &G, int v) {
    dist[v] = 0;
    suspended.push(v);
    while (!suspended.empty()) {
        int u = suspended.front(); suspended.pop();
        for (auto w: G[u]) {
            if (dist[w] != -1) continue;
            else {
                dist[w] = dist[u] + 1;
                suspended.push(w);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    Graph G(N * N);

    unordered_map<int, int> int_sqrt;
    for (int i = 0; i * i <= M; i++) {
        int_sqrt.insert({i * i, i});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int node = i * N + j;
            for (const auto& [m, _]: int_sqrt) {
                if (int_sqrt.find(M - m) != int_sqrt.end()) {
                    int nexti, nextj;
                    
                    nexti = i + int_sqrt[m];
                    nextj = j + int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }
                    
                    nexti = i - int_sqrt[m];
                    nextj = j + int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }

                    nexti = i + int_sqrt[m];
                    nextj = j - int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }

                    nexti = i - int_sqrt[m];
                    nextj = j - int_sqrt[M - m];
                    if ((0 <= nexti && nexti < N) && (0 <= nextj && nextj < N)) {
                        G[node].push_back(nexti * N + nextj);
                    }
                }
            }
        }
    }

    dist.assign(N * N, -1);

    BFS(G, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cout << dist[i * N + j] << " ";
        }
        cout << dist[i * N + (N - 1)] << endl;
    }

    return 0;
}

/*
- レベル的には緑問題らしい...
- まず、マス (i, j) を頂点とするグラフの最短経路問題に帰着できるという発想が必要
- sqrt(M) の距離にあるマスに移動できる、という条件から枝の生え方が決まる
- グラフを作れればあとは重みなしグラフなので最短経路問題は BFS で解ける
- 要するにグラフの構築が肝で sqrt(M) の距離にあるマスをどうやって（効率的に）列挙するか
- x^2 + y^2 == M となる整数 x, y を効率的に求める。0, 1, ..., M までの整数が平方数か・平方数なら根はいくつかを先に求めておくと、「相方が存在するか」という 2-sum に帰着される。
- 書いてて、今、なるほどとなった。そうか、x^2 + y^2 == M という条件式がもう 2-sum じゃないか...そういうことか...
*/