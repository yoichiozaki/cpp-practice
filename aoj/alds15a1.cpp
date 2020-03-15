#include <bits/stdc++.h>
using namespace std;

int n, a[25];

int solve(int i, int m) {
    if (m == 0) return 1;
    if (n <= i) return 0;
    int ret = solve(i+1, m) || solve(i+1, m-a[i]);
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
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