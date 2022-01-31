#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dh[4] = {1, 0, -1, 0};
    int dw[4] = {0, 1, 0, -1};
    int H, W;
    cin >> H >> W;
    vector<vector<int>> canvas(H + 10, vector<int>(W + 10, 0));
    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            char c;
            cin >> c;
            if (c == '.')
                canvas[h][w] = 0;
            else if (c == '1')
                canvas[h][w] = 1;
            else if (c == '2')
                canvas[h][w] = 2;
            else if (c == '3')
                canvas[h][w] = 3;
            else if (c == '4')
                canvas[h][w] = 4;
            else if (c == '5')
                canvas[h][w] = 5;
        }
    }
    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (canvas[h][w] != 0)
            {
                continue;
            }
            bool painted[6] = {false, false, false, false, false, false};
            for (int dir = 0; dir < 4; dir++)
            {
                int nh = h + dh[dir];
                int nw = w + dw[dir];
                painted[canvas[nh][nw]] = true;
            }
            for (int i = 1; i <= 5; i++)
            {
                if (painted[i])
                    continue;
                canvas[h][w] = i;
                break;
            }
        }
    }
    for (int h = 1; h <= H; h++)
    {
        for (int w = 1; w <= W; w++)
        {
            cout << canvas[h][w];
        }
        cout << endl;
    }
    return 0;
}