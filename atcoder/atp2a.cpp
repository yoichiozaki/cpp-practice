#include <bits/stdc++.h>
using namespace std;

int H, W;
char maze[55][55];
int dist[55][55];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1000000007;

int main() {
    cin >> H >> W;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> maze[i][j];
        }
    }

    queue<pair<int, int>> Q;
    Q.push(make_pair(sx, sy));
    dist[sx][sy] = 0;

    while (!Q.empty()) {
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (maze[nx][ny] != '.' || dist[nx][ny] != INF) continue;
            Q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[cx][cy] + 1;
        }
    }

    cout << dist[gx][gy] << endl;
}