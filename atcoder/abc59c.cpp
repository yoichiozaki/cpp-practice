#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n; cin >> n;
    ll ans1 = 0LL, ans2 = 0LL;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    ll cur; // 今見ている項までの総和

    // <<< パターン1 >>>
    // 第1項までの和が正 -> 第2項までの和が負 -> 第3項までの和が正 -> ...
    if (a.at(0) <= 0) {
        ans1 += -a.at(0) + 1; // 第1項が負なので+1にする
        cur = 1;
    } else {
        cur = a.at(0);
    }
    for (int i = 1; i < n; i++) {
        if ((0 < cur && 0 <= cur + a.at(i)) || (cur < 0 && cur + a.at(i) <= 0)) { // 今見ている項までの総和に次の項を足しても符号が反転しなかった場合
            ans1 += abs(cur + a.at(i)) + 1;
            if (0 < cur) {
                cur = -1;
            } else {
                cur = 1;
            }
        } else {
            cur += a.at(i);
        }
    }

    // <<< パターン2 >>>
    // 第1項までの和が負 -> 第2項までの和が正 -> 第3項までの和が負 -> ...
    if (0 <= a.at(0)) {
        ans2 += a.at(0) + 1;
        cur = -1;
    } else {
        cur = a.at(0);
    }
    for (int i = 1; i < n; i++) {
        if ((0 < cur && 0 <= cur + a.at(i)) || (cur < 0 && cur + a.at(i) <= 0)) {
            ans2 += abs(cur + a.at(i)) + 1;
            if (0 < cur) {
                cur = -1;
            } else {
                cur = 1;
            }
        } else {
            cur += a.at(i);
        }
    }

    cout << min(ans1, ans2) << endl;
    return 0;
}
