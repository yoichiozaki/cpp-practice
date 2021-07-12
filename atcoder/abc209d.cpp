#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main()
{
    int N, Q;
    cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : G[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        if (dist[A] % 2 == dist[B] % 2)
        {
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
        }
    }

    return 0;
}