#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> Field(H);
    for (int i = 0; i < H; i++) {
        cin >> Field[i];
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < Field[i].size(); j++) {
            if (Field[i][j] == '#') ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}