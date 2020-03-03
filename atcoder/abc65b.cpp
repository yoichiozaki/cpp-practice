#include <bits/stdc++.h>
using namespace std;

// どのボタンが光るかを順にシミュレートしていく
// 「いつまで経ってもボタン2が光らない」ことを有限回のシミュレートでは確かめられない
// N回ボタンを押してもボタン2が光らなかったとき，その間にN+1回いずれかのボタンが光るので
// そのうちある2つは同じボタンのはずで，同じボタンが光った状態から光っているボタンを押し続けても
// ボタンの光る順番は周期的になるはず．よって永遠にボタン2は光らないと言える．

int main() {
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    int lighting = 1;
    int cnt = 0;
    while (1) {
        if (lighting == 2) {
            cout << cnt << endl;
            break;
        }
        if (n <= cnt) {
            cout << -1 << endl;
            return 0;
        }
        cnt++;
        lighting = a.at(lighting);
    }
    return 0;
}
