#include <bits/stdc++.h>
using namespace std;

// N個のスイッチのon/offの状態は2^N通りでそれを全探索して条件に合致しているのかを調べる

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> vec(M);
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        vec.at(i).resize(k);
        for (int j = 0; j < k; j++) {
            cin >> vec.at(i).at(j);
            vec.at(i).at(j)--;
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) {
        cin >> p.at(i);
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) { // N個のスイッチの状態を整数にエンコードして全探索
        bool ok = true;
        for (int j = 0; j < M; j++) {
            int c = 0; // 電球jにつながっているスイッチの個数
            for (int id : vec.at(j)) {
                if (i & (1<<id)) { // ビット列iの右から数えてid番目の桁が立っているか
                    c++;
                }
            }
            c %= 2;
            if (c != p.at(j)) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}