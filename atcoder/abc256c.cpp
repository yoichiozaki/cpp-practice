#include <bits/stdc++.h>

using namespace std;

int H[3], W[3], A[3][3];
long long ans = 0;

void dfs(int ij) {
    int i = ij / 3;
    int j = ij % 3;
    if (i == 3) {
        ans += 1;
        return;
    }

    if (i == 2) {
        int x = W[j] - A[0][j] - A[1][j];
        if (x <= 0) {
            return;
        }
        A[i][j] = x;
        dfs(ij + 1);
    } else if (j == 2) {
        int x = H[i] - A[i][0] - A[i][1];
        if (x <= 0) {
            return;
        }
        A[i][j] = x;
        dfs(ij + 1);
    } else {
        for (int x = 1; x <= 30; x++) {
            A[i][j] = x;
            dfs(ij + 1);
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++) cin >> H[i];
    for (int j = 0; j < 3; j++) cin >> W[j];
    if (H[0] + H[1] + H[2] != W[0] + W[1] + W[2]) {
        cout << 0 << endl;
        return 0;
    }
    dfs(0);
    cout << ans << endl;
    
    return 0;
}