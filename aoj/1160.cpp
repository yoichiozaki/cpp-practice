#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> field;

void dfs(int h, int w) {
    field[h][w] = 0; // 探索済みの陸地は海にしてしまう

    for (int dh = -1; dh <= 1; dh++) {
        for (int dw = -1; dw <= 1; dw++) {
            int nh = h + dh, nw = w + dw;

            if (nh < 0 || H <= nh || nw < 0 || W <= nw) {
                continue; // 場外なのでスルー
            }
            if (field[nh][nw] == 0) {
                continue; // 海なのでスルー
            }

            dfs(nh, nw);
        }
    }
}

int main() {
    while (cin >> W >> H) {
        if (H == 0 || W == 0) {
            break;
        }
        field.assign(H, vector<int>(W, 0));
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                cin >> field[h][w];
            }
        }

        int count = 0;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (field[h][w] == 0) {
                    continue;
                }
                dfs(h, w);
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}