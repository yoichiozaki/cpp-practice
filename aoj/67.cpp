#include <bits/stdc++.h>
using namespace std;

char field[12][12];
const int dh[4] = {0, 1, 0, -1};
const int dw[4] = {1, 0, -1, 0};

void dfs(int h, int w)
{
    field[h][w] = '0';
    for (int dir = 0; dir < 4; dir++)
    {
        int nh = h + dh[dir];
        int nw = w + dw[dir];

        if (nh < 0 || 12 <= nh || nw < 0 || 12 <= nw)
            continue;
        if (field[nh][nw] == '0')
            continue;

        dfs(nh, nw);
    }
}

int main()
{
    while (scanf("%s", field[0]) != EOF)
    {
        int cnt = 0;
        for (int i = 1; i < 12; i++)
            scanf("%s", field[i]);
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                if (field[i][j] == '1')
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}