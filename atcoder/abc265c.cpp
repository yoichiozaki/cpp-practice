#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> G(H);
    for (auto& s: G) cin >> s;
    vector visited(H, vector<int>(W, 0));

    int i = 0;
    int j = 0;

    while (true) {
        if (visited[i][j]) {
            cout << -1 << endl;
            return 0;
        }
        visited[i][j] = 1;
        if (G[i][j] == 'U' && i != 0) i--;
        else if (G[i][j] == 'D' && i != H - 1) i++;
        else if (G[i][j] == 'L' && j != 0) j--;
        else if (G[i][j] == 'R' && j != W - 1) j++;
        else break;
    }
    cout << i + 1 << " " << j + 1 << endl;
    return 0;
}