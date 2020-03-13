#include <bits/stdc++.h>
using namespace std;

// ポイント
// - 任意のi，jに対して「町iから町jに乗り換え無しで行けるか」を調べて新しいグラフを作る

const int INF = 1001001001;

struct Taxi {
    int C, R;
    vector<int> edges, edges2;
    bool flag;
    int ans;
    Taxi() : flag(false), ans(INF) { }
} taxis[5010];

int main() {
    int N, K; cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> taxis[i].C >> taxis[i].R;
    }

    for (int k = 0; k < K; k++) {
        int from, to; cin >> from >> to;
        from--; to--;
        taxis[from].edges.push_back(to);
        taxis[to].edges.push_back(from);
    }

    // 任意のi，jに対して「町iから町jまで乗り換え無しで行けるか」をBFSで調べる
    for (int i = 0; i < N; i++) {
        queue<int> q;
        q.push(i);
        for (int r = 0; r < taxis[i].R; r++) { // 町iから道路taxis[i].R本以内にある町にフラグを立てる
            queue<int> q2;
            while (!q.empty()) {
                int town = q.front(); q.pop();
                for (int j = 0; j < (int)taxis[town].edges.size(); j++) { // 1つ隣の町を見る
                    int to = taxis[town].edges[j];
                    if (!taxis[to].flag) {
                        taxis[to].flag = true;
                        q2.push(to);
                    }
                }
            }
            q = q2; // 町iから道路r本で行ける町のリストをつかって，町iから道路r+1本で行ける町にフラグを立てに行く
        }

        for (int k = 0; k < N; k++) {
            if (i != k && taxis[k].flag) {
                taxis[i].edges2.push_back(k); // 町iから道路taxis[i].R本以内にある町への直通辺を記録
            }
            taxis[k].flag = false; // 町iから道路taxis[i].R本でたどり着けないのでフラグを倒しておく
        }
    }

    // Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> a = pq.top(); pq.pop();
        int cost = a.first;
        int town = a.second;
        if (cost < taxis[town].ans) {
            taxis[town].ans = cost;
            if (town == N-1) {
                break;
            }
            for (auto iter = taxis[town].edges2.begin(); iter < taxis[town].edges2.end(); iter++) {
                if (taxis[*iter].ans == INF) {
                    pq.push(make_pair(cost + taxis[town].C, *iter));
                }
            }
        }
    }

    cout << taxis[N-1].ans << endl;

    return 0;
}