#include <bits/stdc++.h>
using namespace std;

// プリム法
// 1. Gから任意の頂点rを選び，MSTのルートとしてTに追加
// 2. T == Vとなるまで以下を繰り返す
//     - Tに属する頂点とV-Tに属する頂点をつなぐ辺で重さが最小のものを選択しMSTに加える

// color[n]: 頂点rの状態を保持．
//     - WHITE = Tに属していない
//     - GRAY = Tに属している頂点の隣接頂点
//     - BLACK = Tに属している
// G[n][n]: グラフ
// d[n]: 頂点rを端点に持つような辺の内，Tに属する頂点とV-Tに属する頂点をつなぐような辺の最小の重さを記録
// p[n]: MSTにおける頂点rの親を記録

const int MAX = 100;
const int INF = 1 << 21;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n, G[MAX][MAX];

int prim() {
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for (int i = 0; i < n; i++) {
        d[i] = INF;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while (1) {
        minv = INF;
        u = -1;
        // Tに属する頂点とV-Tに属する頂点をつなぐ辺で重さが最小のものを選択
        for (int i = 0; i < n; i++) {
            if (d[i] < minv && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) break;
        color[u] = BLACK; // 頂点uはMSTに属する
        // uの隣接頂点をGRAYにして次のイテレーションに準備
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && G[u][v] != INF) {
                if (G[u][v] < d[v]) {
                    d[v] = G[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            sum += G[i][p[i]];
        }
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int e; cin >> e;
            G[i][j] = (e == -1 ? INF : e);
        }
    }
    cout << prim() << endl;
    return 0;
}