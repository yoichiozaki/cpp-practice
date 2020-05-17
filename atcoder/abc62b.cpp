#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> pic(H + 2, vector<char>(W + 2, '#'));
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> pic[i][j];
        }
    }
    for (int i = 0; i < H + 2; i++)
    {
        for (int j = 0; j < W + 2; j++)
            cout << pic[i][j];
        cout << endl;
    }
    return 0;
}