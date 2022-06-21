#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> players(N, 0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        for (int j = 0; j <= i; j++) {
            players[j] += x;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (4 <= players[i]) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}