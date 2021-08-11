#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX / 2;

int N, A[10][10];
int ans = -inf;
vector<int> grp[3];

void dfs(int curr, int total)
{
    if (curr == N)
    {
        ans = max(ans, total);
        return;
    }
    for (int g = 0; g < 3; g++)
    {
        int d = 0;
        for (auto i : grp[g])
            d += A[i][curr];
        grp[g].push_back(curr);
        dfs(curr + 1, total + d);
        grp[g].pop_back();
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    dfs(0, 0);
    cout << ans << endl;
}