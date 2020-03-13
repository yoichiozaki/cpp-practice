#include <bits/stdc++.h>
using namespace std;

// ポイント
// - ゾンビに支配されている町から道S本以内で到達する危険な街を列挙
// - 最短経路問題に帰着
//     - 頂点でのコスト -> 向かい合う有向辺に対して終点でかかるコストをその枝のコストとする

const long long INF = 1LL << 60;

vector<long long> edge[108000];
long long dist[108000];
bool zombied[108000];
bool danger[108000];
long long N, M, K, S, P, Q, C, A, B;

void dijkstra(long long start) {
    // <cost, pos>
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    fill(dist, dist+108000, INF);

    dist[start] = 0;
    pq.push(make_pair(0LL, start));

    while (!pq.empty()) {
        pair<long long, long long> tmp = pq.top(); pq.pop();
        long long from = tmp.second;
        long long cost = tmp.first;
        if (dist[from] < cost) continue;
        for (long long i = 0; i < (long long)edge[from].size(); i++) {
            long long to = edge[from][i];
            if (zombied[to]) continue; // ゾンビに支配されている町なのでスルー

            // 辺のコストは遷移先での宿泊代
            long long ncost = P;
            if (danger[to]) ncost = Q; // 遷移先が危険な街
            if (to == N) ncost = 0; // 遷移先が終点なら宿泊しないので0
            if (dist[from] + ncost < dist[to]) {
                dist[to] = dist[from] + ncost;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;

    // ゾンビに支配されている町から道路S本以内の町を深さ優先探索でマークするためのキュー
    queue<long long> q;

    // 入力受け取り
    for (long long k = 0; k < K; k++) {
        cin >> C;
        zombied[C] = true;
        q.push(C);
    }
    for (long long m = 0; m < M; m++) {
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }

    // ゾンビに支配されている町から道路S本以内の町を深さ優先探索でマークする
    for (long long s = 0; s <= S; s++) {
        if (q.empty()) break;
        for (long long t = q.size()-1; 0 <= t; t--) {
            long long from = q.front(); q.pop();
            if (danger[from]) continue; // すでに危険とマークされていたのでスルー
            danger[from] = true;
            for (long long u = 0; u < edge[from].size(); u++) {
                q.push(edge[from][u]); // 隣接頂点をキューに入れて置く
            }
        }
    }

    // 最短経路問題に帰着
    dijkstra(1);

    cout << dist[N] << endl;

    return 0;
}