#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D; cin >> N >> D;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    vector<vector<bool>> G(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= D * D) {
                G[i][j] = true;
            }
        }
    }

    vector<bool> ans(N);
    ans[0] = true;
    queue<int> Q; Q.push(0);

    while (!Q.empty()) {
        int q = Q.front(); Q.pop();
        for (int i = 0; i < N; i++) {
            if (G[q][i] && !ans[i]) {
                // connected but not yet marked
                ans[i] = true;
                Q.push(i);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }

    return 0;
}