#include <bits/stdc++.h>

using namespace std;

int N;
bool G[101][101] = {};
bool visited[101];

bool DFS(int curr, int target)
{
    visited[curr] = true;
    if (curr == target)
        return true;
    for (int i = 1; i <= N; i++)
    {
        if (G[curr][i] && (!visited[i]))
            if (DFS(i, target))
                return true;
    }
    return false;
}

int main()
{
    int Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
        {
            G[u][v] = (!G[u][v]);
            G[v][u] = (!G[v][u]);
        }
        else
        {
            memset(visited, false, sizeof(visited));
            if (DFS(u, v))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}