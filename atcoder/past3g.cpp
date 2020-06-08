#include <bits/stdc++.h>
using namespace std;

const int INF = 2100100100;
int R, C;
vector<vector<char>> maze; // 迷路の内容を保存する配列
vector<vector<int>> dist;  // 距離を記録しておく配列
int sx, sy, gx, gy;

int main()
{
    R = 420;
    C = 420;
    sx = 210, sy = 210;
    int N;
    cin >> N;
    cin >> gx >> gy;
    gx += 210;
    gy += 210;

    dist.assign(R, vector<int>(C, INF));  // 初期化
    maze.assign(R, vector<char>(C, '.')); // 初期化

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        x += 210;
        y += 210;
        maze[x][y] = '#';
    }

    // for (int i = 0; i < 420; i++)
    // {
    //     for (int j = 0; j < 420; j++)
    //         cout << maze[i][j];
    //     cout << endl;
    // }

    queue<pair<int, int>> que;
    que.emplace(make_pair(sx, sy)); // sから探索する
    dist[sx][sy] = 0;
    while (que.size() != 0)
    {                                     // キューの要素がなくなったら終了
        pair<int, int> now = que.front(); // 現在の状態
        que.pop();

        if (now.first == gx && now.second == gy)
        { // 目的地にたどり着いたので終了
            break;
        }

        int dy[6] = {0, 0, 1, -1, 1, 1};
        int dx[6] = {1, -1, 0, 0, 1, -1};
        for (int i = 0; i < 6; i++)
        {
            int ny = now.second + dy[i];
            int nx = now.first + dx[i];
            if (nx < 0 || R <= nx || ny < 0 || C <= ny)
                continue; // 迷路の外に出るならスルー
            if (maze[nx][ny] == '#')
                continue; // 障害物があればスルー
            if (dist[nx][ny] != INF)
                continue; //探索済みならスルー
            que.push(make_pair(nx, ny));
            dist[nx][ny] = dist[now.first][now.second] + 1;
        }
    }
    cout << (dist[gx][gy] == INF ? -1 : dist[gx][gy]) << endl;
    return 0;
}