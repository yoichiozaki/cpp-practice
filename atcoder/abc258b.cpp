#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            A[i][j] = c - '0';
        }
    }
    vector<int> dh = {1, 1,  1, 0,  0, -1, -1, -1};
    vector<int> dw = {1, 0, -1, 1, -1,  1,  0, -1};
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int dir = 0; dir < 8; dir++) {
                long long now = 0;
                long long h = i, w = j;
                for (int k = 0; k < N; k++) {
                    now *= 10;
                    now += A[h][w];
                    h = ((h + dh[dir]) % N + N) % N;
                    w = ((w + dw[dir]) % N + N) % N;
                }
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
    return 0;
}