#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<bool> has_visited;
vector<int> latest;
queue<int> suspended;
void BFS(const Graph &G, int v)
{
    has_visited[v] = true;
    suspended.push(v);

    while (!suspended.empty())
    {
        int u = suspended.front();
        suspended.pop();
        for (auto w : G[u])
        {
            if (has_visited[w])
                continue;
            else
            {
                has_visited[w] = true;
                latest[w] = u;
                suspended.push(w);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    has_visited.assign(N, false);
    latest.assign(N, -1);

    BFS(G, 0);

    for (int i = 0; i < N; i++)
    {
        if (!has_visited[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < N; i++)
    {
        cout << latest[i] + 1 << endl;
    }
    return 0;
}