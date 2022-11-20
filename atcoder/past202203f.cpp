#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W, N; cin >> H >> W >> N;
    int A[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    long long C[N + 1];
    for (int i = 1; i <= N; i++) cin >> C[i];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i + 1 < H && A[i][j] != A[i + 1][j] && C[A[i][j]] == C[A[i + 1][j]]) {
                cout << "No" << endl;
                return 0;
            }
            if (j + 1 < W && A[i][j] != A[i][j + 1] && C[A[i][j]] == C[A[i][j + 1]]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}