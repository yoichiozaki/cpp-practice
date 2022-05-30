#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<pair<int, int>> pieces;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;
            if (c == 'o')
                pieces.emplace_back(i, j);
        }
    }
    const auto& [x1, y1] = pieces[0];
    const auto& [x2, y2] = pieces[1];
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;
}