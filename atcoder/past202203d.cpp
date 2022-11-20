#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N; cin >> T >> N;
    vector<vector<int>> P(T, vector<int>(N, 0));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P[i][j];
        }
    }
    for (int t = 0; t < T; t++) {
        vector<int> highscores(N, 0);
        for (int n = 0; n < N; n++) {
            for (int k = 0; k <= t; k++) {
                highscores[n] = max(highscores[n], P[k][n]);
            }
        }
        
        int ans = 0;
        for (int n = 0; n < N; n++) {
            ans += highscores[n];
        }
        cout << ans << endl;
    }
    return 0;
}