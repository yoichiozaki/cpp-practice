#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C; cin >> R >> C;
    int sy, sx; cin >> sy >> sx;
    int gy, gx; cin >> gy >> gx;
    char c[100][100];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> c[i][j];
        }
    }
    int dist[100][100];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dist[i][j] = 1000000007;
        }
    }
    queue<pair<int, int>> Q;
    Q.push(make_pair(sy, sx));
    dist[sy][sx] = 0;

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        int dc[4] = {1, 0, -1, 0};
        int dr[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (c[nr][nc] != '.' || dist[nr][nc] != 1000000007) {
                continue;
            }
            Q.push(make_pair(nr, nc));
            dist[nr][nc] = dist[cr][cc] + 1;
        }
    }
    cout << dist[gy][gx] << endl;
}