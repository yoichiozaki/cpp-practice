#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    const vector<int> dx = {1, 0, -1,  0, 1, -1, -1,  1};
    const vector<int> dy = {0, 1,  0, -1, 1,  1, -1, -1};
    vector<string> board(H);
    for (int i = 0; i < H; i++) {
        cin >> board.at(i);
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board.at(i).at(j) == '#') { continue; }

            int num = 0;
            for (int d = 0; d < 8; d++) {
                const int ni = i + dx.at(d);
                const int nj = j + dy.at(d);

                if (ni < 0 || H <= ni) { continue; }
                if (nj < 0 || W <= nj) { continue; }
                if (board.at(ni).at(nj) == '#') {
                    num++;
                }
            }

            board.at(i).at(j) = char(num + '0');
        }
    }

    for (int i = 0; i < H; i++) {
        cout << board.at(i) << endl;
    }
    return 0;
}
