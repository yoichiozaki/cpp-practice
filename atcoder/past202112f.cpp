#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int N = 9;
    vector<string> S(3);
    for (auto &el : S)
        cin >> el;
    A--, B--;
    vector<vector<bool>> flag(N, vector<bool>(N));
    flag[A][B] = true;
    queue<pair<int, int>> que;
    que.push(make_pair(A, B));
    while (!que.empty())
    {
        auto p = que.front();
        que.pop();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int x = p.first + i - 1;
                int y = p.second + j - 1;
                if (0 <= x && x < N && 0 <= y && y < N && S[i][j] == '#' && !flag[x][y])
                {
                    flag[x][y] = true;
                    que.push(make_pair(x, y));
                }
            }
        }
    }
    int ans = 0;
    for (auto p : flag)
    {
        for (auto q : p)
            ans += q;
    }
    cout << ans << endl;
    return 0;
}