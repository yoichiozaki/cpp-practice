#include <bits/stdc++.h>
using namespace std;

const int dx[3] = {0, 1, 0}, dy[3] = {1, 1, 2};
int N;
int cloth[10][10];
int x[12], y[12], type[12];

bool canFill(int cx, int cy, int t)
{
    int mx;

    if (t == 0)
    {
        mx = 1;
    }
    else if (t == 1)
    {
        mx = 2;
    }
    else if (t == 2)
    {
        mx = 2;
    }

    for (int i = -mx; i <= mx; i++)
    {
        for (int j = -mx; j <= mx; j++)
        {
            if (abs(i) + abs(j) > mx)
            {
                continue;
            }
            if (t == 1 && (i == 0 && abs(j) == 2 || abs(i) == 2 && j == 0))
            {
                continue;
            }
            int x = j + cx, y = i + cy;
            if (x < 0 || x >= 10 || y < 0 || y >= 10)
            {
                return false;
            }
            if (!cloth[y][x])
            {
                return false;
            }
        }
    }

    return true;
}

void spuit(int cx, int cy, int t, int v)
{
    int mx;

    if (t == 0)
    {
        mx = 1;
    }
    else if (t == 1)
    {
        mx = 2;
    }
    else if (t == 2)
    {
        mx = 2;
    }

    for (int i = -mx; i <= mx; i++)
    {
        for (int j = -mx; j <= mx; j++)
        {
            if (abs(i) + abs(j) > mx)
            {
                continue;
            }
            if (t == 1 && (i == 0 && abs(j) == 2 || abs(i) == 2 && j == 0))
            {
                continue;
            }
            int x = j + cx, y = i + cy;
            if (x < 0 || x >= 10 || y < 0 || y >= 10)
            {
                continue;
            }
            cloth[y][x] -= v;
        }
    }
}

bool dfs(int n)
{
    if (n == N)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (cloth[i][j])
                {
                    return false;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d %d %d\n", x[i], y[i], type[i]);
        }
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!cloth[i][j])
            {
                continue;
            }
            for (int k = 0; k < 3; k++)
            {
                int cx = j + dx[k], cy = i + dy[k];
                if (!canFill(cx, cy, k))
                {
                    continue;
                }
                spuit(cx, cy, k, 1);

                x[n] = cx;
                y[n] = cy;
                type[n] = k + 1;
                if (dfs(n + 1))
                {
                    return true;
                }
                spuit(cx, cy, k, -1);
            }
            return false;
        }
    }

    return false;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &cloth[i][j]);
        }
    }

    dfs(0);
}