#include <bits/stdc++.h>

using namespace std;

// 幅優先探索：隣接頂点はその場で計算できる
int main() {
    string S; cin >> S;
    map<string, int> dist; // 初期状態からの距離
    queue<string> que;

    dist[S] = 0;
    que.push(S);

    while (!que.empty()) {
        string current = que.front(); que.pop();
        if (current == "atcoder") {
            cout << dist[current] << endl;
            return 0;
        } else {
            for (int i = 1; i < 7; i++) {
                string candidate = current;
                swap(candidate[i - 1], candidate[i]);
                if (dist.find(candidate) == dist.end()) {
                    que.push(candidate); // have not visited candidate yet
                    dist[candidate] = dist[current] + 1;
                } 
            }
        }
    }
    return 0;
}