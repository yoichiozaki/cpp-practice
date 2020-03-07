#include <bits/stdc++.h>
using namespace std;

vector<string> field(10);
bool seen[15][15];

const int dh[4] = {1, 0, -1, 0};
const int dw[4] = {0, 1, 0, -1};

void dfs(int h, int w) {
    seen[h][w] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nh = h + dh[dir];
        int nw = w + dw[dir];
        if (nh < 0 || 10 <= nh || nw < 0 || 10 <= nw) {
            continue;
        }
        if (field[nh][nw] == 'x') {
            continue;
        }
        if (seen[nh][nw]) {
            continue;
        }

        dfs(nh, nw);
    }
}

int count_island() {
    int count = 0;
    memset(seen, 0, sizeof(seen));
    for (int h = 0; h < 10; h++) {
        for (int w = 0; w < 10; w++) {
            if (field[h][w] == 'x') {
                continue;
            }
            if (seen[h][w]) {
                continue;
            }
            dfs(h, w);
            count++;
        }
    }
    return count;
}

int main() {
    for (int i = 0; i <10; i++) {
        cin >> field[i];
    }
    for (int h = 0; h < 10; h++) {
        for (int w = 0; w < 10; w++) {
            if (field[h][w] == 'x') {
                field[h][w] = 'o'; // 埋め立てる
                if (count_island() == 1) {
                    cout << "YES" << endl;
                    return 0;
                }
                field[h][w] = 'x'; // もとに戻す
            } else {
                continue;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}