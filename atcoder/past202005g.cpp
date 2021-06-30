#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    // (x, y) => (x + 250) * 500 + (y + 250)
    vector<bool> has_visited(500 * 500, false);
    vector<int> dist(500 * 500, -1);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        has_visited[(x + 250) * 500 + (y + 250)] = true;
    }

    vector<int> dx = {1, 0, -1, 1, -1, 0};
    vector<int> dy = {1, 1, 1, 0, 0, -1};

    queue<int> Q;
    Q.emplace(250 * 500 + 250);
    has_visited[250 * 500 + 250] = true;
    dist[250 * 500 + 250] = 0;

    while (!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        int cur_x = current / 500;
        int cur_y = current % 500;

        for (int dir = 0; dir < 6; dir++)
        {
            int next_x = cur_x + dx[dir];
            int next_y = cur_y + dy[dir];
            if (next_x < 0 || 500 <= next_x || next_y < 0 || 500 <= next_y || has_visited[next_x * 500 + next_y])
                continue;
            dist[next_x * 500 + next_y] = dist[cur_x * 500 + cur_y] + 1;
            has_visited[next_x * 500 + next_y] = true;
            Q.emplace(next_x * 500 + next_y);
        }
    }

    cout << dist[(X + 250) * 500 + Y + 250] << endl;
    return 0;
}