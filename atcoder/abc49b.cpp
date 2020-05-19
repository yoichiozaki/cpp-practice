#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> ans(2 * H);
    for (int i = 0; i < H; i++)
    {
        string r;
        cin >> r;
        ans[2 * i] = r;
        ans[2 * i + 1] = r;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}