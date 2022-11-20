#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    map<int, vector<int>> G;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> Q;
    set<int> has_visited;

    Q.push(1);
    has_visited.insert(1);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        for (int neighbor : G[node]) {
            if (!has_visited.count(neighbor)) {
                has_visited.insert(neighbor);
                Q.push(neighbor);
            }
        }
    }

    cout << *has_visited.rbegin() << endl;
}