#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100001
const long long INF = 1LL << 60;

static int V, E, r;
static vector<pair<int, long long>> graph[MAX_V];
static long long dist[MAX_V];

int main() {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t; long long w;
        cin >> s >> t >> w;
        graph[s].push_back(make_pair(t, w));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < MAX_V; i++) {
        dist[i] = INF;
    }
    dist[r] = 0;
    pq.push(make_pair(0, r));

    while (!pq.empty()) {
        long long curd = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (dist[pos] < curd) {
            continue;
        }
        for (int i = 0; i < (int)graph[pos].size(); i++) {
            int to = graph[pos][i].first;
            long long weight = graph[pos][i].second;
            if (dist[pos] + weight < dist[to]) {
                dist[to] = dist[pos] + weight;
                pq.push(make_pair(dist[to], to));
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
}