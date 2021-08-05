#include <bits/stdc++.h>

using namespace std;

#define INF (long long)4e+18

using Graph = vector<vector<pair<long long, long long>>>;

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);

    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        long long from, to, weight;
        cin >> from >> to >> weight;
        from -= 1;
        to -= 1;
        G[from].push_back(make_pair(to, weight));
        G[to].push_back(make_pair(from, weight));
    }

    vector<long long> dist(N, INF);
    vector<long long> max_satisfaction(N, 0);
    vector<bool> has_fixed(N, false);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    dist[0] = 0;
    max_satisfaction[0] = A[0];
    pq.push(make_pair(0, 0));

    int u, v, cur, nxt;
    long long x, dd;

    while (true)
    {
        while (has_fixed[cur = pq.top().second])
        {
            pq.pop();
        }
        if (cur == N - 1)
        {
            break;
        }
        has_fixed[cur] = true;
        pq.pop();
        for (int i = 0; i < G[cur].size(); i++)
        {
            nxt = G[cur][i].first;
            dd = G[cur][i].second;
            if ((dist[cur] + dd) < dist[nxt])
            {
                pq.push({dist[nxt] = dist[cur] + dd, nxt});
                max_satisfaction[nxt] = max_satisfaction[cur] + A[nxt];
            }
            else if ((dist[cur] + dd) == dist[nxt])
            {
                max_satisfaction[nxt] = max(max_satisfaction[nxt], max_satisfaction[cur] + A[nxt]);
            }
        }
    }
    cout << max_satisfaction[N - 1] << endl;
    return 0;
}