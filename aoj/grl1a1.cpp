#include <bits/stdc++.h>
using namespace std;

int V, E, r;
#define MAX_V 100001
const long long INF = 1LL << 60;
vector<pair<int, long long>> G[MAX_V];
long long dist[MAX_V];

int main() {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t;
        long long d;
        cin >> s >> t >> d;
        G[s].push_back(make_pair(t, d));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < MAX_V; i++) {
        dist[i] = INF;
    }
    dist[r] = 0;

    pq.push(make_pair(0, r));

    while (!pq.empty()) {
        int pos = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int next = G[pos][i].first;
            long long w = G[pos][i].second;
            if (dist[pos] + w < dist[next]) {
                dist[next] = dist[pos] + w;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] < INF) {
            cout << dist[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
    return 0;
}