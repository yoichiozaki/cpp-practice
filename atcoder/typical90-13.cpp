#include <bits/stdc++.h>

using namespace std;

long long N, M;

long long dist[100005];
long long dist1[100005];
long long distN[100005];

vector<pair<int, long long>> G[100005];

void dijkstra(int source)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    for (int i = 1; i <= N; i++)
        dist[i] = (1LL << 60);
    dist[source] = 0;
    Q.push(make_pair(0, source));

    while (!Q.empty())
    {
        int node = Q.top().second;
        Q.pop();
        for (int i = 0; i < G[node].size(); i++)
        {
            int to = G[node][i].first;
            long long cost = G[node][i].second;
            if (dist[to] > dist[node] + cost)
            {
                dist[to] = dist[node] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    dijkstra(1);
    for (int i = 1; i <= N; i++)
        dist1[i] = dist[i];

    dijkstra(N);
    for (int i = 1; i <= N; i++)
        distN[i] = dist[i];

    for (int i = 1; i <= N; i++)
    {
        cout << dist1[i] + distN[i] << endl;
    }
    return 0;
}