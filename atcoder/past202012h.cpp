#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int r, c;
    cin >> r >> c;
    r--, c--;

    int left = 0, down = 1, right = 2, up = 3;
    vector<int> dh = {0, 1, 0, -1};
    vector<int> dw = {-1, 0, 1, 0};

    vector<string> ans(H, "");

    vector<string> field(H, "");
    for (int i = 0; i < H; i++)
    {
        cin >> field[i];
        for (int j = 0; j < W; j++)
        {
            if (field[i][j] == '#')
                ans[i] += "#";
            else
                ans[i] += "?";
        }
    }

    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));
    ans[r][c] = 'o';

    while (!Q.empty())
    {
        int h, w;
        tie(h, w) = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nh = h + dh[dir];
            int nw = w + dw[dir];
            if (0 <= nh && nh < H && 0 <= nw && nw < W && ans[nh][nw] == '?' && field[nh][nw] != '#')
            {
                switch (field[nh][nw])
                {
                case '#':
                    break;
                case '.':
                    Q.push(make_pair(nh, nw));
                    ans[nh][nw] = 'o';
                    break;
                case '^':
                    if (dir == down)
                    {
                        Q.push(make_pair(nh, nw));
                        ans[nh][nw] = 'o';
                    }
                    break;
                case 'v':
                    if (dir == up)
                    {
                        Q.push(make_pair(nh, nw));
                        ans[nh][nw] = 'o';
                    }
                    break;
                case '>':
                    if (dir == left)
                    {
                        Q.push(make_pair(nh, nw));
                        ans[nh][nw] = 'o';
                    }
                    break;
                case '<':
                    if (dir == right)
                    {
                        Q.push(make_pair(nh, nw));
                        ans[nh][nw] = 'o';
                    }
                    break;
                }
            }
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (ans[h][w] == '?')
                ans[h][w] = 'x';
        }
    }

    for (int h = 0; h < H; h++)
    {
        cout << ans[h].c_str() << endl;
    }

    return 0;
}