#include <bits/stdc++.h>
using namespace std;

// 水平方向での切断を全部試しながら貪欲に鉛直方向に切る

// c[i][j]: 上からi個目の部分チョコレートのj列目までの領域に存在するホワイトチョコレートの個数
int c[10][1005];

const int INF = 1001001001;

int main() {
    int h, w, k; cin >> h >> w >> k;
    int ans = INF;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    // 水平方向の切断をすべて試す
    for (int div = 0; div < (1 << (h-1)); div++) {
        // 水平方向に切ったときの分割数（ex. 3回水平方向に切ったら4つ）
        int g = 0;

        // id: 上からi行目の板チョコが何番目の部分に含まれているかを記録
        vector<int> id(h);

        for (int i = 0; i < h; i++) {
            id[i] = g;
            if ((div >> i) & 1) { // divのi桁目に1が立っていればそこでチョコを分割
                g++;
            }
        }
        g++; // 植木算的に，グループ数 = 切れ込み数 + 1

        for (int i = 0; i < g; i++) {
            for (int j = 0; j < w; j++) {
                c[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                c[id[i]][j] += (s[i][j] == '1') ? 1 : 0;
            }
        }

        int num = g - 1; // 板チョコを水平方向に切断してg個の部分チョコレートにしているのですでにg-1回切っている

        vector<int> now(g);

        // j列目で鉛直方向に切断したときに，各領域に含まれるホワイトチョコレートの個数がk個以下であるかを判定する関数
        auto add = [&](int j) {
            for (int i = 0; i < g; i++) now[i] += c[i][j];
            for (int i = 0; i < g; i++) if (k < now[i]) return false;
            return true;
        };

        // 貪欲に左から右へ着る場所をずらしていく
        for (int j = 0; j < w; j++) {
            if (!add(j)) {
                num++;
                now = vector<int>(g);
                if (!add(j)) {
                    num = INF;
                    break;
                }
            }
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}