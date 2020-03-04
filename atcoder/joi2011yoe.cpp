#include <bits/stdc++.h>
using namespace std;

int H, W, N;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
char Map[1000][1000];

int bfs(pair<int, int> start, pair<int, int> goal) {
    vector<vector<int>> dist(H, vector<int>(W, 1e8));
    queue<pair<int, int>> Q;
    Q.push(start);
    dist[start.first][start.second] = 0;
    while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        int i = p.first;
        int j = p.second;
        if (pair<int, int>(i, j) == goal) {
            return dist[i][j];
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || H <= ni) { continue; }
            if (nj < 0 || W <= nj) { continue; }
            if (Map[ni][nj] == 'X') { continue; }
            if (dist[i][j] + 1 < dist[ni][nj]) {
                dist[ni][nj] = dist[i][j] + 1;
                Q.push(pair<int, int>(ni, nj));
            }
        }
    }
    return -1;
}

int main() {
    cin >> H >> W >> N;
    vector<pair<int, int>> points(N+1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'S') {
                Map[i][j] = '0';
            }
            if ('0' <= Map[i][j]  && Map[i][j]<= '9') {
                int c = Map[i][j] - '0';
                points[c] = pair<int, int>(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += bfs(points[i], points[i+1]); // チーズがi個の地点 -> チーズがi+1個の地点 にかかる移動時間
    }
    cout << ans << endl;
}