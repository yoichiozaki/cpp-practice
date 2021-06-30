#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> color_map(N, 0);
    for (int i = 0; i < N; i++)
        cin >> color_map[i];

    for (int _ = 0; _ < Q; _++)
    {
        int inst;
        cin >> inst;
        if (inst == 1)
        {
            int x;
            cin >> x;
            x--;
            cout << color_map[x] << endl;
            for (auto neighbor : G[x])
            {
                color_map[neighbor] = color_map[x];
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            cout << color_map[x] << endl;
            color_map[x] = y;
        }
    }
    return 0;
}