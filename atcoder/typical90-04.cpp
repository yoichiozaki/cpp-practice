#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    vector<int> rowsum(H, 0);
    for (int i = 0; i < H; i++)
    {
        int s = 0;
        for (int j = 0; j < W; j++)
        {
            s += A[i][j];
        }
        rowsum[i] = s;
    }
    vector<int> colsum(W, 0);
    for (int j = 0; j < W; j++)
    {
        int s = 0;
        for (int i = 0; i < H; i++)
        {
            s += A[i][j];
        }
        colsum[j] = s;
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int ans = rowsum[i] + colsum[j] - A[i][j];
            if (j == W - 1)
                cout << ans << endl;
            else
                cout << ans << " ";
        }
    }
    return 0;
}