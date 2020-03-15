#include <bits/stdc++.h>
using namespace std;

const int MAXH = 505;
const int MAXW = 505;

int H, W;
char maze[MAXH][MAXW];
bool visited[MAXH][MAXW];
int sx, sy, gx, gy;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (x < 0 || H <= x || y < 0 || W <= y || maze[x][y] == '#') return;
    if (visited[x][y]) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        dfs(x+dx[i], y+dy[i]);
    }
}

int main() {
    for (int i = 0; i < MAXH; i++) {
        for (int j = 0; j < MAXW; j++) {
            visited[i][j] = false;
        }
    }
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 's') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'g') {
                gx = i;
                gy = j;
            }
        }
    }

    dfs(sx, sy);

    cout << (visited[gx][gy] ? "Yes" : "No") << endl;
}