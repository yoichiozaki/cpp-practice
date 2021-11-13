#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int N;
vector<int> dists;
queue<int> suspended;

void BFS(const Graph &G, int v)
{
    for (int i = 0; i < N; i++)
        dists[i] = -1;

    dists[v] = 0;
    suspended.push(v);

    while (!suspended.empty())
    {
        int u = suspended.front();
        suspended.pop();
        for (auto w : G[u])
        {
            if (dists[w] != -1)
                continue;
            else
            {
                dists[w] = dists[u] + 1;
                suspended.push(w);
            }
        }
    }
}

int main()
{
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
        dists.push_back(-1);

    BFS(G, 0);

    int farest_node = -1, farest_dist = -1;
    for (int i = 0; i < N; i++)
    {
        if (farest_dist < dists[i])
        {
            farest_dist = dists[i];
            farest_node = i;
        }
    }

    BFS(G, farest_node);

    int diamter = -1;
    for (int i = 0; i < N; i++)
        diamter = max(diamter, dists[i]);

    cout << diamter + 1 << endl;
    return 0;
}