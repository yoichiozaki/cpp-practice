#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<int>> cnt(10, vector<int>(10, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cnt[(S[i][j] - '0')][j] += 1;
        }
    }
    int ans = 99999;
    for (int i = 0; i < 10; i++) {
        int mx = 0;
        for (int j = 0; j < 10; j++) {
            mx = max(mx, 10 * (cnt[i][j] - 1) + j);
        }
        ans = min(ans, mx);
    }
    cout << ans << endl;
    return 0;
}