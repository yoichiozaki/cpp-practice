#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> dh = {0, 0, 1, -1};
    vector<int> dw = {1, -1, 0, 0};

    int N, M;
    cin >> N >> M;
    vector<string> field(N);
    for (int i = 0; i < N; i++)
        cin >> field[i];

    int ans = 0;
    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < M; w++)
        {
            if (field[h][w] == '#')
            {
                field[h][w] = '.';

                queue<pair<int, int>> Q;
                vector<vector<bool>> has_visited(N, vector<bool>(M));

                Q.push(make_pair(h, w));
                has_visited[h][w] = true;

                while (Q.size() != 0)
                {
                    auto pos = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int next_h = pos.first + dh[dir];
                        int next_w = pos.second + dw[dir];

                        if (next_h < 0 || N <= next_h || next_w < 0 || M <= next_w || field[next_h][next_w] == '#' || has_visited[next_h][next_w])
                            continue;
                        has_visited[next_h][next_w] = true;
                        Q.push(make_pair(next_h, next_w));
                    }
                }

                bool is_ok = true;
                for (int _h = 0; _h < N; _h++)
                {
                    for (int _w = 0; _w < M; _w++)
                    {
                        if (field[_h][_w] == '.' && !has_visited[_h][_w])
                            is_ok = false;
                    }
                }

                if (is_ok)
                    ans++;

                field[h][w] = '#';
            }
        }
    }
    cout << ans << endl;
    return 0;
}