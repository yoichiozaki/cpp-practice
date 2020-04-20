#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    int homework = 0;
    for (int i = 0; i < m; i++) homework += a[i];
    if (n < homework) cout << -1 << endl;
    else cout << n - homework << endl;
    return 0;
}