#include <bits/stdc++.h>
using namespace std;

const int dh[4] = {1, 0, -1, 0};
const int dw[4] = {0, 1, 0, -1};

int H, W, X, Y;
vector<string> field;

bool has_visited[150][150];
stack<pair<int, int>> suspended;

int ans = 1;

void dfs(int h, int w, int dir)
{
    suspended.push((make_pair(h, w)));
    has_visited[h][w] = true;

    while (!suspended.empty())
    {
        int h_, w_;
        tie(h_, w_) = suspended.top();
        suspended.pop();
        has_visited[h_][w_] = true;
        int nh = h_ + dh[dir];
        int nw = w_ + dw[dir];
        if (0 <= nh && nh < H && 0 <= nw && nw < W && !has_visited[nh][nw] && field[nh][nw] == '.')
        {
            suspended.push(make_pair(nh, nw));
            ans += 1;
        }
    }
}

int main()
{
    cin >> H >> W >> X >> Y;
    X -= 1;
    Y -= 1;
    field.resize(H);
    for (int h = 0; h < H; h++)
    {
        cin >> field[h];
    }
    memset(has_visited, 0, sizeof(has_visited));

    for (int dir = 0; dir < 4; dir++)
    {
        dfs(X, Y, dir);
    }

    cout << ans << endl;
    return 0;
}