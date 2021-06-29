#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int src, to;
    long long cost;

    edge(int to, long long cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, long long cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const
    {
        return to;
    }
};

using Edges = vector<edge>;
using Graph = vector<Edges>;

vector<long long> dijkstra(Graph &G, int s)
{
    vector<long long> dist(G.size(), numeric_limits<long long>::max());
    dist[s] = 0;

    using Pi = pair<long long, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    que.emplace(dist[s], s);

    while (!que.empty())
    {
        auto entry = que.top();
        long long cost = entry.first;
        int idx = entry.second;
        que.pop();

        if (dist[idx] < cost)
            continue;

        for (auto &edge : G[idx])
        {
            auto next_cost = cost + edge.cost;
            if (dist[edge.to] <= next_cost)
                continue;
            dist[edge.to] = next_cost;

            que.emplace(dist[edge.to], edge.to);
        }
    }

    return dist;
}

int main()
{
    int N, M, AB, AC, BC;
    string S;
    cin >> N >> M >> AB >> AC >> BC >> S;
    Graph G(N + 6);
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'A')
        {
            G[i].emplace_back(N, AB);
            G[i].emplace_back(N + 1, AC);
            G[N + 2].emplace_back(i, 0);
            G[N + 4].emplace_back(i, 0);
        }

        if (S[i] == 'B')
        {
            G[i].emplace_back(N + 2, AB);
            G[i].emplace_back(N + 3, BC);
            G[N].emplace_back(i, 0);
            G[N + 5].emplace_back(i, 0);
        }

        if (S[i] == 'C')
        {
            G[i].emplace_back(N + 4, AC);
            G[i].emplace_back(N + 5, BC);
            G[N + 1].emplace_back(i, 0);
            G[N + 3].emplace_back(i, 0);
        }
    }

    cout << dijkstra(G, 0)[N - 1] << endl;
    return 0;
}