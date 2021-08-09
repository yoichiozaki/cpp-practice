#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<int> ans;
void DFS(const Graph &G, int curr, int pre)
{
    ans.push_back(curr);

    for (auto nxt : G[curr])
    {
        if (nxt != pre)
        {
            DFS(G, nxt, curr);
            ans.push_back(curr);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Graph G(N);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < N; i++)
    {
        sort(G[i].begin(), G[i].end());
    }

    DFS(G, 0, -1);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << ans[i] + 1;
    }
    cout << endl;

    return 0;
}