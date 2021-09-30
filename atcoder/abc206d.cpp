#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<bool> has_visited;
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
    int N;
    cin >> N;
    Graph G(N);

    vector<int> A(N);
    set<int> S;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i] -= 1;
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
            DFS(G, i);
            cc++;
        }
    }
    cout << S.size() << endl;
    cout << cc << endl;
    cout << S.size() - cc << endl;
    return 0;
}