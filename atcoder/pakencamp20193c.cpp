#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<long long>> a(n+1, vector<long long>(m+1, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> done(m+1, vector<bool>(m+1, false));
    long long ans = -1;
    for (int i = 1; i <= m-1; i++) {
        for (int j = i+1; j <= m; j++) {
            if (done[j][i]) continue;
            done[i][j] = done[j][i] = true;
            long long s = 0;
            for (int k = 1; k <= n; k++) {
                s += max(a[k][i], a[k][j]);
            }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}