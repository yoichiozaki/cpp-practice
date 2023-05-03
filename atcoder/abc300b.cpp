#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    for (int i = 0; i < H; i++) cin >> B[i];

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
            int ok = 1;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[(i - s + H) % H][(j - t + W) % W] != B[i][j]) {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}