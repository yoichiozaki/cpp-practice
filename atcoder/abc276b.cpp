#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b);
        G[b - 1].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
        cout << G[i].size();
        for (int nbr: G[i]) {
            cout << " " << nbr;
        }
        cout << endl;
    }
    return 0;
}