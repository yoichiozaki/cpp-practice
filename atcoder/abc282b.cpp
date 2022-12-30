#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool ok = true;
            for (int k = 0; k < M; k++) {
                if (S[i][k] == 'x' && S[j][k] == 'x') {
                    ok = false;
                }
            }
            if (ok) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}