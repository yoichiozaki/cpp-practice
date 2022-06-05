#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<bool> square(N + 1, false);
    for (int i = 1; i * i <= N; i++) {
        square[i * i] = true;
    }
    vector<vector<int>> D(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            D[j].push_back(i);
        }
    }
    vector<int> cnt(N + 1);
    for (int i = 1; i <= N; i++) {
        int f = 0;
        for (int j = 0; j < D[i].size(); j++) {
            if (square[D[i][j]]) {
                f = D[i][j];
            }
        }
        cnt[i / f] += 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += cnt[i] * cnt[i];
    }
    cout << ans << endl;
    return 0;
}