#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);

    vector<int> out_degree(N); // out_degree[i]: 頂点iを始点とする辺の本数
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        from -= 1;
        to -= 1;
        G[to].push_back(from); // 辺を逆向きに保存する
        out_degree[from]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
        if (out_degree[i] == 0)
        {
            q.push(i); // シンクノードをキューに突っ込む
        }

    vector<int> order; // order[i]: 頂点iのトポロジカルソートにおける順位の逆順
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        order.push_back(v);
        for (auto neighbor : G[v])
        {
            out_degree[neighbor]--; // シンクノードに向かって生えていた辺を消す
            if (out_degree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    reverse(order.begin(), order.end());
    if (order.size() == N)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}