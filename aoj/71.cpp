#include <bits/stdc++.h>
using namespace std;

vector<string> field;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y)
{
    field[y][x] = '0';

    for (int i = 1; i <= 3; i++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (0 <= nx && nx <= 7 && 0 <= ny && ny <= 7 && field[ny][nx] != '0')
                DFS(nx, ny);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    field.resize(8);
    for (int c = 0; c < N; c++)
    {
        for (int j = 0; j < 8; j++)
            cin >> field[j];
        int X, Y;
        cin >> X >> Y;
        X--;
        Y--;

        DFS(X, Y);

        cout << "Data " << c + 1 << ":" << endl;
        for (int i = 0; i < 8; i++)
            cout << field[i] << endl;
    }
    return 0;
}