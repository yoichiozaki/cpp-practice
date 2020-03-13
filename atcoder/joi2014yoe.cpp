#include <bits/stdc++.h>
using namespace std;

// まず任意のi，jについて「町iから町jまで乗り換え無しで行けるか」を調べる
// その情報を使って「町iから町jにはコストC_ijかかる（直通）タクシーが走っている」として新しいグラフを作成し，それに対してDijkstra法などを適用する

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

    for (int i = 0; i < K; i++) {
        int to, from; cin >> to >> from;
        to--; from--;
        taxis[to].edges.push_back(from);
        taxis[from].edges.push_back(to);
    }

    // 任意のi，jについて
    // 「町iから町jまで乗り換え無しで行けるか」
    // をBFSで調べる
    for (int i = 0; i < N; i++) {
        queue<int> q;
        q.push(i);
        for (int k = 0; k < taxis[i].R; k++) {
            queue<int> q2;
            while (!q.empty()) {
                int n = q.front(); q.pop();
                for (int j = 0; j < (int)taxis[n].edges.size(); j++) {
                    int to = taxis[n].edges[j];
                    if (!taxis[to].flag) {
                        taxis[to].flag = true;
                        q2.push(to); // 町iから道k本以内なので行ける
                    }
                }
            }
            q = q2;
        }
        for (int k = 0; k < N; k++) {
            if (i != k && taxis[k].flag) {
                taxis[i].edges2.push_back(k);
            }
            taxis[k].flag = false;
        }
    }

    // Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0)); // <cost, pos>
    while (!pq.empty()) {
        pair<int, int> a = pq.top(); pq.pop();
        int cost = a.first;
        int n = a.second;
        if (cost < taxis[n].ans) {
            taxis[n].ans = cost;
            if (n == N-1) {
                break;
            }
            for (auto iter = taxis[n].edges2.begin(); iter != taxis[n].edges2.end(); iter++) {
                if (taxis[*iter].ans == INF) {
                    pq.push(make_pair(cost + taxis[n].C, *iter));
                }
            }
        }
    }
    cout << taxis[N-1].ans << endl;
    return 0;
}