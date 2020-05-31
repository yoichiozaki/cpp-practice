#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    vector<vector<int>> gridL(h, vector<int>(w));
    vector<vector<int>> gridR(h, vector<int>(w));
    vector<vector<int>> gridU(h, vector<int>(w));
    vector<vector<int>> gridD(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        cin >> s[i];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            char c = s[i][j];
            if (c == '#')
            {
                gridU[i][j] = 0;
                gridL[i][j] = 0;
            }
            else
            {
                gridU[i][j] = 1 + gridU[max(i - 1, 0)][j];
                gridL[i][j] = 1 + gridL[i][max(j - 1, 0)];
            }
        }
    }

    for (int i = h - 1; i >= 0; --i)
    {
        for (int j = w - 1; j >= 0; --j)
        {
            char c = s[i][j];
            if (c == '#')
            {
                gridD[i][j] = 0;
                gridR[i][j] = 0;
            }
            else
            {
                gridD[i][j] = 1 + gridD[min(i + 1, h - 1)][j];
                gridR[i][j] = 1 + gridR[i][min(j + 1, w - 1)];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            ans = max(ans, gridU[i][j] + gridL[i][j] + gridD[i][j] + gridR[i][j] - 3);
    cout << ans << endl;
}
