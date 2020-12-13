#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> masu(H, "");
    for (int i = 0; i < H; i++)
    {
        cin >> masu[i];
    }
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == H - 1)
            { // 下端
                if (j == W - 1)
                { // 右端
                    ;
                }
                else
                {
                    if (masu[i][j] == '.' && masu[i][j + 1] == '.')
                        ans++;
                }
            }
            else
            {
                if (masu[i][j] == '.' && masu[i][j + 1] == '.')
                    ans++;
                if (masu[i][j] == '.' && masu[i + 1][j] == '.')
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}