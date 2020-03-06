#include <bits/stdc++.h>
using namespace std;

int N, M, S, A[500009], B[500009], C[500009];
int dist[100009];
vector<pair<int, int>> G[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }
    scanf("%d", &S);

    for (int i = 1; i <= N; i++) {
        dist[i] = 1000000007;
    }

    Q.push(make_pair(0, S));
    dist[S] = 0;
    while (!Q.empty()) {
        int pos = Q.top().second; Q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            int to = G[pos][i].first;
            int cost = G[pos][i].second;
            if (dist[pos] + cost < dist[to]) {
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d\n", dist[i]);
    }
    return 0;
}