#include <bits/stdc++.h>

using namespace std;

int field[2010][2010] = {0};
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};

void dfs(int x, int y) {
    if (field[x][y] == 0) {
        return;
    } else {
        field[x][y] = 0;
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || 2010 <= nx || ny < 0 || 2010 <= ny) continue;
            if (field[nx][ny] == 0) continue;
            dfs(nx, ny);
        }
    }
}

int solve() {
    int cnt = 0;
    for (int x = 0; x < 2010; x++) {
        for (int y = 0; y < 2010; y++) {
            if (field[x][y] == 1) {
                dfs(x, y);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        X[i] += 1005, Y[i] += 1005;
        field[X[i]][Y[i]] = 1;
    }
    cout << solve() << endl;
    return 0;
}