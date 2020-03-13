#include <bits/stdc++.h>
using namespace std;

// REF: https://qiita.com/drken/items/56a6b68edef8fc605821

// 累積和を何も考えずに書けるようにする
// - 累積和とは「適切な前処理をしておくことで，配列上の区間の総和を求めるクエリを爆速で処理できるようになる手法」
// - 注意すべきは「配列の範囲指定では，左端は閉区間・右端は開区間」ということ
// - [left, right)のleftとかrightは「配列の両端を含む隙間の内のどこを指しているか」と考えるとわかりやすい
// - 配列aの区間[left, right)の総和はS_right - S_leftである
// - s[i+1] = s[i] + a[i]
// - s[i] = 区間[0, i)の総和
// - s[0] = 区間[0, 0)の総和なので0
// - 配列aに対して累積和sを求めると，配列aの区間[left, right)の総和が s[right] - s[left] で求められる

int main() {
    int n; cin >> n;
    vector<int> a(n, 0);
    vector<int> s(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[i];
    }
    return 0;
}