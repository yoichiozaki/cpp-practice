#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    int lowest = 101;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
            if (A[i][j] < lowest)
                lowest = A[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans += A[i][j] - lowest;
        }
    }
    cout << ans << endl;
    return 0;
}