#include <bits/stdc++.h>

using namespace std;

int dh[4] = {0, 1, 0, -1};
int dw[4] = {1, 0, -1, 0};

string dfs(int h, int w, int current_length, int length, vector<vector<int>> has_visited, vector<string> field)
{
    if (current_length == length)
    {
        return to_string(h + 1) + " " + to_string(w + 1) + "\n";
    }

    has_visited[h][w] = 1;
    int H = field.size();
    int W = field[0].size();

    for (int dir = 0; dir < 4; dir++)
    {
        int nh = h + dh[dir];
        int nw = w + dw[dir];
        if (0 <= nh && nh < H && 0 <= nw && nw < W)
        {
            if (!has_visited[nh][nw] && field[nh][nw] == '#')
            {
                string ret = dfs(nh, nw, current_length + 1, length, has_visited, field);
                if (ret != "")
                {
                    return ret + to_string(h + 1) + " " + to_string(w + 1) + "\n";
                }
            }
        }
    }

    has_visited[h][w] = 0;
    return "";
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    vector<vector<int>> has_visited(H, vector<int>(W, 0));
    for (int h = 0; h < H; h++)
    {
        cin >> field[h];
    }

    int length = 0;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (field[h][w] == '#')
            {
                length += 1;
            }
        }
    }

    cout << length << endl;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (field[h][w] == '#')
            {
                string ret = dfs(h, w, 1, length, has_visited, field);
                if (ret != "")
                {
                    cout << ret.c_str();
                    return 0;
                }
            }
        }
    }
    return 0;
}