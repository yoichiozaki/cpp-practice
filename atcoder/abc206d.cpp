#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<bool> has_visited;
int DFS(const Graph &G, int v, int len)
{
    has_visited[v] = true;

    for (auto u : G[v])
    {
        if (has_visited[u])
            continue;
        return DFS(G, u, len + 1);
    }
    return len;
}

int main()
{
    int N;
    cin >> N;
    Graph G(N);

    vector<int> A(N);
    set<int> S;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        S.insert(A[i]);
    }
    for (int i = 0; i < N / 2; i++)
    {
        if (A[i] != A[N - i - 1])
        {
            G[i].push_back(N - i - 1);
            G[N - i - 1].push_back(i);
        }
    }

    has_visited.assign(N, false);

    int cc = 0;
    for (int i = 0; i < N; i++)
    {
        if (!has_visited[i])
        {
            int l = DFS(G, i, 1);
            if (l != 1)
                cc++;
        }
    }

    cout << S.size() - cc << endl;
    return 0;
}