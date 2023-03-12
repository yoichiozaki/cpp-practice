#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    int field[11][11];
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> field[h][w];
        }
    }
    int perm[20], L = H + W - 2, ans = 0;
    // initialize perm[20] like 00..0011..11
    for (int i = 1; i <= L; i++) {
        if (i > W - 1) perm[i] = 1;
        else perm[i] = 0;
    }
    do {
        int h = 1, w = 1;
        set<int> visited; visited.insert(field[h][w]);
        for (int i = 1; i <= L; i++) {
            if (perm[i]) h++;
            else w++;
            visited.insert(field[h][w]);
        }
        if (visited.size() == L + 1) ans += 1;
    } while (next_permutation(perm + 1, perm + L + 1));
    cout << ans << endl;
    return 0;
}