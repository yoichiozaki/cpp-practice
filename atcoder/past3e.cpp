#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    Graph G(N);
    vector<int> colormap(N, 0);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < N; i++)
        cin >> colormap[i];

    for (int q = 0; q < Q; q++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            x--;
            cout << colormap[x] << endl;
            for (auto neighbor : G[x])
            {
                colormap[neighbor] = colormap[x];
            }
        }
        else if (type == 2)
        {
            int x, y;
            cin >> x >> y;
            x--;
            cout << colormap[x] << endl;
            colormap[x] = y;
        }
    }
    return 0;
}