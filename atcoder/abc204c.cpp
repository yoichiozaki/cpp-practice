#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<bool> has_visited;
queue<int> suspended;

void DFS(const Graph &G, int v)
{
    has_visited[v] = true;

    for (auto u : G[v])
    {
        if (has_visited[u])
            continue;
        DFS(G, u);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;
        G[A].push_back(B);
    }

    int ans = 0;
    for (int init = 0; init < N; init++)
    {
        has_visited.assign(N, false);
        DFS(G, init);
        for (int i = 0; i < N; i++)
        {
            if (has_visited[i])
                ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}