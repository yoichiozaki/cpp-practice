#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> cnt(26, 0);
        for (int j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                for (int x = 0; x < S[j].size(); x++) {
                    cnt[S[j][x] - 'a'] += 1;
                }
            }
        }
        int _ans = 0;
        for (int j = 0; j < 28; j++) {
            if (cnt[j] == K) _ans += 1;
        }
        ans = max(ans, _ans);
    }
    cout << ans << endl;
    return 0;
}