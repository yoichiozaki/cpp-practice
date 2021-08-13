#include <bits/stdc++.h>

using namespace std;

vector<string> rotate_clockwise(vector<string> stamp)
{
    int h = stamp.size();
    int w = stamp[0].size();
    vector<string> rotated(w, string(h, '#'));
    for (int ih = 0; ih < h; ih++)
    {
        for (int jw = 0; jw < w; jw++)
        {
            rotated[jw][h - ih - 1] = stamp[ih][jw];
        }
    }
    return rotated;
}

const int inf = INT_MAX / 2;

vector<string> trim(vector<string> stamp, int H, int W)
{
    int min_h = inf;
    int max_h = -1;
    int min_w = inf;
    int max_w = -1;

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (stamp[h][w] == '#')
            {
                min_h = min(min_h, h);
                max_h = max(max_h, h);
                min_w = min(min_w, w);
                max_w = max(max_w, w);
            }
        }
    }

    vector<string> trimmed;
    for (int h = min_h; h < max_h + 1; h++)
    {
        string row = "";
        for (int w = min_w; w < max_w + 1; w++)
            row += stamp[h][w];

        trimmed.push_back(row);
    }

    return trimmed;
}

bool check(vector<string> field, vector<string> stamp)
{
    int H = field.size();
    int W = field[0].size();
    int h = stamp.size();
    int w = stamp[0].size();

    if (H < h || W < w)
        return false; // too big

    for (int ih = 0; ih < H - h + 1; ih++)
    {
        for (int jw = 0; jw < W - w + 1; jw++)
        {
            bool ok = true;

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (field[ih + i][jw + j] == '#' && stamp[i][j] == '#')
                        return false;
                }
            }

            if (ok)
                return true;
        }
    }
    return false;
}

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    for (int h = 0; h < H; h++)
    {
        cin >> field[h];
    }

    vector<string> stamp(H);
    for (int h = 0; h < H; h++)
    {
        cin >> stamp[h];
    }

    stamp = trim(stamp, H, W);

    for (int dir = 0; dir < 4; dir++)
    {
        if (check(field, stamp))
        {
            cout << "Yes" << endl;
            return 0;
        }

        stamp = rotate_clockwise(stamp);
    }

    cout << "No" << endl;
    return 0;
}