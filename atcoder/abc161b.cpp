#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s <= a[i] * 4 * m) cnt++;
    }
    if (m <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}