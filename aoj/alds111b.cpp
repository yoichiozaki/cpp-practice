#include <bits/stdc++.h>
using namespace std;

// d[v]: 行きがけ順
// f[v]: 帰りがけ順

#define N 100
#define WHITE 0 // 未訪問
#define GRAY 1 // 行きがけ順の意味で訪問済み
#define BLACK 2 // 帰りがけ順の意味で訪問済み

int n; // グラフサイズ
int G[N][N]; // 隣接行列形式でのグラフ
int status[N]; // 各頂点の訪問状態を保持する配列
int d[N]; // 行きがけ順のタイムスタンプ
int f[N]; // 帰りがけ順のタイムスタンプ
int ticktock = 0;

// 頂点uからDFS
void DFS(int u) {
    status[u] = GRAY; // 行きがけ
    d[u] = ++ticktock;

    for (int v = 0; v < n; v++) {
        if (G[u][v] == 0) continue; // 頂点vが頂点uの隣接頂点でないのでスルー
        if (status[v] == WHITE) { // 頂点vが未訪問なので訪問していく
            DFS(v);
        }
    }

    status[u] = BLACK; // 帰りがけ
    f[u] = ++ticktock;
}

int main() {
    cin >> n;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        status[i] = WHITE;
        d[i] = 0;
        f[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v; v--;
            G[u][v] = 1;
        }
    }

    // グラフは全頂点が連結しているとは限らん
    for (int u = 0; u < n; u++) {
        if (status[u] == WHITE) {
            DFS(u);
        }
    }

    for (int u = 0; u < n; u++) {
        cout << u+1 << " " << d[u] << " " << f[u] << endl;
    }
    return 0;
}