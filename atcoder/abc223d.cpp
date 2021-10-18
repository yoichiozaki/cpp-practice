#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> in_degree(N, 0);
    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        in_degree[b] += 1;
        G[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < N; i++)
    {
        if (in_degree[i] == 0)
            heap.push(i);
    }
    vector<int> ans;
    ans.reserve(N);
    while (!heap.empty())
    {
        int node = heap.top();
        heap.pop();
        ans.push_back(node);
        for (int neighbor : G[node])
        {
            in_degree[neighbor] -= 1;
            if (in_degree[neighbor] == 0)
                heap.push(neighbor);
        }
    }

    if (ans.size() != N)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < N; i++)
            cout << ans[i] + 1 << (i + 1 == N ? "\n" : " ");
    }
    return 0;
}