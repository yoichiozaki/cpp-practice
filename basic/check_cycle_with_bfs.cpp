#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int N; cin >> N;

    Graph G(N);
    vector<int> out_degree(N, 0);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        out_degree[a]++;
        out_degree[b]++;
    }

    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (out_degree[i] == 1) {
            que.push(i);
        }
    }

    vector<bool> has_pushed(N, false);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        has_pushed[v] = true; // queにpushされていないとpopされないので「取り出されたときに」チェックしている
        for (auto w : G[v]) {
            out_degree[w]--; // vが削除されるのでwのout_degreeが1減る
            if (out_degree[w] == 0) {
                que.push(w);
            }
        }
    }

    int Q; cin >> Q;
    for (int _ = 0; _ < Q; _++) {
        int a, b; cin >> a >> b; a--; b--;
        if (!has_pushed[a] && !has_pushed[b]) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}

// 外向きの辺が生えていない頂点を，その頂点めがけた辺ともども削除して行くことを考えると
// グラフ中にcycleが存在するとき，そのcycleに含まれる頂点はシンクとして削除されることはないので，BFSのキューに入らない