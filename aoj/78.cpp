#include <bits/stdc++.h>
using namespace std;

// 再帰で書けそう！

void rec(vector<vector<int>> &table, int h, int w, int num)
{
    int N = table.size();
    if (N * N < num)
        return; // 全部書き終わった

    if (N <= h) // 下にはみ出した
    {
        rec(table, 0, w, num);
    }
    else if (N <= w) // 右にはみ出した
    {
        rec(table, h, 0, num);
    }
    else if (w < 0) // 左にはみ出した
    {
        rec(table, h, N - 1, num);
    }
    else if (table[h][w] != 0) // 記入しようとした場所に別の数字が記入されていた
    {
        rec(table, h + 1, w - 1, num); // 左下に書き込みに行く
    }
    else
    {
        table[h][w] = num;                 // (h, w)に書き込む
        rec(table, h + 1, w + 1, num + 1); // 右下を書き込みに行く
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        vector<vector<int>> table;
        table.resize(N);
        for (int i = 0; i < N; i++)
        {
            table[i].resize(N, 0);
        }

        table[(N + 1) / 2][(N - 1) / 2] = 1; // 中央下

        rec(table, (N + 1) / 2 + 1, (N - 1) / 2 + 1, 2);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << setw(4) << setfill(' ') << table[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}