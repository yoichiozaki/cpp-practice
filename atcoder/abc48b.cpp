#include <bits/stdc++.h>
using namespace std;

/*
 * Point
 * - a以上b以下の整数のうち，条件を満たすものの個数を求める系問題では
 *   f(n) := 0以上n以下の整数のうち条件を満たすものの個数
 *   という関数を定義しておくことでf(b) - f(a-1)で求められる．ただしa = 0のとき
 *   f(-1)が呼ばれることに注意すること．
 */

using ull = unsigned long long;

ull a, b, x;

ull f(ull p) {
    if (p == -1) {
        return (ull)0;
    } else {
        return (ull)p/x + (ull)1;
    }
}

int main() {
    cin >> a >> b >> x;
    cout << f(b) - f(a-1) << endl;
    return 0;
}
