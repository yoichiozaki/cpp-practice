#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    int R, C; cin >> R >> C; R--, C--;
    int ans = 0;
    if (0 <= R-1 && R-1 < H && 0 <= C && C < W) ans += 1;
    if (0 <= R+1 && R+1 < H && 0 <= C && C < W) ans += 1;
    if (0 <= R && R < H && 0 <= C-1 && C-1 < W) ans += 1;
    if (0 <= R && R < H && 0 <= C+1 && C+1 < W) ans += 1;
    cout << ans << endl;
    return 0;
}