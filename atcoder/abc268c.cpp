#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cnt[(P[i] - 1 - i + j + N) % N] += 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}