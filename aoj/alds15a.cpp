#include <bits/stdc++.h>
using namespace std;

int n, A[50];

// Aのi番目以降の要素を使って合計をmにできるかを判定する関数
int solve(int i, int m) {
    if (m == 0) return 1;
    if (n <= i) return 0;
    int res = solve(i+1, m) || solve(i+1, m-A[i]);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int m; cin >> m;
        if (solve(0, m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}