#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector A(N, vector<bool>(N));
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        A[u][v] = true; A[v][u] = true;
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i][j] && A[j][k] && A[k][i]) {
                    ret += 1;
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}