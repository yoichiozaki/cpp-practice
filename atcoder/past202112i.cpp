#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<pair<long long, long long>>>;

// 頂点数が10^18まであるので多すぎる -> 結局エレベーターがある階が重要なのでそれだけを頂点にする

int main()
{
    long long N;
    int M;
    cin >> N >> M;

    Graph G(N, vector<pair<long long, long long>>());
    for (long long i = 0; i < N - 1; i++)
    {
        G[i].push_back(make_pair(i + 1, 1LL));
        G[i + 1].push_back(make_pair(i, 1LL));
    }
    for (int i = 0; i < M; i++)
    {
        long long A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        G[A].push_back(make_pair(B, C));
        G[B].push_back(make_pair(A, C));
    }

    long long INF = LONG_LONG_MAX / 2LL;

    vector<long long> dist(N, INF);
    set<long long> has_visited;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> suspended;

    has_visited.insert(0LL);
    suspended.push({0LL, 0LL});
    dist[0LL] = 0LL;

    while (!suspended.empty())
    {
        auto p1 = suspended.top();
        suspended.pop();
        long long d = p1.first;
        long long u = p1.second;
        has_visited.insert(u);
        for (auto p2 : G[u])
        {
            long long v = p2.first;
            long long cost = p2.second;
            if ((has_visited.find(v) == has_visited.end()) && dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                suspended.push({dist[v], v});
            }
        }
    }
    cout << dist[N - 1] << endl;
    return 0;
}