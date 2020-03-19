#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int G[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int v; cin >> v; v--;
            G[u][v] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n-1) cout << G[i][j] << endl;
            else cout << G[i][j] << " ";
        }
    }
    return 0;
}