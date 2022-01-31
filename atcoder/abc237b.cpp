#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cin >> A[h][w];
        }
    }
    vector<vector<int>> B(W, vector<int>(H));
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            B[w][h] = A[h][w];
        }
    }
    for (int w = 0; w < W; w++)
    {
        for (int h = 0; h < H; h++)
        {
            cout << B[w][h];
            if (h == H - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}